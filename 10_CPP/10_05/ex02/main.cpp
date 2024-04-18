
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat br("PRESIDENTE(?)", 50);
		Bureaucrat br2("REDELMONDO", 5);
        ShrubberyCreationForm sh("VILLA PER BLACK JACK E SQUILLO DI LUSSO");
        RobotomyRequestForm ro("IS THIS NIPOTE DI MUBARAQ?");
        PresidentialPardonForm pa("SALVA ITAGLIA");

        std::cout << br << std::endl;
        std::cout << sh << std::endl;
        std::cout << ro << std::endl;
        std::cout << pa << std::endl;

        br.signForm(sh);
        br.signForm(ro);
        br2.signForm(pa);

        br.executeForm(sh);
        br2.executeForm(ro);
        br2.executeForm(pa);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}