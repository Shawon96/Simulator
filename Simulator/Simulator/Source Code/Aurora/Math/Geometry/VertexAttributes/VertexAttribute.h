#ifndef GeometryOperations_VertexAttributes_VertexAttribute_H
#define GeometryOperations_VertexAttributes_VertexAttribute_H

#include <type_traits>
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
			private:
				std::string name;
				VertexAttributeType type;
			protected:
				
			public:

				VertexAttributeBase() = default;
				virtual ~VertexAttributeBase() = default;

				std::string Name() const {
					return name;
				}

				Aurora::Math::Geometry::VertexAttributeType Type() const {
					return type;
				}

				template<typename T>
				void Name(T &&value) {
					name = std::forward<T>(value);
				}

				template<typename T>
				void Type(T &&value) {
					type = std::forward<T>(value);
				}

				VertexAttributeBase(const std::string &name, VertexAttributeType type)
				{
					this->name = name;
					this->type = type;
				}

				VertexAttributeBase(const VertexAttributeBase &value) : name(value.Name()), type(value.Type())
				{

				}

				VertexAttributeBase(VertexAttributeBase &&value) : name(std::move(value.Name())), type(std::move((value.Type())))
				{

				}

				VertexAttributeBase &operator=(VertexAttributeBase && value)
				{
					if (this == &value)
						return *this;

					this->name = std::move(value.Name());
					this->type = std::move(value.Type());

					return *this;
				}

				VertexAttributeBase& operator=(const VertexAttributeBase& value)
				{
					if (this == &value)
						return *this;

					this->name = value.Name();
					this->type = value.Type();

					return *this;
				}

				

			};

			template<typename DataType>
			class VertexAttribute : public VertexAttributeBase
			{
			protected:
				

			private:
				std::shared_ptr<UniqueDynamicTypeVector<DataType>> values;

			public:
				VertexAttribute()
				{
					//TODO: Type detection for the values collection
					/*if (std::is_same<UInt16, decltype(*values.get())::value_type>::value)
					{
						this->Type(VertexAttributeType::UnsignedByte);
					}
					else if (std::is_same<half_float::half, decltype(*values.get())::value_type>::value)
					{
						this->Type(VertexAttributeType::HalfFloat);
					}
					else if (std::is_same<Vector2DHalfPrecision, (*values.get())>::value)
					{
						this->Type(VertexAttributeType::HalfFloatVector2);
					}
					else if (std::is_same<Vector3DHalfPrecision, decltype(*values.get())::value_type>::value)
					{
						this->Type(VertexAttributeType::HalfFloatVector3);
					}
					else if (std::is_same<Vector4DHalfPrecision, decltype(*values.get())::value_type>::value)
					{
						this->Type(VertexAttributeType::HalfFloatVector4);
					}
					else if (std::is_same<Float, decltype(*values.get())::value_type>::value)
					{
						this->Type(VertexAttributeType::Float);
					}
					else if (std::is_same<Vector2DFloat, decltype(*values.get())::value_type>::value)
					{
						this->Type(VertexAttributeType::FloatVector2);
					}
					else if (std::is_same<Vector3DFloat, decltype(*values.get())::value_type>::value)
					{
						this->Type(VertexAttributeType::HalfFloatVector3);
					}
					else if (std::is_same<Vector4DFloat, decltype(*values.get())::value_type>::value)
					{
						this->Type(VertexAttributeType::HalfFloatVector4);
					}
					else if (std::is_same<Vector3DDouble, decltype(*values.get())::value_type>::value)
					{
						this->Type(VertexAttributeType::EmulatedDoubleVector3);
					}
					else
					{
						this->Type(VertexAttributeType::Unknown);
					}*/
				}
				virtual ~VertexAttribute() = default;

				VertexAttribute(const std::string &name, VertexAttributeType type) : VertexAttributeBase(name, type)
				{
					this->values = std::shared_ptr<UniqueDynamicTypeVector<DataType>>();
				}

				VertexAttribute(const std::string &name, VertexAttributeType type, int capacity) : VertexAttributeBase(name, type)
				{
					this->values = std::shared_ptr<UniqueDynamicTypeVector<DataType>>();
					this->values->resize(capacity);
				}

				VertexAttribute(const VertexAttribute &value) : VertexAttributeBase(value)
				{
					
				}
				VertexAttribute(VertexAttribute &&value) : VertexAttributeBase(std::move(value)), values(std::move(value.Values()))
				{
					value.Values(nullptr);
				}
				VertexAttribute &operator=(VertexAttribute && value)
				{
					if (this == &value)
						return *this;

					this->Name(std::move(value.Name()));
					this->Type(std::move(value.Type()));
					this->values = std::move(Values());
					value.Values(nullptr);

					return *this;
				}
				VertexAttribute& operator=(const VertexAttribute& value)
				{
					if (this == &value)
						return *this;

					this->Name(value.Name());
					this->Type(value.Type());
					this->values = Values();

					return *this;
				}

				std::shared_ptr<UniqueDynamicTypeVector<DataType>> Values() const {
					return values;
				}

				template<typename T>
				void Values(T &&value) {
					values = std::forward<T>(value);
				}
			};

			template<typename Type>
			using UniqueVertexAttribute = std::unique_ptr < VertexAttribute<Type> > ;
		};
	};
};

#endif