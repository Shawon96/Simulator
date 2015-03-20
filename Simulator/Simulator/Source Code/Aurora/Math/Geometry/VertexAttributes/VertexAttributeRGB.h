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

			class VertexAttributeRGB : public VertexAttribute < Byte >
			{
			public: 
				VertexAttributeRGB() = default;
				virtual ~VertexAttributeRGB() = default;
				VertexAttributeRGB(const VertexAttributeRGB &value) : VertexAttribute(value)
				{

				}
				VertexAttributeRGB(VertexAttributeRGB &&value) : VertexAttribute(std::move(value))
				{

				}
				VertexAttributeRGB &operator=(VertexAttributeRGB && value)
				{
					if (this == &value)
						return *this;

					this->Name(std::move(value.Name()));
					this->Type(std::move(value.Type()));
					this->Values(std::move(Values()));

					return *this;
				}
				VertexAttributeRGB& operator=(const VertexAttributeRGB& value)
				{
					if (this == &value)
						return *this;

					this->Name(value.Name());
					this->Type(value.Type());
					this->Values(Values());

					return *this;
				}
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