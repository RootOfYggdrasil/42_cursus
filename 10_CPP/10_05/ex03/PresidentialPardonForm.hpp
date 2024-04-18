
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &copy);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

	std::string getTarget() const;
	void execute(const Bureaucrat &executor) const;
};



#endif