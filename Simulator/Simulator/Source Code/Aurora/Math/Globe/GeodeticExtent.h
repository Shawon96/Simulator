#ifndef GeodeticExtent_H
#define GeodeticExtent_H

#include <functional>
#include <stdlib.h> 
#include "Geodetic2D.h"

namespace Aurora
{
	namespace Math
	{
		namespace Globe
		{
			class GeodeticExtent
			{
				private:
					double west;
					double south;
					double east;
					double north;

				public:
					GeodeticExtent();
					GeodeticExtent(double west, double south, double east, double north);
					GeodeticExtent(const Geodetic2D &bottomLeft, const Geodetic2D &topRight);
					virtual ~GeodeticExtent();
					bool Equals(const GeodeticExtent &other);

					bool operator==(const GeodeticExtent &right);
					bool operator!=(const GeodeticExtent &right);
					int GetHashCode();
			};
		}
	}
}

#endif