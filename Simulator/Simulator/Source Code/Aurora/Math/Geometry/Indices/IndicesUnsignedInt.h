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
			class IndicesUnsignedInt : public IndicesBase
			{
			public:
				
				IndicesUnsignedInt() : IndicesBase(IndicesType::UnsignedInt)
				{
					values = std::make_shared<UniqueUIntVector>();
				}
				virtual ~IndicesUnsignedInt() = default;

				IndicesUnsignedInt(const IndicesUnsignedInt &value)
				{
					values = value.Values();
					IndicesBase::IndicesBase(IndicesType::UnsignedInt);
				}

				IndicesUnsignedInt(IndicesUnsignedInt &&value)
				{
					values = std::move(value.Values());
					IndicesBase::IndicesBase(IndicesType::UnsignedInt);
					value.Values(nullptr);
				}
				IndicesUnsignedInt &operator=(IndicesUnsignedInt && value)
				{
					if (this == &value)
						return *this;

					values = std::move(value.Values());
					IndicesBase::IndicesBase(IndicesType::UnsignedInt);
					value.Values(nullptr);

					return *this;
				}
				IndicesUnsignedInt& operator=(const IndicesUnsignedInt& value)
				{
					if (this == &value)
						return *this;

					values = value.Values();
					IndicesBase::IndicesBase(IndicesType::UnsignedInt);

					return *this;
				}

				IndicesUnsignedInt(int capacity) : IndicesBase(IndicesType::UnsignedInt)
				{
					values = std::make_shared<UniqueUIntVector>(capacity);
					this->values->resize(capacity);
				}

				std::shared_ptr<UniqueUIntVector> Values() const {
					return values;
				}

				template<typename T>
				void Values(T &&value) {
					values = std::forward<T>(value);
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