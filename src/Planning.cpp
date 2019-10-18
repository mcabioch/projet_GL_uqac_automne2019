#include "Planning.h"

Planning::Planning() :
	_planning()
{}

std::map<int, std::map<std::string, std::vector<bool>>> Planning::calculate(const Globals& globals, const std::vector<TeamMember>& teamMembers, const std::vector<QString>& weekdays){
	for(const auto& day : weekdays){
		_weekdays.push_back(day.toStdString());
	}

	std::vector<bool> baseDay;
	std::vector<int> nbMemberPerDay;
	for(size_t i = 0; i < 24*15; ++i){
		baseDay.push_back(false);
		nbMemberPerDay.push_back(0);
	}

	std::map<std::string, std::vector<bool>> baseWeek;
	std::map<std::string, std::vector<int>> globalPlanning;
	for(const auto& day : _weekdays){
		baseWeek[day] = baseDay;
		globalPlanning[day] = nbMemberPerDay;
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

	auto available = out;
	for(auto& day : _weekdays){
		auto g_worked_b = globals.workedDays.begin();
		auto g_worked_e = globals.workedDays.end();

		auto t_off_b = member.daysOff.begin();
		auto t_off_e = member.daysOff.end();

		if(std::find(g_worked_b, g_worked_e, day) == g_worked_e){
			continue;
		}
		if(std::find(t_off_b, t_off_e, day) != t_off_e){
			continue;
		}

		
	}

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
