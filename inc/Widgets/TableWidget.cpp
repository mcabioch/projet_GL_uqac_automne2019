#include "TableWidget.hpp"

TableWidget::TableWidget(QWidget* parent, size_t w, size_t h) :
	Widget(parent),
	headerContent(nullptr),
	headerContainer(nullptr),
	grid(nullptr),
	content(nullptr),
	container(nullptr),
	scroll(nullptr),
	center(nullptr),
	x(0),
	y(0),
	w(w),
	h(h)
{}

TableWidget::~TableWidget(){
	this->deletions();
}

void TableWidget::deletions(){
	deletePtr(headerContent);
	deletePtr(headerContainer);
	deletePtr(grid);
	deletePtr(content);
	deletePtr(container);
	deletePtr(scroll);
	deletePtr(center);
}

TableWidget* TableWidget::get(size_t w, size_t h){
	this->w = (w > 0)?w:this->w;
	this->h = (h > 0)?h:this->h;

	this->update();

	size_t lines = widgets.size() / headers.size();
	size_t widgetIndex = 0;

	int checkboxSize = 24;
	int margin = 2;

	for(size_t line{0}; line < lines; ++line){
		for(size_t i{0}; i < headers.size() && widgetIndex < widgets.size(); ++i, ++widgetIndex){
			auto& widget = widgets[widgetIndex];
			int newWidth = 0;

			if(this->isCheckbox(widgetIndex)){
				newWidth = checkboxSize * 3;
			} else {
				newWidth = this->w / (headers.size() - checkPerLine[line]);
				newWidth -= (headers.size() - 1) * margin;
				newWidth -= checkboxSize * checkPerLine[line];
			}

			if(this->w > 0){
				widget->setMaximumWidth(newWidth);
			}
		}
	}

	return this;
}

void TableWidget::nextCell(){
	x++;

	if(x >= headers.size()){
		x = 0;
		y++;
	}
}

void TableWidget::update(){
	headerContent = new QHBoxLayout;
	headerContainer = new Widget;
	grid = new QGridLayout;
	content = new QVBoxLayout;
	container = new QWidget;
	scroll = new QScrollArea;
	center = new QVBoxLayout;

	checkPerLine.clear();

	for(auto& widget : headers){
		headerContent->addWidget(widget);

		headerContent->addItem(new QHSpacerItem);
	}

	x = 0;
	y = 0;

	size_t line = 0;
	for(size_t i{0}; i < widgets.size(); ++i){
		auto& widget = widgets[i];

		grid->addWidget(widget, y, x);

		for(size_t j{0}; j < checkboxs.size(); ++j){
			if(i == checkboxs[j]){
				line++;
			}
		}

		this->nextCell();

		if(x == 0){
			checkPerLine.push_back(line);
			line = 0;
		}
	}

	checkPerLine.push_back(line);
	line = 0;

	content->addLayout(grid);

	container->setLayout(content);
	scroll->setWidget(container);

	if(w > 0){
		container->setMaximumWidth(w-5);
	}
	if(h > 0){
		container->setMaximumHeight(h-5);
	}

	scroll->setStyleSheet("QScrollArea { background-color: transparent; border: 0px solid white; }");
	scroll->setWidgetResizable(true);
	scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scroll->ensureVisible(0, 0, 0, 0);

	headerContainer->setLayout(headerContent);

	center->addWidget(headerContainer);
	center->addWidget(scroll);

	headerContainer->setContentsMargins(0, 0, 0, 0);
	grid->setContentsMargins(0, 0, 0, 0);
	content->setContentsMargins(0, 0, 0, 0);
	center->setContentsMargins(0, 0, 0, 0);

	this->setLayout(center);
}

void TableWidget::addHeader(QWidget* widget){
	headers.push_back(widget);
}

void TableWidget::addHeader(QWidget*, size_t){}

void TableWidget::setHeader(QWidget*, size_t){}

void TableWidget::add(QWidget* widget){
	widgets.push_back(widget);
}

void TableWidget::add(QCheckBox* widget){
	checkboxs.push_back(widgets.size());
	widgets.push_back(widget);
}

void TableWidget::add(QWidget*, size_t, size_t){}

void TableWidget::set(QWidget*, size_t, size_t){}

bool TableWidget::isCheckbox(size_t index){
	for(auto checkbox : checkboxs){
		if(checkbox == index){ return true; }
		if(checkbox > index){ return false; }
	}

	return false;
}
