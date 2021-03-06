#ifndef GeometryOperations_Indices_IndicesUnsignedShort_H
#define GeometryOperations_Indices_IndicesUnsignedShort_H
#include "IndicesBase.h"
#include "TriangleIndicesUnsignedShort.h"
#include "..\..\..\Globals\GlobalOperations.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class IndicesUnsignedShort : public IndicesBase
			{
			public:
				IndicesUnsignedShort() : IndicesBase(IndicesType::UnsignedShort)
				{
					values = std::make_shared<UniqueUShortVector>();
				}
				virtual ~IndicesUnsignedShort() = default;

				IndicesUnsignedShort(const IndicesUnsignedShort &value)
				{
					values = value.Values();
					IndicesBase::IndicesBase(IndicesType::UnsignedInt);
				}

				IndicesUnsignedShort(IndicesUnsignedShort &&value)
				{
					values = std::move(value.Values());
					IndicesBase::IndicesBase(IndicesType::UnsignedInt);
					value.Values(nullptr);
				}
				IndicesUnsignedShort &operator=(IndicesUnsignedShort && value)
				{
					if (this == &value)
						return *this;

					values = std::move(value.Values());
					IndicesBase::IndicesBase(IndicesType::UnsignedInt);
					value.Values(nullptr);

					return *this;
				}
				IndicesUnsignedShort& operator=(const IndicesUnsignedShort& value)
				{
					if (this == &value)
						return *this;

					values = value.Values();
					IndicesBase::IndicesBase(IndicesType::UnsignedInt);

					return *this;
				}

				IndicesUnsignedShort(int capacity) : IndicesBase(IndicesType::UnsignedShort)
				{
					values = std::make_shared<UniqueUShortVector>(capacity);
					this->values->resize(capacity);
				}

				std::shared_ptr<UniqueUShortVector> Values() const {
					return values;
				}

				template<typename T>
				void Values(T &&value) {
					values = std::forward<T>(value);
				}

				void AddTriangle(const TriangleIndicesUnsignedShort &triangle)
				{
					values->push_back(UniqueUShort(std::make_unique<UInt16>(triangle.UI0())));
					values->push_back(UniqueUShort(std::make_unique<UInt16>(triangle.UI1())));
					values->push_back(UniqueUShort(std::make_unique<UInt16>(triangle.UI2())));
				}

			private:
				//TODO: linked list optimization??
				std::shared_ptr<UniqueUShortVector> values;


			};
		};
	};
};

#endif