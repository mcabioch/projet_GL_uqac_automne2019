
#include "WindowButton.hpp"

WindowButton::WindowButton(ButtonType type, QWidget *parent) :
	QAbstractButton(parent),
	m_Type(type),
	m_State(STATE_NORMAL),
	m_Normal(nullptr),
	m_Hovered(nullptr),
	m_Clicked(nullptr)
{
	this->setGradient(0, 0, 0, 0, 0, 0, 0, 220);

	normalPen.setRgb(0, 0, 0);
	hoveredPen.setRgb(255, 255, 255);
	clickedPen.setRgb(255, 255, 255);
}

WindowButton::~WindowButton(){
	deletePtr(m_Normal);
	deletePtr(m_Hovered);
	deletePtr(m_Clicked);
}

void WindowButton::resizeEvent(QResizeEvent *event){
	Q_UNUSED(event);

	InitPixmaps();
}

void WindowButton::paintEvent(QPaintEvent *event){
	Q_UNUSED(event);

	QPainter painter(this);

	if(isEnabled()){
		switch(m_State){
			case STATE_NORMAL:
				if(m_Normal != nullptr){ painter.drawPixmap(0, 0, *m_Normal); }
				break;
			case STATE_HOVERED:
				if(m_Hovered != nullptr){ painter.drawPixmap(0, 0, *m_Hovered); }
				break;
			case STATE_CLICKED:
				if(m_Clicked != nullptr){ painter.drawPixmap(0, 0, *m_Clicked); }
				break;
		}
	} else {
		if(m_Normal != nullptr){ painter.drawPixmap(0, 0, *m_Normal); }
	}
}

void WindowButton::InitPixmaps(){
	// Delete previous button
	InitPixmap(&m_Normal);
	InitPixmap(&m_Hovered);
	InitPixmap(&m_Clicked);

	switch(m_Type){
		case BUTTON_MINIMIZE:
			InitMinimize();
			break;
		case BUTTON_MAXIMIZE:
			InitMaximize();
			break;
		case BUTTON_CLOSE:
			InitClose();
			break;
	}
}

void WindowButton::InitPixmap(QPixmap **pixmap){
	deletePtr(*pixmap);

	*pixmap = new QPixmap(size());
	(*pixmap)->fill(Qt::transparent);
}

void WindowButton::InitMinimize(){
	/********** Button's border **********/
	QPolygon border;

	border << QPoint(0, 4)
		   << QPoint(4, 0)
		   << QPoint(width() - 1, 0)
		   << QPoint(width() - 1, height() - 1)
		   << QPoint(0, height() - 1);
	/*************************************/

	/********** Button's symbol **********/
	QPolygon symbol;
	int mini{4}, maxi{8};

	symbol << QPoint(mini, height() - maxi)
		   << QPoint(width() - mini, height() - maxi)
		   << QPoint(width() - mini, height() - mini)
		   << QPoint(mini, height() - mini);
	/*************************************/

	QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
	linearGrad.setColorAt(0, gradientStart);
	linearGrad.setColorAt(1, gradientEnd);

	QLinearGradient invertlinearGrad(QPointF(0, 0), QPointF(0, height()));
	invertlinearGrad.setColorAt(0, gradientEnd);
	invertlinearGrad.setColorAt(1, gradientStart);

	QPainter painter;

	/********** Normal **********/
	painter.begin(m_Normal);

	painter.setPen(QPen(Qt::black));
	painter.setBrush(QBrush(linearGrad));

	painter.drawPolygon(border);

	painter.setPen(Qt::NoPen);
	painter.setBrush(QBrush(normalPen));

	painter.drawPolygon(symbol);

	painter.end();
	/****************************/

	/********** Hovered **********/
	painter.begin(m_Hovered);

	painter.setPen(QPen(Qt::black));
	painter.setBrush(QBrush(linearGrad));

	painter.drawPolygon(border);

	painter.setPen(Qt::NoPen);
	painter.setBrush(QBrush(hoveredPen));

	painter.drawPolygon(symbol);

	painter.end();
	/*****************************/

	/********** Clicked **********/
	painter.begin(m_Clicked);

	painter.setPen(QPen(Qt::black));
	painter.setBrush(QBrush(invertlinearGrad));

	painter.drawPolygon(border);

	painter.setPen(Qt::NoPen);
	painter.setBrush(QBrush(clickedPen));

	painter.drawPolygon(symbol);

	painter.end();
	/*****************************/
}

