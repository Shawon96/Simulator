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

					double West() const {
						return west;
					}
					template<typename T>
					void West(T &&value) {
						

						west = std::forward<T>(value);
					}

					double South() const {
						return south;
					}
					template<typename T>
					void South(T &&value) {
						

						south = std::forward<T>(value);
					}

					double East() const {
						return east;
					}
					template<typename T>
					void East(T &&value) {
						

						east = std::forward<T>(value);
					}

					double North() const {
						return north;
					}
					template<typename T>
					void North(T &&value) {
						

						north = std::forward<T>(value);
					}
			};
		}
	}
}

#endif