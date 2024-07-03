
#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>
#include <iomanip>

class PmergeMe
{
private:
	std::vector<int> _vectorSort;
	std::deque<int> _dequeSort;
	clock_t _start;
	clock_t _end;
	void fillVector(char const *argv[]);
public:
	PmergeMe();
	~PmergeMe();

	void sort(char const *argv[]);
};