#ifndef GeometryOperations_VertexAttributes_VertexAttribute_H
#define GeometryOperations_VertexAttributes_VertexAttribute_H

#include "VertexAttributeType.h"
#include "..\..\..\Globals\GlobalDatatypes.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			using namespace Aurora::DataTypes;
			class VertexAttributeBase
			{
			protected:
				VertexAttributeBase(const std::string &name, VertexAttributeType type)
				{
					this->name = name;
					this->type = type;
				}

				
			private:
				std::string name;
				VertexAttributeType type;
				
			public:
				std::string Name() const {
					return name;
				}

				Aurora::Math::Geometry::VertexAttributeType Type() const {
					return type;
				}

			};

			template<typename DataType>
			class VertexAttribute : VertexAttributeBase
			{
			protected:
				VertexAttribute(const std::string &name, VertexAttributeType type) : VertexAttributeBase(name, type)
				{
					this->values = std::shared_ptr<UniqueDynamicTypeVector<DataType>>();
				}

				VertexAttribute(const std::string &name, VertexAttributeType type, int capacity) : VertexAttributeBase(name, type)
				{
					this->values = std::shared_ptr<UniqueDynamicTypeVector<DataType>>();
					this->values->resize(capacity);
				}

			private:
				std::shared_ptr<UniqueDynamicTypeVector<DataType>> values;
				
			public:
				std::shared_ptr<UniqueDynamicTypeVector<DataType>> Values() const {
					return values;
				}
			};
		};
	};
};

#endif