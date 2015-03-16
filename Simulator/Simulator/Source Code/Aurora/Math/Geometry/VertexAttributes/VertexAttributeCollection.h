#ifndef GeometryOperations_VertexAttributes_VertexAttributeCollection_H
#define GeometryOperations_VertexAttributes_VertexAttributeCollection_H

#include "VertexAttribute.h"
#include "..\..\..\Globals\GlobalOperations.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			template<typename Type>
			using VertexAttributeCollection = std::map < std::string, VertexAttribute<Type> >;
		};
	};
};

#endif