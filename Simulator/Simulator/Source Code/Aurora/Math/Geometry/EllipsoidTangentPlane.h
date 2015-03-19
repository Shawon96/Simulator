#ifndef GeometryOperations_Edge_H
#define GeometryOperations_Edge_H
#include <functional>
#include <stdlib.h> 
#include "..\..\Globals\GlobalDatatypes.h"
#include "Ellipsoid.h"
#include "../Vectors/Vector3D.h"
#include "../BoundingVolumes/AxisAlignedBoundingBox.h"
#include "../CollisionDetection/CollisionDetectionOperations.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			using namespace Aurora::DataTypes;
			using namespace Aurora::Math;
			using namespace Aurora::Math::BoundingVolumes;
			using namespace Aurora::Math::CollisionDetection;

			class EllipsoidTangentPlane
			{
			private:
				Vector3DDouble origin;
				Vector3DDouble normal;
				double d;
				Vector3DDouble xAxis;
				Vector3DDouble yAxis;
			public:
				Vector3DDouble Origin() const {
					return origin;
				}
				Vector3DDouble Normal() const {
					return normal;
				}
				double D() const {
					return d;
				}
				Vector3DDouble Axis() const {
					return xAxis;
				}
				Vector3DDouble Axis() const {
					return yAxis;
				}

				EllipsoidTangentPlane(Ellipsoid &ellipsoid, const UniqueVector3DDoubleVector &positions)
				{
					/*if (ellipsoid == nullptr)
					{
					throw new ArgumentNullException("ellipsoid");
					}

					if (positions == nullptr)
					{
					throw new ArgumentNullException("positions");
					}*/

					if (positions.size() < 1)
					{
						throw std::bad_function_call("positions: At least one position is required.");
					}

					AxisAlignedBoundingBox box(positions);

					origin = ellipsoid.ScaleToGeodeticSurface(box.Center());
					normal = ellipsoid.GeodeticSurfaceNormal(origin);
					d = -origin.Dot(origin);
					yAxis = origin.Cross(origin.MostOrthogonalAxis()).Normalize();
					xAxis = yAxis.Cross(origin).Normalize();
				}

				std::shared_ptr<UniqueVector2DDoubleVector> ComputePositionsOnPlane(const UniqueVector3DDoubleVector &positions)
				{
					/*if (positions == null)
					{
						throw new ArgumentNullException("positions");
					}*/

					std::shared_ptr<std::vector < Vector2DDouble>> positionsOnPlane = std::make_shared<std::vector < Vector2DDouble>>();
					//TODO: Better resize, Check other similar places
					positionsOnPlane->resize(positions.size());

					for(auto position : positions)
					{
						Vector3DDouble intersectionPoint;

						if (IntersectionTests::TryRayPlane(Vector3DDouble::GetZero(), position.Normalize(), normal, d, intersectionPoint))
						{
							Vector3DDouble v = intersectionPoint - origin;
							positionsOnPlane->push_back(Vector2DDouble(xAxis.Dot(v), yAxis.Dot(v)));
						}
						else
						{
							// Ray does not intersect plane
						}
					}

					return positionsOnPlane;
				}

				
			
			};

		};
	};
};

#endif