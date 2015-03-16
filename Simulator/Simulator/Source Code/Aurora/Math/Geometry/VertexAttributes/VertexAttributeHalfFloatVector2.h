#ifndef GeometryOperations_VertexAttributes_VertexAttributeHalfFloatVector2_H
#define GeometryOperations_VertexAttributes_VertexAttributeHalfFloatVector2_H

#include "VertexAttribute.h"
#include "../../Vector2D.h"
namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeHalfFloatVector2 : VertexAttribute < Vector2DHalfPrecision >
			{
			public: VertexAttributeHalfFloatVector2(const std::string &name) : VertexAttribute(name, VertexAttributeType::HalfFloatVector2)
			{

			}

					VertexAttributeHalfFloatVector2(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::HalfFloatVector2, capacity)
					{

					}
			};
		};
	};
};

#endif