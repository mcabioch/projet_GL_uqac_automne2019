#include "String.hpp"

string::string() :
	std::string("")
{}
string::string(const char* str) :
	std::string(str)
{}
string::string(QString str) :
	std::string(str.toStdString())
{}
string::string(std::string str) :
	std::string(str)
{}

string& string::operator=(const QString& str){
	std::string::operator=(str.toStdString());
	return *this;
}
