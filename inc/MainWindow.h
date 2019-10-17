#ifndef HEADER_MAINWINDOW
#define HEADER_MAINWINDOW

#include "Widgets/Qt.hpp"

/*!
* \class	MainWindow
* \brief	The main window of the software
*/
class MainWindow : public Window {
	/* Usefull or required defines */
		Q_OBJECT
	/* Members of Template */
	public:
		/* Internal enums of Template */
			
		/* Constructors & Destructor of Template */
			/*! \brief	The constructor of the class */
			MainWindow(QWidget* parent = nullptr);
			virtual ~MainWindow();
		/* Getters of Template */
			
		/* Setters of Template */
			
		/* Statics of Template */
			
		/* Operators of Template */
			
		/* Friends of Template */
			
		/* Others members of Template */
			

	public slots:
		

	signals:
		

	protected:
		/* Getters of Template */
			
		/* Setters of Template */
			
		/* Statics of Template */
			
		/* Friends of Template */
			
		/* Others members of Template */
			

	private:
		

	/* Atttributes of Template */
	public:
		/* Global */
			
		/* Local */
			

	protected:
		/* Global */
			
		/* Local */
			

	private:
		/* Global */
			
		/* Local */
			QVBoxLayout* centerLayout;
			QWidget* center;

			QTabWidget* _tab;
			QWidget* _generalTab;
			QWidget* _teamTab;
			QWidget* _planningTab;
};

#endif //HEADER_MAINWINDOW
