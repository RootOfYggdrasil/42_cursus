
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <climits>
#include <cfloat>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &obj);
	static void convertChar(const std::string &input);
	static void convertInt(const std::string &input);
	static void convertFloat(const std::string &input);
	static void convertDouble(const std::string &input);
	static int	ftStoi(const std::string &input);
	static float	ftStof(const std::string &input);
	static double	ftStod(const std::string &input);

public:
	static void convert(const std::string &input);

	class ImpossibleConversionException : public std::exception
	{
		virtual const char *what() const throw();
	};

};

#endif