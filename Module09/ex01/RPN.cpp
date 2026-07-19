/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:23:48 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 21:48:58 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression)
{
	while (!_stack.empty())
		_stack.pop();
	std::istringstream iss(expression);
	std::string token;
	while (iss >> token)
	{
		if (token.size() != 1)
			throw std::runtime_error("Error");
		char c = token[0];
		if (c >= '0' && c <= '9')
			_stack.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			if (c == '+')
				_stack.push(a + b);
			else if (c == '-')
				_stack.push(a - b);
			else if (c == '*')
				_stack.push(a * b);
			else
			{
				if (b == 0)
					throw std::runtime_error("Error");
				_stack.push(a / b);
			}
		}
		else
			throw std::runtime_error("Error");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return (_stack.top());
}
