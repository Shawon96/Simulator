#ifndef GeometryOperations_Indices_IndicesBase_H
#define GeometryOperations_Indices_IndicesBase_H

#include "IndicesType.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class IndicesBase
			{
			protected:
				

				
			private:
				IndicesType type;
			public:
				IndicesBase() = default;
				virtual ~IndicesBase() = default;
				IndicesBase(IndicesType type)
				{
					type = type;
				}

				Aurora::Math::Geometry::IndicesType Datatype() const {
					return type;
				}
			};
		};
	};
};

#endif