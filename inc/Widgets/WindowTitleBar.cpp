#include "WindowTitleBar.hpp"

WindowTitleBar::WindowTitleBar(QWidget *parent) :
	Widget(parent),
	m_Cache(nullptr),
	m_Title(this),
	m_Minimize(WindowButton::BUTTON_MINIMIZE, this),
	m_Maximize(WindowButton::BUTTON_MAXIMIZE, this),
	m_Close(WindowButton::BUTTON_CLOSE, this),
	resized(true),
	titleBar(true)
{
	connect(&m_Minimize, SIGNAL(clicked()), this, SLOT(Minimized()));
	connect(&m_Maximize, SIGNAL(clicked()), this, SLOT(Maximized()));
	connect(&m_Close, SIGNAL(clicked()), this, SLOT(Quit()));

	this->setFixedHeight(33);
	this->setMinimumWidth(200);
	this->setWindowTitle("");

	m_Title.setStyleSheet("color: white; font-family: Sans; font-weight: bold; font-size: 14px");
}

WindowTitleBar::~WindowTitleBar(){

}

void WindowTitleBar::UpdateWindowTitle(QString title){
	m_Title.setText(title);
}

void WindowTitleBar::ApplyResizeChange(bool state){
	resized = state;
}

void WindowTitleBar::ApplyTitleBarState(bool state){
	titleBar = state;
}
