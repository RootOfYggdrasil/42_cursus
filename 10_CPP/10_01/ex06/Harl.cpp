
#include "Harl.hpp"

Harl::Harl(void) {return;}

Harl::~Harl(void) {return;}

void Harl::debug(void) {
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR]: I cannot believe that adding extra bacon cost more money. You do not put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO]: I just love the taste of bacon. I cannot get enough!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[WARNING]: I think you are overdoing it on the bacon. I think that is going to get you in trouble!" << std::endl;
}

enum Level {
	DEBUG,
	ERROR,
	INFO,
	WARNING
};

void Harl::complain(std::string level) {
	std::map<std::string, Level> map = {
		{"DEBUG", DEBUG},
		{"ERROR", ERROR},
		{"INFO", INFO},
		{"WARNING", WARNING}
	};

	if (map.find(level) != map.end())
	{
		switch (map[level])
		{
			case DEBUG:
				(this->debug)();
			case ERROR:
				(this->error)();
			case INFO:
				(this->info)();
			case WARNING:
			{
				(this->warning)();
				break;
			}
			default:
			{
				std::cout << "SIGNOR PACCIANI CHE DICE!!!!" << std::endl;
				break;
			}
		}
	}
	else
		std::cout << "SIGNOR PACCIANI CHE DICE!!!!" << std::endl;

	
	return;
}