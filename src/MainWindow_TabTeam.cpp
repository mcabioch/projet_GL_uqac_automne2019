#include "MainWindow.h"

void MainWindow::initTeamTab(QTabWidget* tabWidget){
	_teamTab = new QMainWindow();
	_teamToolBar = new QToolBar();
	
	tabWidget->addTab(_teamTab, "Team");
	_teamTab->addToolBar(_teamToolBar);

	const QIcon addIcon = QIcon("./res/icons/add-icon.png");
	QAction *addAct = new QAction(addIcon, tr("&Add Member"), _teamTab);
	addAct->setStatusTip(tr("Create a new team member"));
	connect(addAct, &QAction::triggered, this, &MainWindow::addMember);
	_teamToolBar->addAction(addAct);

	const QIcon editIcon = QIcon("./res/icons/edit-icon.png");
	QAction *editAct = new QAction(editIcon, tr("&Edit Member"), _teamTab);
	editAct->setStatusTip(tr("Edit a team member"));
	connect(editAct, SIGNAL(triggered()), this, SLOT(editMember(int 1)));
	_teamToolBar->addAction(editAct);
	
	const QIcon deleteIcon = QIcon("./res/icons/delete-icon.png");
	QAction *deleteAct = new QAction(deleteIcon, tr("&Delete Member"), _teamTab);
	deleteAct->setStatusTip(tr("Delete a team member"));
	connect(deleteAct, SIGNAL(triggered()), this, SLOT(deleteMember(int 1)));
	_teamToolBar->addAction(deleteAct);
}

void MainWindow::addMember() {
	std::cout << "test" << std::endl;
	AddMemberModal newMember(this, _weekdays, teamMembers);
	newMember.setModal(true);
	newMember.exec();
}

void MainWindow::editMember(int memberId) {
	std::cout << "test1" << std::endl;
}

void MainWindow::deleteMember(int memberId) {
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