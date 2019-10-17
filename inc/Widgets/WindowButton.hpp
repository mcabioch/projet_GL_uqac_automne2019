/*!
* \file WindowButton.hpp
* \author Mathias CABIOCH-DELALANDE
* \date 07 juin 2018
*/
#ifndef HEADER_WINDOW_BUTTON
#define HEADER_WINDOW_BUTTON

#include <QtWidgets>

#include "QtDefines.hpp"

/*!
* \class WindowButton
* \brief The buttons for the WindowTitleBar and the Window
*/
class WindowButton : public QAbstractButton{
	Q_OBJECT
	public:
		/*! \brief The differents buttons type */
		enum ButtonType{
			BUTTON_MINIMIZE,
			BUTTON_MAXIMIZE,
			BUTTON_CLOSE
		};

		/*!
		* \brief The constructor
		*		\param[in]		type			The type of the button as \b ButtonType
		*		\param[in]		parent			The parent widget
		*/
		WindowButton(ButtonType type, QWidget *parent = nullptr);
		~WindowButton();

		/*! \brief Set the normal color of the button lines */
		void setNormalColor(int r, int g, int b, int a = 255);
		/*! \brief Set the hovered color of the button lines */
		void setHoveredColor(int r, int g, int b, int a = 255);
		/*! \brief Set the clicked color of the button lines */
		void setClickedColor(int r, int g, int b, int a = 255);

		/*! \brief Set the background color of the button */
		void setBackground(int r, int g, int b, int a = 255);

		/*! \brief Set the gradient background color of the button */
		void setGradient(int r1, int g1, int b1, int a1, int r2, int g2, int b2, int a2);

	protected:
		/*!
		* \brief The resize event of the button
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void resizeEvent(QResizeEvent *event);
		/*!
		* \brief The paint event of the button
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void paintEvent(QPaintEvent *event);

		/*!
		* \brief The enter event of the button
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void enterEvent(QEvent *event);
		/*!
		* \brief The leave event of the button
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void leaveEvent(QEvent *event);
		/*!
		* \brief The mouse press event of the button
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void mousePressEvent(QMouseEvent *event);
		/*!
		* \brief The mouse release event of the button
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void mouseReleaseEvent(QMouseEvent *event);

		/*! \brief The differents buttons states */
		enum ButtonState{
			STATE_NORMAL,
			STATE_HOVERED,
			STATE_CLICKED
		};

	private:
		ButtonType m_Type;
		ButtonState m_State;
		QPixmap *m_Normal;
		QPixmap *m_Hovered;
		QPixmap *m_Clicked;

		void InitPixmaps();
		void InitPixmap(QPixmap **pixmap);
		void InitMinimize();
		void InitMaximize();
		void InitClose();

		QColor gradientStart;
		QColor gradientEnd;

		QColor normalPen;
		QColor hoveredPen;
		QColor clickedPen;
};

#endif //HEADER_WINDOW_BUTTON
