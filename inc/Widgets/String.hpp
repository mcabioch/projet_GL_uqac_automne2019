/*!
*
*	\file		String.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Monday March, 25 2019 15:47:50
*	\modified	Monday March, 25 2019
*
*/
#ifndef HEADER_STRING
#define HEADER_STRING

#include "Widgets/Qt.hpp"

class string : public std::string {
	public:
		string();
		string(const char* str);
		string(QString str);
		string(std::string str);

		string& operator=(const QString& str);
};

#endif //HEADER_STRING
