#ifndef HEADER_PLANNING
#define HEADER_PLANNING

#include <iostream>
#include <map>
#include <vector>

#include "Globals.h"
#include "TeamMember.h"

class Planning {
	public:
		Planning();
		~Planning(){}

		std::map<int, std::map<std::string, std::vector<bool>>> calculate(const Globals& globals, const std::vector<TeamMember>& teamMembers, const std::vector<QString>& weekdays);

		friend std::ostream& operator<<(std::ostream& os, const Planning& p);

	private:
		std::map<int, std::map<std::string, std::vector<bool>>> _planning;
};

#endif //HEADER_PLANNING