#include "WindowTitleBar.hpp"

void WindowTitleBar::drawTitleBar(QPainter& painter){
	QPolygon frame;

	frame << QPoint( 20,4)
		  << QPoint(width() - 4,4)
		  << QPoint(width() - 4, 32)
		  << QPoint(4, 32)
		  << QPoint(4, 20);

	painter.drawPolygon(frame);
}

void WindowTitleBar::drawButtonsArea(QPainter& painter){
	QPolygon buttons;

	buttons << QPoint(width() - 80, 4)
			<< QPoint(width() - 4, 4)
			<< QPoint(width() - 4, 32)
			<< QPoint(width() - 88, 32)
			<< QPoint(width() - 88, 12);

	painter.drawPolygon(buttons);
}
