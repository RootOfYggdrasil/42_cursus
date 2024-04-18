
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default shrubbery creation form", 145, 137), _target("default target") { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("shrubbery creation form", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target) { }

ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const { return this->_target; }

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return "File could not be opened.";
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file(this->getTarget() + "_shrubbery");
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException();
	file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
	file.close();
}
