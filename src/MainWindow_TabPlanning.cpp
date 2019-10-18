#include "MainWindow.h"

void MainWindow::initPlanningTab(QTabWidget* tabWidget){
	_planningTab = new QWidget();

	tabWidget->addTab(_planningTab, "Planning");

	_globals = {6, 16.5, 6, {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}};
	int id = 0;
	_teamMembers.push_back(TeamMember(id++, 0, QString('a'+id), QString('A'+id), {"Monday"}));
	_teamMembers.push_back(TeamMember(id++, 0, QString('a'+id), QString('A'+id), {"Wednesday"}));
	_teamMembers.push_back(TeamMember(id++, 0, QString('a'+id), QString('A'+id), {"Saturday"}));

	std::cout << _globals << "\n" << _teamMembers.size() << "\n";
	for(auto& teamMember : _teamMembers){
		std::cout << teamMember << std::endl;
	}
}

void MainWindow::deletePlanningTab(QTabWidget* tabWidget){
	deletePtr(_planningTab);
}

void MainWindow::resetPlanningTab(QTabWidget* tabWidget){
	deletePlanningTab(tabWidget);
	initPlanningTab(tabWidget);
}
