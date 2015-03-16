#ifndef GeometryOperations_VertexAttributes_VertexAttributeRGBA_H
#define GeometryOperations_VertexAttributes_VertexAttributeRGBA_H

#include "VertexAttribute.h"
#include "..\..\..\Globals\GlobalDatatypes.h"
namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			using namespace Aurora::DataTypes;

			class VertexAttributeRGBA : VertexAttribute < Byte >
			{
			public:
				VertexAttributeRGBA(const std::string &name) : VertexAttribute(name, VertexAttributeType::UnsignedByte)
				{

				}

				VertexAttributeRGBA(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::UnsignedByte, capacity * 4)
				{

				}

				void AddColor(const Color<Byte> &color)
				{
					Values().push_back(color.R);
					Values().push_back(color.G);
					Values().push_back(color.B);
					Values().push_back(color.A);
				}
			};
		};
	};
};

#endif