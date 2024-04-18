
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

	std::string getTarget() const;
	void execute(const Bureaucrat &executor) const;

	class FileNotOpenException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif