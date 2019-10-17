#include "Window.hpp"

void Window::drawDefaultBackground(QPixmap* cache){
	QPainter painter(cache);

	QColor darkBlue( 23,  23, 34);
	QColor lightBlue(177, 177, 203);

	/********** Window's background **********/
		QPolygon background;

		background << QPoint(0, 16)
				   << QPoint(16, 0)
				   << QPoint(width() - 1, 0)
				   << QPoint(width() - 1, height() - 1)
				   << QPoint(width() - 17, height() - 1)
				   << QPoint(272, height() - 1)
				   << QPoint(256, height() - 1)
				   << QPoint(16, height() - 1)
				   << QPoint(16, 272)
				   << QPoint(0, 256);

		painter.setPen(QPen(darkBlue));
		painter.setBrush(QBrush(darkBlue));

		painter.drawPolygon(background);
	/*****************************************/

	/********** Window's frame **********/
		QPolygon frame;

		frame << QPoint(4, 20)
			  << QPoint(20, 4)
			  << QPoint(width() - 4, 4)
			  << QPoint(width() -  4, height() - 5)
			  << QPoint(width() - 20, height() - 5)
			  << QPoint(268, height() - 5)
			  << QPoint(252, height() - 5)
			  << QPoint(20, height() - 5)
			  << QPoint(20, 268)
			  << QPoint(4, 252);

		painter.setPen(QPen(lightBlue));
		painter.setBrush(Qt::NoBrush);

		painter.drawPolygon(frame);
	/*****************************************/
}

void Window::drawBackground(QPixmap*){
	this->setBackground();
}

void Window::setBackground(QPixmap* cache){
	if(cache == nullptr){
		this->drawDefaultBackground(m_Cache);
		return;
	}

	QPainter painter(m_Cache);
	painter.drawPixmap(0, 0, *cache);
}
