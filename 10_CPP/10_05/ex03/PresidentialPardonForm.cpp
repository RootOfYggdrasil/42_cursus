
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default presidential pardon form", 25, 5), _target("default target") { }

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("presidential pardon form", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _target(copy._target) { }

PresidentialPardonForm::~PresidentialPardonForm() { }

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const { return this->_target; }

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
