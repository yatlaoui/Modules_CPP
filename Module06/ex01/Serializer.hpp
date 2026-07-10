/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 04:53:31 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/09 02:17:49 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

//uniptr est un integer assez grand pour tenir un ptr
// serialize() ne copie pas l'objet et ne le sauvegarde pas. 
// Elle transforme simplement l'adresse contenue dans un pointeur en un entier (uintptr_t).
// deserialize() fait l'opération inverse en réinterprétant 
// cet entier comme un pointeur vers le même objet.