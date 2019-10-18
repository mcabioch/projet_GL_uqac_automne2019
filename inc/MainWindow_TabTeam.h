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
	void editMember();
	void deleteMember();

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
	void initTeamTable();
	
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
		QWidget* _teamCenter;
		QVBoxLayout* _teamLay;
		QToolBar* _teamToolBar;
		QTableWidget *_teamTable;

		std::vector<TeamMember> teamMembers;
		std::vector<TeamMember> selectedTeamMembers;

		enum Columns {
			ID, FIRSTNAME, LASTNAME, NBHOURS, DAYSOFF
		};

#endif //HEADER_MAINWINDOW_TAB_TEAM
