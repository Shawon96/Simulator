#ifndef GeometryOperations_VertexAttributes_VertexAttributeDoubleVector3_H
#define GeometryOperations_VertexAttributes_VertexAttributeDoubleVector3_H

#include "VertexAttribute.h"
#include "../../Vector3D.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeDoubleVector3 : VertexAttribute < Vector3DDouble >
			{
			public: VertexAttributeDoubleVector3(const std::string &name) : VertexAttribute(name, VertexAttributeType::EmulatedDoubleVector3)
			{

			}

					VertexAttributeDoubleVector3(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::EmulatedDoubleVector3, capacity)
					{

					}
			};
		};
	};
};

#endif