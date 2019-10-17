#include "Lines.hpp"

Line::Line(QWidget* parent, QFrame::Shape shape) :
	QFrame(parent)
{
	this->setFrameShadow(QFrame::Sunken);
	this->setFrameShape(shape);
}
