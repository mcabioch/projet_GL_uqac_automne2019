#include "Scene.hpp"

Scene::Scene(QObject* parent) :
	QGraphicsScene(parent),
	initialized(false)
{
	/* Variables */
		updater = new QTimer(this);
	
	/* Initialisations */
	
		/* Textes */
			
	
		/* Timer */
			updater->start(20);
			connect(updater, SIGNAL(timeout()), this, SLOT(update()));
		
		/* Movies */
			
}

Scene::~Scene() {
	
}
