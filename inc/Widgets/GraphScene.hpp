/*!
*
*	\file		GraphScene.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		10 juin 2018
*
*/
#ifndef HEADER_GRAPH_SCENE
#define HEADER_GRAPH_SCENE

#include <map>
#include <vector>
#include <utility>
#include <cmath>

#include "Scene.hpp"

/*! \brief	An alias to simplify the use of the type for the graph */
typedef long double GraphMapType;
/*! \brief	The array where the graphs' points are stored */
typedef std::map<GraphMapType, GraphMapType> GraphMap;
/*! \brief	A data type to simplify the draw of the differents graphs */
typedef std::pair<std::pair<GraphMapType, GraphMapType>, std::pair<GraphMapType, GraphMapType>> utmost;

/*!
* \class	GraphScene
* \brief	A Scene implementation to draw graphs
*/
class GraphScene : public Scene {
	Q_OBJECT
	public:
		/*! \brief	Construct the Scene */
		GraphScene(QObject* parent = nullptr);
		~GraphScene();

		/*!
		* \brief	Reinit the graphs
		* \return	void
		*/
		void reinit();

		/*!
		* \brief	Create a new graph with values
		*		\param[in]		ins				Values to add to a new graph
		*
		*		\return			void
		*/
		template<class T>
		void addGraph(std::map<T, T> ins){
			GraphMap out;
			
			for(auto in : ins){
				out[static_cast<GraphMapType>(in.first)] = static_cast<GraphMapType>(in.second);
			}
			
			graphs.push_back(out);
		}

		/*!
		* \brief	Create a new graph with a starting value
		*		\param[in]		in				Values to add to a new graph
		*
		*		\return			void
		*/
		template<class T>
		void addGraph(std::pair<T, T> in){
			GraphMap out;
			
			out[static_cast<GraphMapType>(in.first)] = static_cast<GraphMapType>(in.second);
			
			graphs.push_back(out);
		}

		/*!
		* \brief	Create a new graph with values
		*		\param[in]		ins				Values to add to a new graph
		*
		*		\return			void
		*/
		template<class T>
		void addGraph(std::vector<T> ins){
			GraphMap out;
			GraphMapType index = 0;
			
			for(auto in : ins){
				out[index++] = static_cast<GraphMapType>(in);
			}
			
			graphs.push_back(out);
		}

		/*!
		* \brief	Add values in
		*		\param[in]		index			The index of the graph to modify
		*		\param[in]		vals			The value to add in X/Y to the \a index graph
		*
		*		\return			\b true or \b false
		*/
		template<class T>
		bool addInGraph(size_t index, std::pair<T, T> vals){
			if(index >= graphs.size()){
				if(index == graphs.size() && index == 0){
					addGraph(vals);
					
					return true;
				} else {
					return false;
				}
			}
			
			graphs[index][static_cast<GraphMapType>(vals.first)] = static_cast<GraphMapType>(vals.second);
			
			return true;
		}

		/*!
		* \brief	Set the maximum of the X axis
		*		\param[in]		in				The value to set
		*
		*		\return			void
		*/
		template<class T>
		void setXMax(T in){
			xMax = static_cast<GraphMapType>(in);
		}

		/*!
		* \brief	set the minimum of the X axis
		*		\param[in]		in				The value to set
		*
		*		\return			void
		*/
		template<class T>
		void setXMin(T in){
			xMin = static_cast<GraphMapType>(in);
		}

		/*!
		* \brief	Set the step in the X axis
		*		\param[in]		in				The value to set
		*
		*		\return			void
		*/
		template<class T>
		void setXStep(T in){
			xStep = static_cast<GraphMapType>(in);
		}

		/*!
		* \brief	Set the boudaries for the X axis
		*		\param[in]		min				The minimum X value
		*		\param[in]		max				The maximum X value
		*
		*		\return			void
		*/
		template<class T>
		void setXRange(T min, T max){
			xMin = static_cast<GraphMapType>(min);
			xMax = static_cast<GraphMapType>(max);
		}

		/*!
		* \brief	Set the maximum of the Y axis
		*		\param[in]		in				The value to set
		*
		*		\return			void
		*/
		template<class T>
		void setYMax(T in){
			yMax = static_cast<GraphMapType>(in);
		}

		/*!
		* \brief	Set the minimum of the Y axis
		*		\param[in]		in				The value to set
		*
		*		\return			void
		*/
		template<class T>
		void setYMin(T in){
			yMin = static_cast<GraphMapType>(in);
		}

		/*!
		* \brief	Set the step in the Y axis
		*		\param[in]		in				The value to set
		*
		*		\return			void
		*/
		template<class T>
		void setYStep(T in){
			yStep = static_cast<GraphMapType>(in);
		}

		/*!
		* \brief	Set the boundaries in the Y axis
		*		\param[in]		min				The minimum Y value
		*		\param[in]		max				The maximum Y value
		*
		*		\return			void
		*/
		template<class T>
		void setYRange(T min, T max){
			yMin = static_cast<GraphMapType>(min);
			yMax = static_cast<GraphMapType>(max);
		}

		/*!
		* \brief	Set the distance between two points
		*		\param[in]		dist			The value to set
		*
		*		\return			void
		*/
		template<class T>
		void setPointsDist(T dist){
			pointsDist = (dist <= 0)?1:static_cast<GraphMapType>(dist);
		}

		/*! \brief	Return the number of graphs in the scene */
		size_t getNbGraphs(){ return graphs.size(); }

	public slots:
		/*!
		* \brief	Overload of the pur virtual parent method Scene::update()
		* \return			void
		*/
		void update();

	signals:


	private:
		utmost drawGraph(GraphMap graph, size_t index);

		GraphMapType transX(GraphMapType in){
			return in * pointsDist;
		}

		GraphMapType transY(GraphMapType in){
			return -1 * in * pointsDist;
		}

		GraphMapType minX(std::vector<utmost> ins);
		GraphMapType maxX(std::vector<utmost> ins);
		GraphMapType minY(std::vector<utmost> ins);
		GraphMapType maxY(std::vector<utmost> ins);

	private:
		std::vector<GraphMap> graphs;

		GraphMapType pointsDist;

		GraphMapType xMax;
		GraphMapType xMin;
		GraphMapType xStep;

		GraphMapType yMax;
		GraphMapType yMin;
		GraphMapType yStep;
};

#endif //HEADER_GRAPH_SCENE
