#include "MainWindow.h"

void MainWindow::initPlanningTab(QTabWidget* tabWidget){
	_planningTab = new QWidget();

	tabWidget->addTab(_planningTab, "Planning");

	_p_globals = {6, 16.5, 6, {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}};

	int id = 0;
	_p_teamMembers.push_back(TeamMember(++id, 0, QString('a'+id), QString('A'+id), {"Monday"}));
	_p_teamMembers.push_back(TeamMember(++id, 0, QString('a'+id), QString('A'+id), {"Wednesday"}));
	_p_teamMembers.push_back(TeamMember(++id, 0, QString('a'+id), QString('A'+id), {"Saturday"}));

	std::cout << _p_globals << "\n" << _p_teamMembers.size() << "\n";
	for(auto& teamMember : _p_teamMembers){
		std::cout << teamMember << std::endl;
	}

	_planning.calculate(_p_globals, _p_teamMembers, _weekdays);
}

void MainWindow::deletePlanningTab(QTabWidget* tabWidget){
	deletePtr(_planningTab);
}

void MainWindow::resetPlanningTab(QTabWidget* tabWidget){
	deletePlanningTab(tabWidget);
	initPlanningTab(tabWidget);
}
