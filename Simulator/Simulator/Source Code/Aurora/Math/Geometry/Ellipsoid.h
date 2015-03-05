#ifndef Ellipsoid_H
#define Ellipsoid_H

#include <functional>
#include <stdlib.h> 
#include "../Vector3D.h"
#include "../Globe/GlobeOperations.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			using namespace Aurora::Math;
			using namespace Aurora::Math::Globe;
			class Ellipsoid
			{
				private:
					Vector3D<double> radii;
					Vector3D<double> radiiSquared;					
					Vector3D<double> radiiToTheFourth;
					Vector3D<double> oneOverRadiiSquared;
			public:
				static Ellipsoid Wgs84;
				static Ellipsoid ScaledWgs84;
				static Ellipsoid UnitSphere;

					Vector3D<double> Radii() const {
						return radii;
					}
					template<typename T>
					void Radii(T &&value) {
						static_assert(!is_same<objectPhysics, T>::value, Aurora::Errors::ErrorMessages::TypeMismatch.c_str());

						radii = std::forward<T>(value);
					}

					Vector3D<double> RadiiSquared() const {
						return radiiSquared;
					}
					template<typename T>
					void RadiiSquared(T &&value) {
						static_assert(!is_same<objectPhysics, T>::value, Aurora::Errors::ErrorMessages::TypeMismatch.c_str());

						radiiSquared = std::forward<T>(value);
					}

					Vector3D<double> RadiiToTheFourth() const {
						return radiiToTheFourth;
					}
					template<typename T>
					void RadiiToTheFourth(T &&value) {
						static_assert(!is_same<objectPhysics, T>::value, Aurora::Errors::ErrorMessages::TypeMismatch.c_str());

						radiiToTheFourth = std::forward<T>(value);
					}

					Vector3D<double> OneOverRadiiSquared() const {
						return oneOverRadiiSquared;
					}
					template<typename T>
					void OneOverRadiiSquared(T &&value) {
						static_assert(!is_same<objectPhysics, T>::value, Aurora::Errors::ErrorMessages::TypeMismatch.c_str());

						oneOverRadiiSquared = std::forward<T>(value);
					}

					Ellipsoid();
					Ellipsoid(double x, double y, double z);
					Ellipsoid(const Vector3D<double> &radii);
					~Ellipsoid();
					Ellipsoid(const Ellipsoid &value);
					Ellipsoid(Ellipsoid &&value);
					Ellipsoid &operator=(Ellipsoid && value);
					Ellipsoid& operator=(const Ellipsoid& value);

					static Vector3D<double> CentricSurfaceNormal(const Vector3D<double> &positionOnEllipsoid);
					Vector3D<double> GeodeticSurfaceNormal(const Vector3D<double> &positionOnEllipsoid);
					Vector3D<double> GeodeticSurfaceNormal(const Geodetic3D &geodetic);
					double MinimumRadius();
					double MaximumRadius();
					std::vector<double> Intersections(const Vector3D<double> &origin, Vector3D<double> &direction);
					Vector3D<double> ToVector3D(const Geodetic2D &geodetic);
					Vector3D<double> ToVector3D(const Geodetic3D &geodetic);
					std::vector<Geodetic3D> ToGeodetic3D(const std::vector<Vector3D<double>> &positions);
					std::vector<Geodetic2D> ToGeodetic2D(const std::vector<Vector3D<double>> &positions);
					Geodetic2D ToGeodetic2D(const Vector3D<double> &positionOnEllipsoid);
					Geodetic3D ToGeodetic3D(const Vector3D<double> &position);
					Vector3D<double> ScaleToGeodeticSurface(const Vector3D<double> &position);
					Vector3D<double> ScaleToGeocentricSurface(const Vector3D<double> &position);
					std::vector<Vector3D<double>> ComputeCurve(const Vector3D<double> &start, const Vector3D<double> &stop, const double &granularity);
			};
		}
	}
}

#endif