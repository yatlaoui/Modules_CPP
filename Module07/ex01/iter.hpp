/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:32:29 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 13:49:43 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cstddef>

// read-only: takes its argument by const reference
template <typename T>
void print(T const &x)
{
	std::cout << x << " ";
	return;
}

// mutating: takes its argument by non-const reference
template <typename T>
void increment(T &x)
{
	x = x + 1;
	return;
}

template <typename T, typename F>
void iter(T *array, size_t const length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}
