#include "GeodeticExtent.h"

namespace Aurora
{
	namespace Math
	{
		namespace Globe
		{

			GeodeticExtent::GeodeticExtent()
			{

			}

			GeodeticExtent::GeodeticExtent(double west, double south, double east, double north)
			{

			}

			GeodeticExtent::GeodeticExtent(const Geodetic2D &bottomLeft, const Geodetic2D &topRight)
			{

			}

			GeodeticExtent::~GeodeticExtent()
			{

			}

			bool GeodeticExtent::Equals(const GeodeticExtent &other)
			{
				return true;

			}

			bool GeodeticExtent::operator==(const GeodeticExtent &right)
			{
				return true;
			}

			bool GeodeticExtent::operator!=(const GeodeticExtent &right)
			{
				return true;
			}

			int GeodeticExtent::GetHashCode()
			{
				return 0;
			}

		}
	}
}