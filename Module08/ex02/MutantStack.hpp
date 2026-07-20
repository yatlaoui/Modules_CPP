/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 03:00:06 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/20 09:32:59 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <deque>
#include <list>

// Crée un alias de type appelé "iterator".
// Au lieu d'écrire std::deque<T>::iterator partout,
// on pourra simplement écrire iterator.
//
// typename est obligatoire ici car T est un template.
// Il indique au compilateur que "iterator" est un type.
typedef typename std::deque<T>::iterator iterator;


// Même chose, mais pour un iterator qui ne permet pas de modifier les valeurs.
// On peut parcourir le container, mais pas faire : *it = nouvelleValeur;
typedef typename std::deque<T>::const_iterator const_iterator;


// Iterator qui permet de parcourir le container dans le sens inverse.
// Exemple : 3 2 1 au lieu de 1 2 3.
typedef typename std::deque<T>::reverse_iterator reverse_iterator;


// Version constante du reverse_iterator.
// On parcourt à l'envers mais sans pouvoir modifier les éléments.
typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;



// Retourne un iterator qui pointe sur le premier élément du stack.
//
// this->c représente le container interne de std::stack.
// Par défaut, ce container est un std::deque.
//
// Donc ici on appelle :
// deque.begin()
//
// Exemple :
// c = [10][20][30]
// begin() pointe sur 10.
iterator begin()
{
    return (this->c.begin());
}



// Retourne un iterator qui pointe juste après le dernier élément.
//
// C'est la convention des iterators STL :
// [begin ... end[
//
// Exemple :
// [10][20][30]
//              ^
//              end()
iterator end()
{
    return (this->c.end());
}



// Version const de begin().
//
// Elle est utilisée quand le MutantStack est déclaré const.
//
// Exemple :
// const MutantStack<int> stack;
//
// On ne peut alors récupérer qu'un const_iterator.
const_iterator begin() const
{
    return (this->c.begin());
}



// Version const de end().
//
// Retourne la position après le dernier élément,
// sans permettre la modification.
const_iterator end() const
{
    return (this->c.end());
}



// Retourne un reverse_iterator qui commence par le dernier élément.
//
// Exemple :
//
// c = [10][20][30]
//
// rbegin() pointe sur 30.
reverse_iterator rbegin()
{
    return (this->c.rbegin());
}



// Retourne la fin du parcours inverse.
//
// Comme end() pour un parcours normal,
// rend() représente la position avant le premier élément.
reverse_iterator rend()
{
    return (this->c.rend());
}



// Version constante de rbegin().
//
// Permet de parcourir un MutantStack const dans le sens inverse.
const_reverse_iterator rbegin() const
{
    return (this->c.rbegin());
}



// Version constante de rend().
//
// Même principe que rend(), mais sans modification possible.
const_reverse_iterator rend() const
{
    return (this->c.rend());
}

//======================================================//

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}
		~MutantStack() {}

		typedef typename std::deque<T>::iterator               iterator;
		typedef typename std::deque<T>::const_iterator         const_iterator;
		typedef typename std::deque<T>::reverse_iterator       reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin()
        { 
            return (this->c.begin());
        }

		iterator end()
        {
            return (this->c.end());
        }

		const_iterator begin() const
        { 
            return (this->c.begin());
        }
        
		const_iterator end() const
        {
            return (this->c.end());
        }

		reverse_iterator rbegin()
        {
            return (this->c.rbegin());
        }

		reverse_iterator rend()
        { 
            return (this->c.rend());
        }

		const_reverse_iterator rbegin() const
        {
            return (this->c.rbegin());
        }
        
		const_reverse_iterator rend() const
        {
            return (this->c.rend());
        }
};

//================================================================================
// Container Adapter Explanation
//================================================================================
//
// A container adapter is a class that uses an existing STL container internally
// but provides a more restricted and specialized interface.
//
// std::stack is a container adapter. It does not store elements by itself:
// by default, it uses a std::deque as its underlying container:
//
//              std::stack
//                  |
//                  v
//          protected member "c"
//                  |
//                  v
//              std::deque<T>
//
// The deque already provides many operations such as begin(), end(), indexing,
// insertion, etc. However, std::stack hides these functions because a stack
// should only allow stack operations:
//
//      push() -> add an element on top
//      pop()  -> remove the top element
//      top()  -> access the top element
//
// The goal is to respect the LIFO (Last In First Out) principle:
//
//      push(1), push(2), push(3)
//
//              [3]  <- top()
//              [2]
//              [1]
//
//      pop() removes 3 first.
//
// The underlying container is stored in a protected member called "c".
// Since MutantStack inherits from std::stack, it has access to this member.
//
// MutantStack exposes the iterators of the internal container (deque) in order
// to allow iteration:
//
//      begin()  -> first element
//      end()    -> position after the last element
//      rbegin() -> last element backwards
//      rend()   -> position before the first element
//
// In other words, MutantStack keeps the behavior of a stack but adds the
// possibility to iterate through its elements.