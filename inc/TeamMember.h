#ifndef HEADER_TEAMMEMBER
#define HEADER_TEAMMEMBER

#include <string>
#include <vector>
#include "Widgets/Qt.hpp"

class TeamMember {
    public:
        TeamMember(int _id, double _nbHours, QString _firstName, QString _lastName, std::vector<QString> &_daysOff);
        ~TeamMember();
        friend std::ostream & operator<<(std::ostream &os, const TeamMember &tm);

        int getId();
        double getNbHours();
        QString getFirstName();
        QString getLastName();
        std::vector<QString> getDaysOff();

        void setId(int _id);
        void setNbHours(double _nbHours);
        void setFirstName(QString _firstName);
        void setLastName(QString _lastName);
        void setDaysOff(std::vector<QString> &_daysOff);

    private:
        int id;
        double nbHours;
        QString firstName, lastName;
        std::vector<QString> daysOff;
};

#endif //TEAMMEMBER