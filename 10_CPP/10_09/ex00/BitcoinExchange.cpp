
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	this->_exchangeRatio = other._exchangeRatio;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->_exchangeRatio = other._exchangeRatio;
    return *this;
}

float   ftStof(const std::string &input)
{
        float   result = 0;
	int             i = 0;
        int             sign = 1;
	int             len = input.length();
        int             point = 0;

        while(i < len && isspace(input[i]))
                i++;
        if (i < len && (input[i] == '-' || input[i] == '+'))
                sign = (input[i++] == '-') ? -1 : 1 ;
        while (i < len && ((input[i] >= '0' && input[i] <= '9') || input[i] == '.'))
        {
         	if (input[i] == '.')
                {
                        if (point)
                                throw std::invalid_argument("Invalid Number");
                        point = 1;
                }
                else
                {
                        result = result * 10 + input[i] - '0';
                        if (point)
                                point *= 10;
                }
                i++;
        }
	return (point ? result * sign / point : result * sign);
}


bool	isDateValid(const std::string date)
{
	int	day, month, year;
	bool	isBisestile = false;
	if(sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) < 3)
		return false;
	if (year < 2009 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
		isBisestile = true;
	if (month == 2 && ((isBisestile && day > 29) || (!isBisestile && day > 28)))
		return	false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return	false;
	return true;
}

double  ftStod(const std::string &input)
{
        double  result = 0;
        int             i = 0;
        int             sign = 1;
        int             len = input.length();
        int             point = 0;

        while(i < len && isspace(input[i]))
                i++;
        if (i < len && (input[i] == '-' || input[i] == '+'))
                sign = (input[i++] == '-') ? -1 : 1 ;
        while (i < len && ((input[i] >= '0' && input[i] <= '9') || input[i] == '.'))
        {
                if (input[i] == '.')
                {
                        if (point)
                                throw std::invalid_argument("Invalid argument");
                        point = 1;
                }
                else
                {
                        result = result * 10 + input[i] - '0';
                        if (point)
                                point *= 10;
                }
                i++;
        }
        return (point ? result * sign / point : result * sign);
}

bool	ParseLine(std::string line, std::string delim, float downLimit, float upLimit)
{
	//2020-08-09,11767.6
	//date extract parsing
	/*if (line.size() < 11 + delim.size())
	{
		throw std::exception();
		return;
	}*/
	//DateParsing(line, '-');
	/*if (line.compare(10, delim.size(), delim) != 0)
	{
		throw std::exception();
		return;
	}*/
	std::string date, numberString;
	size_t		delimPos;
	float		number;
	
	delimPos = line.find(delim);
	if (delimPos == std::string::npos)
	{
		std::cerr << "Error: bad input " << line << std::endl;
		return false;
	}
	date = line.substr(0, delimPos);
	numberString = line.substr(delimPos + 1);
	bool point = false;
	for (size_t i = 0; i < numberString.size(); i++)
	{
		if (i == 0 && numberString[i] == ' ')
			continue;
		if (isdigit(numberString[i]) || numberString[i] == '.')
		{
			if (numberString[i] == '.' && point)
			{
				std::cerr << "Error: bad input num invalid" << numberString << std::endl;
				return false;
			}
			else if (numberString[i] == '.')
				point = true;
		}
		else
		{
			std::cerr << "Error: bad input num invalid" << numberString << std::endl;
			return false;
		}
	}
	std::istringstream numberStream(numberString);
	if (!isDateValid(date))
	{
		std::cerr << "Error: bad input date invalid " << date << std::endl;
		return false;
	}
	if (!(numberStream >> number))
	{

		std::cerr << "Error: bad input num invalid " << numberString << std::endl;
		return false;
	}
	else if (number < downLimit)
	{
		std::cerr << "Error: input below " << downLimit << std::endl;
		return false;
	}
	else if (number >= upLimit)
	{
		std::cerr << "Error: input upper " << upLimit << std::endl;
		return false;
	}
	return true;
	
	
	
	//delim

	//float number parsing
}

void	BitcoinExchange::LoadExchangeRate(std::string fileName)
{
	std::ifstream fileExchangeRate(fileName.c_str());

	if(fileExchangeRate.is_open())
	{
		std::string line;
		while (std::getline(fileExchangeRate, line))
		{
			//line.erase(line.find(','), 1);
			if (ParseLine(line, ",", 0, std::numeric_limits<float>::max()))
			{
				this->_exchangeRatio.insert(std::pair<std::string, float>(line.substr(0, line.find(',')), ftStof(line.substr(line.find(',') + 1))));
			}
			
			//std::cout << line << std::endl;
		}
	}
}

bool	BitcoinExchange::isEmpty()
{
	return this->_exchangeRatio.empty();
}

void	BitcoinExchange::processInputFile(std::string fileName)
{
	std::ifstream fileExchangeRate(fileName.c_str());

	if(fileExchangeRate.is_open())
	{
		std::string line;
		while (std::getline(fileExchangeRate, line))
		{
			//line.erase(line.find(','), 1);
			if(ParseLine(line, "|", 0 , std::numeric_limits<int>::max()))
			{
				size_t pos = line.find('|');
				std::string date = line.substr(0, pos - 1);
				float number = ftStof(line.substr(pos + 2));

				std::map<std::string, float>::const_iterator it = this->_exchangeRatio.find(date);
				if (it != this->_exchangeRatio.end())
					std::cout << date << " => " << number << " => " << number * it->second << std::endl;
				else
				{
					it = this->_exchangeRatio.lower_bound(date);
					if (it == this->_exchangeRatio.begin())
						std::cerr << "Error: no exchange rate found" << std::endl;
					else
					{
						it--;
						std::cout << date << " => " << number << " => " << number * it->second << std::endl;
					}
				}
			}
		}
	}
}