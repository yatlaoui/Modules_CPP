/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 07:45:36 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/24 07:45:48 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <string>
#include <iostream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();

        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};
