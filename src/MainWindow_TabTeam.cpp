#include "MainWindow.h"

void MainWindow::initTeamTab(QTabWidget* tabWidget){
	_teamTab = new QWidget();
}

void MainWindow::resetTeamTab(QTabWidget* tabWidget){
	deleteTeamTab(tabWidget);
	initTeamTab(tabWidget);
}

void MainWindow::deleteTeamTab(QTabWidget* tabWidget){
	deletePtr(_generalTab);
}
