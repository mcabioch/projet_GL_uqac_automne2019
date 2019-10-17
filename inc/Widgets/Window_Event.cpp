#include "Window.hpp"

void Window::showEvent(QShowEvent *event){
	Q_UNUSED(event);

	CenterOnScreen();
}

void Window::paintEvent(QPaintEvent *event){
	Q_UNUSED(event);
	
	if(m_Cache != nullptr){
		QPainter painter(this);

		painter.drawPixmap(0, 0, *m_Cache);
		this->useTransparency();
	}
}

void Window::resizeEvent(QResizeEvent *event){
	Q_UNUSED(event);

	deletePtr(m_Cache);

	m_Cache = new QPixmap(size());
	m_Cache->fill(Qt::transparent);

	this->drawBackground(m_Cache);

	m_SizeGrip->move(width() - 32, height() - 49);
	m_SizeGrip->resize(32, 32);
}
