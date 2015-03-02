#ifndef Matrix3X3_H
#define Matrix3X3_H
#include "..\Globals\GlobalDatatypes.h"

using namespace Aurora::DataTypes;

namespace Aurora
{
	/*!
	Namespace: Math

	This namespace holds needed math operations for the engine.
	*/
	namespace Math
	{
		template<typename MatrixType>
		class MATRIX3X3
		{
		public:
			MATRIX3X3();
			MATRIX3X3(MatrixType m00, MatrixType m01, MatrixType m02, MatrixType m10, MatrixType m11, MatrixType m12, MatrixType m20, MatrixType m21, MatrixType m22);
			MATRIX3X3(const MATRIX3X3<MatrixType> &mat);
			~MATRIX3X3();
			MatrixType M11, M12, M13;
			MatrixType M21, M22, M23;
			MatrixType M31, M32, M33;

			MATRIX3X3<MatrixType> operator+(const MatrixType				&value);
			MATRIX3X3<MatrixType> operator+(const MATRIX3X3<MatrixType>			&value);

			MATRIX3X3<MatrixType> operator-(const MatrixType				&value);
			MATRIX3X3<MatrixType> operator-(const MATRIX3X3<MatrixType>			&value);

			MATRIX3X3<MatrixType> &operator=(const MATRIX3X3<MatrixType>		&value);

			MATRIX3X3<MatrixType> &operator+=(const MatrixType			&value);
			MATRIX3X3<MatrixType> &operator+=(const MATRIX3X3<MatrixType>		&value);

			MATRIX3X3<MatrixType> &operator-=(const MatrixType			&value);
			MATRIX3X3<MatrixType> &operator-=(const MATRIX3X3<MatrixType>		&value);

			MATRIX3X3<MatrixType> operator*(const MatrixType				&value);
			MATRIX3X3<MatrixType> operator*(const MATRIX3X3<MatrixType>			&value);

			MATRIX3X3<MatrixType> &operator*=(const MatrixType			&value);
			MATRIX3X3<MatrixType> &operator*=(const MATRIX3X3<MatrixType>		&value);

