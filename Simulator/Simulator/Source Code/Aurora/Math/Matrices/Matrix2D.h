#ifndef MATRIX2X2_H
#define MATRIX2X2_H
#include "../../Globals/GlobalOperations.h"

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
		class Matrix2D
		{
		public:
			Matrix2D();
			Matrix2D(MatrixType m00, MatrixType m01, MatrixType m10, MatrixType m11);
			Matrix2D(const Matrix2D<MatrixType> &mat);
			~Matrix2D();
			MatrixType M11, M12;
			MatrixType M21, M22;

			Matrix2D<MatrixType> operator+(const MatrixType				&value);
			Matrix2D<MatrixType> operator+(const Matrix2D<MatrixType>			&value);

			Matrix2D<MatrixType> operator-(const MatrixType				&value);
			Matrix2D<MatrixType> operator-(const Matrix2D<MatrixType>			&value);

			Matrix2D<MatrixType> &operator=(const Matrix2D<MatrixType>		&value);

			Matrix2D<MatrixType> &operator+=(const MatrixType			&value);
			Matrix2D<MatrixType> &operator+=(const Matrix2D<MatrixType>		&value);

			Matrix2D<MatrixType> &operator-=(const MatrixType			&value);
			Matrix2D<MatrixType> &operator-=(const Matrix2D<MatrixType>		&value);

			Matrix2D<MatrixType> operator*(const MatrixType				&value);
			Matrix2D<MatrixType> operator*(const Matrix2D<MatrixType>			&value);

			Matrix2D<MatrixType> &operator*=(const MatrixType			&value);
			Matrix2D<MatrixType> &operator*=(const Matrix2D<MatrixType>		&value);

		protected:
		};

		using Matrix2DBool = Matrix2D < bool >;
		using Matrix2DDouble = Matrix2D < double >;
		using Matrix2DFloat = Matrix2D < float >;
		using Matrix2DInt = Matrix2D < int >;
		using Matrix2DHalfPrecision = Matrix2D < half_float::half >;

		template<typename MatrixType>
		Matrix2D<MatrixType>::Matrix2D()
		{
			this->M11 = 0; this->M12 = 0;
			this->M21 = 0; this->M22 = 0;
		}
		template<typename MatrixType>
		Matrix2D<MatrixType>::Matrix2D(MatrixType m00, MatrixType m01, MatrixType m10, MatrixType m11)
		{
			this->M11 = m00;		this->M12 = m01;
			this->M21 = m10;		this->M22 = m11;
		}
		template<typename MatrixType>
		Matrix2D<MatrixType>::Matrix2D(const Matrix2D<MatrixType> &mat)
		{
			this->M11 = mat.M11;	this->M12 = mat.M12;
			this->M21 = mat.M21;	this->M22 = mat.M22;
		}
		template<typename MatrixType>
		Matrix2D<MatrixType>::~Matrix2D()
		{

		}
		template<typename MatrixType>
		Matrix2D<MatrixType> Matrix2D<MatrixType>::operator+(const MatrixType			&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 + value;		mat.M12 = this->M12 + value;
			mat.M21 = this->M21 + value;		mat.M22 = this->M22 + value;
			return(mat);*/
			return(Matrix2D(this->M11 + value, this->M12 + value, this->M21 + value, this->M22 + value));
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> Matrix2D<MatrixType>::operator+(const Matrix2D<MatrixType>		&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 + value.M11;	mat.M12 = this->M12 + value.M12;
			mat.M21 = this->M21 + value.M21;	mat.M22 = this->M22 + value.M22;
			return(mat);*/
			return(Matrix2D(this->M11 + value.M11, this->M12 + value.M12, this->M21 + value.M21, this->M22 + value.M22));
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> Matrix2D<MatrixType>::operator-(const MatrixType			&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 - value;		mat.M12 = this->M12 - value;
			mat.M21 = this->M21 - value;		mat.M22 = this->M22 - value;
			return(mat);*/
			return(Matrix2D(this->M11 - value, this->M12 - value, this->M21 - value, this->M22 - value));
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> Matrix2D<MatrixType>::operator-(const Matrix2D<MatrixType>		&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 - value.M11;	mat.M12 = this->M12 - value.M12;
			mat.M21 = this->M21 - value.M21;	mat.M22 = this->M22 - value.M22;
			return(mat);*/
			return(Matrix2D(this->M11 - value.M11, this->M12 - value.M12, this->M21 - value.M21, this->M22 - value.M22));
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> &Matrix2D<MatrixType>::operator=(const Matrix2D<MatrixType>		&value)
		{
			if (this == &value) { return(*this); }
			this->M11 = value.M11;				this->M12 = value.M12;
			this->M21 = value.M21;				this->M22 = value.M22;
			return(*this);
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> &Matrix2D<MatrixType>::operator+=(const MatrixType		&value)
		{
			this->M11 += value;					this->M12 += value;
			this->M21 += value;					this->M22 += value;
			return(*this);
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> &Matrix2D<MatrixType>::operator+=(const Matrix2D<MatrixType>	&value)
		{
			if (this == &value) { return(*this); }
			this->M11 += value.M11;				this->M12 += value.M12;
			this->M21 += value.M21;				this->M22 += value.M22;
			return(*this);
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> &Matrix2D<MatrixType>::operator-=(const MatrixType		&value)
		{
			this->M11 -= value;					this->M12 -= value;
			this->M21 -= value;					this->M22 -= value;
			return(*this);
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> &Matrix2D<MatrixType>::operator-=(const Matrix2D<MatrixType>	&value)
		{
			if (this == &value) { return(*this); }
			this->M11 -= value.M11;				this->M12 -= value.M12;
			this->M21 -= value.M21;				this->M22 -= value.M22;
			return(*this);
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> Matrix2D<MatrixType>::operator*(const MatrixType			&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 * value;		mat.M12 = this->M12 * value;
			mat.M21 = this->M21 * value;		mat.M22 = this->M22 * value;
			return(mat);*/
			return(Matrix2D(this->M11 * value, this->M12 * value, this->M21 * value, this->M22 * value));
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> Matrix2D<MatrixType>::operator*(const Matrix2D<MatrixType>		&value)
		{
			/*MATRIX2X2 mat;
			mat.M11 = this->M11 * value.M11 + this->M12 * value.M21;		mat.M12 = this->M11 * value.M12 + this->M12 * value.M22;
			mat.M21 = this->M21 * value.M11 + this->M22 * value.M21;		mat.M22 = this->M21 * value.M12 + this->M22 * value.M22;
			return(mat);*/
			return(Matrix2D(this->M11 * value.M11 + this->M12 * value.M21,
				this->M11 * value.M12 + this->M12 * value.M22,
				this->M21 * value.M11 + this->M22 * value.M21,
				this->M21 * value.M12 + this->M22 * value.M22));
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> &Matrix2D<MatrixType>::operator*=(const MatrixType			&value)
		{
			this->M11 *= value;	this->M12 *= value;
			this->M21 *= value; this->M22 *= value;
			return(*this);
		}
		template<typename MatrixType>
		Matrix2D<MatrixType> &Matrix2D<MatrixType>::operator*=(const Matrix2D<MatrixType>		&value)
		{
			Matrix2D mat = *this;
			this->M11 = mat.M11 * value.M11 + mat.M12 * value.M21;		this->M12 = mat.M11 * value.M12 + mat.M12 * value.M22;
			this->M21 = mat.M21 * value.M11 + mat.M22 * value.M21;		this->M22 = mat.M21 * value.M12 + mat.M22 * value.M22;
			return(*this);
		}
	}
}

#endif