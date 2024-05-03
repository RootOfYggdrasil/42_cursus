
#include "Base.hpp"

int main()
{
    std::srand(std::time(0));

	int i = 0;
    Base* obj = generate();
    identify(obj);
    identify(*obj);
	identify(NULL);

    delete obj;

    return 0;
}