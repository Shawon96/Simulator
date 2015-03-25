#ifndef Math_Polygons_TriangleMeshSubdivisionResult_H
#define Math_Polygons_TriangleMeshSubdivisionResult_H

#include "../Geometry/Indices/IndicesOperations.h"
#include "../Vectors/EmulatedVector3D.h"

namespace Aurora
{

	namespace Math
	{
		namespace Polygons
		{
			using namespace Aurora::Math;
			using namespace Aurora::Math::Geometry;

			class TriangleMeshSubdivisionResult
			{
			private:
				std::shared_ptr<UniqueVector3DDoubleVector> positions;
				

				IndicesUnsignedInt indices;
				
			public:
				TriangleMeshSubdivisionResult() = default;
				virtual ~TriangleMeshSubdivisionResult() = default;
				TriangleMeshSubdivisionResult(const TriangleMeshSubdivisionResult &value) : positions(value.Positions()), indices(value.indices)
				{

				}
				TriangleMeshSubdivisionResult(TriangleMeshSubdivisionResult &&value) : positions(std::move(value.Positions())), indices(std::move(value.indices))
				{
					value.Positions(nullptr);
					value.Indices(nullptr);
				}
				TriangleMeshSubdivisionResult &operator=(TriangleMeshSubdivisionResult && value)
				{
					if (this == &value)
						return *this;

					this->indices = std::move(value.Indices());
					this->positions = std::move(value.Positions());

					value.Positions(nullptr);
					value.Indices(nullptr);
					

					return *this;
				}
				TriangleMeshSubdivisionResult& operator=(const TriangleMeshSubdivisionResult& value)
				{
					if (this == &value)
						return *this;

					this->indices = value.Indices();
					this->positions = value.Positions();

					return *this;
				}

				TriangleMeshSubdivisionResult(const UniqueVector3DDoubleVector &positions, const IndicesUnsignedInt &indices)
				{
					this->positions = positions;
					this->indices = indices;
				}

				std::shared_ptr<UniqueVector3DDoubleVector> Positions() const {
					return positions;
				}
				template<typename T>
				void Positions(T &&value) {
					positions = std::forward<T>(value);
				}

				Aurora::Math::Geometry::IndicesUnsignedInt Indices() const {
					return indices;
				}


				template<typename T>
				void Indices(T &&value) {
					indices = std::forward<T>(value);
				}
			};
		};
	};
};

#endif