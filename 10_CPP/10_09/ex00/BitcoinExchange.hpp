
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <cctype>
#include <exception>
#include <sstream>
#include <limits>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_exchangeRatio;

public:
        BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &other);
		void	LoadExchangeRate(std::string fileName);
		bool	isEmpty();
		void	processInputFile(std::string fileName);

};


#endif