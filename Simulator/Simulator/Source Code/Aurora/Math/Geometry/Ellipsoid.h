#ifndef GeometryOperations_Ellipsoid_H
#define GeometryOperations_Ellipsoid_H

#include <functional>
#include <stdlib.h> 
#include <vector>
#include <memory>
#include "../Vectors/Vector3D.h"
#include "../Globe/GlobeOperations.h"
#include "../../Errors/ErrorOperations.h"

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
				Ellipsoid();
				Ellipsoid(double x, double y, double z);
				Ellipsoid(const Vector3DDouble &radii);
				virtual ~Ellipsoid();
				Ellipsoid(const Ellipsoid &value);
				Ellipsoid(Ellipsoid &&value);
				Ellipsoid &operator=(Ellipsoid && value);
				Ellipsoid& operator=(const Ellipsoid& value);

				



				static Vector3DDouble CentricSurfaceNormal(const Vector3DDouble &positionOnEllipsoid);
				Vector3DDouble GeodeticSurfaceNormal(const Vector3DDouble &positionOnEllipsoid);
				Vector3DDouble GeodeticSurfaceNormal(const Geodetic3D &geodetic);
				double MinimumRadius();
				double MaximumRadius();
				UniqueDoubleVector Intersections(const Vector3DDouble &origin, Vector3DDouble &direction);
				Vector3DDouble ToVector3D(const Geodetic2D &geodetic);
				Vector3DDouble ToVector3D(const Geodetic3D &geodetic);
				UniqueGeodetic3DVector ToGeodetic3D(const UniqueVector3DDoubleVector &positions);
				UniqueGeodetic2DVector ToGeodetic2D(const UniqueVector3DDoubleVector &positions);
				Geodetic2D ToGeodetic2D(const Vector3DDouble &positionOnEllipsoid);
				Geodetic3D ToGeodetic3D(const Vector3DDouble &position);
				Vector3DDouble ScaleToGeodeticSurface(const Vector3DDouble &position);
				Vector3DDouble ScaleToGeocentricSurface(const Vector3DDouble &position);
				UniqueVector3DDoubleVector ComputeCurve(const Vector3DDouble &start, const Vector3DDouble &stop, const double &granularity);

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
			};

		};
	};
};

#endif