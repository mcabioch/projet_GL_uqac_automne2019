/*!
*
*	\file		Font.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		05 juin 2018
*
*/
#ifndef HEADER_FONT
#define HEADER_FONT

#include <QtWidgets>

/*!
* \class Font
* \brief A class to treat fonts with QFont
*/
class Font {
	public:
		Font();
		~Font();

		/*!
		* \brief Load a font from a file
		*		\param[in]		path		The path of the file
		*		\return			Return a QFont of the font
		*/
		static QFont load(QString path);

	public slots:
		

	protected:
		

	signals:
		

	private:
		
};

#endif //HEADER_FONT
