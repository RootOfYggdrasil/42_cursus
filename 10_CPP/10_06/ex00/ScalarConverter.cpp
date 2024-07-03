
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { }

ScalarConverter::~ScalarConverter() { }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) { return *this;}

int		ScalarConverter::ftStoi(const std::string &input)
{
	size_t		result = 0;
	int		i = 0;
	int		sign = 1;
	int		len = input.length();

	while(i < len && isspace(input[i]))
		i++;
	if (i < len && input[i] == '-' || input[i] == '+')
		sign = (input[i++] == '-') ? -1 : 1 ;
	while (i < len && input[i] >= '0' && input[i] <= '9')
	{
		result = result * 10 + input[i] - '0';
		i++;
	}
	if ((result > INT_MAX && sign == 1) || (result - 1 > INT_MAX && sign == -1))
		throw std::invalid_argument("Invalid argument");
	return (result * sign);
}

float	ScalarConverter::ftStof(const std::string &input)
{
	float	result = 0;
	int		i = 0;
	int		sign = 1;
	int		len = input.length();
	int		point = 0;

	while(i < len && isspace(input[i]))
		i++;
	if (i < len && input[i] == '-' || input[i] == '+')
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

double	ScalarConverter::ftStod(const std::string &input)
{
	double	result = 0;
	int		i = 0;
	int		sign = 1;
	int		len = input.length();
	int		point = 0;

	while(i < len && isspace(input[i]))
		i++;
	if (i < len && input[i] == '-' || input[i] == '+')
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

int		isPseudoLiteral(const std::string &input)
{
	if (input == "nan" || input == "nanf" || input == "inf" || input == "inff" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
		return 1;
	return 0;
}

void	printPseudoLiteral(const std::string &input) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input.find("inf") != std::string::npos)
		std::cout << "float: " << (input[input.size() - 1] == 'f' ? input + 'f' : input ) << std::endl;
	else if (input != "impossible")
		std::cout << "float: " << (input[input.size() - 1] == 'f' ? input : input + 'f') << std::endl;
	else
		std::cout << "float: " << input << std::endl;
	std::cout << "double: " << input << std::endl;
}

void	ScalarConverter::convertInt(const std::string &input)
{
	std::cout << "int: ";
	try
	{
		std::cout << static_cast<int>(ftStoi(input.c_str())) << std::endl;
	}
	catch (std::exception &e)
	{
		if (input.length() == 1 && std::isprint(input[0]))
			std::cout << static_cast<int>(input[0]) << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void	ScalarConverter::convertChar(const std::string &input)
{
	std::cout << "char: ";
	int	tmp = 0;

	try
	{
		tmp = ftStoi(input.c_str());
		if (tmp < 32 || tmp > 126)
			std::cout << "Non displayable" << std::endl;
		else if (input.length() > 1)
		{
			if(tmp < 32 || tmp > 126)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "'" << static_cast<char>(tmp) << "'" << std::endl;
		}
		else
			std::cout << "'" << input[0] << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "impossible" << std::endl;
	}
}

void	ScalarConverter::convertFloat(const std::string &input)
{
	std::cout << "float: ";
	try
	{
		std::cout << std::fixed << std::setprecision(2) << static_cast<float>(ftStof(input.c_str())) << "f" << std::endl;	
	}
	catch (std::exception &e)
	{
		std::cerr << "impossible" << std::endl;
	}
}

void	ScalarConverter::convertDouble(const std::string &input)
{
	std::cout << "double: ";
	try
	{
		std::cout << std::fixed << std::setprecision(2) << static_cast<double>(ftStod(input.c_str())) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "impossible" << std::endl;
	}
}

bool	isNoSense(const std::string &input)
{
	bool point = false;
	bool f = false;
	for (size_t i = 0; i < input.size(); i++)
	{
		if(isdigit(input[i]))
			continue;
		else if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue;
		else if (input[i] == '.' && !point)
			point = true;
		else if (input[i] == 'f' && !f)
			f = true;
		else
			return true;
	}
	return false;
}

void	ScalarConverter::convert(const std::string &input)
{
	if (input.length() == 0)
		std::cout << "Empty input" << std::endl;
	else if (isPseudoLiteral(input))
		printPseudoLiteral(input);
	else if (isNoSense(input))
		printPseudoLiteral("impossible");
	else
	{
		convertChar(input);
		convertInt(input);
		convertFloat(input);
		convertDouble(input);
	}
}
