#include "Planning.h"

Planning::Planning() :
	_planning()
{}

std::map<int, std::map<std::string, std::vector<bool>>> Planning::calculate(const Globals& globals, const std::vector<TeamMember>& teamMembers, const std::vector<QString>& weekdays){
	std::vector<bool> baseDay;
	std::vector<int> nbMemberPerDay;
	for(size_t i = 0; i < 24*15; ++i){
		baseDay.push_back(false);
		nbMemberPerDay.push_back(0);
	}

	std::map<std::string, std::vector<bool>> baseWeek;
	std::map<std::string, std::vector<int>> globalPlanning;
	for(const auto& day : weekdays){
		baseWeek[day.toStdString()] = baseDay;
		globalPlanning[day.toStdString()] = nbMemberPerDay;
	}

	for(const auto& member : teamMembers){
		_planning[member.getId()] = baseWeek;
	}

	std::cout << *this << std::endl;
	for(auto& member : teamMembers){
		auto memberSlots = getBestSlots(globals, member, _planning[member.getId()], globalPlanning);

		if(!memberSlots.size()){
			continue;
		}

		auto bestSlot = memberSlots[0];
		_planning[member.getId()][bestSlot.first][bestSlot.second] = true;
	}

	return _planning;
}

std::vector<std::pair<std::string, size_t>> Planning::getBestSlots(const Globals& globals, const TeamMember& member, std::map<std::string, std::vector<bool>> memberPlanning, std::map<std::string, std::vector<int>> globalPlanning) {
	std::vector<std::pair<std::string, size_t>> out;

	

	return out;
}

std::ostream& operator<<(std::ostream& os, const Planning& p){
	os << "Nb member : " << p._planning.size() << "\n";
	try {
		os << "Nb week days : " << p._planning.at(1).size() << "\n";
		os << "Nb hours a day : " << p._planning.at(1).at("Monday").size() << "\n";
	} catch(std::out_of_range& e){}

	return os;
}
