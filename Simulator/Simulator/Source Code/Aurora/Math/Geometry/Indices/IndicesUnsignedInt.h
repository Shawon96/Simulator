#ifndef GeometryOperations_Indices_IndicesUnsignedInt_H
#define GeometryOperations_Indices_IndicesUnsignedInt_H

#include "IndicesBase.h"
#include "TriangleIndicesUnsignedInt.h"
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
				IndicesUnsignedInt() : IndicesBase(IndicesType::UnsignedInt)
				{
				}

				IndicesUnsignedInt(int capacity) : IndicesBase(IndicesType::UnsignedInt)
				{
					values.resize(capacity);
				}

				std::vector<unsigned int> Values() const {
					return values;
				}

				void AddTriangle(const TriangleIndicesUnsignedInt &triangle)
					{
						values.push_back(triangle.UI0());
						values.push_back(triangle.UI1());
						values.push_back(triangle.UI2());
					}

			private:
				std::vector<unsigned int> values;
				
				
			};
		};
	};
};

#endif