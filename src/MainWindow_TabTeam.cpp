#include "MainWindow.h"

void MainWindow::initTeamTab(QTabWidget* tabWidget){
	_teamTab = new QMainWindow();
	_teamCenter = new QWidget;
	_teamToolBar = new QToolBar();
	_teamTable = new QTableWidget();
	_teamLay = new QVBoxLayout();
	
	tabWidget->addTab(_teamTab, "Team");
	_teamTab->addToolBar(_teamToolBar);
	_teamTab->setCentralWidget(_teamCenter);

	const QIcon addIcon = QIcon("./res/icons/add-icon.png");
	QAction *addAct = new QAction(addIcon, tr("&Add Member"), _teamTab);
	addAct->setStatusTip(tr("Create a new team member"));
	connect(addAct, &QAction::triggered, this, &MainWindow::addMember);
	_teamToolBar->addAction(addAct);

	const QIcon editIcon = QIcon("./res/icons/edit-icon.png");
	QAction *editAct = new QAction(editIcon, tr("&Edit Member"), _teamTab);
	editAct->setStatusTip(tr("Edit a team member"));
	connect(editAct, SIGNAL(triggered()), this, SLOT(editMember()));
	_teamToolBar->addAction(editAct);
	
	const QIcon deleteIcon = QIcon("./res/icons/delete-icon.png");
	QAction *deleteAct = new QAction(deleteIcon, tr("&Delete Member"), _teamTab);
	deleteAct->setStatusTip(tr("Delete a team member"));
	connect(deleteAct, SIGNAL(triggered()), this, SLOT(deleteMember()));
	_teamToolBar->addAction(deleteAct);

	_teamTable->setColumnCount(5);
	QStringList headers = { "Id", "First name", "Last name", "Nb of hours", "Days off"};
	_teamTable->setHorizontalHeaderLabels(headers);

	initTeamTable();

	_teamCenter->setLayout(_teamLay);
	_teamLay->addWidget(_teamTable);
}

void MainWindow::addMember() {
	std::cout << "test" << std::endl;
	AddMemberModal newMember(this, _weekdays, teamMembers, *_teamTable);
	newMember.setModal(true);
	newMember.exec();
}

void MainWindow::editMember() {
	for(auto &e : teamMembers) {
		std::cout << e << std::endl;
	}
}

void MainWindow::initTeamTable() {
	for(auto &e : teamMembers) {
		_teamTable->setItem(_teamTable->rowCount() - 1, ID, new QTableWidgetItem(QString::number(e.getId())));
	}
}

void MainWindow::deleteMember() {
	std::cout << "test2" << std::endl;
}

void MainWindow::deleteTeamTab(QTabWidget* tabWidget){
	deletePtr(_teamToolBar);
	deletePtr(_teamLay);
	deletePtr(_teamTab);
}

void MainWindow::resetTeamTab(QTabWidget* tabWidget){
	deleteTeamTab(tabWidget);
	initTeamTab(tabWidget);
}