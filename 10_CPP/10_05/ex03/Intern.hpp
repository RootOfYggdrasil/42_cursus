
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
private:
	typedef AForm *(Intern::*createFormFunction)(std::string const target);

	AForm *createRobotomyRequest(std::string const target);
	AForm *createShrubberyCreation(std::string const target);
	AForm *createPresidentialPardon(std::string const target);

public:
	Intern();
	~Intern();
	Intern(Intern const &copy);
	Intern &operator=(Intern const &copy);

	AForm *makeForm(std::string const formName, std::string const target);
};

#endif