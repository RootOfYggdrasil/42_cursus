
#include "iter.hpp"

template< typename T >
void sum(T const &element)
{
    std::cout << element << " + " << element << " = " << element + element << std::endl;
}

int main()
{
    int inArr[] = {1, 2, 3, 4, 5};
    double doArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char chArr[] = {'a', 'b', 'c', 'e','d', 'f'};
	std::string strArr[] = {"one", "two", "three", "four", "five"};

    std::cout << "intArray: " << std::endl;;
    iter(inArr, 5, sum<int>);
    std::cout << std::endl;

    std::cout << "doubleArray: " << std::endl;;
    iter(doArr, 5, sum<double>);
    std::cout << std::endl;

    std::cout << "charArray: " << std::endl;;
    iter(chArr, 5, sum<char>);
    std::cout << std::endl;

	std::cout << "stringArray: " << std::endl;;
	iter(strArr, 5, sum<std::string>);
	std::cout << std::endl;

    return 0;
}
