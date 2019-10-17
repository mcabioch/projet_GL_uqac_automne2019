/*!
*
*	\file		DrawScene.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		30 mai 2018
*
*/
#ifndef HEADER_DRAW_SCENE
#define HEADER_DRAW_SCENE

#include "Scene.hpp"

/*!
* \class	DrawScene
* \brief	A Scene implementation to draw with tiles system
*/
class DrawScene : public Scene {
	Q_OBJECT
	public:
		/*! \brief	Create the DrawScene */
		DrawScene(QObject* parent = nullptr);
		~DrawScene();

		/*!
		* \brief	Set the tiles' size
		*		\param[in]		s		The value to set
		*
		*		\return			void
		*/
		void setTilesize(int s);

	public slots:
		/*!
		* \brief	Overload of the pur virtual parent method Scene::update()
		* \return			void
		*/
		void update();

	signals:

		
	protected:
		int tileSize;
		bool printed_background;

		std::map<std::string, QPixmap> pixmaps;
		std::map<std::string, QPixmap> scaled_pixmaps;
	
	private:

};

#endif //HEADER_DRAW_SCENE
