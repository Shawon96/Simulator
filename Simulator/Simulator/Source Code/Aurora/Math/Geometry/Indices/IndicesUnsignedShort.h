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
				}

				IndicesUnsignedInt(int capacity) : IndicesBase(IndicesType::UnsignedShort)
				{
					values.resize(capacity);
				}

				std::vector<unsigned short> Values() const {
					return values;
				}

				void AddTriangle(const TriangleIndicesUnsignedShort &triangle)
				{
					values.push_back(triangle.UI0());
					values.push_back(triangle.UI1());
					values.push_back(triangle.UI2());
				}

			private:
				std::vector<unsigned short> values;


			};
		};
	};
};

#endif