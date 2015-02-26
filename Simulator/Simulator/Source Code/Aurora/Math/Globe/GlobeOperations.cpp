#include "GlobeOperations.h"

namespace Aurora
{
	namespace Math
	{
		namespace Globe
		{

			std::shared_ptr<Geodetic3D> GlobeOperations::CreateGeodetic3DFromGeodetic2D(const Geodetic2D &value)
			{
				return(std::make_shared<Geodetic3D>(value.Longitude(), value.Latitude()));
			}

			std::shared_ptr<Geodetic2D> GlobeOperations::CreateGeodetic2DFromGeodetic3D(const Geodetic3D &value)
			{
				return(std::make_shared<Geodetic2D>(value.Longitude(), value.Latitude()));
			}

			std::shared_ptr<Geodetic3D> GlobeOperations::CreateGeodetic3DFromGeodetic2DWithHeight(const Geodetic2D &value, const double &height)
			{
				return(std::make_shared<Geodetic3D>(value.Longitude(), value.Latitude(), height));
			}
		}
	}
}