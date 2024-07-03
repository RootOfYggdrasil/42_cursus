
#include <iostream>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size post pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Size pre cicle: " << mstack.size() << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	/*my test*/
	MutantStack<int> mstack2;
	mstack2.push(1);
	mstack2.push(2);
	mstack2.push(3);
	mstack2.push(4);
	std::cout << "Size pre cicle: " << mstack2.size() << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "Top: " << mstack2.top() << std::endl;
		mstack2.pop();
		std::cout << "Size cicle: " << mstack2.size() << std::endl;
	}
	std::cout << "Size post cicle: " << mstack2.size() << std::endl;



	return 0;
}