#ifndef GeometryOperations_VertexAttributes_VertexAttributeHalfFloat_H
#define GeometryOperations_VertexAttributes_VertexAttributeHalfFloat_H

#include "VertexAttribute.h"
#include "..\..\..\Globals\GlobalDatatypes.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeHalfFloat : VertexAttribute < half_float::half >
			{
			public: VertexAttributeHalfFloat(const std::string &name) : VertexAttribute(name, VertexAttributeType::HalfFloat)
			{

			}

					VertexAttributeHalfFloat(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::HalfFloat, capacity)
					{

					}
			};
		};
	};
};

#endif