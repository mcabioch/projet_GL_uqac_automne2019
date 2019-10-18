#include "Planning.h"

Planning::Planning() :
	_freq(4),
	_planning()
{}

std::map<int, std::map<std::string, std::vector<bool>>> Planning::calculate(const Globals& globals, const std::vector<TeamMember>& teamMembers, const std::vector<QString>& weekdays){
	for(const auto& day : weekdays){
		_weekdays.push_back(day.toStdString());
	}

	std::vector<bool> baseDay;
	std::vector<int> nbMemberPerDay;
	for(size_t i = 0; i < 24*_freq; ++i){
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

	std::ofstream writer("res/planning.csv");
	writer << toCSV(globals, teamMembers, ";") << std::endl;
	writer.close();

	return _planning;
}

std::vector<std::pair<std::string, size_t>> Planning::getBestSlots(const Globals& globals, const TeamMember& member, const std::map<std::string, std::vector<bool>>& memberPlanning, const std::map<std::string, std::vector<int>>&/* globalPlanning*/) {
	std::vector<std::pair<std::string, size_t>> out;

	/*auto available = out;
	for(auto& day : _weekdays){
		auto g_worked_b = globals.workedDays.begin();
		auto g_worked_e = globals.workedDays.end();

		auto t_off_b = member.getDaysOff().begin();
		auto t_off_e = member.getDaysOff().end();

		if(std::find(g_worked_b, g_worked_e, day) == g_worked_e){
			continue;
		}
		if(std::find(t_off_b, t_off_e, day.c_str()) != t_off_e){
			continue;
		}

		std::cout << day << std::endl;
		auto& possibleSlots = memberPlanning.at(day);
		for(size_t i = 0; i < possibleSlots.size(); ++i){
			float actHour = static_cast<float>(i) / _freq;

			if(actHour >= globals.startMin && actHour <= globals.endMax){
				available.push_back(std::make_pair(day, i));
			}
		}
	}*/

	

	return out;
}

std::string Planning::toCSV(const Globals&/* globals*/, const std::vector<TeamMember>& teamMembers, std::string separator){
	std::string csv = "";

	for(auto& day : _weekdays){
		csv += separator + day;
	}
	csv += "\n";

	for(auto& member : teamMembers){
		csv += member.getFirstName().toStdString() + " " + member.getLastName().toStdString();

		/*for(auto& slot : _planning[member.getId()][day]){
			for(auto& day : _weekdays){
				if(slot){
					csv += separator;
				} else {
					csv += separator + "?";
				}
			}
		}*/
	}

	return csv;
}

std::ostream& operator<<(std::ostream& os, const Planning& p){
	os << "Nb member : " << p._planning.size() << "\n";
	try {
		os << "Nb week days : " << p._planning.at(1).size() << "\n";
		os << "Nb hours a day : " << p._planning.at(1).at("Monday").size() << "\n";
	} catch(std::out_of_range& e){}

	return os;
}
