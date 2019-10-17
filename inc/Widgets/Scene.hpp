/*!
*
*	\file		Scene.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		30 mai 2018
*
*/
#ifndef HEADER_SCENE
#define HEADER_SCENE

#include <QtWidgets>

#include <iostream>

/*!
* \class	Scene
* \brief	An implementation of QGraphcsScene with an updator
*/
class Scene : public QGraphicsScene {
	Q_OBJECT
	public:
		/*! \brief	Construct the QGraphicsScene */
		Scene(QObject* parent = nullptr);
		~Scene();

	public slots:
		/*!
		* \brief	A pure virtual method to redefine it in child classes
		* \return			void
		*/
		virtual void update() = 0;

	signals:

		
	protected:
		bool initialized;
	
	private:
		QTimer* updater;
};

#endif //HEADER_SCENE
