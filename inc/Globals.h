#ifndef HEADER_GLOBALS
#define HEADER_GLOBALS

#include <iostream>
#include <vector>

struct Globals {
	float startMin;
	float endMax;
	float nbHours;
	std::vector<std::string> workedDays;
};

std::ostream& operator<<(std::ostream& os, const Globals& g);
std::istream& operator>>(std::istream& is, Globals& g);

#endif //HEADER_GLOBALS
