/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 02:53:05 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/11 00:53:00 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

// creates randomly one of the three types and returns it as a Base
Base *generate(void)
{
    std::srand(std::time(NULL));

    switch (std::rand() % 3)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();  
    }
}

//pointer version
void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown / NULL" << std::endl;
    
}

//reference version
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout<< "A" <<std::endl;
        return;
    }
    catch (std::exception &) {}

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout<< "B" <<std::endl;
        return;
    }
    catch (std::exception &) {}

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout<< "C" <<std::endl;
        return;
    }
    catch (std::exception &) {}
}
