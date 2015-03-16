#ifndef GeometryOperations_VertexAttributes_VertexAttributeByte_H
#define GeometryOperations_VertexAttributes_VertexAttributeByte_H

#include "VertexAttribute.h"
#include "../../Vector4D.h"
namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeHalfFloatVector4 : VertexAttribute < Vector4DHalfPrecision >
			{
			public: VertexAttributeHalfFloatVector4(const std::string &name) : VertexAttribute(name, VertexAttributeType::HalfFloatVector4)
			{

			}

					VertexAttributeHalfFloatVector4(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::HalfFloatVector4, capacity)
					{

					}
			};
		};
	};
};

#endif