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
			using VertexAttributeHalfFloat = VertexAttribute < half_float::half >;
			
		};
	};
};

#endif