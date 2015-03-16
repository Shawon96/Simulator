#ifndef GeometryOperations_VertexAttributes_VertexAttributeFloatVector3_H
#define GeometryOperations_VertexAttributes_VertexAttributeFloatVector3_H

#include "VertexAttribute.h"
#include "../../Vector3D.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeFloatVector3 : VertexAttribute < Vector3DFloat >
			{
			public: 
				VertexAttributeFloatVector3(const std::string &name) : VertexAttribute(name, VertexAttributeType::FloatVector3)
			{

			}

				VertexAttributeFloatVector3(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::FloatVector3, capacity)
					{

					}
			};
		};
	};
};

#endif