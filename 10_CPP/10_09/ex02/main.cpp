
#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " <number of elements>" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe p = PmergeMe();
		p.sort(argv);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}