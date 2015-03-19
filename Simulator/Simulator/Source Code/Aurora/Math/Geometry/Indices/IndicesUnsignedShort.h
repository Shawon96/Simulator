#ifndef GeometryOperations_Indices_IndicesOperations_H
#define GeometryOperations_Indices_IndicesOperations_H
#include "IndicesBase.h"
#include "TriangleIndicesUnsignedShort.h"
#include "..\..\..\Globals\GlobalOperations.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class IndicesUnsignedInt : IndicesBase
			{
			public:
				IndicesUnsignedInt() : IndicesBase(IndicesType::UnsignedShort)
				{
					values = std::make_shared<UniqueUShortVector>();
				}

				IndicesUnsignedInt(int capacity) : IndicesBase(IndicesType::UnsignedShort)
				{
					values = std::make_shared<UniqueUShortVector>(capacity);
					this->values->resize(capacity);
				}

				std::shared_ptr<UniqueUShortVector> Values() const {
					return values;
				}

				void AddTriangle(const TriangleIndicesUnsignedShort &triangle)
				{
					values->push_back(triangle.UI0());
					values->push_back(triangle.UI1());
					values->push_back(triangle.UI2());
				}

			private:
				std::shared_ptr<UniqueUShortVector> values;


			};
		};
	};
};

#endif