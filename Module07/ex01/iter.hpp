/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:32:29 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/11 20:05:49 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cstddef>

// class Awesome
// {
//     private:
//         int _n;
//     public:
//         Awesome(void) : _n(42) {return;}
//         int get(void) const {return this->_n;}
// };

// std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
// {
// 	o << rhs.get();
// 	return (o);
// }

// Function takes its argument by non-const reference (can modify elements)
template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

// Function takes its argument by const reference (read only)
template <typename T>
void iter(T *array, size_t length, void (*func)(T const &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

// Const array: only the const-reference version makes sense
template <typename T>
void iter(T const *array, size_t length, void (*func)(T const &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

// template<typename T>
// void print(T const & x)
// {
// 	std::cout << x << std::endl;
// 	return;
// }

