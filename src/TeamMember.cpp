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

int TeamMember::getId() {
    return id;
}

void TeamMember::setId(int _id) {
    id = _id;
}

double TeamMember::getNbHours() {
    return nbHours;
}

void TeamMember::setNbHours(double _nbHours) {
    nbHours = _nbHours;
}

QString TeamMember::getFirstName() {
    return firstName;
}

void TeamMember::setFirstName(QString _firstName) {
    firstName = _firstName;
}

QString TeamMember::getLastName() {
    return lastName;
}

void TeamMember::setLastName(QString _lastName) {
    lastName = _lastName;
}

std::vector<QString> TeamMember::getDaysOff() {
    return daysOff;
}

void TeamMember::setDaysOff(std::vector<QString> &_daysOff) {
    daysOff = _daysOff;
}