#ifndef GlobeOperations_H
#define GlobeOperations_H

#include "Trig.h"
#include <memory>

/*!
Namespace: Aurora

This namespace is the main package for the engine. It holds all the main classes, namespaces, operations etc... that defines the functionality of this
project/engine.
*/
namespace Aurora
{
	/*!
	Namespace: Math

	This namespace holds needed math operations for the engine.
	*/
	namespace Math
	{
		namespace Globe
		{
			class GlobeOperations
			{
			public:
				static std::shared_ptr<Geodetic3D> CreateGeodetic3DFromGeodetic2D(const Geodetic2D &value);
				static std::shared_ptr<Geodetic3D> CreateGeodetic3DFromGeodetic2DWithHeight(const Geodetic2D &value, const double &height);
				static std::shared_ptr<Geodetic2D> CreateGeodetic2DFromGeodetic3D(const Geodetic3D &value);
			};
		}
	}
}

#endif