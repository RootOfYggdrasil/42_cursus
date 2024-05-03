
#include "Serializer.hpp"

int	main()
{
	Data data;
	data.interger_data = 118;
	data.string_data = "SE NI MONDO!!";
	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Integer: " << ptr->interger_data << std::endl;
	std::cout << "String: " << ptr->string_data << std::endl;
	std::cout << "raw: " << raw << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	return 0;
}