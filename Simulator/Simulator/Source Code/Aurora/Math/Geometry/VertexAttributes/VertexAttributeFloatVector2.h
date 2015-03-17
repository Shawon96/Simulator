#ifndef GeometryOperations_VertexAttributes_VertexAttributeFloatVector2_H
#define GeometryOperations_VertexAttributes_VertexAttributeFloatVector2_H

#include "VertexAttribute.h"
#include "../../Vectors/Vector2D.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeFloatVector2 : VertexAttribute < Vector2DFloat >
			{
			public: VertexAttributeFloatVector2(const std::string &name) : VertexAttribute(name, VertexAttributeType::FloatVector2)
			{

			}

					VertexAttributeFloatVector2(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::FloatVector2, capacity)
					{

					}
			};
		};
	};
};

#endif