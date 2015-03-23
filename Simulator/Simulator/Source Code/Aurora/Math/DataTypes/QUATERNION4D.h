#ifndef MATH_DATATYPES_QUATERNION4D_H
#define MATH_DATATYPES_QUATERNION4D_H
#include "Rectangle.h"
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

			/*!
			\brief 4d quaternion
			*/
			template<typename Type>
			class mQUATERNION4D
			{
			public:
				mQUATERNION4D();
				mQUATERNION4D(Type q0, Vector3D<Type> qv);
				mQUATERNION4D(const mQUATERNION4D<Type> &value);
				~mQUATERNION4D();
				mQUATERNION4D<Type> &operator=(const mQUATERNION4D<Type>		&value);
				mQUATERNION4D<Type> operator+(const mQUATERNION4D<Type>			&value);
				mQUATERNION4D<Type> &operator+=(const mQUATERNION4D<Type>		&value);
				mQUATERNION4D<Type> operator-(const mQUATERNION4D<Type>			&value);
				mQUATERNION4D<Type> &operator-=(const mQUATERNION4D<Type>		&value);
				mQUATERNION4D<Type> operator*(const mQUATERNION4D<Type>			&value);
				mQUATERNION4D<Type> operator*(const Type					&value);
				mQUATERNION4D<Type> &operator*=(const Type				&value);
				mQUATERNION4D<Type> &operator*=(const mQUATERNION4D<Type>		&value);
				Type		q0;			/*!< The real part.						*/
				Vector3D<Type>	qV;			/*!< The imaginary part xi+yj+zk.		*/
				void ZeroQuarternion(void);
			};

			template<typename Type>
			mQUATERNION4D<Type>::mQUATERNION4D()
			{
				this->q0 = 0;
			}
			template<typename Type>
			mQUATERNION4D<Type>::mQUATERNION4D(Type q0, Vector3D<Type> qv)
			{
				this->q0 = q0;
				this->qV = qv;
			}
			template<typename Type>
			mQUATERNION4D<Type>::mQUATERNION4D(const mQUATERNION4D<Type> &value)
			{
				this->q0 = value.q0;
				this->qV = value.qV;
			}
			template<typename Type>
			mQUATERNION4D<Type>::~mQUATERNION4D()
			{

			}
			template<typename Type>
			mQUATERNION4D<Type> &mQUATERNION4D<Type>::operator=(const mQUATERNION4D<Type>		&value)
			{
				if (this == &value) { return(*this); }
				this->q0 = value.q0;
				this->qV = value.qV;
				return(*this);
			}
			template<typename Type>
			mQUATERNION4D<Type> mQUATERNION4D<Type>::operator+(const mQUATERNION4D<Type>		&value)
			{
				return(mQUATERNION4D(this->q0 + value.q0, Vector3D(this->qV.X + value.qV.X, this->qV.Y + value.qV.Y, this->qV.Z + value.qV.Z)));
			}
			template<typename Type>
			mQUATERNION4D<Type> mQUATERNION4D<Type>::operator-(const mQUATERNION4D<Type>		&value)
			{
				return(mQUATERNION4D(this->q0 - value.q0, Vector3D(this->qV.X - value.qV.X, this->qV.Y - value.qV.Y, this->qV.Z - value.qV.Z)));
			}
			template<typename Type>
			mQUATERNION4D<Type> &mQUATERNION4D<Type>::operator+=(const mQUATERNION4D<Type>		&value)
			{
				if (this == &value) { return(*this); }
				this->q0 += value.q0;
				this->qV += value.qV;
				return(*this);
			}
			template<typename Type>
			mQUATERNION4D<Type> &mQUATERNION4D<Type>::operator-=(const mQUATERNION4D<Type>		&value)
			{
				if (this == &value) { return(*this); }
				this->q0 -= value.q0;
				this->qV -= value.qV;
				return(*this);
			}
			template<typename Type>
			mQUATERNION4D<Type> mQUATERNION4D<Type>::operator*(const Type		&value)
			{
				return(mQUATERNION4D<Type>(this->q0 * value, Vector3D<Type>(this->qV.X * value, this->qV.Y * value, this->qV.Z * value)));
			}
			template<typename Type>
			mQUATERNION4D<Type> &mQUATERNION4D<Type>::operator*=(const mQUATERNION4D<Type>		&value)
			{
				if (this == &value) { return(*this); }
				this->q0 *= value.q0;
				this->qV.X *= value.qV.X;
				this->qV.Y *= value.qV.Y;
				this->qV.Z *= value.qV.Z;
				return(*this);
			}
			template<typename Type>
			void mQUATERNION4D<Type>::ZeroQuarternion()
			{
				this->q0 = 0.0;
				this->qV.Zero();
			}
		};
	};
};

#endif