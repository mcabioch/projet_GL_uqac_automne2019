#ifndef HEADER_MAINWINDOW_TAB_PLANNING
#define HEADER_MAINWINDOW_TAB_PLANNING


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
	

signals:
	

protected:
	/* Getters of MainWindow */
		
	/* Setters of MainWindow */
		
	/* Statics of MainWindow */
		
	/* Friends of MainWindow */
		
	/* Others members of MainWindow */
		

private:
	void initPlanningTab(QTabWidget* tabWidget);
	void resetPlanningTab(QTabWidget* tabWidget);
	void deletePlanningTab(QTabWidget* tabWidget);

/* Atttributes of MainWindow */
public:
	/* Global */
		
	/* Local */
		

protected:
	/* Global */
		
	/* Local */
		Globals _globals;
		std::vector<TeamMember> _teamMembers;

private:
	/* Global */
		
	/* Local */
		QWidget* _planningTab;
		QVBoxLayout* _planningLay;

#endif //HEADER_MAINWINDOW_TAB_PLANNING
