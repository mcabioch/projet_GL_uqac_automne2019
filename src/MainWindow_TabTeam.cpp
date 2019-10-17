#include "MainWindow.h"

void MainWindow::initTeamTab(QTabWidget* tabWidget){
	_teamTab = new QWidget();

	tabWidget->addTab(_teamTab, "Team");
}

void MainWindow::deleteTeamTab(QTabWidget* tabWidget){
	deletePtr(_teamTab);
}

void MainWindow::resetTeamTab(QTabWidget* tabWidget){
	deleteTeamTab(tabWidget);
	initTeamTab(tabWidget);
}
