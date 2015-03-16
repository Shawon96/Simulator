#ifndef GeometryOperations_Mesh_H
#define GeometryOperations_Mesh_H




namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			enum class PrimitiveType
			{
				Points,
				Lines,
				LineLoop,
				LineStrip,
				Triangles,
				TriangleStrip,
				TriangleFan,
				LinesAdjacency,
				LineStripAdjacency,
				TrianglesAdjacency,
				TriangleStripAdjacency
			};

			enum class WindingOrder
			{
				Clockwise,
				Counterclockwise
			};

			
		};
	};
};

#endif