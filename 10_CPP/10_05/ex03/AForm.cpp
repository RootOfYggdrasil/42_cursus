
#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) { }

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) { }

AForm::~AForm() { }

AForm &AForm::operator=(AForm const &copy)
{
	if (this != &copy)
	{
		_signed = copy._signed;
		
	}
	return *this;
}

std::string AForm::getName() const { return this->_name; }

bool AForm::getSigned() const { return this->_signed; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
	out << "Form: "
		<< AForm.getName()
		<< " is "
		<< (AForm.getSigned() ? "" : "not ")
		<< "signed. Grade to sign: "
		<< AForm.getGradeToSign()
		<< ". Grade to execute: "
		<< AForm.getGradeToExecute();
	return out;
}