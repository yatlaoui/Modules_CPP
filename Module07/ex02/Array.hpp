/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:32:37 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/17 03:45:21 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T   *_data;
        unsigned int    _size;

    public:
    // Creates an empty array
    // Allocates an empty dynamic array and sets size to 0
        Array(void) : _data(new T[0]), _size(0){}
    // Creates an array of n elements
    // Allocates memory and stores the array size
        Array(unsigned int n) : _data(new T[n]), _size(n){}

        // Copy constructor: allocate our OWN memory, then copy each value.
        // Creates a new independent array and copies all elements
        // Uses deep copy to avoid sharing the same memory
        // Pourquoi ? Parce qu'on ne veut pas que les deux objets partagent le même pointeur.
        // ex: Modifier a ne modifie pas b.
        Array(Array const &other) : _data(new T[other._size]), _size(other._size)
        {
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = other._data[i];
        }
    
        // Assignment: free old memory, allocate new, copy. Guard against self-assign.
        // Deep copy vs shallow copy: if we just copied the pointer _data, 
        // two arrays would share the same memory. 
        // Deleting one would break the other (double free / dangling pointer). 
        // So the copy ctor and operator= allocate a new block and copy element by element.
        //  Modifying one array never affects the other.
        // Copy assignment operator
        // Replaces current data with a deep copy of other's data
        // Il intervient quand l'objet existe déjà
        //Pourquoi on fait tout ça ? Parce que a avait déjà des données, il faut les remplacer proprement.
        Array &operator=(Array const &other)
        {
            if (this != &other)
            {
                delete [] _data;
                _size = other._size;
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _data[i] = other._data[i];
            }
            return (*this);
        }

        // notes: shallow copy avec ptr parce que deux objets partagent le même tableau
        // donc si je change une valeur dans l'un, l'autre change aussi ()
        //alors qu'une deep copy on a deux tableaux differents donc changer les valeurs de l'un ne 
        // changera pas les valeurs de l'autre
        //notes sur les ref: on utilise des ref pour eviter des copies inuties (pas deep ou hsalow, jsute des copies)
        // en utilsant la ref on fait juste un alias vers l'element
        ~Array(void)
        {
            delete [] _data;
        }

        // Read/write access
        // on a un int pour l'index pour pouvoir detecter des - 
        // mais size est unisgned parce qu'une taille ne peut pas etre negative
        // Allows read and write access to an element
        // Checks if the index is valid before returning the element
        // Returns a reference so the element can be modified
        T &operator[](int index)
        {
            if (index < 0 || static_cast<unsigned int>(index) >= _size)
                throw std::exception();
            return (_data[index]);
        }

        // Read-only access bc of const
        // Allows read-only access to an element of a const Array
        // Checks if the index is valid before returning the element
        // Returns a const reference to prevent modification
        T const &operator[](int index) const
        {
            if (index < 0 || static_cast<unsigned int>(index) >= _size)
                throw std::exception();
            return (_data[index]);
        }

        unsigned int size(void) const
        {
            return (_size);
        }
};


// Résumé pour l'oral :

// Constructeur normal → crée un nouveau tableau.
// Constructeur de copie → crée un nouveau tableau et copie les valeurs (deep copy).
// Assignment operator → détruit l'ancien tableau, recrée un nouveau et copie les valeurs.