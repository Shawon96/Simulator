#ifndef GeometryOperations_VertexAttributes_VertexAttributeFloatVector4_H
#define GeometryOperations_VertexAttributes_VertexAttributeFloatVector4_H

#include "VertexAttribute.h"
#include "../../Vector4D.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeFloatVector4 : VertexAttribute < Vector4DFloat >
			{
			public: VertexAttributeFloatVector4(const std::string &name) : VertexAttribute(name, VertexAttributeType::FloatVector4)
			{

			}

					VertexAttributeFloatVector4(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::FloatVector4, capacity)
					{

					}
			};
		};
	};
};

#endif