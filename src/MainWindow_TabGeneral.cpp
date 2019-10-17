#include "MainWindow.h"

void MainWindow::initGeneralTab(QTabWidget* tabWidget){
	/* New */
	_g_tab = new QWidget();
	_g_lay = new QVBoxLayout();
	/*******/

	//_g_daysChoice = new QVBoxLayout();
	//_g_checkAllLay = new QHBoxLayout();
	//_g_allCheckbox = new QCheckBox("Check all");
	//_g_checkDays = new QHBoxLayout();

	/*for(auto& weekday : _weekdays){
		_g_daysCheckboxes[weekday] = new QCheckBox(weekday);
		_g_checkDays->addWidget(_g_daysCheckboxes[weekday]);
	}*/

	//_g_checkAllLay->addWidget(_g_allCheckbox);

	//_g_daysChoice->addLayout(_g_checkAllLay);
	//_g_daysChoice->addLayout(_g_checkDays);

	//_g_lay->addLayout(_g_daysChoice);
	_g_tab->setLayout(_g_lay);

	tabWidget->addTab(_g_tab, "General");
}

void MainWindow::deleteGeneralTab(QTabWidget* tabWidget){
	/*for(auto& dayCheckbox : _g_daysCheckboxes){
		deletePtr(dayCheckbox.second);
	}
	_g_daysCheckboxes.clear();*/

	//deletePtr(_g_allCheckbox);

	//deletePtr(_g_checkAllLay);
	//deletePtr(_g_checkDays);

	//deletePtr(_g_daysChoice);

	deletePtr(_g_lay);
	deletePtr(_g_tab);
}

void MainWindow::resetGeneralTab(QTabWidget* tabWidget){
	deleteGeneralTab(tabWidget);
	initGeneralTab(tabWidget);
}
