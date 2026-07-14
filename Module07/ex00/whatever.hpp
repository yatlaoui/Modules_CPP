/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 01:48:34 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/14 18:17:36 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

// avec &, a et b sont juste des alias de s1 et s2.
// ne copie toujours rien.
// On renvoie simplement une référence vers s1.
//on utulise des references pour eviter de faire des copies inutiles, on référencie juste les valeurs
//passée à la fonction 
//cosnt pour eviter les modif, les fonctions doivent dire qui est min et qui est max pas modifer des trucs

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
