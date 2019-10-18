#ifndef HEADER_MAINWINDOW_TAB_TEAM
#define HEADER_MAINWINDOW_TAB_TEAM

/* Members of MainWindow */
public:
	/* Internal enums of MainWindow */
		
	/* Getters of MainWindow */
		
	/* Setters of MainWindow */
		
	/* Statics of MainWindow */
		
	/* Operators of MainWindow */
		
	/* Friends of MainWindow */
		
	/* Others members of MainWindow */
		

public slots:
	void addMember();
	void editMember(int memberId);
	void deleteMember(int memberId);

signals:
	

protected:
	/* Getters of MainWindow */
		
	/* Setters of MainWindow */
		
	/* Statics of MainWindow */
		
	/* Friends of MainWindow */
		
	/* Others members of MainWindow */

private:
	void initTeamTab(QTabWidget* tabWidget);
	void resetTeamTab(QTabWidget* tabWidget);
	void deleteTeamTab(QTabWidget* tabWidget);
	
/* Atttributes of MainWindow */
public:
	/* Global */
		
	/* Local */
		

protected:
	/* Global */
		
	/* Local */
		

private:
	/* Global */
		
	/* Local */
		QMainWindow* _teamTab;
		QVBoxLayout* _teamLay;
		QToolBar* _teamToolBar;
		std::vector<TeamMember> teamMembers;
		std::vector<TeamMember> selectedTeamMembers;

#endif //HEADER_MAINWINDOW_TAB_TEAM
