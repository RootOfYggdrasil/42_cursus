
#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	AForm();
	virtual ~AForm();
	AForm(std::string const name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &copy);
	AForm &operator=(AForm const &copy);

	std::string getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	void		beSigned(Bureaucrat const &bureaucrat);

    virtual void execute(const Bureaucrat &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);

#endif