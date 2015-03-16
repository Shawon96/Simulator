#ifndef GeometryOperations_VertexAttributes_VertexAttributeByte_H
#define GeometryOperations_VertexAttributes_VertexAttributeByte_H

#include "VertexAttribute.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			class VertexAttributeByte : VertexAttribute <Byte>
			{
			public: VertexAttributeByte(const std::string &name) : VertexAttribute(name, VertexAttributeType::UnsignedByte)
				{

				}

				VertexAttributeByte(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::UnsignedByte, capacity)
				{

				}
			};
		};
	};
};

#endif