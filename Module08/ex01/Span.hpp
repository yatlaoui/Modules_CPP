/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:59:55 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 00:17:02 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <numeric>
#include <vector>

// Span: stores at most N integers and can tell you the shortest / longest
// distance between any two of the numbers it holds.
class Span
{
	private:
		unsigned int		_maxSize; // how many numbers we are allowed to store
		std::vector<int>	_numbers; // the actual storage

	public:
		Span();                              // default (kept minimal, private use)
		Span(unsigned int n);                // the "real" constructor
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);          // add one number (throws if full)
		int  shortestSpan() const;           // smallest distance between two numbers
		int  longestSpan() const;            // biggest distance between two numbers

		class SpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
