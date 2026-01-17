/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 10:49:39 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/27 17:54:43 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;

    std::cout << "=== An Array of Animals ===" << std::endl;
    
    const int arraySize = 8;
    Animal* animals[arraySize];
    
    // Half with Dogs
    for (int index = 0; index < arraySize / 2; index++)
        animals[index] = new Dog();
    // Half with Cats
    for (int index = arraySize / 2; index < arraySize; index++)
        animals[index] = new Cat();
    
    std::cout << "\n=== Sounds ===" << std::endl;
    for (int index = 0; index < arraySize; index++)
    {
        std::cout << animals[index]->getType() << ": ";
        animals[index]->makeSound();
    }
    std::cout << "\n=== Array Deletion ===" << std::endl;
    for (int index = 0; index < arraySize; index++)
        delete animals[index];

    std::cout << "\n=== Copy Constructor ===" << std::endl;
    Dog basic;
    basic.getBrain()->setIdea(0, "Hello!");
    basic.getBrain()->setIdea(1, "Let's go for a walk");
    {
        Dog tmp = basic;
        std::cout << "Original idea: " << basic.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea: " << tmp.getBrain()->getIdea(0) << std::endl;
        std::cout << "Changing copy's idea..." << std::endl;
        tmp.getBrain()->setIdea(0, "I am a copy dog!");
        std::cout << "Original idea after change: " << basic.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea after change: " << tmp.getBrain()->getIdea(0) << std::endl;
        std::cout << "tmp going out of scope..." << std::endl;
    }
    std::cout << "After scope, original still exists" << std::endl;

    std::cout << "\n=== Assignment Operator ===" << std::endl;
    Dog another;
    another.getBrain()->setIdea(0, "I am another dog");
    std::cout << "Before assignment: " << another.getBrain()->getIdea(0) << std::endl;
    another = basic;
    std::cout << "After assignment: " << another.getBrain()->getIdea(0) << std::endl;
    return (0);
}
