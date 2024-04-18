
#include "Intern.hpp"

Intern::Intern() { }

Intern::~Intern() { }

Intern::Intern(Intern const &copy) { *this = copy; }

Intern &Intern::operator=(Intern const &copy)
{
	(void)copy;
	return *this;
}

AForm *Intern::createPresidentialPardon(std::string const target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequest(std::string const target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreation(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(std::string const name, std::string const target) {
	std::string				formName[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	createFormFunction		formType[3]	= {&Intern::createPresidentialPardon, &Intern::createRobotomyRequest, &Intern::createShrubberyCreation};

	for (int i = 0; i < 3; i++) {
		if (formName[i].compare(name) == 0) {
			std::cout << "Intern successfully created " << name << " form" << std::endl;
			return ((this->*formType[i])(target));
		}
	}
	std::cout << "Intern failed to create " << name << " form, because prototype doesn't exist\n";
	return (NULL);
}
