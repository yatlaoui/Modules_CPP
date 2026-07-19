/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:24:03 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 22:04:13 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <deque>

class PmergeMe
{
    private:
		std::vector<int> _vec;
		std::deque<int>  _deq;

		void parse(int argc, char **argv);

		void sortVector();
		void sortDeque();

		void mergeInsertVec(std::vector<std::pair<int, int> > &v);
		void mergeInsertDeq(std::deque<std::pair<int, int> > &v);
		static bool cmpFirst(const std::pair<int, int> &a, const std::pair<int, int> &b);

		std::vector<size_t> jacobOrder(size_t m) const;
		void printVec(const std::string &label) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void run(int argc, char **argv);
};
