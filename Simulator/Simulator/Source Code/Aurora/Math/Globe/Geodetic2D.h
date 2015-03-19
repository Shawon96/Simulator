#ifndef Geodetic2D_H
#define Geodetic2D_H
#include <functional>
#include <stdlib.h> 
#include <vector>
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
			class Geodetic2D
			{
			private:
				double longitude;
				double latitude;
				void init();
				void init(const Geodetic2D &value);
				void init(const Geodetic2D &&value);
			public:

				Geodetic2D();
				virtual ~Geodetic2D();
				Geodetic2D(const Geodetic2D &value);
				Geodetic2D(Geodetic2D &&value);
				Geodetic2D &operator=(Geodetic2D && value);
				Geodetic2D& operator=(const Geodetic2D& value);

				Geodetic2D(double longitude, double latitude);

				double Longitude() const {
					return longitude;
				}
				template<typename T>
				void Longitude(T &&value) {
					

					longitude = std::forward<T>(value);
				}

				double Latitude() const {
					return latitude;
				}
				template<typename T>
				void Latitude(T &&value) {
					

					latitude = std::forward<T>(value);
				}


				bool EqualsEpsilon(const Geodetic2D &value, double epsilon);

				bool Equals(const Geodetic2D &value);

				bool operator ==(const Geodetic2D		&value);

				bool operator !=(const Geodetic2D		&value);

				std::size_t GetHashCode();
			};

			using UniqueGeodetic2DVector = std::vector < std::unique_ptr<Geodetic2D> >;
		}
	}
}
#endif