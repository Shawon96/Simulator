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
					Vector3DDouble radii;
					Vector3DDouble radiiSquared;					
					Vector3DDouble radiiToTheFourth;
					Vector3DDouble oneOverRadiiSquared;
			public:
				static Ellipsoid Wgs84;
				static Ellipsoid ScaledWgs84;
				static Ellipsoid UnitSphere;

					Vector3DDouble Radii() const {
						return radii;
					}
					template<typename T>
					void Radii(T &&value) {
						

						radii = std::forward<T>(value);
					}

					Vector3DDouble RadiiSquared() const {
						return radiiSquared;
					}
					template<typename T>
					void RadiiSquared(T &&value) {
						

						radiiSquared = std::forward<T>(value);
					}

					Vector3DDouble RadiiToTheFourth() const {
						return radiiToTheFourth;
					}
					template<typename T>
					void RadiiToTheFourth(T &&value) {
						

						radiiToTheFourth = std::forward<T>(value);
					}

					Vector3DDouble OneOverRadiiSquared() const {
						return oneOverRadiiSquared;
					}
					template<typename T>
					void OneOverRadiiSquared(T &&value) {
						

						oneOverRadiiSquared = std::forward<T>(value);
					}

					Ellipsoid();
					Ellipsoid(double x, double y, double z);
					Ellipsoid(const Vector3DDouble &radii);
					~Ellipsoid();
					Ellipsoid(const Ellipsoid &value);
					Ellipsoid(Ellipsoid &&value);
					Ellipsoid &operator=(Ellipsoid && value);
					Ellipsoid& operator=(const Ellipsoid& value);

					static Vector3DDouble CentricSurfaceNormal(const Vector3DDouble &positionOnEllipsoid);
					Vector3DDouble GeodeticSurfaceNormal(const Vector3DDouble &positionOnEllipsoid);
					Vector3DDouble GeodeticSurfaceNormal(const Geodetic3D &geodetic);
					double MinimumRadius();
					double MaximumRadius();
					std::vector<double> Intersections(const Vector3DDouble &origin, Vector3DDouble &direction);
					Vector3DDouble ToVector3D(const Geodetic2D &geodetic);
					Vector3DDouble ToVector3D(const Geodetic3D &geodetic);
					std::vector<Geodetic3D> ToGeodetic3D(const std::vector<Vector3DDouble> &positions);
					std::vector<Geodetic2D> ToGeodetic2D(const std::vector<Vector3DDouble> &positions);
					Geodetic2D ToGeodetic2D(const Vector3DDouble &positionOnEllipsoid);
					Geodetic3D ToGeodetic3D(const Vector3DDouble &position);
					Vector3DDouble ScaleToGeodeticSurface(const Vector3DDouble &position);
					Vector3DDouble ScaleToGeocentricSurface(const Vector3DDouble &position);
					std::vector<Vector3DDouble> ComputeCurve(const Vector3DDouble &start, const Vector3DDouble &stop, const double &granularity);
			};
		}
	}
}

#endif