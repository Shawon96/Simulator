#ifndef Math_CollisionDetection_ContainmentTests_H
#define Math_CollisionDetection_ContainmentTests_H

#include "../Vectors/Vector2D.h"
#include "../Vectors/Vector3D.h"

namespace Aurora
{
	namespace Math
	{
		namespace CollisionDetection
		{
			using namespace Aurora::Math;
			class ContainmentTests
			{
			public:
				static bool PointInsideTriangle(const Vector2DDouble &point, const Vector2DDouble &p0, const Vector2DDouble &p1, const Vector2DDouble &p2)
				{
					//
					// Implementation based on http://www.blackpawn.com/texts/pointinpoly/default.html.
					//
					Vector2DDouble v0 = (p1 - p0);
					Vector2DDouble v1 = (p2 - p0);
					Vector2DDouble v2 = (point - p0);

					double dot00 = v0.Dot(v0);
					double dot01 = v0.Dot(v1);
					double dot02 = v0.Dot(v2);
					double dot11 = v1.Dot(v1);
					double dot12 = v1.Dot(v2);

					double q = 1.0 / (dot00 * dot11 - dot01 * dot01);
					double u = (dot11 * dot02 - dot01 * dot12) * q;
					double v = (dot00 * dot12 - dot01 * dot02) * q;

					return (u > 0) && (v > 0) && (u + v < 1);
				}

				/// <summary>
				/// The pyramid's base points should be in counterclockwise winding order.
				/// </summary>
				static bool PointInsideThreeSidedInfinitePyramid(
					const Vector3DDouble &point,
					const Vector3DDouble &pyramidApex,
					const Vector3DDouble &pyramidBase0,
					const Vector3DDouble &pyramidBase1,
					const Vector3DDouble &pyramidBase2)
				{
					Vector3DDouble v0 = pyramidBase0 - pyramidApex;
					Vector3DDouble v1 = pyramidBase1 - pyramidApex;
					Vector3DDouble v2 = pyramidBase2 - pyramidApex;

					//
					// Face normals
					//
					Vector3DDouble n0 = v1.Cross(v0);
					Vector3DDouble n1 = v2.Cross(v1);
					Vector3DDouble n2 = v0.Cross(v2);

					Vector3DDouble planeToPoint = point - pyramidApex;

					return ((planeToPoint.Dot(n0) < 0) && (planeToPoint.Dot(n1) < 0) && (planeToPoint.Dot(n2) < 0));
				}
			};

		};
	};
};

#endif