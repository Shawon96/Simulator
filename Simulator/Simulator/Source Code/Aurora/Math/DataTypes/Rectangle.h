#ifndef MATH_DATATYPES_Rectangle_H
#define MATH_DATATYPES_Rectangle_H
#include "../Vectors/EmulatedVector3D.h"
#include "RECT.h"
#include <math.h>

/*!
Namespace: Aurora

This namespace is the main package for the engine. It holds all the main classes, namespaces, operations etc... that defines the functionality of this
project/engine.
*/
namespace Aurora
{
	/*!
	Namespace: Math

	This namespace holds needed math operations for the engine.
	*/
	namespace Math
	{
		namespace DataTypes
		{
			using namespace Aurora::DataTypes;

			template<typename Type>
			class Rectangle
			{
			private:
				Vector2D<Type> point;
				mRECT<Type> size;
			public:
				Rectangle();
				Rectangle(Type x, Type y, Type heigh, Type width);
				Rectangle(const Vector2D<Type> &point, const mRECT<Type> &size);
				Rectangle<Type> & operator=(const Rectangle<Type> & value);
				Rectangle(Rectangle<Type> &&value);
				Rectangle<Type> & operator=(Rectangle<Type> && value);
				virtual ~Rectangle();

				Vector2D<Type> Point() const {
					return point;
				}
				template<typename T>
				void Point(T &&value) {
					point = std::forward<T>(value);
				}

				mRECT<Type> Size() const {
					return size;
				}
				template<typename T>
				void Size(T &&value) {
					size = std::forward<T>(value);
				}
			};

			template<typename Type>
			Aurora::Math::DataTypes::Rectangle<Type>::Rectangle(Type x, Type y, Type heigh, Type width) : Rectangle(Vector2D<Type>(x, y), mRECT<Type>(width, heigh))
			{

			}

			template<typename Type>
			Rectangle<Type> & Aurora::Math::DataTypes::Rectangle<Type>::operator=(Rectangle<Type> && value)
			{
				if (this == &value) { return(*this); }
				this->point = std::move(value.Point());
				this->size = std::move(value.Size());
				return(*this);
			}

			template<typename Type>
			Aurora::Math::DataTypes::Rectangle<Type>::Rectangle(Rectangle<Type> &&value) : point(std::move(value.Point())), size(std::move(value.Size()))
			{

			}

			template<typename Type>
			Rectangle<Type> & Aurora::Math::DataTypes::Rectangle<Type>::operator=(const Rectangle<Type> & value)
			{
				if (this == &value) { return(*this); }
				this->point = value.Point();
				this->size = value.Size();
				return(*this);
			}

			template<typename Type>
			Aurora::Math::DataTypes::Rectangle<Type>::~Rectangle()
			{

			}

			template<typename Type>
			Aurora::Math::DataTypes::Rectangle<Type>::Rectangle(const Vector2D<Type> &point, const mRECT<Type> &size) : point(point), size(size)
			{
			}


			template<typename Type>
			Aurora::Math::DataTypes::Rectangle<Type>::Rectangle() : point(Vector2D<Type>::GetZero()), size(mRECT<Type>())
			{

			}
		};
	};
};

#endif