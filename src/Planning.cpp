#include "Planning.h"

Planning::Planning() :
	_planning()
{}

std::map<int, std::map<std::string, std::vector<bool>>> Planning::calculate(const Globals& globals, const std::vector<TeamMember>& teamMembers, const std::vector<QString>& weekdays){
	

	return _planning;
}

std::ostream& operator<<(std::ostream& os, const Planning& p){
	os << "Nb member : " << p._planning.size() << "\n";
	try {
		os << "Nb week days : " << p._planning.at(1).size() << "\n";
		os << "Nb hours a day : " << p._planning.at(1).at("Monday").size() << "\n";
	} catch(std::out_of_range& e){}

	return os;
}
