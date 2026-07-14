/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:32:29 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/14 20:08:26 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cstddef>

// read-only: takes its argument by const reference
template< typename T >
void print( T const & x )
{
	std::cout << x << " ";
	return;
}

// mutating: takes its argument by non-const reference
template< typename T >
void increment( T & x )
{
	x += 1;
	return;
}

// Calls `func` on each of the `length` elements of `array`.
// `F` is a template parameter, so `func` can be any callable:
//  - a function pointer taking T &        (mutating)
//  - a function pointer taking T const &  (read only)
//  - a functor or lambda
// Const arrays work too: T simply deduces to `const SomeType`.
template <typename T, typename F>
void iter(T *array, size_t const length, F func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}
