
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat br("PRESIDENTE(?)", 50);
		Bureaucrat br2("REDELMONDO", 5);

		Intern in;

        AForm *sh;
		sh = in.makeForm("ShrubberyCreation", "VILLA PER BLACK JACK E SQUILLO DI LUSSO");
        AForm *ro = in.makeForm("RobotomyRequest", "IS THIS NIPOTE DI MUBARAQ?");
        AForm *pa = in.makeForm("PresidentialPardon", "SALVA ITAGLIA");
        std::cout << br << std::endl;
        std::cout << *sh << std::endl;
        //std::cout << ro << std::endl;
        //std::cout << pa << std::endl;

        br.signForm(*sh);
        br.signForm(*ro);
        br2.signForm(*pa);

        br.executeForm(*sh);
        br2.executeForm(*ro);
        br2.executeForm(*pa);
		delete sh;
		delete ro;
		delete pa;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}