#include "Widget.hpp"

void Widget::paintEvent(QPaintEvent*){
	QStyleOption opt;
	QPainter p(this);

	opt.init(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
