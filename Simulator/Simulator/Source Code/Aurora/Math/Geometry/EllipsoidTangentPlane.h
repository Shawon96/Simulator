#ifndef GeometryOperations_EllipsoidTangentPlane_H
#define GeometryOperations_EllipsoidTangentPlane_H

#include <functional>
#include <stdlib.h> 
#include "..\..\Globals\GlobalDatatypes.h"
#include "Ellipsoid.h"
//#include "../Vectors/Vector3D.h"
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
				EllipsoidTangentPlane() = default;
				virtual ~EllipsoidTangentPlane() = default;
				EllipsoidTangentPlane(const EllipsoidTangentPlane &value) : origin(value.Origin()), normal(value.Normal()), d(value.D()), xAxis(value.XAxis()), yAxis(value.YAxis())
				{
				}
				EllipsoidTangentPlane(EllipsoidTangentPlane &&value) : origin(std::move(value.Origin())), normal(std::move(value.Normal())), d(std::move(value.D())), xAxis(std::move(value.XAxis())), yAxis(std::move(value.YAxis()))
				{
				}
				EllipsoidTangentPlane &operator=(EllipsoidTangentPlane && value)
				{
					if (this == &value)
						return *this;

					this->origin = std::move(value.Origin());
					this->normal = std::move(value.Normal());
					this->d = std::move(value.D());
					this->xAxis = std::move(value.XAxis());
					this->yAxis = std::move(value.YAxis());

					return *this;
				}
				EllipsoidTangentPlane& operator=(const EllipsoidTangentPlane& value)
				{
					if (this == &value)
						return *this;

					this->origin = value.Origin();
					this->normal = value.Normal();
					this->d = value.D();
					this->xAxis = value.XAxis();
					this->yAxis = value.YAxis();

					return *this;
				}

				Vector3DDouble Origin() const {
					return origin;
				}
				Vector3DDouble Normal() const {
					return normal;
				}
				double D() const {
					return d;
				}
				Vector3DDouble XAxis() const {
					return xAxis;
				}
				Vector3DDouble YAxis() const {
					return yAxis;
				}

				EllipsoidTangentPlane(Aurora::Math::Geometry::Ellipsoid &ellipsoid, const UniqueVector3DDoubleVector &positions)
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
					Aurora::Math::Geometry::Ellipsoid e;
					std::shared_ptr<UniqueVector2DDoubleVector> positionsOnPlane = std::make_shared<UniqueVector2DDoubleVector>();
					//TODO: Better resize, Check other similar places
					positionsOnPlane->resize(positions.size());

					for(auto &position : positions)
					{
						Vector3DDouble intersectionPoint;

						if (IntersectionTests::TryRayPlane(Vector3DDouble::GetZero(), position->Normalize(), normal, d, intersectionPoint))
						{
							Vector3DDouble v = intersectionPoint - origin;
							positionsOnPlane->push_back(std::unique_ptr<Vector2DDouble>(new Vector2DDouble(xAxis.Dot(v), yAxis.Dot(v))));
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