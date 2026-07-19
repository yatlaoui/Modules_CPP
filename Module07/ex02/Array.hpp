/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:32:37 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 13:50:29 by yaatlaou         ###   ########.fr       */
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
        Array(void) : _data(new T[0]), _size(0){}

        Array(unsigned int n) : _data(new T[n]), _size(n){}

        Array(Array const &other) : _data(new T[other._size]), _size(other._size)
        {
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = other._data[i];
        }
    
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

        ~Array(void)
        {
            delete [] _data;
        }

        T &operator[](int index)
        {
            if (index < 0 || static_cast<unsigned int>(index) >= _size)
                throw std::exception();
            return (_data[index]);
        }

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
