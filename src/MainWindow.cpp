#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	Window(parent),
	centerLayout(nullptr),
	widget(nullptr),
	center(nullptr)
{
	/* Base */
		center = new QWidget;
		centerLayout = new QVBoxLayout;
		widget = new QWidget;

		this->setWindowTitle("QT 5.11 - Window");
		this->setCentralWidget(center);

		center->setLayout(centerLayout);

		this->enableResize(false);
	/********/
}

MainWindow::~MainWindow(){
	deletePtr(widget);

	deletePtr(centerLayout);
	deletePtr(center);
}
