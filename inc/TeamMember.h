#ifndef HEADER_TEAMMEMBER
#define HEADER_TEAMMEMBER

#include <string>
#include <vector>
#include "Widgets/Qt.hpp"

class TeamMember {
    public:
        TeamMember(int _id, double _nbHours, QString _firstName, QString _lastName, const std::vector<QString> &_daysOff);
        ~TeamMember();
        friend std::ostream & operator<<(std::ostream &os, const TeamMember &tm);

        friend std::ofstream & operator<<(std::ofstream &os, const TeamMember &tm);
        friend std::ifstream & operator>>(std::ifstream &is, TeamMember &tm);

    private:
        int id;
        double nbHours;
        QString firstName, lastName;
        std::vector<QString> daysOff;
};

#endif //TEAMMEMBER
