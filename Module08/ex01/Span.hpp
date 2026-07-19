/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:59:55 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 07:25:06 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <numeric>
#include <vector>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int  shortestSpan() const;
		int  longestSpan() const;

		template <typename InputIterator>
		void addMany(InputIterator begin, InputIterator end)
		{
			if (_numbers.size() + static_cast<size_t>(std::distance(begin, end)) > _maxSize) //on cast parce que size renvoieun size_t et distance renvoie autre chose
				throw std::out_of_range("addMany: not enough space in the Span");
			_numbers.insert(_numbers.end(), begin, end); //rajoute a la fin de _numbers tous les éléments compris entre les itérateurs begin et end.
		}

		class SpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
