#include "DrawScene.hpp"

DrawScene::DrawScene(QObject* parent) :
	Scene(parent),
	tileSize(64),
	printed_background(false)
{
	/* Variables */
		
	
	/* Initialisations */
		
		/* Textes */
			
	
		/* Timer */
			/*updater->start(20);
			connect(updater, SIGNAL(timeout()), this, SLOT(update()));*/
		
		/* Movies */
			
}

DrawScene::~DrawScene() {
	
}

void DrawScene::update(){
	if(!initialized){
		return;
	}
}

void DrawScene::setTilesize(int s){
	tileSize = s;
	
	for(auto& item : pixmaps){
		auto& pixmap = item.second;
		
		if(pixmap.width() < pixmap.height()){
			scaled_pixmaps[item.first] = pixmap.scaledToHeight(s);
		} else {
			scaled_pixmaps[item.first] = pixmap.scaledToWidth(s);
		}
	}
	
	printed_background = false;
}
