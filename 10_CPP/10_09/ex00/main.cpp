
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange exchange;
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc [filename]" << std::endl;
		return 1;
	}
	exchange.LoadExchangeRate("data.csv");
	if (exchange.isEmpty())
	{
		std::cerr << "Error: No exchange rate found" << std::endl;
		return 1;
	}
	exchange.processInputFile(argv[1]);
	return 0;	
}