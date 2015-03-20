#ifndef GeometryOperations_Mesh_H
#define GeometryOperations_Mesh_H

#include "Indices/IndicesOperations.h"
#include "VertexAttributes/VertexAttributesOperations.h"

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

			template<typename Type>
			class Mesh
			{
			private:
				std::shared_ptr<UniqueVertexAttributeCollection<Type>> attributes;
				
				IndicesBase indices;
				PrimitiveType meshPrimitiveType;
				WindingOrder frontFaceWindingOrder;
			public:
				Mesh()
				{
					
				}

				std::shared_ptr<UniqueVertexAttributeCollection<Type>> Attributes() const {
					return attributes;
				}

				Aurora::Math::Geometry::IndicesBase Indices() const {
					return indices;
				}
				template<typename T>
				void Indices(T &&value) {
					indices = std::forward<T>(value);
				}

				Aurora::Math::Geometry::Mesh::PrimitiveType MeshPrimitiveType() const {
					return meshPrimitiveType;
				}
				template<typename T>
				void MeshPrimitiveType(T &&value) {
					meshPrimitiveType = std::forward<T>(value);
				}

				Aurora::Math::Geometry::WindingOrder FrontFaceWindingOrder() const {
					return frontFaceWindingOrder;
				}
				template<typename T>
				void FrontFaceWindingOrder(T &&value) {
					frontFaceWindingOrder = std::forward<T>(value);
				}
			};
		};
	};
};

#endif