/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:39:40 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/18 12:35:53 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include <iostream>
#include <iomanip>
#include "Contact_class.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    int _count;
    int _next;

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void add();
    void search() const;
};

#endif
