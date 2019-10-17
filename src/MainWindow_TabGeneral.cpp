#include "MainWindow.h"

void MainWindow::initGeneralTab(QTabWidget* tabWidget){
	_generalTab = new QWidget();
}

void MainWindow::resetGeneralTab(QTabWidget* tabWidget){
	deleteGeneralTab(tabWidget);
	initGeneralTab(tabWidget);
}

void MainWindow::deleteGeneralTab(QTabWidget* tabWidget){
	deletePtr(_generalTab);
}
