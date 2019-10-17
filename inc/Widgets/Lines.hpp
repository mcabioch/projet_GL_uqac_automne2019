/*!
*
*	\file		Lines.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		08 septembrre 2019
*
*/
#ifndef HEADER_QLINE
#define HEADER_QLINE

#include <QtWidgets>

/*!
* \class	Line
* \brief	Create a line
*/
class Line : public QFrame {
	Q_OBJECT
	public:
		/*! \brief	Create a Line */
		Line(QWidget* parent, QFrame::Shape shape);
		virtual ~Line(){}
};

/*!
* \class	HLine
* \brief	Create a horizontal line
*/
class HLine : public Line {
	Q_OBJECT
	public:
		/*! \brief	Create a HLine */
		HLine(QWidget* parent = nullptr) : Line(parent, QFrame::HLine) {}
		virtual ~HLine(){}
};

/*!
* \class	VLine
* \brief	Create a line
*/
class VLine : public Line {
	Q_OBJECT
	public:
		/*! \brief	Create a VLine */
		VLine(QWidget* parent = nullptr) : Line(parent, QFrame::VLine) {}
		virtual ~VLine(){}
};

#endif //HEADER_QLINE
