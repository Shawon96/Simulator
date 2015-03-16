#ifndef GeometryOperations_VertexAttributes_VertexAttributeFloat_H
#define GeometryOperations_VertexAttributes_VertexAttributeFloat_H

#include "VertexAttribute.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeFloat : VertexAttribute < float >
			{
			public: VertexAttributeFloat(const std::string &name) : VertexAttribute(name, VertexAttributeType::Float)
			{

			}

					VertexAttributeFloat(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::Float, capacity)
					{

					}
			};
		};
	};
};

#endif