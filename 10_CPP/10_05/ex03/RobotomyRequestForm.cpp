
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default robotomy request form", 72, 45), _target("default target") { }

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("robotomy request form", 72, 45), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _target(copy._target) { }

RobotomyRequestForm::~RobotomyRequestForm() { }

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const { return this->_target; }

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Drilling noises... ";
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " robotomization has failed." << std::endl;
}
