#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	Window(parent),
	centerLayout(nullptr),
	center(nullptr),

	_tab(nullptr),
	_generalTab(nullptr),
	_teamTab(nullptr),
	_planningTab(nullptr)
{
	/* Base */
		center = new QWidget;
		centerLayout = new QVBoxLayout;

		this->setWindowTitle("Planning Generator");
		this->setCentralWidget(center);

		center->setLayout(centerLayout);

		this->enableResize(true);
		this->Fullscreen();
	/********/

	_tab = new QTabWidget();

	initGeneralTab(_tab);
	initTeamTab(_tab);
	initPlanningTab(_tab);

	_tab->addTab(_generalTab, "General");
	_tab->addTab(_teamTab, "Team");
	_tab->addTab(_planningTab, "Planning");

	centerLayout->addWidget(_tab);
}

MainWindow::~MainWindow(){
	deleteGeneralTab(_tab);
	deleteTeamTab(_tab);
	deletePlanningTab(_tab);

	deletePtr(_tab);

	deletePtr(centerLayout);
	deletePtr(center);
}
