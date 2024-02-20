
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <map>

class Harl {
private:
	void debug(void);
	void error(void);
	void info(void);
	void warning(void);
public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);
};


#endif