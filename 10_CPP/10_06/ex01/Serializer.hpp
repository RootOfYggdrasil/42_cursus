
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <stdint.h>

struct Data
{
	int			interger_data;
	std::string string_data;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();
		Serializer &operator=(const Serializer &other);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data*	 deserialize(uintptr_t raw);
};


#endif