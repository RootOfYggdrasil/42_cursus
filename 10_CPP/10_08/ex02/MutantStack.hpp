
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	/* data */
public:
	MutantStack() : std::stack<T>() { };
	~MutantStack() { };
	MutantStack(MutantStack const &other) : std::stack<T>(other) { };
	MutantStack &operator=(MutantStack const &other);

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};


#endif