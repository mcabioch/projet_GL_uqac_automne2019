#include "WindowTitleBar.hpp"

void WindowTitleBar::resizeEvent(QResizeEvent* event){
	Q_UNUSED(event);

	deletePtr(m_Cache);

	m_Cache = new QPixmap(size());

	m_Cache->fill(Qt::transparent);

	int buttonSize = 20;
	int titleMarginTop = 4;
	int marginTop = height()/2.0 - buttonSize/2.0 + titleMarginTop/2.0;

	if(titleBar){
		QPainter painter(m_Cache);

		QColor lightBlue(177, 177, 203, 255);
		QColor gradientStart(0, 0, 0, 0);
		QColor gradientEnd(0, 0, 0, 220);

		QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
		linearGrad.setColorAt(0, gradientStart);
		linearGrad.setColorAt(1, gradientEnd);

		painter.setPen(QPen(lightBlue));
		painter.setBrush(QBrush(linearGrad));
		this->drawTitleBar(painter);

		painter.setPen(QPen(lightBlue));
		painter.setBrush(QBrush(lightBlue));
		this->drawButtonsArea(painter);

		m_Title.move(buttonSize, titleMarginTop);
		m_Title.resize(width() - 116, 29);
	} else {
		m_Title.setText("");
	}

	if(resized && titleBar){
		m_Minimize.move(width() - buttonSize*4, marginTop);
		m_Maximize.move(width() - buttonSize*3, marginTop);
	} else {
		m_Minimize.move(-1*  buttonSize*4, marginTop);
		m_Maximize.move(-1*  buttonSize*4, marginTop);
	}

	if(titleBar){
		m_Close.move(width() - (buttonSize+5), marginTop);
	} else {
		m_Close.move(-1*  buttonSize*4, marginTop);
	}

	m_Minimize.resize(buttonSize, buttonSize);
	m_Maximize.resize(buttonSize, buttonSize);
	m_Close.resize(buttonSize, buttonSize);
}

void WindowTitleBar::paintEvent(QPaintEvent* event){
	Q_UNUSED(event);

	if(m_Cache != nullptr){
		QPainter painter(this);

		painter.drawPixmap(0, 0,* m_Cache);
	}
}

void WindowTitleBar::mousePressEvent(QMouseEvent* event){
	m_Diff = event->pos();

	setCursor(QCursor(Qt::SizeAllCursor));
}

void WindowTitleBar::mouseReleaseEvent(QMouseEvent* event){
	Q_UNUSED(event);

	setCursor(QCursor(Qt::ArrowCursor));
}

void WindowTitleBar::mouseMoveEvent(QMouseEvent* event){
	QPoint p = event->globalPos();

	window()->move(p - m_Diff);
}
