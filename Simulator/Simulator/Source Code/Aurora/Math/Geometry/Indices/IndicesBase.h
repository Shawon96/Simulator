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
				IndicesBase(IndicesType type)
				{
					type = type;
				}
			private:
				IndicesType type;
			public:
				Aurora::Math::Geometry::IndicesType Datatype() const {
					return type;
				}
			};
		};
	};
};

#endif