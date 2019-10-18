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

std::ostream & operator<<(std::ostream &os, const TeamMember &tm) {
    os << tm.id << " " << tm.nbHours << " " << tm.firstName.toStdString() << " " << tm.lastName.toStdString() << " " << tm.daysOff.size() << " ";
    
    for(auto &e : tm.daysOff) {
        os << e.toStdString() << " ";
    }

    os << "\n";

    return os;
}