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

				virtual ~Mesh() = default;
				Mesh(const Mesh &value) : indices(value.Indices()), meshPrimitiveType(value.MeshPrimitiveType()), frontFaceWindingOrder(value.FrontFaceWindingOrder()), attributes(value.Attributes())
				{

				}
				Mesh(Mesh &&value) : indices(std::move(value.Indices())), meshPrimitiveType(std::move(value.MeshPrimitiveType())), frontFaceWindingOrder(std::move(value.FrontFaceWindingOrder())), attributes(std::move(value.Attributes()))
				{
					value.Attributes(nullptr);
				}
				Mesh &operator=(Mesh && value)
				{
					if (this == &value)
						return *this;

					this->indices = std::move(value.Indices());
					this->meshPrimitiveType = value.MeshPrimitiveType();
					this->frontFaceWindingOrder = value.FrontFaceWindingOrder();
					this->attributes = std::move(.Attributes());

					value.Attributes(nullptr);

					return *this;
				}
				Mesh& operator=(const Mesh& value)
				{
					if (this == &value)
						return *this;

					this->indices = value.Indices();
					this->meshPrimitiveType = value.MeshPrimitiveType();
					this->frontFaceWindingOrder = value.FrontFaceWindingOrder();
					this->attributes = value.Attributes();

					return *this;
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