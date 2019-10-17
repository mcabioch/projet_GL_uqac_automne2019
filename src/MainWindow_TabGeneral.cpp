#include "MainWindow.h"

void MainWindow::initGeneralTab(QTabWidget* tabWidget){
/* New */
	_g_tab = new QWidget();
	_g_lay = new QVBoxLayout();

	_g_daysChoice = new QVBoxLayout();
	_g_checkAllLay = new QHBoxLayout();
	_g_allCheckbox = new QCheckBox("Check all");
	_g_checkDays = new QHBoxLayout();

	_g_minTimeLay = new QHBoxLayout();
	_g_minTimeEdit = new QTimeEdit();
	_g_minTimeLabel = new QLabel("Minimum hour to start : ");

	_g_maxTimeLay = new QHBoxLayout();
	_g_maxTimeEdit = new QTimeEdit();
	_g_maxTimeLabel = new QLabel("Maximum hour to stop : ");

	_g_defaultHoursLay = new QHBoxLayout();
	_g_defaultHoursEdit = new QDoubleSpinBox();
	_g_defaultHoursLabel = new QLabel("Default hours per week : ");

	_g_buttons = new QHBoxLayout();
	_g_saver = new QPushButton("Save datas");
	_g_computer = new QPushButton("Create planning");
/*******/

/* Add */
	_g_buttons->addWidget(_g_saver);
	_g_buttons->addWidget(_g_computer);
	_g_buttons->addItem(new QHSpacerItem());

	_g_minTimeLay->addWidget(_g_minTimeLabel);
	_g_minTimeLay->addWidget(_g_minTimeEdit);
	_g_minTimeLay->addItem(new QHSpacerItem());

	_g_maxTimeLay->addWidget(_g_maxTimeLabel);
	_g_maxTimeLay->addWidget(_g_maxTimeEdit);
	_g_maxTimeLay->addItem(new QHSpacerItem());

	_g_defaultHoursLay->addWidget(_g_defaultHoursLabel);
	_g_defaultHoursLay->addWidget(_g_defaultHoursEdit);
	_g_defaultHoursLay->addItem(new QHSpacerItem());

	for(auto& weekday : _weekdays){
		_g_daysCheckboxes[weekday] = new QCheckBox(weekday);
		_g_checkDays->addWidget(_g_daysCheckboxes[weekday]);
	}
	_g_checkDays->addItem(new QHSpacerItem());

	_g_checkAllLay->addWidget(_g_allCheckbox);

	_g_daysChoice->addLayout(_g_checkAllLay);
	_g_daysChoice->addLayout(_g_checkDays);

	_g_lay->addLayout(_g_daysChoice);
	_g_lay->addLayout(_g_defaultHoursLay);
	_g_lay->addLayout(_g_minTimeLay);
	_g_lay->addLayout(_g_maxTimeLay);
	_g_lay->addLayout(_g_buttons);

	_g_lay->addItem(new QVSpacerItem());
	_g_tab->setLayout(_g_lay);

	tabWidget->addTab(_g_tab, "General");
/*******/

	_g_defaultHoursEdit->setMinimum(0);
	_g_defaultHoursEdit->setMaximum(90);

	connect(_g_allCheckbox, SIGNAL(stateChanged(int)), this, SLOT(generalAllCheckstate(int)));
	connect(_g_saver, SIGNAL(released()), this, SLOT(generalSaveDatas()));
	connect(_g_computer, SIGNAL(released()), this, SLOT(generalCalculate()));
}

void MainWindow::deleteGeneralTab(QTabWidget* tabWidget){
	deletePtr(_g_buttons);
	deletePtr(_g_saver);
	deletePtr(_g_computer);

	deletePtr(_g_minTimeEdit);
	deletePtr(_g_minTimeLabel);
	deletePtr(_g_minTimeLay);

	deletePtr(_g_maxTimeEdit);
	deletePtr(_g_maxTimeLabel);
	deletePtr(_g_maxTimeLay);

	deletePtr(_g_defaultHoursEdit);
	deletePtr(_g_defaultHoursLabel);
	deletePtr(_g_defaultHoursLay);

	for(auto& dayCheckbox : _g_daysCheckboxes){
		deletePtr(dayCheckbox.second);
	}
	_g_daysCheckboxes.clear();

	deletePtr(_g_allCheckbox);

	deletePtr(_g_checkAllLay);
	deletePtr(_g_checkDays);

	deletePtr(_g_daysChoice);

	deletePtr(_g_lay);
	deletePtr(_g_tab);
}

void MainWindow::generalAllCheckstate(int state){
	Qt::CheckState cState;

	if(!state){
		_g_allCheckbox->setText("Check all");
		cState = Qt::Unchecked;
	} else {
		_g_allCheckbox->setText("Uncheck all");
		cState = Qt::Checked;
	}

	for(auto& weekday : _weekdays){
		_g_daysCheckboxes[weekday]->setCheckState(cState);
	}
}

void MainWindow::generalSaveDatas(){
	
}

void MainWindow::generalCalculate(){
	

	
}

void MainWindow::resetGeneralTab(QTabWidget* tabWidget){
	deleteGeneralTab(tabWidget);
	initGeneralTab(tabWidget);
}
