
#include "Base.hpp"

Base::~Base() { }

Base *generate()
{
    int random = std::rand() % 3;
    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknow type" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		Base &ref = dynamic_cast <A&> (p);
		std::cout << "A&" << std::endl;
		(void)ref;
		return ;
	}
	catch (std::exception &e) {};
	try
	{
		Base &ref = dynamic_cast <B&> (p);
		std::cout << "B&" << std::endl;
		(void)ref;
		return ;
	}
	catch (std::exception &e) {};
	try
	{
		Base &ref = dynamic_cast <C&> (p);
		std::cout << "C&" << std::endl;
		(void)ref;
		return ;
	}
	catch (std::exception &e) {};
	std::cout << "Base&" << std::endl;
}