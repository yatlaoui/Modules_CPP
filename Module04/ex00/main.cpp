#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Testing Correct Polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n=== Type Information ===" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "\n=== Making Sounds ===" << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Testing Wrong Polymorphism ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\n=== Type Information ===" << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    std::cout << "\n=== Making Sounds (Wrong) ===" << std::endl;
    wrongCat->makeSound(); // will output WrongAnimal sound (not polymorphic)!
    wrongMeta->makeSound();

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n=== Testing WrongCat directly ===" << std::endl;
    WrongCat directWrongCat;
    directWrongCat.makeSound(); // This will output WrongCat sound

    return 0;
}
