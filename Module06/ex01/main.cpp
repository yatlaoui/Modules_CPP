/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:47:06 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/09 02:47:33 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    // Create a Data object
    Data data;
    data.nb = 42;

    // Create a pointer to the object
    Data *ptr = &data;

    // Serialize: pointer -> integer
    uintptr_t raw = Serializer::serialize(ptr);
    // Deserialize: integer -> pointer
    Data *back = Serializer::deserialize(raw);

    // Display the results
    std::cout << "Original pointer     : " << ptr << std::endl;
    std::cout << "Serialized integer   : " << raw << std::endl;
    std::cout << "Deserialized pointer : " << back << std::endl;
    std::cout << "Value                : " << back->nb << std::endl;

    // Verify that both pointers are identical
    if (ptr == back)
        std::cout << "Success: same pointer." << std::endl;
    else
        std::cout << "Error: different pointers." << std::endl;
    return (0);
}