		protected:
		};
		template<typename MatrixType>
		MATRIX3X3<MatrixType>::MATRIX3X3()
		{
			this->M11 = 0;			this->M12 = 0;			this->M13 = 0;
			this->M21 = 0;			this->M22 = 0;			this->M23 = 0;
			this->M31 = 0;			this->M32 = 0;			this->M33 = 0;
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType>::MATRIX3X3(MatrixType m00, MatrixType m01, MatrixType m02, MatrixType m10, MatrixType m11, MatrixType m12, MatrixType m20, MatrixType m21, MatrixType m22)
		{
			this->M11 = m00;		this->M12 = m01;		this->M13 = m02;
			this->M21 = m10;		this->M22 = m11;		this->M23 = m12;
			this->M31 = m20;		this->M32 = m21;		this->M33 = m22;
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType>::MATRIX3X3(const MATRIX3X3 &mat)
		{
			this->M11 = mat.M11;	this->M12 = mat.M12;	this->M13 = mat.M13;
			this->M21 = mat.M21;	this->M22 = mat.M22;	this->M23 = mat.M23;
			this->M31 = mat.M31;	this->M32 = mat.M32;	this->M33 = mat.M33;
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType>::~MATRIX3X3()
		{

		}

		/*
		m00		m01		m02
		m10		m11		m12
		m20		m21		m22
		*/
		template<typename MatrixType>
		MATRIX3X3<MatrixType> MATRIX3X3<MatrixType>::operator+(const MatrixType			&value)
		{
			return(MATRIX3X3(this->M11 + value,	// m00
				this->M12 + value,	// m01
				this->M13 + value,	// m02
				this->M21 + value,	// m10
				this->M22 + value,	// m11
				this->M23 + value,	// m12
				this->M31 + value,	// m20
				this->M32 + value,	// m21
				this->M33 + value	// m22
				));
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> MATRIX3X3<MatrixType>::operator+(const MATRIX3X3<MatrixType>		&value)
		{
			return(MATRIX3X3(this->M11 + value.M11,	// m00
				this->M12 + value.M12,	// m01
				this->M13 + value.M13,	// m02
				this->M21 + value.M21,	// m10
				this->M22 + value.M22,	// m11
				this->M23 + value.M23,	// m12
				this->M31 + value.M31,	// m20
				this->M32 + value.M32,	// m21
				this->M33 + value.M33	// m22
				));
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> MATRIX3X3<MatrixType>::operator-(const MatrixType			&value)
		{
			return(MATRIX3X3(this->M11 - value,	// m00
				this->M12 - value,	// m01
				this->M13 - value,	// m02
				this->M21 - value,	// m10
				this->M22 - value,	// m11
				this->M23 - value,	// m12
				this->M31 - value,	// m20
				this->M32 - value,	// m21
				this->M33 - value	// m22
				));
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> MATRIX3X3<MatrixType>::operator-(const MATRIX3X3<MatrixType>		&value)
		{
			return(MATRIX3X3(this->M11 - value.M11,	// m00
				this->M12 - value.M12,	// m01
				this->M13 - value.M13,	// m02
				this->M21 - value.M21,	// m10
				this->M22 - value.M22,	// m11
				this->M23 - value.M22,	// m12
				this->M31 - value.M31,	// m20
				this->M32 - value.M32,	// m21
				this->M33 - value.M33	// m22
				));
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> &MATRIX3X3<MatrixType>::operator=(const MATRIX3X3<MatrixType>		&value)
		{
			if (this == &value) { return(*this); }
			this->M11 = value.M11;				this->M12 = value.M12;			this->M13 = value.M13;
			this->M21 = value.M21;				this->M22 = value.M22;			this->M23 = value.M23;
			this->M31 = value.M31;				this->M32 = value.M32;			this->M33 = value.M33;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> &MATRIX3X3<MatrixType>::operator+=(const MatrixType		&value)
		{
			this->M11 += value;					this->M12 += value;				this->M13 += value;
			this->M21 += value;					this->M22 += value;				this->M23 += value;
			this->M31 += value;					this->M32 += value;				this->M33 += value;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> &MATRIX3X3<MatrixType>::operator+=(const MATRIX3X3<MatrixType>	&value)
		{
			if (this == &value) { return(*this); }
			this->M11 += value.M11;				this->M12 += value.M12;			this->M13 += value.M13;
			this->M21 += value.M21;				this->M22 += value.M22;			this->M23 += value.M23;
			this->M31 += value.M31;				this->M32 += value.M32;			this->M33 += value.M33;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> &MATRIX3X3<MatrixType>::operator-=(const MatrixType		&value)
		{
			this->M11 -= value;					this->M12 -= value;				this->M13 -= value;
			this->M21 -= value;					this->M22 -= value;				this->M23 -= value;
			this->M31 -= value;					this->M32 -= value;				this->M33 -= value;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> &MATRIX3X3<MatrixType>::operator-=(const MATRIX3X3<MatrixType>	&value)
		{
			if (this == &value) { return(*this); }
			this->M11 -= value.M11;				this->M12 -= value.M12;			this->M13 -= value.M13;
			this->M21 -= value.M21;				this->M22 -= value.M22;			this->M23 -= value.M23;
			this->M31 -= value.M31;				this->M32 -= value.M32;			this->M33 -= value.M33;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> MATRIX3X3<MatrixType>::operator*(const MatrixType			&value)
		{
			return(MATRIX3X3(this->M11 * value,	// m00
				this->M12 * value,	// m01
				this->M13 * value,	// m02
				this->M21 * value,	// m10
				this->M22 * value,	// m11
				this->M23 * value,	// m12
				this->M31 * value,	// m20
				this->M32 * value,	// m21
				this->M33 * value	// m22
				));
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> MATRIX3X3<MatrixType>::operator*(const MATRIX3X3<MatrixType>		&value)
		{
			/*MATRIX3X3 mat;
			mat.M11 = this->M11 * value.M11 + this->M12 * value.M21 + this->M13 * value.M31;
			mat.M12 = this->M11 * value.M12 + this->M12 * value.M22 + this->M13 * value.M32;
			mat.M13 = this->M11 * value.M13 + this->M12 * value.M23 + this->M13 * value.M33;

			mat.M21 = this->M21 * value.M11 + this->M22 * value.M21 + this->M23 * value.M31;
			mat.M22 = this->M21 * value.M12 + this->M22 * value.M22 + this->M23 * value.M32;
			mat.M23 = this->M21 * value.M13 + this->M22 * value.M23 + this->M23 * value.M33;

			mat.M31 = this->M31 * value.M11 + this->M32 * value.M21 + this->M33 * value.M31;
			mat.M32 = this->M31 * value.M12 + this->M32 * value.M22 + this->M33 * value.M32;
			mat.M33 = this->M31 * value.M13 + this->M32 * value.M23 + this->M33 * value.M33;*/
			return(MATRIX3X3(this->M11 * value.M11 + this->M12 * value.M21 + this->M13 * value.M31,		// m00
				this->M11 * value.M12 + this->M12 * value.M22 + this->M13 * value.M32,		// m01
				this->M11 * value.M13 + this->M12 * value.M23 + this->M13 * value.M33,		// m02
				this->M21 * value.M11 + this->M22 * value.M21 + this->M23 * value.M31,		// m10
				this->M21 * value.M12 + this->M22 * value.M22 + this->M23 * value.M32,		// m11
				this->M21 * value.M13 + this->M22 * value.M23 + this->M23 * value.M33,		// m12
				this->M31 * value.M11 + this->M32 * value.M21 + this->M33 * value.M31,		// m20
				this->M31 * value.M12 + this->M32 * value.M22 + this->M33 * value.M32,		// m21
				this->M31 * value.M13 + this->M32 * value.M23 + this->M33 * value.M33));	// m22




		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> &MATRIX3X3<MatrixType>::operator*=(const MatrixType			&value)
		{
			this->M11 *= value;	this->M12 *= value; this->M13 *= value;
			this->M21 *= value; this->M22 *= value; this->M23 *= value;
			this->M31 *= value; this->M32 *= value; this->M33 *= value;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX3X3<MatrixType> &MATRIX3X3<MatrixType>::operator*=(const MATRIX3X3<MatrixType>		&value)
		{
			MATRIX3X3 mat = *this;
			this->M11 = mat.M11 * value.M11 + mat.M12 * value.M21 + mat.M13 * value.M31;
			this->M12 = mat.M11 * value.M12 + mat.M12 * value.M22 + mat.M13 * value.M32;
			this->M13 = mat.M11 * value.M13 + mat.M12 * value.M23 + mat.M13 * value.M33;

			this->M21 = mat.M21 * value.M11 + mat.M22 * value.M21 + mat.M23 * value.M31;
			this->M22 = mat.M21 * value.M12 + mat.M22 * value.M22 + mat.M23 * value.M32;
			this->M23 = mat.M21 * value.M13 + mat.M22 * value.M23 + mat.M23 * value.M33;

			this->M31 = mat.M31 * value.M11 + mat.M32 * value.M21 + mat.M33 * value.M31;
			this->M32 = mat.M31 * value.M12 + mat.M32 * value.M22 + mat.M33 * value.M32;
			this->M33 = mat.M31 * value.M13 + mat.M32 * value.M23 + mat.M33 * value.M33;
			return(*this);
		}
	}

}

#endif