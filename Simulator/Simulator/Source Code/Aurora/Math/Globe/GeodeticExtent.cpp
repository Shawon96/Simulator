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
				west = west;
				south = south;
				east = east;
				north = north;
			}

			GeodeticExtent::GeodeticExtent(const Geodetic2D &bottomLeft, const Geodetic2D &topRight)
			{
				west = bottomLeft.Longitude();
				south = bottomLeft.Latitude();
				east = topRight.Longitude();
				north = topRight.Latitude();
			}

			GeodeticExtent::~GeodeticExtent()
			{

			}

			bool GeodeticExtent::Equals(const GeodeticExtent &other)
			{
				return west == other.west && south == other.south && east == other.east && north == other.north;
			}

			bool GeodeticExtent::operator==(const GeodeticExtent &right)
			{
				return this->Equals(right);
			}

			bool GeodeticExtent::operator!=(const GeodeticExtent &right)
			{
				return !this->Equals(right);
			}

			int GeodeticExtent::GetHashCode()
			{
				std::hash<double> doubleHash;
				return doubleHash(this->west) ^ doubleHash(this->east) ^ doubleHash(this->north) ^ doubleHash(this->south);
			}

		}
	}
}