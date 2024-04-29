
#include "Serializer.hpp"

int	main()
{
	Data data;
	data.a = 42;
	data.b = "Hello, World!";
	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "a: " << ptr->a << std::endl;
	std::cout << "b: " << ptr->b << std::endl;
	std::cout << "raw: " << raw << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	return 0;
}