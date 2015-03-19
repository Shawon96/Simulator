#ifndef GeometryOperations_VertexAttributes_VertexAttributeRGB_H
#define GeometryOperations_VertexAttributes_VertexAttributeRGB_H

#include "VertexAttribute.h"
#include "..\..\..\Globals\GlobalDatatypes.h"
namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			using namespace Aurora::DataTypes;

			class VertexAttributeRGB : VertexAttribute < Byte >
			{
			public: 
				VertexAttributeRGB(const std::string &name) : VertexAttribute(name, VertexAttributeType::UnsignedByte)
			{

			}

					VertexAttributeRGB(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::UnsignedByte, capacity * 3)
					{

					}

					void AddColor(const Color<Byte> &color)
					{
						Values()->push_back(UniqueByte(new Byte(color.R)));
						Values()->push_back(UniqueByte(new Byte(color.G)));
						Values()->push_back(UniqueByte(new Byte(color.B)));
					}
			};
		};
	};
};

#endif