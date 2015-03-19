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
					values = std::make_shared<UniqueUIntVector>();
				}

				IndicesUnsignedInt(int capacity) : IndicesBase(IndicesType::UnsignedInt)
				{
					values = std::make_shared<UniqueUIntVector>(capacity);
					this->values->resize(capacity);
				}

				std::shared_ptr<UniqueUIntVector> Values() const {
					return values;
				}

				void AddTriangle(const TriangleIndicesUnsignedInt &triangle)
					{
						values->push_back(UniqueUInt(new UInt32(triangle.UI0())));
						values->push_back(UniqueUInt(new UInt32(triangle.UI1())));
						values->push_back(UniqueUInt(new UInt32(triangle.UI2())));
					}

			private:
				std::shared_ptr<UniqueUIntVector> values;
				
				
			};
		};
	};
};

#endif