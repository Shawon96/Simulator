#ifndef GeometryOperations_Edge_H
#define GeometryOperations_Edge_H
#include <functional>
#include <stdlib.h> 
#include "..\..\Globals\GlobalDatatypes.h"
#include "Ellipsoid.h"
#include "../Vectors/Vector3D.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			using namespace Aurora::DataTypes;

			//class EllipsoidTangentPlane
			//{
			//public:
			//	EllipsoidTangentPlane(const Ellipsoid &ellipsoid, const std::vector<Vector3DDouble> &positions)
			//	{
			//		/*if (ellipsoid == nullptr)
			//		{
			//		throw new ArgumentNullException("ellipsoid");
			//		}

			//		if (positions == nullptr)
			//		{
			//		throw new ArgumentNullException("positions");
			//		}*/

			//		if (positions.size() < 1)
			//		{
			//			throw std::bad_function_call("positions: At least one position is required.");
			//		}

			//		AxisAlignedBoundingBox box = new AxisAlignedBoundingBox(positions);

			//		_origin = ellipsoid.ScaleToGeodeticSurface(box.Center);
			//		_normal = ellipsoid.GeodeticSurfaceNormal(_origin);
			//		_d = -_origin.Dot(_origin);
			//		_yAxis = _origin.Cross(_origin.MostOrthogonalAxis).Normalize();
			//		_xAxis = _yAxis.Cross(_origin).Normalize();
			//	}

			//	public ICollection<Vector2D> ComputePositionsOnPlane(IEnumerable<Vector3D> positions)
			//	{
			//		if (positions == null)
			//		{
			//			throw new ArgumentNullException("positions");
			//		}

			//		IList<Vector2D> positionsOnPlane = new List<Vector2D>(CollectionAlgorithms.EnumerableCount(positions));

			//		foreach(Vector3D position in positions)
			//		{
			//			Vector3D intersectionPoint;

			//			if (IntersectionTests.TryRayPlane(Vector3D.Zero, position.Normalize(), _normal, _d, out intersectionPoint))
			//			{
			//				Vector3D v = intersectionPoint - _origin;
			//				positionsOnPlane.Add(new Vector2D(_xAxis.Dot(v), _yAxis.Dot(v)));
			//			}
			//			else
			//			{
			//				// Ray does not intersect plane
			//			}
			//		}

			//		return positionsOnPlane;
			//	}

			//	public Vector3D Origin{ get{ return _origin; } }
			//	public Vector3D Normal{ get{ return _normal; } }
			//	public double D{ get{ return _d; } }
			//	public Vector3D XAxis{ get{ return _xAxis; } }
			//	public Vector3D YAxis{ get{ return _yAxis; } }

			//	private Vector3D _origin;
			//	private Vector3D _normal;
			//	private double _d;
			//	private Vector3D _xAxis;
			//	private Vector3D _yAxis;
			//}

		};
	};
};

#endif