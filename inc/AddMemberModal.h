#ifndef HEADER_ADDMEMBERMODAL
#define HEADER_ADDMEMBERMODAL

#include "Widgets/Qt.hpp"
#include "TeamMember.h"

class AddMemberModal : public QDialog {
    Q_OBJECT

    public :
        AddMemberModal(QWidget *parent, const std::vector<QString> &weekdays, std::vector<TeamMember> &teamMembers);
        virtual ~AddMemberModal();
        
    private :
        QGridLayout *mainLayout;
        QVBoxLayout *formLayout;
        QHBoxLayout *checkDaysOff;
        QLabel *daysOffLabel;
        QCheckBox* checkAll;
        QLineEdit *firstName;
        QLineEdit *lastName;

        QHBoxLayout *hoursPerWeekLay;
		QLabel *hoursPerWeekLabel;
		QDoubleSpinBox *hoursPerWeek;
        QPushButton *confirmButton;


        std::vector<QString> daysOff, weekdays;
        std::vector<TeamMember> teamMembers;
		std::map<QString, QCheckBox*> _t_daysCheckboxes;
        int workTime;

        void initWindow();

    public slots:
	    void generalAllCheckstate(int state);
        void addNewMember();

    signals:
};

#endif