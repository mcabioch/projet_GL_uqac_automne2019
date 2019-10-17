/*!
*
*	\file		TableWidget.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		09 juin 2018
*
*/
#ifndef HEADER_TABLE_WIDGET
#define HEADER_TABLE_WIDGET

#include <QtWidgets>
#include "Qt.hpp"

/*!
* \class	TableWidget
* \brief	Create a personnalized TableWidget
*/
class TableWidget : public Widget {
	Q_OBJECT
	public:
		/*! \brief	Create a QGridLayout */
		TableWidget(QWidget* parent = nullptr, size_t w = 0, size_t h = 0);
		~TableWidget();

		/*!
		* \brief	
		*		\param[in]		widget		The widget to add
		*		\return			void
		*/
		void addHeader(QWidget* widget);

		/*!
		* \brief	
		*		\param[in]		widget		The widget to add
		*		\param[in]		x			The x position on the top of the grid
		*		\return			void
		* \todo
		*/
		void addHeader(QWidget* widget, size_t x);

		/*!
		* \brief	
		*		\param[in]		widget		The widget to add
		*		\param[in]		x			The x position on the top of the grid
		*		\return			void
		* \todo
		*/
		void setHeader(QWidget* widget, size_t x);

		/*!
		* \brief	Add a widget to the table
		*		\param[in]		widget		The widget to add
		*		\return			void
		*/
		void add(QWidget* widget);
		/*!
		* \brief	Add a checkbox to the table
		*		\param[in]		widget		The checkbox to add
		*		\return			void
		*/
		void add(QCheckBox* widget);

		/*!
		* \brief	Put a widget at the position \a x/\a y
		*		\param[in]		widget		The widget to add
		*		\param[in]		x			The x position in the grid
		*		\param[in]		y			The y position in the grid
		*		\return			void
		* \todo
		*/
		void add(QWidget* widget, size_t x, size_t y);

		/*!
		* \brief	Replace a widget at the position \a x/\a y
		*		\param[in]		widget		The widget to add
		*		\param[in]		x			The x position in the grid
		*		\param[in]		y			The y position in the grid
		*		\return			void
		* \todo
		*/
		void set(QWidget* widget, size_t x, size_t y);

		/*! \brief	Return the grid layout address */
		TableWidget* get(size_t w = 0, size_t h = 0);

	public slots:
		

	signals:
		

	protected:
		/*! \brief Update the grid layout */
		void update();

	private:
		void nextCell();
		void deletions();

		bool isCheckbox(size_t index);

	private:
				QHBoxLayout* headerContent;
			Widget* headerContainer;
						QGridLayout* grid;
					QVBoxLayout* content;
				QWidget* container;
			QScrollArea* scroll;
		QVBoxLayout* center;

		std::vector<QWidget*> widgets;
		std::vector<QWidget*> headers;

		std::vector<size_t> checkboxs;
		std::vector<size_t> checkPerLine;

		size_t x;
		size_t y;

		size_t w;
		size_t h;
};

#endif //HEADER_TABLE_WIDGET
