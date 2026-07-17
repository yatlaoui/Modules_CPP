/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:32:29 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/16 00:30:51 by yasmine          ###   ########.fr       */
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

// Calls `function` on each of the `length` elements of `array`.
// `F` is a template parametern so we can call any type of function
// le fait d'utiliser deux templates, un por le type du tab et un autre pour
// la fonction fait que ca prend des tab const et non const, ça donne plus de liberté
template <typename T, typename F>
void iter(T *array, size_t const length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}
