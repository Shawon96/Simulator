#ifndef Math_CollisionDetection_IntersectionTests_H
#define Math_CollisionDetection_IntersectionTests_H

#include "../Vectors/Vector3D.h"

namespace Aurora
{
	namespace Math
	{
		namespace CollisionDetection
		{
			using namespace Aurora::Math;
			class IntersectionTests
			{
				
			public:
				static bool TryRayPlane(
					const Vector3DDouble &rayOrigin,
					const Vector3DDouble &rayDirection,
					const Vector3DDouble &planeNormal,
					double planeD,
					Vector3DDouble &intersectionPoint)
				{
					double denominator = planeNormal.Dot(rayDirection);

					if (abs(denominator) < 0.00000000000000000001)
					{
						//
						// Ray is parallel to plane.  The ray may be in the polygon's plane.
						//
						intersectionPoint = Vector3DDouble::GetZero();
						return false;
					}

					double t = (-planeD - planeNormal.Dot(rayOrigin)) / denominator;

					if (t < 0)
					{
						intersectionPoint = Vector3DDouble::GetZero();
						return false;
					}

					intersectionPoint = rayOrigin + (rayDirection * t);
					return true;
				}
			};

		};
	};
};

#endif