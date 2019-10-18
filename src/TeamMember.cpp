#include "TeamMember.h"

TeamMember::TeamMember(int _id, double _nbHours, QString _firstName, QString _lastName, std::vector<QString> &_daysOff) {
    id = _id;
    nbHours = _nbHours;
    firstName = _firstName;
    lastName = _lastName;
    daysOff = _daysOff;
}

TeamMember::~TeamMember() {

}