/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 03:00:06 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 11:32:36 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <deque>
#include <list>

// Trick: std::stack is really just a wrapper around another container
// (a std::deque by default). That underlying container is stored in a
// PROTECTED member called "c". Because we inherit from std::stack, we can
// reach "c" and simply expose ITS iterators. So we borrow the deque's
// iterators and hand them out as our own.
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}
		~MutantStack() {}

		typedef typename std::deque<T>::iterator               iterator;
		typedef typename std::deque<T>::const_iterator         const_iterator;
		typedef typename std::deque<T>::reverse_iterator       reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin()
        { 
            return (this->c.begin());
        }

		iterator end()
        {
            return (this->c.end());
        }

		const_iterator begin() const
        { 
            return (this->c.begin());
        }
        
		const_iterator end() const
        {
            return (this->c.end());
        }

		reverse_iterator rbegin()
        {
            return (this->c.rbegin());
        }

		reverse_iterator rend()
        { 
            return (this->c.rend());
        }

		const_reverse_iterator rbegin() const
        {
            return (this->c.rbegin());
        }
        
		const_reverse_iterator rend() const
        {
            return (this->c.rend());
        }
};
