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

			class VertexAttributeRGBA : public VertexAttribute < Byte >
			{
			public:
				VertexAttributeRGBA() = default;
				virtual ~VertexAttributeRGBA() = default;
				VertexAttributeRGBA(const VertexAttributeRGBA &value) : VertexAttribute(value)
				{

				}
				VertexAttributeRGBA(VertexAttributeRGBA &&value) : VertexAttribute(std::move(value))
				{

				}
				VertexAttributeRGBA &operator=(VertexAttributeRGBA && value)
				{
					if (this == &value)
						return *this;

					this->Name(std::move(value.Name()));
					this->Type(std::move(value.Type()));
					this->Values(std::move(Values()));
					value.Values(nullptr);

					return *this;
				}
				VertexAttributeRGBA& operator=(const VertexAttributeRGBA& value)
				{
					if (this == &value)
						return *this;

					this->Name(value.Name());
					this->Type(value.Type());
					this->Values(Values());

					return *this;
				}
				VertexAttributeRGBA(const std::string &name) : VertexAttribute(name, VertexAttributeType::UnsignedByte)
				{

				}

				VertexAttributeRGBA(const std::string &name, int capacity) : VertexAttribute(name, VertexAttributeType::UnsignedByte, capacity * 4)
				{

				}

				void AddColor(const Color<Byte> &color)
				{
					Values()->push_back(UniqueByte(new Byte(color.R)));
					Values()->push_back(UniqueByte(new Byte(color.G)));
					Values()->push_back(UniqueByte(new Byte(color.B)));
					Values()->push_back(UniqueByte(new Byte(color.A)));
				}
			};
		};
	};
};

#endif