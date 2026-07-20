/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:24:01 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/20 06:47:31 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//================================================================================
// Canonical Form
//================================================================================

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

//================================================================================
// Parsing & Validation
//================================================================================

void PmergeMe::parsing(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string token = argv[i];
		if (token.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < token.size(); j++)
			if (token[j] < '0' || token[j] > '9')
				throw std::runtime_error("Error");
		char *end;
		long value = std::strtol(token.c_str(), &end, 10);
		if (*end != '\0' || value < 0 || value > INT_MAX)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(value));
		_deq.push_back(static_cast<int>(value));
	}
	if (_vec.empty())
		throw std::runtime_error("Error");
}

//================================================================================
// Jacobsthal Utilities
//================================================================================

bool PmergeMe::cmpFirst(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.first < b.first);
}

std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t m) const
{
	std::vector<size_t> order;
	if (m == 0)
		return (order);
	std::vector<size_t> jac;
	size_t prev = 1, cur = 3;
	jac.push_back(cur);
	while (cur < m)
	{
		size_t next = cur + 2 * prev;
		jac.push_back(next);
		prev = cur;
		cur = next;
	}
	order.push_back(1);
	size_t start = 2;
	for (size_t g = 0; g < jac.size(); g++)
	{
		size_t high = jac[g];
		if (high > m)
			high = m;
		for (size_t k = high; k >= start; k--)
		{
			order.push_back(k);
			if (k == start)
				break;
		}
		start = jac[g] + 1;
		if (start > m)
			break;
	}
	return (order);
}

//================================================================================
// Vector Merge-Insertion Sort
//================================================================================

void PmergeMe::mergeInsertVec(std::vector<std::pair<int, int> > &v)
{
	size_t n = v.size();
	if (n < 2)
		return;
	bool odd = (n % 2 != 0);
	std::pair<int, int> straggler;
	if (odd)
		straggler = v[n - 1];
	std::vector<std::pair<int, int> > winners;
	std::vector<std::pair<int, int> > losers;
	size_t limit = n - (odd ? 1 : 0);
	for (size_t i = 0; i < limit; i += 2)
	{
		if (v[i].first >= v[i + 1].first)
		{
			winners.push_back(v[i]);
			losers.push_back(v[i + 1]);
		}
		else
		{
			winners.push_back(v[i + 1]);
			losers.push_back(v[i]);
		}
	}
	mergeInsertVec(winners);
	v = winners;
	std::vector<size_t> order = buildJacobsthalOrder(losers.size());
	for (size_t k = 0; k < order.size(); k++)
	{
		std::pair<int, int> val = losers[order[k] - 1];
		std::vector<std::pair<int, int> >::iterator pos =
			std::upper_bound(v.begin(), v.end(), val, cmpFirst);
		v.insert(pos, val);
	}
	if (odd)
	{
		std::vector<std::pair<int, int> >::iterator pos = std::upper_bound(v.begin(), v.end(), straggler, cmpFirst);
		v.insert(pos, straggler);
	}
}

void PmergeMe::sortVector()
{
	if (_vec.size() <= 1)
		return;
	bool odd = (_vec.size() % 2 != 0);
	int straggler = 0;
	size_t limit = _vec.size() - (odd ? 1 : 0);
	if (odd)
		straggler = _vec[_vec.size() - 1];
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < limit; i += 2)
	{
		int a = _vec[i];
		int b = _vec[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	mergeInsertVec(pairs);
	std::vector<int> result;
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		result.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	std::vector<size_t> order = buildJacobsthalOrder(pend.size());
	for (size_t k = 0; k < order.size(); k++)
	{
		int value = pend[order[k] - 1];
		std::vector<int>::iterator pos =
			std::upper_bound(result.begin(), result.end(), value);
		result.insert(pos, value);
	}
	if (odd)
	{
		std::vector<int>::iterator pos = std::upper_bound(result.begin(), result.end(), straggler);
		result.insert(pos, straggler);
	}
	_vec = result;
}

//================================================================================
// Deque Merge-Insertion Sort
//================================================================================

void PmergeMe::mergeInsertDeq(std::deque<std::pair<int, int> > &v)
{
	size_t n = v.size();
	if (n < 2)
		return;
	bool odd = (n % 2 != 0);
	std::pair<int, int> straggler;
	if (odd)
		straggler = v[n - 1];
	std::deque<std::pair<int, int> > winners;
	std::deque<std::pair<int, int> > losers;
	size_t limit = n - (odd ? 1 : 0);
	for (size_t i = 0; i < limit; i += 2)
	{
		if (v[i].first >= v[i + 1].first)
		{
			winners.push_back(v[i]);
			losers.push_back(v[i + 1]);
		}
		else
		{
			winners.push_back(v[i + 1]);
			losers.push_back(v[i]);
		}
	}
	mergeInsertDeq(winners);
	v = winners;
	std::vector<size_t> order = buildJacobsthalOrder(losers.size());
	for (size_t k = 0; k < order.size(); k++)
	{
		std::pair<int, int> val = losers[order[k] - 1];
		std::deque<std::pair<int, int> >::iterator pos =
			std::upper_bound(v.begin(), v.end(), val, cmpFirst);
		v.insert(pos, val);
	}
	if (odd)
	{
		std::deque<std::pair<int, int> >::iterator pos =
			std::upper_bound(v.begin(), v.end(), straggler, cmpFirst);
		v.insert(pos, straggler);
	}
}

void PmergeMe::sortDeque()
{
	if (_deq.size() <= 1)
		return;
	bool odd = (_deq.size() % 2 != 0);
	int straggler = 0;
	size_t limit = _deq.size() - (odd ? 1 : 0);
	if (odd)
		straggler = _deq[_deq.size() - 1];

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < limit; i += 2)
	{
		int a = _deq[i];
		int b = _deq[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	mergeInsertDeq(pairs);
	std::deque<int> result;
	std::deque<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		result.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	std::vector<size_t> order = buildJacobsthalOrder(pend.size());
	for (size_t k = 0; k < order.size(); k++)
	{
		int value = pend[order[k] - 1];
		std::deque<int>::iterator pos =
			std::upper_bound(result.begin(), result.end(), value);
		result.insert(pos, value);
	}
	if (odd)
	{
		std::deque<int>::iterator pos =
			std::upper_bound(result.begin(), result.end(), straggler);
		result.insert(pos, straggler);
	}
	_deq = result;
}

//================================================================================
// Display
//================================================================================

void PmergeMe::printVector(const std::string &label) const
{
	std::cout << label;
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

//================================================================================
// Execution
//================================================================================

void PmergeMe::execute(int argc, char **argv)
{
	parsing(argc, argv);
	printVector("Before:");
	struct timeval start, end;
	gettimeofday(&start, NULL);
	sortVector();
	gettimeofday(&end, NULL);
	double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	gettimeofday(&start, NULL);
	sortDeque();
	gettimeofday(&end, NULL);
	double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	printVector("After: ");
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
