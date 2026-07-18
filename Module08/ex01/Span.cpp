/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:59:48 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 00:09:12 by yasmine          ###   ########.fr       */
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
	// Already full? We are not allowed to store more than _maxSize numbers.
	if (_numbers.size() >= _maxSize)
		throw SpanException();
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	// We need at least 2 numbers to measure a distance between two of them.
	if (_numbers.size() < 2)
		throw SpanException();

	// Idea: if we sort the numbers, the two closest values are always
	// next to each other. So the shortest span is the smallest gap between
	// two neighbours in the sorted list.
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	// std::adjacent_difference fills "diffs" with the gaps between neighbours.
	// (Its very first element is a copy of sorted[0], so we skip index 0.)
	std::vector<int> diffs(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());

	// The smallest of those gaps is our shortest span.
	return (*std::min_element(diffs.begin() + 1, diffs.end()));
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw SpanException();

	// The longest distance is simply biggest value minus smallest value.
	// std::min_element / std::max_element give us iterators to those.
	int minValue = *std::min_element(_numbers.begin(), _numbers.end());
	int maxValue = *std::max_element(_numbers.begin(), _numbers.end());
	return (maxValue - minValue);
}

const char* Span::SpanException::what() const throw()
{
	return "Span error: the Span is full, or it holds fewer than 2 numbers.";
}
