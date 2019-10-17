#include "WindowTitleBar.hpp"

void WindowTitleBar::Minimized(){
	window()->showMinimized();
}

void WindowTitleBar::Maximized(){
	if(window()->windowState() == Qt::WindowMaximized){
		window()->showNormal();
	} else{
		window()->showMaximized();
	}
}

void WindowTitleBar::Quit(){
	qApp->quit();
}
