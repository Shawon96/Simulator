#ifndef MATH_DATATYPES_RECT_H
#define MATH_DATATYPES_RECT_H
#include "..\..\Globals\GlobalOperations.h"
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
			class mRECT
			{
			public:
				mRECT();
				mRECT(Type width, Type height);
				~mRECT();
				mRECT(const mRECT<Type> &value);
				mRECT & operator=(const mRECT<Type> & value);
				mRECT(mRECT<Type> &&value);
				mRECT & operator=(mRECT<Type> && value);

				Type Width;
				Type Height;

				bool operator==(const mRECT<Type>		&value);

				bool operator!=(const mRECT<Type>		&value);

				bool IsZero() const;
			};

			template<typename Type>
			mRECT<Type>::mRECT(Type width, Type height)
			{
				this->Width = width;
				this->Height = height;
			}
			template<typename Type>
			mRECT<Type>::mRECT() : Width(0), Height(0)
			{
				this->Width = 0;
				this->Height = 0;
			}
			template<typename Type>
			mRECT<Type>::mRECT(mRECT<Type> &&value) : Width(value.Width), Height(value.Height)
			{

			}
			template<typename Type>
			mRECT<Type>::mRECT(const mRECT<Type> &value) : Width(value.Width), Height(value.Height)
			{

			}
			template<typename Type>
			mRECT<Type>::~mRECT()
			{

			}
			template<typename Type>
			bool mRECT<Type>::operator==(const mRECT<Type> &value)
			{
				bool isEqual = false;

				if (this->Width == value.Width && this->Height == value.Height)
					isEqual = true;

				return(isEqual);
			}
			template<typename Type>
			bool mRECT<Type>::operator!=(const mRECT<Type> &value)
			{
				bool isEqual = false;

				if (this->Width != value.Width && this->Height != value.Height)
					isEqual = true;

				return(isEqual);
			}
			template<typename Type>
			bool mRECT<Type>::IsZero() const
			{
				bool isZero = false;

				if (this->Width == 0 && this->Height == 0)
					isZero = true;

				return(isZero);
			}
			template<typename Type>
			mRECT<Type> & mRECT<Type>::operator=(mRECT<Type> && value)
			{
				this->Width = value.Width;
				this->Height = value.Height;
				return(*this);
			}
			template<typename Type>
			mRECT<Type> & mRECT<Type>::operator=(const mRECT<Type> & value)
			{
				this->Width = value.Width;
				this->Height = value.Height;
				return(*this);
			}
		};
	};
};

#endif