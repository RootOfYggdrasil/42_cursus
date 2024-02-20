
#include "Harl.hpp"

Harl::Harl(void) {return;}

Harl::~Harl(void) {return;}

void Harl::debug(void) {
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::error(void) {
	std::cout << "ERROR: I cannot believe that adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::info(void) {
	std::cout << "INFO: I just love the taste of bacon. I cannot get enough!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "WARNING: I think you are overdoing it on the bacon. I think that’s going to get you in trouble!" << std::endl;
}

typedef void (Harl::*HarlMapFunction)(void);

void Harl::complain(std::string level) {
	std::map<std::string, HarlMapFunction> map;
	map["DEBUG"] = &Harl::debug;
	map["ERROR"] = &Harl::error;
	map["INFO"] = &Harl::info;
	map["WARNING"] = &Harl::warning;

	if (map.find(level) != map.end()) {
		(this->*map[level])();
		return;
	}
	std::cout << "Invalid level" << std::endl;
	return;
}