/*!
* \file WindowTitleBar.hpp
* \author Mathias CABIOCH-DELALANDE
* \date 08 juin 2018
*/
#ifndef HEADER_WINDOW_TITLEBAR
#define HEADER_WINDOW_TITLEBAR

#include <QtWidgets>

#include "WindowButton.hpp"

/*!
* \class WindowTitleBar
* \brief The titlebar of the Window class
*/
class WindowTitleBar : public Widget{
	Q_OBJECT
	public:
		/*!
		* \brief The constructor
		*		\param[in]		parent		The parent widget
		*/
		WindowTitleBar(QWidget* parent = nullptr);
		~WindowTitleBar();

	public slots:
		/*!
		* \brief Update the window's title
		*		\param[in]		title			The new title
		*		\return			void
		*/
		void UpdateWindowTitle(QString title);
		/*!
		* \brief Apply the resize state change
		*		\param[in]		state			The state to save and apply
		*		\return			void
		*/
		void ApplyResizeChange(bool state);
		/*!
		* \brief Show or hide the titlebar
		*		\param[in]		state			The state to save and apply
		*		\return			void
		*/
		void ApplyTitleBarState(bool state);

		/*! \brief Minimize the window */
		void Minimized();
		/*! \brief Maximize the window */
		void Maximized();
		/*! \brief Quit the application */
		void Quit();

	protected:
		/*!
		* \brief The resize event of the titlebar
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void resizeEvent(QResizeEvent* event);
		/*!
		* \brief The paint event of the titlebar
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void paintEvent(QPaintEvent* event);

		/*!
		* \brief The mouse press event of the titlebar
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void mousePressEvent(QMouseEvent* event);
		/*!
		* \brief The mouse release event of the titlebar
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void mouseReleaseEvent(QMouseEvent* event);
		/*!
		* \brief The mouse move event of the titlebar
		*		\param[in]		event			The event to treat
		*		\return			void
		*/
		void mouseMoveEvent(QMouseEvent* event);

		/*!
		* \brief Draw the titlebar
		*		\param[in]		painter			The painter for the titlebar
		*		\return			void
		*/
		void drawTitleBar(QPainter& painter);
		/*!
		* \brief Draw the buttons area
		*		\param[in]		painter			The painter for the buttons area
		*		\return			void
		*/
		void drawButtonsArea(QPainter& painter);

	private:
		QPixmap* m_Cache;
		QLabel m_Title;
		QPoint m_Diff;

		WindowButton m_Minimize;
		WindowButton m_Maximize;
		WindowButton m_Close;

		bool resized;
		bool titleBar;
};

#endif //HEADER_WINDOW_TITLEBAR
