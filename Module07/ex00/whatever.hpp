/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 01:48:34 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/11 17:41:53 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T const &max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	return (b);
}
