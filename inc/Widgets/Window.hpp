/*!
* \file Window.hpp
* \author Mathias CABIOCH-DELALANDE
* \date 08 juin 2018
*/
#ifndef HEADER_WINDOW
#define HEADER_WINDOW

#ifdef Q_WS_X11
	#include <QX11Info>
#endif

#include <QtWidgets>

#include "WindowTitleBar.hpp"

/*!
* \class Window
* \brief A custom window
*/
class Window : public Widget {
	Q_OBJECT
	public:
		/*!
		* \brief The constructor
		*		\param[in]		parent		The parent widget
		*/
		Window(QWidget* parent = nullptr);
		/*! \brief The destructor */
		~Window();

		/*!
		* \brief Set the window title
		*		\param[in]		title		The title
		*		\return			void
		*/
		void setWindowTitle(const QString &title);
		/*!
		* \brief Set the central widget
		*		\param[in]		widget		The central widget
		*		\return			void
		*/
		void setCentralWidget(QWidget* widget);
		/*!
		* \brief Set the window size
		*		\param[in]		w		The window width
		*		\param[in]		h		The window height
		*		\return			void
		*/
		void setSize(int w, int h);

		/*!
		* \brief Set the window margin
		*		\param[in]		m		The size of all the margins
		*		\return			void
		*/
		void setMargin(int m){ this->setMargin(m, m, m, m); }
		/*!
		* \brief Set the window margin
		*		\param[in]		t		The top margin
		*		\param[in]		r		The right margin
		*		\param[in]		b		The bottom margin
		*		\param[in]		l		The left margin
		*		\return			void
		*/
		void setMargin(int t, int r, int b, int l);

		/*!
		* \brief Call to fullscreen or unfullscreen the window
		*		\return			void
		*/
		void fullscreen();
		/*!
		* \brief Call to minimize the window
		*		\return			void
		*/
		void minimize();
		/*!
		* \brief Call to close the window
		*		\return			void
		*/
		void quit();

	protected:
		/*!
		* \brief The show event of the window
		*		\param[in]		event		The event sended
		*		\return			void
		*/
		void showEvent(QShowEvent* event);
		/*!
		* \brief The paint event of the window
		*		\param[in]		event		The event sended
		*		\return			void
		*/
		void paintEvent(QPaintEvent* event);
		/*!
		* \brief The resize event of the window
		*		\param[in]		event		The event sended
		*		\return			void
		*/
		void resizeEvent(QResizeEvent* event);

		/*!
		* \details The method to overload to draw a personnalized background
		*			The default content is { this->setBackground(); }
		* \brief Draw the background of the window
		*		\param[in]		cache		The pixmap to draw as the background
		*		\return			void
		*/
		virtual void drawBackground(QPixmap* cache);
		/*!
		* \brief Draw the default background of the window
		*		\param[in]		cache		The pixmap to draw the default background
		*		\return			void
		*/
		void drawDefaultBackground(QPixmap* cache);
		/*!
		* \brief Set the background window
		*		\param[in]		cache		The pixmap to draw as the background
		*		\return			void
		*/
		void setBackground(QPixmap* cache = nullptr);

		/*!
		* \brief Set if yes or no the window can be resized
		*		\param[in]		enable		\b true or \b false
		*		\return			void
		*/
		void enableResize(bool enable);
		/*!
		* \brief Set the titlebar visibility
		*		\param[in]		enable		\b true or \b false
		*		\return			void
		*/
		void showTitlebar(bool enable);

	signals:
		/*!
		* \brief Call when the window title is changed
		*		\param[in]		title		The title of the window
		*		\return			void
		*/
		void WindowTitleChanged(QString title);
		/*!
		* \brief Call when the window is resized
		*		\param[in]		state		The state resized or unresized
		*		\return			void
		*/
		void WindowResizeChanged(bool state);
		/*!
		* \brief Call when the state of the titlebar is changed show/hide
		*		\param[in]		state		The state visible or hidden
		*		\return			void
		*/
		void TitleBarShowState(bool state);

		/*!
		* \brief Call when the window as to be fullscreened or not
		*		\return			void
		*/
		void Fullscreen();
		/*!
		* \brief Call when the window has to be reduice or not
		*		\return			void
		*/
		void Reduice();
		/*!
		* \brief Call when the window has to be closed
		*		\return			void
		*/
		void Quit();

	private:
		/*! \brief Center the window on the screen */
		void CenterOnScreen();

		/*! \brief Set the transparency of the window for every version of Qt */
		void setTransparency();
		/*! \brief Use the transparency for every version of Qt */
		void useTransparency();

	protected:
		QPixmap* m_Cache;

	private:
		QGridLayout* m_MainLayout;
		WindowTitleBar* m_TitleBar;
		QSizeGrip* m_SizeGrip;

		QVBoxLayout* m_CenterLayout;
		QWidget* m_CenterWidget;

		bool transparent;
		bool enabledResize;
		bool isFullscreen;
};

#endif //HEADER_WINDOW
