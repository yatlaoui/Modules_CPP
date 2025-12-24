/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 07:46:57 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/24 07:47:00 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "=== Testing Abstract Animal ===" << std::endl;
    // This should NOT compile:
    // const Animal* meta = new Animal(); // ERROR: Cannot instantiate abstract class
    
    std::cout << "=== Testing from Subject ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // should not create a leak
    delete i;

    std::cout << "\n=== Creating Array of Animals ===" << std::endl;
    const int arraySize = 10;
    Animal* animals[arraySize];
    
    // Fill half with Dogs
    for (int idx = 0; idx < arraySize / 2; idx++) {
        animals[idx] = new Dog();
    }
    
    // Fill half with Cats
    for (int idx = arraySize / 2; idx < arraySize; idx++) {
        animals[idx] = new Cat();
    }

    std::cout << "\n=== Testing Sounds ===" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }

    std::cout << "\n=== Deleting Array ===" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        delete animals[idx];
    }

    std::cout << "\n=== Testing Deep Copy ===" << std::endl;
    Dog basic;
    basic.getBrain()->setIdea(0, "I am a good dog!");
    basic.getBrain()->setIdea(1, "I love bones");
    
    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
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

    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    Dog another;
    another.getBrain()->setIdea(0, "I am another dog");
    std::cout << "Before assignment: " << another.getBrain()->getIdea(0) << std::endl;
    another = basic;
    std::cout << "After assignment: " << another.getBrain()->getIdea(0) << std::endl;

    return 0;
}
