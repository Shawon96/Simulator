#ifndef Geodetic3D_H
#define Geodetic3D_H

#include <functional>
#include <stdlib.h> 
#include <vector>
#include <memory>
#include "Geodetic2D.h"

namespace Aurora
{
	namespace Math
	{
		namespace Globe
		{
			class Geodetic3D
			{
			private:
				double longitude;
				double latitude;
				double height;

				void init();
				void init(const Geodetic3D &value);
				void init(const Geodetic3D &&value);
			public:

				Geodetic3D();
				virtual ~Geodetic3D();
				Geodetic3D(const Geodetic3D &value);
				Geodetic3D(Geodetic3D &&value);
				Geodetic3D &operator=(Geodetic3D && value);
				Geodetic3D& operator=(const Geodetic3D& value);
				Geodetic3D(const Geodetic2D &geodetic2D, double height);

				Geodetic3D(double longitude, double latitude);
				Geodetic3D(double longitude, double latitude, double height);
				

				

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

				double Height() const {
					return height;
				}
				template<typename T>
				void Height(T &&value) {
					

					height = std::forward<T>(value);
				}


				bool Equals(const Geodetic3D &value);

				bool operator ==(const Geodetic3D		&value);

				bool operator !=(const Geodetic3D		&value);

				std::size_t GetHashCode();
			};
			using UniqueGeodetic3D = std::unique_ptr<Geodetic3D>;
			using UniqueGeodetic3DVector = std::vector < UniqueGeodetic3D >;

		}
	}
}
#endif