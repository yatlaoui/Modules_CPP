/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:59:48 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 07:47:59 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanException();
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw SpanException();
	std::vector<int> sorted = _numbers; //un nouveau vectoeur une copie
	std::sort(sorted.begin(), sorted.end());
	std::vector<int> diffs(sorted.size()); //un nouveau vectoeur une copie
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin()); //trier du debut a la fin et placer au début
	return (*std::min_element(diffs.begin() + 1, diffs.end())); //on skip le premier parce que c'est pas une diff
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw SpanException();
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}

const char* Span::SpanException::what() const throw()
{
	return "Span error: the Span is full, or it holds fewer than 2 numbers.";
}
