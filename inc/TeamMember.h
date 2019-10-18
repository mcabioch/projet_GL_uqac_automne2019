#ifndef HEADER_TEAMMEMBER
#define HEADER_TEAMMEMBER

#include <string>
#include <vector>
#include "Widgets/Qt.hpp"

class TeamMember {
    public:
        TeamMember(int _id, double _nbHours, QString _firstName, QString _lastName, std::vector<QString> &_daysOff);
        ~TeamMember();

    private:
        int id;
        double nbHours;
        QString firstName, lastName;
        std::vector<QString> daysOff;
};

#endif //TEAMMEMBER