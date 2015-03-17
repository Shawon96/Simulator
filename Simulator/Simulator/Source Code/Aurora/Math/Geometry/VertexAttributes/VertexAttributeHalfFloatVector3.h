#ifndef GeometryOperations_VertexAttributes_VertexAttributeHalfFloatVector3_H
#define GeometryOperations_VertexAttributes_VertexAttributeHalfFloatVector3_H

#include "VertexAttribute.h"
#include "../../Vectors/Vector3D.h"
namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeHalfFloatVector3 : VertexAttribute < Vector3DHalfPrecision >
			{
			public: VertexAttributeHalfFloatVector3(const std::string &name) : VertexAttribute(name, VertexAttributeType::HalfFloatVector3)
			{

			}

					VertexAttributeHalfFloatVector3(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::HalfFloatVector3, capacity)
					{

					}
			};
		};
	};
};

#endif