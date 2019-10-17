#include "Font.hpp"

Font::Font(){
	
}

Font::~Font(){
	
}

QFont Font::load(QString path){
	int id = QFontDatabase::addApplicationFont(path);
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont font(family);

	return font;
}
