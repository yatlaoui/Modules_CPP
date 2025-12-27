# Explications des Concepts C++ - Module 04

## Table des matières
1. [Virtual et Polymorphisme](#1-virtual-et-polymorphisme)
2. [Pure Virtual (= 0) et Classes Abstraites](#2-pure-virtual--0-et-classes-abstraites)
3. [Deep Copy vs Shallow Copy](#3-deep-copy-vs-shallow-copy)
4. [Ordre des Constructeurs et Destructeurs](#4-ordre-des-constructeurs-et-destructeurs)
5. [Résumé des Exercices 00, 01, 02](#5-résumé-des-exercices-00-01-02)

---

## 1. Virtual et Polymorphisme

### Qu'est-ce que `virtual` ?

Le mot-clé `virtual` permet le **polymorphisme** en C++. Il indique au compilateur que la méthode peut être redéfinie (override) dans les classes dérivées, et que l'appel doit être résolu à l'**exécution** (runtime) et non à la **compilation** (compile time).

### Sans `virtual` (Mauvais exemple)

```cpp
class Animal {
public:
    void makeSound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
};

int main() {
    Animal* animal = new Dog();
    animal->makeSound();  // Affiche: "Some generic animal sound"
    // ❌ Pas le bon comportement! On voulait "Woof!"
    delete animal;
}
```

**Problème**: Sans `virtual`, le compilateur décide à la compilation quelle fonction appeler. Comme `animal` est de type `Animal*`, il appelle `Animal::makeSound()`, même si l'objet est en réalité un `Dog`.

### Avec `virtual` (Bon exemple)

```cpp
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }
    virtual ~Animal() {}  // Destructeur virtual OBLIGATOIRE!
};

class Dog : public Animal {
public:
    void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
};

int main() {
    Animal* animal = new Dog();
    animal->makeSound();  // Affiche: "Woof!"
    // ✅ Bon comportement! Polymorphisme!
    delete animal;
}
```

**Solution**: Avec `virtual`, le compilateur crée une **vtable** (table virtuelle) qui permet de résoudre l'appel de fonction à l'exécution. Il regarde le type réel de l'objet (`Dog`) et appelle la bonne fonction.

### Pourquoi `virtual ~Animal()` ?

```cpp
class Animal {
public:
    virtual ~Animal() {
        std::cout << "Animal destructor" << std::endl;
    }
};

class Dog : public Animal {
private:
    Brain* brain;  // Pointeur alloué dynamiquement
public:
    Dog() { brain = new Brain(); }
    ~Dog() {
        delete brain;  // Libération de la mémoire
        std::cout << "Dog destructor" << std::endl;
    }
};

int main() {
    Animal* animal = new Dog();
    delete animal;
    // Avec virtual ~Animal(): appelle ~Dog() puis ~Animal() ✅
    // Sans virtual: appelle seulement ~Animal() ❌ MEMORY LEAK!
}
```

**Règle importante**: Si une classe a des fonctions virtuelles, le destructeur DOIT être virtuel!

---

## 2. Pure Virtual (= 0) et Classes Abstraites

### Qu'est-ce qu'une fonction pure virtuelle ?

Une fonction **pure virtuelle** est une fonction qui:
- N'a pas d'implémentation dans la classe de base
- Se termine par `= 0`
- Rend la classe **abstraite** (non-instanciable)

### Syntaxe

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual
    //                              ^^^^
    //                              Ceci rend la fonction "pure"
};
```

### Pourquoi utiliser `= 0` ?

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual
    virtual ~Animal() {}
};

int main() {
    Animal a;  // ❌ ERREUR DE COMPILATION!
    // error: cannot declare variable 'a' to be of abstract type 'Animal'

    Animal* ptr = new Animal();  // ❌ ERREUR DE COMPILATION!
    // error: invalid abstract type for new-expression
}
```

**Raison**: Créer un objet `Animal` n'a pas de sens! Un animal peut-il faire un bruit sans être un chien, un chat, etc. ? Non! Donc on force les classes dérivées à implémenter `makeSound()`.

### Classes concrètes (implémentent les fonctions pures)

```cpp
class Dog : public Animal {
public:
    void makeSound() const {  // Implémentation obligatoire
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const {  // Implémentation obligatoire
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Animal a;  // ❌ Impossible
    Dog d;        // ✅ OK - Dog implémente makeSound()
    Cat c;        // ✅ OK - Cat implémente makeSound()

    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    animals[0]->makeSound();  // "Woof!"
    animals[1]->makeSound();  // "Meow!"

    delete animals[0];
    delete animals[1];
}
```

### Différence entre `virtual` et `= 0`

| Concept | virtual | virtual ... = 0 (pure virtual) |
|---------|---------|--------------------------------|
| **Implémentation** | A une implémentation par défaut | N'a PAS d'implémentation |
| **Override obligatoire ?** | Non (optionnel) | Oui (obligatoire) |
| **Classe instanciable ?** | Oui | Non (classe abstraite) |
| **Usage** | Comportement par défaut | Forcer l'implémentation |

---

## 3. Deep Copy vs Shallow Copy

### Shallow Copy (Copie superficielle) - DANGEREUX ⚠️

```cpp
class Dog {
private:
    Brain* brain;  // Pointeur!
public:
    Dog() {
        brain = new Brain();  // Allocation dynamique
    }

    // Copie par défaut (shallow copy) ❌
    // Dog(const Dog& other) {
    //     brain = other.brain;  // Copie juste le pointeur!
    // }

    ~Dog() {
        delete brain;
    }
};

int main() {
    Dog dog1;
    Dog dog2 = dog1;  // Shallow copy

    // Problème: dog1.brain et dog2.brain pointent vers la MÊME adresse!
    //
    //  dog1.brain  ──┐
    //                ├──> [Brain object in memory]
    //  dog2.brain  ──┘

}  // Destruction: ❌ CRASH! double free
   // ~Dog() de dog2: delete brain (OK)
   // ~Dog() de dog1: delete brain (ERREUR - déjà supprimé!)
```

**Problème**: Les deux objets partagent le même pointeur. Quand on détruit un objet, on libère la mémoire, mais l'autre objet a encore un pointeur vers cette mémoire (dangling pointer).

### Deep Copy (Copie profonde) - CORRECT ✅

```cpp
class Brain {
private:
    std::string ideas[100];
public:
    Brain() {}

    Brain(const Brain& other) {  // Deep copy de Brain
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];  // Copie les valeurs
        }
    }

    Brain& operator=(const Brain& other) {
        if (this != &other) {
            for (int i = 0; i < 100; i++) {
                ideas[i] = other.ideas[i];
            }
        }
        return *this;
    }

    void setIdea(int i, std::string idea) { ideas[i] = idea; }
    std::string getIdea(int i) const { return ideas[i]; }
};

class Dog {
private:
    Brain* brain;
public:
    Dog() {
        brain = new Brain();
    }

    // Deep copy constructor ✅
    Dog(const Dog& other) {
        brain = new Brain(*other.brain);  // Crée un NOUVEAU Brain
        //      ^^^^^^^^^^^
        //      Allocation d'un nouvel objet Brain
        //      et copie du contenu de other.brain
    }

    // Deep copy assignment operator ✅
    Dog& operator=(const Dog& other) {
        if (this != &other) {
            delete brain;  // Supprime l'ancien brain
            brain = new Brain(*other.brain);  // Crée un nouveau
        }
        return *this;
    }

    ~Dog() {
        delete brain;
    }

    Brain* getBrain() const { return brain; }
};

int main() {
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I love bones");

    Dog dog2 = dog1;  // Deep copy

    // Maintenant: dog1.brain et dog2.brain pointent vers des objets DIFFÉRENTS
    //
    //  dog1.brain ──> [Brain object 1 in memory: "I love bones"]
    //  dog2.brain ──> [Brain object 2 in memory: "I love bones"]

    dog2.getBrain()->setIdea(0, "I love toys");

    std::cout << dog1.getBrain()->getIdea(0) << std::endl;  // "I love bones"
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;  // "I love toys"
    // ✅ Les deux sont indépendants!

}  // Destruction: ✅ OK! Chaque Dog détruit son propre Brain
```

### Visualisation

```
SHALLOW COPY (❌ MAUVAIS):
┌─────────┐        ┌─────────────┐
│  dog1   │──────┐ │    Brain    │
└─────────┘      ├─│  ideas[100] │
                 │ └─────────────┘
┌─────────┐      │
│  dog2   │──────┘
└─────────┘
Problème: delete brain appelé 2 fois sur la même adresse!

DEEP COPY (✅ BON):
┌─────────┐        ┌─────────────┐
│  dog1   │───────>│  Brain #1   │
└─────────┘        │ ideas[100]  │
                   └─────────────┘
┌─────────┐        ┌─────────────┐
│  dog2   │───────>│  Brain #2   │
└─────────┘        │ ideas[100]  │
                   └─────────────┘
Solution: Chaque Dog a son propre Brain!
```

---

## 4. Ordre des Constructeurs et Destructeurs

### Règle fondamentale

**Constructeurs**: De la classe parent vers la classe enfant (top-down)
**Destructeurs**: De la classe enfant vers la classe parent (bottom-up)

### Exemple simple

```cpp
class Animal {
public:
    Animal() {
        std::cout << "1. Animal constructor" << std::endl;
    }
    virtual ~Animal() {
        std::cout << "4. Animal destructor" << std::endl;
    }
};

class Dog : public Animal {
private:
    Brain* brain;
public:
    Dog() {
        std::cout << "2. Dog constructor" << std::endl;
        brain = new Brain();
        std::cout << "3. Brain created" << std::endl;
    }
    ~Dog() {
        std::cout << "5. Dog destructor" << std::endl;
        delete brain;
        std::cout << "6. Brain deleted" << std::endl;
    }
};

int main() {
    std::cout << "Creating Dog:" << std::endl;
    Dog* dog = new Dog();

    std::cout << "\nDeleting Dog:" << std::endl;
    delete dog;
}
```

**Output**:
```
Creating Dog:
1. Animal constructor
2. Dog constructor
3. Brain created

Deleting Dog:
5. Dog destructor
6. Brain deleted
4. Animal destructor
```

### Ordre détaillé avec Brain

```cpp
class Brain {
public:
    Brain() {
        std::cout << "  - Brain constructor" << std::endl;
    }
    ~Brain() {
        std::cout << "  - Brain destructor" << std::endl;
    }
};

class Animal {
protected:
    std::string type;
public:
    Animal() {
        std::cout << "1. Animal constructor" << std::endl;
        type = "Animal";
    }
    virtual ~Animal() {
        std::cout << "6. Animal destructor" << std::endl;
    }
};

class Dog : public Animal {
private:
    Brain* brain;
public:
    Dog() : Animal() {  // Appelle explicitement Animal()
        std::cout << "2. Dog constructor start" << std::endl;
        brain = new Brain();
        std::cout << "3. Dog constructor end" << std::endl;
    }

    ~Dog() {
        std::cout << "4. Dog destructor start" << std::endl;
        delete brain;
        std::cout << "5. Dog destructor end" << std::endl;
    }
};
```

**Output détaillé**:
```
Construction:
1. Animal constructor          ← Parent d'abord
2. Dog constructor start       ← Puis enfant
  - Brain constructor          ← Allocation du Brain
3. Dog constructor end

Destruction (ordre inverse):
4. Dog destructor start        ← Enfant d'abord
  - Brain destructor           ← Libération du Brain
5. Dog destructor end
6. Animal destructor           ← Puis parent
```

### Pourquoi cet ordre ?

**Construction**: La classe enfant a besoin que le parent soit initialisé avant de pouvoir utiliser ses membres.

```cpp
class Animal {
protected:
    std::string type;  // Doit être initialisé d'abord
public:
    Animal() : type("Animal") {}
};

class Dog : public Animal {
public:
    Dog() : Animal() {
        type = "Dog";  // Utilise la variable héritée de Animal
        // Si Animal n'était pas construit, type n'existerait pas!
    }
};
```

**Destruction**: La classe enfant doit être détruite en premier car elle peut utiliser des ressources du parent.

```cpp
class Dog : public Animal {
private:
    Brain* brain;
public:
    ~Dog() {
        delete brain;  // Doit être fait avant ~Animal()
        // Car brain pourrait utiliser des ressources de Animal
    }
};
```

---

## 5. Résumé des Exercices 00, 01, 02

### Exercice 00 : Introduction au Polymorphisme

**Objectif**: Comprendre `virtual` et le polymorphisme de base

**Classes**:
- `Animal` (classe de base avec `virtual void makeSound()`)
- `Dog` et `Cat` (héritent de Animal et override makeSound())
- `WrongAnimal` et `WrongCat` (sans virtual - pour montrer la différence)

**Ce qu'on apprend**:
```cpp
// Bon (avec virtual)
Animal* animal = new Dog();
animal->makeSound();  // "Woof!" ✅

// Mauvais (sans virtual)
WrongAnimal* wrong = new WrongCat();
wrong->makeSound();  // Son de WrongAnimal, pas WrongCat ❌
```

**Fichiers**:
- `Animal.hpp/cpp` - Classe de base avec virtual
- `Dog.hpp/cpp`, `Cat.hpp/cpp` - Classes dérivées
- `WrongAnimal.hpp/cpp`, `WrongCat.hpp/cpp` - Contre-exemple

---

### Exercice 01 : Deep Copy avec Brain

**Objectif**: Comprendre la différence entre shallow copy et deep copy

**Nouveauté**: Ajout de la classe `Brain`

**Classes**:
- `Animal`, `Dog`, `Cat` (même qu'ex00)
- **`Brain`** (nouveau) - Contient un tableau de 100 idées
- `Dog` et `Cat` ont un `Brain*` (pointeur!)

**Ce qu'on apprend**:
```cpp
class Dog {
private:
    Brain* brain;  // Pointeur = risque de shallow copy!
public:
    // Deep copy constructor OBLIGATOIRE
    Dog(const Dog& other) {
        brain = new Brain(*other.brain);  // Nouveau Brain
    }

    // Deep copy assignment OBLIGATOIRE
    Dog& operator=(const Dog& other) {
        if (this != &other) {
            delete brain;
            brain = new Brain(*other.brain);
        }
        return *this;
    }
};
```

**Test dans main**:
```cpp
Dog dog1;
dog1.getBrain()->setIdea(0, "I love bones");

Dog dog2 = dog1;  // Copy constructor
dog2.getBrain()->setIdea(0, "I love toys");

// dog1 et dog2 doivent avoir des Brains indépendants!
std::cout << dog1.getBrain()->getIdea(0);  // "I love bones"
std::cout << dog2.getBrain()->getIdea(0);  // "I love toys"
```

**Fichiers**:
- `Brain.hpp/cpp` - Nouvelle classe
- `Dog.hpp/cpp`, `Cat.hpp/cpp` - Modifiés pour inclure Brain*
- Implémentation de copy constructor et assignment operator

---

### Exercice 02 : Classes Abstraites (Pure Virtual)

**Objectif**: Rendre Animal non-instanciable avec pure virtual

**Modification**: `Animal::makeSound()` devient pure virtual

**Changement dans Animal.hpp**:
```cpp
// Ex00 et Ex01:
virtual void makeSound() const {
    std::cout << "Some animal sound" << std::endl;
}

// Ex02:
virtual void makeSound() const = 0;  // Pure virtual!
//                              ^^^^
```

**Conséquence**:
```cpp
// Ex00 et Ex01: ✅ Possible (mais bizarre)
Animal* animal = new Animal();
animal->makeSound();  // "Some animal sound"

// Ex02: ❌ IMPOSSIBLE (erreur de compilation)
Animal* animal = new Animal();
// error: cannot instantiate abstract class

// ✅ Mais on peut toujours utiliser le polymorphisme:
Animal* animals[2];
animals[0] = new Dog();   // OK
animals[1] = new Cat();   // OK
animals[0]->makeSound();  // "Woof!"
animals[1]->makeSound();  // "Meow!"
```

**Pourquoi ?**
Créer un `Animal` générique n'a pas de sens dans la vraie vie. Un animal EST TOUJOURS soit un chien, soit un chat, etc. On force donc les utilisateurs à créer des classes concrètes.

**Fichiers**:
- `Animal.hpp` - `makeSound()` devient `= 0`
- `Animal.cpp` - Pas d'implémentation de makeSound()
- `Dog.hpp/cpp`, `Cat.hpp/cpp` - Inchangés (déjà implémentent makeSound)

---

### Tableau récapitulatif

| Concept | Ex00 | Ex01 | Ex02 |
|---------|------|------|------|
| **Polymorphisme (virtual)** | ✅ Introduit | ✅ Utilisé | ✅ Utilisé |
| **Destructeur virtual** | ✅ Obligatoire | ✅ Obligatoire | ✅ Obligatoire |
| **Brain class** | ❌ | ✅ Ajouté | ✅ Présent |
| **Deep copy** | ❌ Pas nécessaire | ✅ Obligatoire | ✅ Obligatoire |
| **Pure virtual (= 0)** | ❌ | ❌ | ✅ Animal abstrait |
| **Animal instanciable ?** | ✅ Oui | ✅ Oui | ❌ Non |

---

### Progression logique

1. **Ex00**: "Voici le polymorphisme avec `virtual`"
2. **Ex01**: "Maintenant gérez les pointeurs avec deep copy"
3. **Ex02**: "Rendez la classe de base abstraite avec `= 0`"

Chaque exercice ajoute un niveau de complexité et enseigne un concept C++ important!

---

## Exemples de Code Complets

### Test de compilation pour vérifier l'abstraction

```cpp
// test_abstract.cpp
#include "Animal.hpp"

int main() {
    Animal test;  // ❌ Ne doit PAS compiler en ex02
    return 0;
}
```

Compilation:
```bash
# Ex00 et Ex01:
g++ test_abstract.cpp Animal.cpp
# ✅ Compile sans erreur

# Ex02:
g++ test_abstract.cpp Animal.cpp
# ❌ Erreur: cannot declare variable 'test' to be of abstract type 'Animal'
```

### Vérification de deep copy

```cpp
int main() {
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Idea 1");

    {
        Dog dog2 = dog1;  // Deep copy
        dog2.getBrain()->setIdea(0, "Idea 2");

        std::cout << "dog1: " << dog1.getBrain()->getIdea(0) << std::endl;
        std::cout << "dog2: " << dog2.getBrain()->getIdea(0) << std::endl;

        // Si shallow copy: les deux affichent "Idea 2" ❌
        // Si deep copy: dog1="Idea 1", dog2="Idea 2" ✅

    }  // dog2 détruit ici

    // Si shallow copy: ❌ CRASH ici (dog1.brain déjà libéré)
    // Si deep copy: ✅ dog1 fonctionne toujours
    std::cout << "dog1 still exists: "
              << dog1.getBrain()->getIdea(0) << std::endl;
}
```

---

## Questions Fréquentes (FAQ)

### Q1: Pourquoi `const` dans `makeSound() const` ?

**Réponse**: Cela garantit que la méthode ne modifie pas l'état de l'objet.

```cpp
void makeSound() const {
    // this->type = "Modified";  // ❌ ERREUR - const interdit
    std::cout << type << std::endl;  // ✅ OK - lecture seulement
}
```

### Q2: Différence entre `virtual` et `override` ?

```cpp
class Animal {
    virtual void makeSound() const = 0;  // Déclare virtual
};

class Dog : public Animal {
    void makeSound() const override;  // Override (C++11)
    // 'override' est optionnel mais recommandé
    // Il vérifie qu'on override bien une fonction virtual
};
```

### Q3: Peut-on avoir une classe abstraite sans `= 0` ?

**Non**. Une classe est abstraite SI ET SEULEMENT SI elle a au moins une fonction pure virtual (`= 0`).

### Q4: Faut-il delete un objet abstrait ?

**Oui**, mais via un pointeur de classe dérivée:

```cpp
Animal* animal = new Dog();  // OK
delete animal;  // OK si ~Animal() est virtual
```

---

## Conclusion

### Points clés à retenir:

1. **`virtual`** = Polymorphisme (résolution à l'exécution)
2. **`= 0`** = Pure virtual (classe abstraite)
3. **Deep copy** = Copier le contenu, pas le pointeur
4. **Ordre construction** = Parent → Enfant
5. **Ordre destruction** = Enfant → Parent
6. **Destructeur virtual** = TOUJOURS avec inheritance

### Checklist pour l'examen:

- [ ] `virtual void makeSound() const = 0;` dans Animal
- [ ] `virtual ~Animal()` (destructeur virtual)
- [ ] Deep copy constructor dans Dog/Cat
- [ ] Deep copy assignment operator dans Dog/Cat
- [ ] Animal ne peut PAS être instancié
- [ ] Dog et Cat implémentent makeSound()
- [ ] Tests montrent polymorphisme
- [ ] Tests montrent deep copy
- [ ] Pas de memory leaks

Bon courage! 🚀