void WindowButton::InitMaximize(){
	/********** Button's border **********/
	QPolygon border;

	border << QPoint(0, 0)
		   << QPoint(width() - 5, 0)
		   << QPoint(width() - 1, 4)
		   << QPoint(width() - 1, height() - 1)
		   << QPoint(0, height() - 1);
	/*************************************/

	/********** Button's symbol **********/
	QPolygon symbol1, symbol2;
	int mini{4}, maxi{8};

	symbol1 << QPoint(mini, mini)
			<< QPoint(width() - mini, mini)
			<< QPoint(width() - mini, maxi)
			<< QPoint(mini, maxi);

	symbol2 << QPoint(mini, maxi)
			<< QPoint(width() - mini, maxi)
			<< QPoint(width() - mini, height() - mini)
			<< QPoint(mini, height() - mini);
	/*************************************/

	QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
	linearGrad.setColorAt(0, gradientStart);
	linearGrad.setColorAt(1, gradientEnd);

	QLinearGradient invertlinearGrad(QPointF(0, 0), QPointF(0, height()));
	invertlinearGrad.setColorAt(0, gradientEnd);
	invertlinearGrad.setColorAt(1, gradientStart);

	QPainter painter;

	/********** Normal **********/
	painter.begin(m_Normal);

	painter.setPen(QPen(Qt::black));
	painter.setBrush(QBrush(linearGrad));

	painter.drawPolygon(border);

	painter.setPen(QPen(normalPen));
	painter.setBrush(QBrush(normalPen));

	painter.drawPolygon(symbol1);

	painter.setPen(QPen(normalPen));
	painter.setBrush(Qt::NoBrush);

	painter.drawPolygon(symbol2);

	painter.end();
	/****************************/

	/********** Hovered **********/
	painter.begin(m_Hovered);

	painter.setPen(QPen(Qt::black));
	painter.setBrush(QBrush(linearGrad));

	painter.drawPolygon(border);

	painter.setPen(QPen(hoveredPen));
	painter.setBrush(QBrush(hoveredPen));

	painter.drawPolygon(symbol1);

	painter.setPen(QPen(hoveredPen));
	painter.setBrush(Qt::NoBrush);

	painter.drawPolygon(symbol2);

	painter.end();
	/*****************************/

	/********** Clicked **********/
	painter.begin(m_Clicked);

	painter.setPen(QPen(Qt::black ));
	painter.setBrush(QBrush(invertlinearGrad));

	painter.drawPolygon(border);

	painter.setPen(QPen(clickedPen));
	painter.setBrush(QBrush(clickedPen));

	painter.drawPolygon(symbol1);

	painter.setPen(QPen(clickedPen));
	painter.setBrush(Qt::NoBrush);

	painter.drawPolygon(symbol2);

	painter.end();
	/*****************************/
}

void WindowButton::InitClose(){
	/********** Button's border **********/
	QPolygon border;

	border << QPoint(0, 4)
		   << QPoint(4, 0)
		   << QPoint(width() - 5, 0)
		   << QPoint(width() - 1, 4)
		   << QPoint(width() - 1, height() - 5)
		   << QPoint(width() - 5, height() - 1)
		   << QPoint(4, height() - 1)
		   << QPoint(0, height() - 5);
	/*************************************/

	/********** Button's symbol **********/
	int mini{6}, maxi{7};
	QLine symbol1(QPoint(mini, mini), QPoint(width() - maxi, height() - maxi));
	QLine symbol2(QPoint(width() - maxi, mini), QPoint(mini, height() - maxi));
	/*************************************/

	QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
	linearGrad.setColorAt(0, gradientStart);
	linearGrad.setColorAt(1, gradientEnd);

	QLinearGradient invertlinearGrad(QPointF(0, 0), QPointF(0, height()));
	invertlinearGrad.setColorAt(0, gradientEnd);
	invertlinearGrad.setColorAt(1, gradientStart);

	QPainter painter;

	/********** Normal **********/
	painter.begin(m_Normal);

	painter.setPen(QPen(Qt::black));
	painter.setBrush(QBrush(linearGrad));

	painter.drawPolygon(border);

	painter.setPen(QPen(QBrush(normalPen), 2.0));

	painter.drawLine(symbol1);
	painter.drawLine(symbol2);

	painter.end();
	/****************************/

	/********** Hovered **********/
	painter.begin(m_Hovered);

	painter.setPen(QPen(Qt::black));
	painter.setBrush(QBrush(linearGrad));

	painter.drawPolygon(border);

	painter.setPen(QPen(QBrush(hoveredPen), 2.0));

	painter.drawLine(symbol1);
	painter.drawLine(symbol2);

	painter.end();
	/*****************************/

	/********** Clicked **********/
	painter.begin(m_Clicked);

	painter.setPen(QPen(Qt::black));
	painter.setBrush(QBrush(invertlinearGrad));

	painter.drawPolygon(border);

	painter.setPen(QPen(QBrush(clickedPen), 2.0));

	painter.drawLine(symbol1);
	painter.drawLine(symbol2);

	painter.end();
	/*****************************/
}

void WindowButton::setNormalColor(int r, int g, int b, int a){
	normalPen.setRgb(r, g, b, a);
}

void WindowButton::setHoveredColor(int r, int g, int b, int a){
	hoveredPen.setRgb(r, g, b, a);
}

void WindowButton::setClickedColor(int r, int g, int b, int a){
	clickedPen.setRgb(r, g, b, a);
}

void WindowButton::setBackground(int r, int g, int b, int a){
	this->setGradient(r, g, b, a, r, g, b, a);
}

void WindowButton::setGradient(int r1, int g1, int b1, int a1, int r2, int g2, int b2, int a2){
	gradientStart.setRgb(r1, g1, b1);
	gradientEnd.setRgb(r2, g2, b2);

	gradientStart.setAlpha(a1);
	gradientEnd.setAlpha(a2);

	InitPixmaps();
}

void WindowButton::enterEvent(QEvent *event){
	Q_UNUSED(event);

	m_State = STATE_HOVERED;
	update();
}

void WindowButton::leaveEvent(QEvent *event){
	Q_UNUSED(event);

	m_State = STATE_NORMAL;
	update();
}

void WindowButton::mousePressEvent(QMouseEvent *event){
	QAbstractButton::mousePressEvent(event);

	m_State = STATE_CLICKED;
	update();
}

void WindowButton::mouseReleaseEvent(QMouseEvent *event){
	QAbstractButton::mouseReleaseEvent(event);

	if(underMouse()){ m_State = STATE_HOVERED; }
	else{ m_State = STATE_NORMAL; }

	update();
}
