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
			using UniqueVertexAttributeCollection = std::map < std::string, UniqueVertexAttribute<Type> >;
		};
	};
};

#endif