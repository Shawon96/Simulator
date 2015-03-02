#ifndef Matrix4D_H
#define Matrix4D_H
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
		class MATRIX4X4
		{
		public:
			/*!
			\brief Basic class constructor. This will format the matrix as an Identity matrix.
			*/
			MATRIX4X4();
			/*!
			\brief Use this constructor to format the matrix with the wanted values. The are as follows:

			| column |  column |column |column
			------------------------------------
			row |	m00		m01		m02		m03
			row	|	m10		m11		m12		m13
			row	|	m20		m21		m22		m23
			row	|	m30		m31		m32		m33
			*/
			MATRIX4X4(MatrixType m00, MatrixType m01, MatrixType m02, MatrixType m03, MatrixType m10, MatrixType m11, MatrixType m12, MatrixType m13, MatrixType m20, MatrixType m21, MatrixType m22, MatrixType m23, MatrixType m30, MatrixType m31, MatrixType m32, MatrixType m33);
			/*!
			\brief This is this classes copy-constructor.
			\param &mat Another 4x4 matrix.
			*/
			MATRIX4X4(const MATRIX4X4<MatrixType> &mat);
			/*!
			\brief Class destructor.
			*/
			~MATRIX4X4();
			MatrixType M11, M12, M13, M14;	/*!< First row of the matrix.	*/
			MatrixType M21, M22, M23, M24;	/*!< Second row of the matrix.	*/
			MatrixType M31, M32, M33, M34;	/*!< Third row of the matrix.	*/
			MatrixType M41, M42, M43, M44;	/*!< Fourth row of the matrix.	*/

			/*!
			\brief Adds a scalar value into every element of the matrix.
			\param &value The scalar value to be added.
			\return A copy of this matrix with the added scalar value. Notice the is not added directly into the class, but it is copyed to the assigned to the place needed. If you need to add and assign the data into this class, then use the += operator.
			*/
			MATRIX4X4<MatrixType> operator+(const MatrixType				&value);
			/*!
			\brief Adds another 4x4 matrix with this class and returns a copy.
			\param &value The other 4x4 matrix to be added with this class.
			\return A copy of the added matrixes.
			*/
			MATRIX4X4<MatrixType> operator+(const MATRIX4X4<MatrixType>			&value);

			/*!
			\brief Same properties as the addition but in this case it is negation.
			*/
			MATRIX4X4<MatrixType> operator-(const MatrixType				&value);
			/*!
			\brief Same properties as the addition but in this case it is negation.
			*/
			MATRIX4X4<MatrixType> operator-(const MATRIX4X4<MatrixType>			&value);

			/*!
			\brief This is the assignment operator, it will assign the values of another 4x4 matrix into this one and returns an reference to *this.
			\param &value Another 4x4 matrix whos values needs to be assigned into this class.
			\return An reference to *this.
			*/
			MATRIX4X4<MatrixType> &operator=(const MATRIX4X4<MatrixType>		&value);

			/*!
			\brief This will add the given scalar value directly into the class and returns an reference to *this.
			\param &value The scalar value to be added.
			\return An reference to *this.
			*/
			MATRIX4X4<MatrixType> &operator+=(const MatrixType			&value);
			/*!
			\brief This will add the values of another 4x4 matrix directly into this class and returns an reference to *this.
			\param &value Another 4x4 matrix.
			\return Returns an reference to *this.
			*/
			MATRIX4X4<MatrixType> &operator+=(const MATRIX4X4<MatrixType>		&value);

			/*!
			\brief Same as addition assignment but negation in this case.
			*/
			MATRIX4X4<MatrixType> &operator-=(const MatrixType			&value);
			/*!
			\brief Same as addition assignment but negation in this case.
			*/
			MATRIX4X4<MatrixType> &operator-=(const MATRIX4X4<MatrixType>		&value);

			/*!
			\brief This operator will multiply every component of this class by the given scalar value and then return the result as a copy.
			\param &value The scalar to be multiplyed.
			\return Returns an copy of the result.
			*/
			MATRIX4X4<MatrixType> operator*(const MatrixType				&value);
			/*!
			\brief This will multiply an another 4x4 matrix and return the result as a copy.
			\param &value Another 4x4 matrix.
			\return The result copy.
			*/
			MATRIX4X4<MatrixType> operator*(const MATRIX4X4<MatrixType>			&value);

			/*!
			\brief Same as normal multiplication but in this case the result will be inserted into the class and the operator will return an reference to *this.
			*/
			MATRIX4X4<MatrixType> &operator*=(const MatrixType			&value);
			/*!
			\brief Same as normal multiplication but in this case the result will be inserted into the class and the operator will return an reference to *this.
			*/
			MATRIX4X4<MatrixType> &operator*=(const MATRIX4X4<MatrixType>		&value);

		protected:
		};

		template<typename MatrixType>
		MATRIX4X4<MatrixType>::MATRIX4X4()
		{
			this->M11 = 0;			this->M12 = 0;			this->M13 = 0;		this->M14 = 0;
			this->M21 = 0;			this->M22 = 0;			this->M23 = 0;		this->M24 = 0;
			this->M31 = 0;			this->M32 = 0;			this->M33 = 0;		this->M34 = 0;
			this->M41 = 0;			this->M42 = 0;			this->M43 = 0;		this->M44 = 0;
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType>::MATRIX4X4(MatrixType m00, MatrixType m01, MatrixType m02, MatrixType m03, MatrixType m10, MatrixType m11, MatrixType m12, MatrixType m13, MatrixType m20, MatrixType m21, MatrixType m22, MatrixType m23, MatrixType m30, MatrixType m31, MatrixType m32, MatrixType m33)
		{
			this->M11 = m00;		this->M12 = m01;		this->M13 = m02;	this->M14 = m03;
			this->M21 = m10;		this->M22 = m11;		this->M23 = m12;	this->M24 = m13;
			this->M31 = m20;		this->M32 = m21;		this->M33 = m22;	this->M34 = m23;
			this->M41 = m30;		this->M42 = m31;		this->M43 = m32;	this->M44 = m33;
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType>::MATRIX4X4(const MATRIX4X4<MatrixType> &mat)
		{
			this->M11 = mat.M11;	this->M12 = mat.M12;	this->M13 = mat.M13;	this->M14 = mat.M14;
			this->M21 = mat.M21;	this->M22 = mat.M22;	this->M23 = mat.M23;	this->M24 = mat.M24;
			this->M31 = mat.M31;	this->M32 = mat.M32;	this->M33 = mat.M33;	this->M34 = mat.M34;
			this->M41 = mat.M41;	this->M42 = mat.M42;	this->M43 = mat.M43;	this->M44 = mat.M44;
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType>::~MATRIX4X4()
		{

		}

		/*
		m00		m01		m02		m03
		m10		m11		m12		m13
		m20		m21		m22		m23
		m30		m31		m32		m33
		*/
		template<typename MatrixType>
		MATRIX4X4<MatrixType> MATRIX4X4<MatrixType>::operator+(const MatrixType			&value)
		{
			return(MATRIX4X4<MatrixType>(this->M11 + value,	// m00
				this->M12 + value,	// m01
				this->M13 + value,	// m02
				this->M14 + value,	// m03
				this->M21 + value,	// m10
				this->M22 + value,	// m11
				this->M23 + value,	// m12
				this->M24 + value,	// m13
				this->M31 + value,	// m20
				this->M32 + value,	// m21
				this->M33 + value,	// m22
				this->M34 + value,	// m23
				this->M41 + value,	// m30
				this->M42 + value,	// m31
				this->M43 + value,	// m32
				this->M44 + value	// m33
				));
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> MATRIX4X4<MatrixType>::operator+(const MATRIX4X4<MatrixType>		&value)
		{
			return(MATRIX4X4<MatrixType>(this->M11 + value.M11,	// m00
				this->M12 + value.M12,	// m01
				this->M13 + value.M13,	// m02
				this->M14 + value.M14,	// m03
				this->M21 + value.M21,	// m10
				this->M22 + value.M22,	// m11
				this->M23 + value.M23,	// m12
				this->M24 + value.M24,	// m13
				this->M31 + value.M31,	// m20
				this->M32 + value.M32,	// m21
				this->M33 + value.M33,	// m22
				this->M34 + value.M34,	// m23
				this->M41 + value.M41,	// m30
				this->M42 + value.M42,	// m31
				this->M43 + value.M43,	// m32
				this->M44 + value.M44	// m33
				));
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> MATRIX4X4<MatrixType>::operator-(const MatrixType			&value)
		{
			return(MATRIX4X4<MatrixType>(this->M11 - value,	// m00
				this->M12 - value,	// m01
				this->M13 - value,	// m02
				this->M14 - value,	// m03
				this->M21 - value,	// m10
				this->M22 - value,	// m11
				this->M23 - value,	// m12
				this->M24 - value,	// m13
				this->M31 - value,	// m20
				this->M32 - value,	// m21
				this->M33 - value,	// m22
				this->M34 - value,	// m23
				this->M41 - value,	// m30
				this->M42 - value,	// m31
				this->M43 - value,	// m32
				this->M44 - value	// m33
				));
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> MATRIX4X4<MatrixType>::operator-(const MATRIX4X4<MatrixType>		&value)
		{
			return(MATRIX4X4<MatrixType>(this->M11 - value.M11,	// m00
				this->M12 - value.M12,	// m01
				this->M13 - value.M13,	// m02
				this->M14 - value.M14,	// m03
				this->M21 - value.M21,	// m10
				this->M22 - value.M22,	// m11
				this->M23 - value.M23,	// m12
				this->M24 - value.M24,	// m13
				this->M31 - value.M31,	// m20
				this->M32 - value.M32,	// m21
				this->M33 - value.M33,	// m22
				this->M34 - value.M34,	// m23
				this->M41 - value.M41,	// m30
				this->M42 - value.M42,	// m31
				this->M43 - value.M43,	// m32
				this->M44 - value.M44	// m33
				));
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> &MATRIX4X4<MatrixType>::operator=(const MATRIX4X4<MatrixType>		&value)
		{
			if (this == &value) { return(*this); }
			this->M11 = value.M11;	this->M12 = value.M12;	this->M13 = value.M13;	this->M14 = value.M14;
			this->M21 = value.M21;	this->M22 = value.M22;	this->M23 = value.M23;	this->M24 = value.M24;
			this->M31 = value.M31;	this->M32 = value.M32;	this->M33 = value.M33;	this->M34 = value.M34;
			this->M41 = value.M41;	this->M42 = value.M42;	this->M43 = value.M43;	this->M44 = value.M44;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> &MATRIX4X4<MatrixType>::operator+=(const MatrixType		&value)
		{
			this->M11 += value;	this->M12 += value;	this->M13 += value;	this->M14 += value;
			this->M21 += value;	this->M22 += value;	this->M23 += value;	this->M24 += value;
			this->M31 += value;	this->M32 += value;	this->M33 += value;	this->M34 += value;
			this->M41 += value;	this->M42 += value;	this->M43 += value;	this->M44 += value;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> &MATRIX4X4<MatrixType>::operator+=(const MATRIX4X4<MatrixType>	&value)
		{
			if (this == &value) { return(*this); }
			this->M11 += value.M11;	this->M12 += value.M12;	this->M13 += value.M13;	this->M14 += value.M14;
			this->M21 += value.M21;	this->M22 += value.M22;	this->M23 += value.M23;	this->M24 += value.M24;
			this->M31 += value.M31;	this->M32 += value.M32;	this->M33 += value.M33;	this->M34 += value.M34;
			this->M41 += value.M41;	this->M42 += value.M42;	this->M43 += value.M43;	this->M44 += value.M44;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> &MATRIX4X4<MatrixType>::operator-=(const MatrixType		&value)
		{
			this->M11 -= value;	this->M12 -= value;	this->M13 -= value;	this->M14 -= value;
			this->M21 -= value;	this->M22 -= value;	this->M23 -= value;	this->M24 -= value;
			this->M31 -= value;	this->M32 -= value;	this->M33 -= value;	this->M34 -= value;
			this->M41 -= value;	this->M42 -= value;	this->M43 -= value;	this->M44 -= value;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> &MATRIX4X4<MatrixType>::operator-=(const MATRIX4X4<MatrixType>	&value)
		{
			if (this == &value) { return(*this); }
			this->M11 -= value.M11;	this->M12 -= value.M12;	this->M13 -= value.M13;	this->M14 -= value.M14;
			this->M21 -= value.M21;	this->M22 -= value.M22;	this->M23 -= value.M23;	this->M24 -= value.M24;
			this->M31 -= value.M31;	this->M32 -= value.M32;	this->M33 -= value.M33;	this->M34 -= value.M34;
			this->M41 -= value.M41;	this->M42 -= value.M42;	this->M43 -= value.M43;	this->M44 -= value.M44;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> MATRIX4X4<MatrixType>::operator*(const MatrixType			&value)
		{
			return(MATRIX4X4<MatrixType>(this->M11 * value,	// m00
				this->M12 * value,	// m01
				this->M13 * value,	// m02
				this->M14 * value,	// m03
				this->M21 * value,	// m10
				this->M22 * value,	// m11
				this->M23 * value,	// m12
				this->M24 * value,	// m13
				this->M31 * value,	// m20
				this->M32 * value,	// m21
				this->M33 * value,	// m22
				this->M34 * value,	// m23
				this->M41 * value,	// m30
				this->M42 * value,	// m31
				this->M43 * value,	// m32
				this->M44 * value	// m33
				));
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> MATRIX4X4<MatrixType>::operator*(const MATRIX4X4<MatrixType>		&value)
		{
			/*MATRIX4X4 mat;
			mat.M11 = this->M11 * value.M11 + this->M12 * value.M21 + this->M13 * value.M31 + this->M14 * value.M41;
			mat.M12 = this->M11 * value.M12 + this->M12 * value.M22 + this->M13 * value.M32 + this->M14 * value.M42;
			mat.M13 = this->M11 * value.M13 + this->M12 * value.M23 + this->M13 * value.M33 + this->M14 * value.M43;
			mat.M14 = this->M11 * value.M14 + this->M12 * value.M24 + this->M13 * value.M34 + this->M14 * value.M44;

			mat.M21 = this->M21 * value.M11 + this->M22 * value.M21 + this->M23 * value.M31 + this->M24 * value.M41;
			mat.M22 = this->M21 * value.M12 + this->M22 * value.M22 + this->M23 * value.M32 + this->M24 * value.M42;
			mat.M23 = this->M21 * value.M13 + this->M22 * value.M23 + this->M23 * value.M33 + this->M24 * value.M43;
			mat.M24 = this->M21 * value.M14 + this->M22 * value.M24 + this->M23 * value.M34 + this->M24 * value.M44;

			mat.M31 = this->M31 * value.M11 + this->M32 * value.M21 + this->M33 * value.M31 + this->M34 * value.M41;
			mat.M32 = this->M31 * value.M12 + this->M32 * value.M22 + this->M33 * value.M32 + this->M34 * value.M42;
			mat.M33 = this->M31 * value.M13 + this->M32 * value.M23 + this->M33 * value.M33 + this->M34 * value.M43;
			mat.M34 = this->M31 * value.M14 + this->M32 * value.M24 + this->M33 * value.M34 + this->M34 * value.M44;

			mat.M41 = this->M41 * value.M11 + this->M42 * value.M21 + this->M43 * value.M31 + this->M44 * value.M41;
			mat.M42 = this->M41 * value.M12 + this->M42 * value.M22 + this->M43 * value.M32 + this->M44 * value.M42;
			mat.M43 = this->M41 * value.M13 + this->M42 * value.M23 + this->M43 * value.M33 + this->M44 * value.M43;
			mat.M44 = this->M41 * value.M14 + this->M42 * value.M24 + this->M43 * value.M34 + this->M44 * value.M44;*/
			return(MATRIX4X4<MatrixType>(this->M11 * value.M11 + this->M12 * value.M21 + this->M13 * value.M31 + this->M14 * value.M41,
				this->M11 * value.M12 + this->M12 * value.M22 + this->M13 * value.M32 + this->M14 * value.M42,
				this->M11 * value.M13 + this->M12 * value.M23 + this->M13 * value.M33 + this->M14 * value.M43,
				this->M11 * value.M14 + this->M12 * value.M24 + this->M13 * value.M34 + this->M14 * value.M44,
				this->M21 * value.M11 + this->M22 * value.M21 + this->M23 * value.M31 + this->M24 * value.M41,
				this->M21 * value.M12 + this->M22 * value.M22 + this->M23 * value.M32 + this->M24 * value.M42,
				this->M21 * value.M13 + this->M22 * value.M23 + this->M23 * value.M33 + this->M24 * value.M43,
				this->M21 * value.M14 + this->M22 * value.M24 + this->M23 * value.M34 + this->M24 * value.M44,
				this->M31 * value.M11 + this->M32 * value.M21 + this->M33 * value.M31 + this->M34 * value.M41,
				this->M31 * value.M12 + this->M32 * value.M22 + this->M33 * value.M32 + this->M34 * value.M42,
				this->M31 * value.M13 + this->M32 * value.M23 + this->M33 * value.M33 + this->M34 * value.M43,
				this->M31 * value.M14 + this->M32 * value.M24 + this->M33 * value.M34 + this->M34 * value.M44,
				this->M41 * value.M11 + this->M42 * value.M21 + this->M43 * value.M31 + this->M44 * value.M41,
				this->M41 * value.M12 + this->M42 * value.M22 + this->M43 * value.M32 + this->M44 * value.M42,
				this->M41 * value.M13 + this->M42 * value.M23 + this->M43 * value.M33 + this->M44 * value.M43,
				this->M41 * value.M14 + this->M42 * value.M24 + this->M43 * value.M34 + this->M44 * value.M44
				));
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> &MATRIX4X4<MatrixType>::operator*=(const MatrixType			&value)
		{
			this->M11 *= value;	this->M12 *= value;	this->M13 *= value;	this->M14 *= value;
			this->M21 *= value;	this->M22 *= value;	this->M23 *= value;	this->M24 *= value;
			this->M31 *= value;	this->M32 *= value;	this->M33 *= value;	this->M34 *= value;
			this->M41 *= value;	this->M42 *= value;	this->M43 *= value;	this->M44 *= value;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX4X4<MatrixType> &MATRIX4X4<MatrixType>::operator*=(const MATRIX4X4<MatrixType>		&value)
		{
			MATRIX4X4<MatrixType> mat = *this;
			this->M11 = mat.M11 * value.M11 + mat.M12 * value.M21 + mat.M13 * value.M31 + mat.M14 * value.M41;
			this->M12 = mat.M11 * value.M12 + mat.M12 * value.M22 + mat.M13 * value.M32 + mat.M14 * value.M42;
			this->M13 = mat.M11 * value.M13 + mat.M12 * value.M23 + mat.M13 * value.M33 + mat.M14 * value.M43;
			this->M14 = mat.M11 * value.M14 + mat.M12 * value.M24 + mat.M13 * value.M34 + mat.M14 * value.M44;

			this->M21 = mat.M21 * value.M11 + mat.M22 * value.M21 + mat.M23 * value.M31 + mat.M24 * value.M41;
			this->M22 = mat.M21 * value.M12 + mat.M22 * value.M22 + mat.M23 * value.M32 + mat.M24 * value.M42;
			this->M23 = mat.M21 * value.M13 + mat.M22 * value.M23 + mat.M23 * value.M33 + mat.M24 * value.M43;
			this->M24 = mat.M21 * value.M14 + mat.M22 * value.M24 + mat.M23 * value.M34 + mat.M24 * value.M44;

			this->M31 = mat.M31 * value.M11 + mat.M32 * value.M21 + mat.M33 * value.M31 + mat.M34 * value.M41;
			this->M32 = mat.M31 * value.M12 + mat.M32 * value.M22 + mat.M33 * value.M32 + mat.M34 * value.M42;
			this->M33 = mat.M31 * value.M13 + mat.M32 * value.M23 + mat.M33 * value.M33 + mat.M34 * value.M43;
			this->M34 = mat.M31 * value.M14 + mat.M32 * value.M24 + mat.M33 * value.M34 + mat.M34 * value.M44;

			this->M41 = mat.M41 * value.M11 + mat.M42 * value.M21 + mat.M43 * value.M31 + mat.M44 * value.M41;
			this->M42 = mat.M41 * value.M12 + mat.M42 * value.M22 + mat.M43 * value.M32 + mat.M44 * value.M42;
			this->M43 = mat.M41 * value.M13 + mat.M42 * value.M23 + mat.M43 * value.M33 + mat.M44 * value.M43;
			this->M44 = mat.M41 * value.M14 + mat.M42 * value.M24 + mat.M43 * value.M34 + mat.M44 * value.M44;
			return(*this);
		}
	}
}

#endif