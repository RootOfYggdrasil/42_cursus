
#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){
	this->_vectorSort = std::vector<int>();
	this->_dequeSort = std::deque<int>();
	this->_start = 0;
	this->_end = 0;
}

PmergeMe::~PmergeMe() {}

template <typename PT>
void insertionSort(PT begin, PT end)
{
	for (PT i = begin + 1; i < end; i++)
	{
		PT j = i;
		while (j > begin && *j < *(j - 1))
		{
			std::iter_swap(j, j - 1);
			j--;
		}
	}
}

template <typename T, typename PT>
void mergeInsertionSort(T &c, PT begin, PT end)
{
	int	distanceInsertion = 5;
	if (std::distance(begin, end) <= distanceInsertion)
		insertionSort(begin, end);
	else
	{
		PT cut = begin + std::distance(begin, end) / 2;
		mergeInsertionSort(c, begin, cut);
		mergeInsertionSort(c, cut, end);
		T copy(std::distance(begin, end));
		std::merge(begin, cut, cut, end, copy.begin());
		std::copy(copy.begin(), copy.end(), begin);
	}
		
}



size_t strlength(char const string[])
{
	int i = 0;
	while (string[i] != '\0')
		i++;
	return i;
}

bool isNumber(char const string[])
{
	for (size_t i = 0; i < strlength(string); i++)
	{
		if (!isdigit(string[i]))
			return false;
	}
	return true;
}

void PmergeMe::fillVector(char const *argv[])
{
	int i = 1;
	if (argv[1] == '\0')
		throw std::invalid_argument("Invalid number of elements");
	while (argv[i] != '\0')
	{
		if (!isNumber(argv[i]))
			throw std::invalid_argument("Invalid element: \'" + std::string(argv[i]) + "\' is not a correct number");
		this->_vectorSort.push_back(atoi(argv[i]));
		this->_dequeSort.push_back(atoi(argv[i]));
		i++;
	}	
}

template <typename T>
void printVector(T &c)
{
	std::copy(c.begin(), c.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void printTime(std::vector<int> &c , clock_t start, clock_t end)
{
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << c.size() << " std::vector<int>" <<  " elements: " << (double)(end - start) / CLOCKS_PER_SEC << "us" << std::endl;
}

void printTime(std::deque<int> &c , clock_t start, clock_t end)
{
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << c.size() << " std::deque<int>" <<  " elements: " << (double)(end - start) / CLOCKS_PER_SEC << "us" << std::endl;
}

void PmergeMe::sort(char const *argv[])
{
	this->fillVector(argv);
	std::cout << "Before sorting:";
	printVector(this->_vectorSort);
	this->_start = clock();
	mergeInsertionSort(this->_vectorSort, this->_vectorSort.begin(), this->_vectorSort.end());
	this->_end = clock();
	std::cout << "After sorting:";
	printVector(this->_vectorSort);
	printTime(this->_vectorSort, this->_start, this->_end);
	this->_start = clock();
	mergeInsertionSort(this->_dequeSort, this->_dequeSort.begin(), this->_dequeSort.end());
	this->_end = clock();
	printTime(this->_dequeSort, this->_start, this->_end);
}


