#ifndef MATRIX2X2_H
#define MATRIX2X2_H
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
		class MATRIX2X2
		{
		public:
			MATRIX2X2();
			MATRIX2X2(MatrixType m00, MatrixType m01, MatrixType m10, MatrixType m11);
			MATRIX2X2(const MATRIX2X2<MatrixType> &mat);
			~MATRIX2X2();
			MatrixType M11, M12;
			MatrixType M21, M22;

			MATRIX2X2<MatrixType> operator+(const MatrixType				&value);
			MATRIX2X2<MatrixType> operator+(const MATRIX2X2<MatrixType>			&value);

			MATRIX2X2<MatrixType> operator-(const MatrixType				&value);
			MATRIX2X2<MatrixType> operator-(const MATRIX2X2<MatrixType>			&value);

			MATRIX2X2<MatrixType> &operator=(const MATRIX2X2<MatrixType>		&value);

			MATRIX2X2<MatrixType> &operator+=(const MatrixType			&value);
			MATRIX2X2<MatrixType> &operator+=(const MATRIX2X2<MatrixType>		&value);

			MATRIX2X2<MatrixType> &operator-=(const MatrixType			&value);
			MATRIX2X2<MatrixType> &operator-=(const MATRIX2X2<MatrixType>		&value);

			MATRIX2X2<MatrixType> operator*(const MatrixType				&value);
			MATRIX2X2<MatrixType> operator*(const MATRIX2X2<MatrixType>			&value);

			MATRIX2X2<MatrixType> &operator*=(const MatrixType			&value);
			MATRIX2X2<MatrixType> &operator*=(const MATRIX2X2<MatrixType>		&value);

		protected:
		};
		template<typename MatrixType>
		MATRIX2X2<MatrixType>::MATRIX2X2()
		{
			this->M11 = 0; this->M12 = 0;
			this->M21 = 0; this->M22 = 0;
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType>::MATRIX2X2(MatrixType m00, MatrixType m01, MatrixType m10, MatrixType m11)
		{
			this->M11 = m00;		this->M12 = m01;
			this->M21 = m10;		this->M22 = m11;
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType>::MATRIX2X2(const MATRIX2X2<MatrixType> &mat)
		{
			this->M11 = mat.M11;	this->M12 = mat.M12;
			this->M21 = mat.M21;	this->M22 = mat.M22;
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType>::~MATRIX2X2()
		{

		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> MATRIX2X2<MatrixType>::operator+(const MatrixType			&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 + value;		mat.M12 = this->M12 + value;
			mat.M21 = this->M21 + value;		mat.M22 = this->M22 + value;
			return(mat);*/
			return(MATRIX2X2(this->M11 + value, this->M12 + value, this->M21 + value, this->M22 + value));
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> MATRIX2X2<MatrixType>::operator+(const MATRIX2X2<MatrixType>		&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 + value.M11;	mat.M12 = this->M12 + value.M12;
			mat.M21 = this->M21 + value.M21;	mat.M22 = this->M22 + value.M22;
			return(mat);*/
			return(MATRIX2X2(this->M11 + value.M11, this->M12 + value.M12, this->M21 + value.M21, this->M22 + value.M22));
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> MATRIX2X2<MatrixType>::operator-(const MatrixType			&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 - value;		mat.M12 = this->M12 - value;
			mat.M21 = this->M21 - value;		mat.M22 = this->M22 - value;
			return(mat);*/
			return(MATRIX2X2(this->M11 - value, this->M12 - value, this->M21 - value, this->M22 - value));
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> MATRIX2X2<MatrixType>::operator-(const MATRIX2X2<MatrixType>		&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 - value.M11;	mat.M12 = this->M12 - value.M12;
			mat.M21 = this->M21 - value.M21;	mat.M22 = this->M22 - value.M22;
			return(mat);*/
			return(MATRIX2X2(this->M11 - value.M11, this->M12 - value.M12, this->M21 - value.M21, this->M22 - value.M22));
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> &MATRIX2X2<MatrixType>::operator=(const MATRIX2X2<MatrixType>		&value)
		{
			if (this == &value) { return(*this); }
			this->M11 = value.M11;				this->M12 = value.M12;
			this->M21 = value.M21;				this->M22 = value.M22;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> &MATRIX2X2<MatrixType>::operator+=(const MatrixType		&value)
		{
			this->M11 += value;					this->M12 += value;
			this->M21 += value;					this->M22 += value;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> &MATRIX2X2<MatrixType>::operator+=(const MATRIX2X2<MatrixType>	&value)
		{
			if (this == &value) { return(*this); }
			this->M11 += value.M11;				this->M12 += value.M12;
			this->M21 += value.M21;				this->M22 += value.M22;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> &MATRIX2X2<MatrixType>::operator-=(const MatrixType		&value)
		{
			this->M11 -= value;					this->M12 -= value;
			this->M21 -= value;					this->M22 -= value;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> &MATRIX2X2<MatrixType>::operator-=(const MATRIX2X2<MatrixType>	&value)
		{
			if (this == &value) { return(*this); }
			this->M11 -= value.M11;				this->M12 -= value.M12;
			this->M21 -= value.M21;				this->M22 -= value.M22;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> MATRIX2X2<MatrixType>::operator*(const MatrixType			&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 * value;		mat.M12 = this->M12 * value;
			mat.M21 = this->M21 * value;		mat.M22 = this->M22 * value;
			return(mat);*/
			return(MATRIX2X2(this->M11 * value, this->M12 * value, this->M21 * value, this->M22 * value));
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> MATRIX2X2<MatrixType>::operator*(const MATRIX2X2<MatrixType>		&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 * value.M11 + this->M12 * value.M21;		mat.M12 = this->M11 * value.M12 + this->M12 * value.M22;
			mat.M21 = this->M21 * value.M11 + this->M22 * value.M21;		mat.M22 = this->M21 * value.M12 + this->M22 * value.M22;
			return(mat);*/
			return(MATRIX2X2(this->M11 * value.M11 + this->M12 * value.M21,
				this->M11 * value.M12 + this->M12 * value.M22,
				this->M21 * value.M11 + this->M22 * value.M21,
				this->M21 * value.M12 + this->M22 * value.M22));
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> &MATRIX2X2<MatrixType>::operator*=(const MatrixType			&value)
		{
			this->M11 *= value;	this->M12 *= value;
			this->M21 *= value; this->M22 *= value;
			return(*this);
		}
		template<typename MatrixType>
		MATRIX2X2<MatrixType> &MATRIX2X2<MatrixType>::operator*=(const MATRIX2X2<MatrixType>		&value)
		{
			MATRIX2X2 mat = *this;
			this->M11 = mat.M11 * value.M11 + mat.M12 * value.M21;		this->M12 = mat.M11 * value.M12 + mat.M12 * value.M22;
			this->M21 = mat.M21 * value.M11 + mat.M22 * value.M21;		this->M22 = mat.M21 * value.M12 + mat.M22 * value.M22;
			return(*this);
		}
	}
}

#endif