#include "GraphScene.hpp"

GraphScene::GraphScene(QObject* parent) :
	Scene(parent),
	pointsDist(1),
	xMax(10),
	xMin(-10),
	xStep(1),
	yMax(10),
	yMin(-10),
	yStep(1)
{
	/* Variables */
		
	
	/* Initialisations */
		initialized = true;
		/* Textes */
			
	
		/* Timer */
			
		
		/* Movies */
			
}

GraphScene::~GraphScene() {
	
}

void GraphScene::update(){
	if(!initialized){
		return;
	}
	
	size_t index = 0;
	std::vector<utmost> pointsVect;
	
	for(auto& graph : graphs){
		pointsVect.push_back(drawGraph(graph, index++));
	}
	
	QPen pen(Qt::black, 1, Qt::SolidLine);
	QLineF xAxis(transX(minX(pointsVect)), transY(0), transX(maxX(pointsVect)), transY(0));
	QLineF yAxis(transX(0), transY(minY(pointsVect)), transX(0), transY(maxY(pointsVect)));
	
	addLine(xAxis, pen);
	addLine(yAxis, pen);
}

utmost GraphScene::drawGraph(GraphMap graph, size_t index){
	if(graph.size() < 2){
		return std::make_pair(std::make_pair(0, 0), std::make_pair(0, 0));
	}
	
	GraphMapType xa = 0;
	GraphMapType ya = 0;
	
	GraphMapType xb = 0;
	GraphMapType yb = 0;
	
	auto it = graph.begin();
	
	xa = it->first;
	ya = it->second;
	++it;
	
	GraphMapType x = xa;
	GraphMapType miny = 99999;
	GraphMapType maxy = 0;
	
	for(; it != graph.end(); ++it){
		xb = it->first;
		yb = it->second;
		
		QPen pen(Qt::black, 1, Qt::SolidLine);
		
		switch(index){
			case 0:
				pen.setBrush(Qt::blue);
				break;
			case 1:
				pen.setBrush(Qt::cyan);
				break;
			case 2:
				pen.setBrush(Qt::darkBlue);
				break;
			case 3:
				pen.setBrush(Qt::darkGreen);
				break;
			case 4:
				pen.setBrush(Qt::darkMagenta);
				break;
			case 5:
				pen.setBrush(Qt::darkRed);
				break;
			case 6:
				pen.setBrush(Qt::darkYellow);
				break;
			case 7:
				pen.setBrush(Qt::green);
				break;
			case 8:
				pen.setBrush(Qt::yellow);
				break;
			case 9:
				pen.setBrush(Qt::red);
				break;
			case 10:
				pen.setBrush(Qt::magenta);
				break;
			case 11:
				pen.setBrush(Qt::darkCyan);
				break;
		}
		
		QLineF line(transX(xa), transY(ya), transX(xb), transY(yb));
		
		addLine(line, pen);
		
		xa = xb;
		ya = yb;
		
		miny = std::min(miny, yb);
		maxy = std::max(maxy, yb);
	}
	
	return std::make_pair(std::make_pair(x, miny), std::make_pair(xb, maxy));
}

GraphMapType GraphScene::minX(std::vector<utmost> ins){
	GraphMapType out = 99999;
	
	for(auto& in : ins){
		out = std::min(out, in.first.first);
	}
	
	return out;
}

GraphMapType GraphScene::maxX(std::vector<utmost> ins){
	GraphMapType out = 0;
	
	for(auto& in : ins){
		out = std::max(out, in.second.first);
	}
	
	return out;
}

GraphMapType GraphScene::minY(std::vector<utmost> ins){
	GraphMapType out = 99999;
	
	for(auto& in : ins){
		out = std::min(out, in.first.second);
	}
	
	return out;
}

GraphMapType GraphScene::maxY(std::vector<utmost> ins){
	GraphMapType out = 0;
	
	for(auto& in : ins){
		out = std::max(out, in.second.second);
	}
	
	return out;
}

void GraphScene::reinit(){
	graphs.clear();
}
