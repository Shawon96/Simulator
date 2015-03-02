#ifndef Vector4D_H
#define Vector4D_H

#include "Matrix4D.h"

using namespace Aurora::DataTypes;
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
		template<typename VectorType>
		class VECTOR4D
		{
		public:
			VectorType X;
			VectorType Y;
			VectorType Z;
			VectorType W;
			VECTOR4D();
			VECTOR4D(VectorType x, VectorType y, VectorType z, VectorType w);
			VECTOR4D(const VECTOR4D<VectorType> &value);
			virtual ~VECTOR4D();
			VECTOR4D(VECTOR4D<VectorType> &&value);
			VECTOR4D<VectorType> & operator=(VECTOR4D<VectorType> && value);
			VECTOR4D<VectorType> &operator=(const VECTOR4D<VectorType>		&value);


#pragma region AdditionAndSubstractionOperators
			const VECTOR4D<VectorType> operator+(const VectorType			&value);

			const VECTOR4D<VectorType> operator+(const VECTOR4D<VectorType>		&value);

			const VECTOR4D<VectorType> operator-(const VectorType			&value);

			const VECTOR4D<VectorType> operator-(const VECTOR4D<VectorType>		&value);

			VECTOR4D<VectorType> &operator=(const VectorType			&value);

			VECTOR4D<VectorType> &operator+=(const VectorType		&value);

			VECTOR4D<VectorType> &operator+=(const VECTOR4D<VectorType>		&value);

			const VECTOR4D<VectorType> &operator-=(const VectorType		&value);

			const VECTOR4D<VectorType> &operator-=(const VECTOR4D<VectorType>		&value);
#pragma endregion AdditionAndSubstractionOperators

#pragma region DivisionAndMultiplicationOperators

			const VECTOR4D<VectorType> operator*(const VectorType		&value);

			const VectorType operator*(const VECTOR4D<VectorType>		&value);

			const VECTOR4D<VectorType> &operator*=(const VectorType		&value);

			const VECTOR4D<VectorType> operator/(const VectorType		&value) const;
			const VECTOR4D<VectorType> &operator/=(const VectorType		&value);

			const VECTOR4D<VectorType> &operator*=(const MATRIX2X2<VectorType>		&value);

			const VECTOR4D<VectorType> operator*(const MATRIX2X2<VectorType>		&value);
#pragma endregion DivisionAndMultiplicationOperators

#pragma region ComparisonOperators
			bool operator==(const VECTOR4D<VectorType>		&value);

			bool operator!=(const VECTOR4D<VectorType>		&value);
#pragma endregion ComparisonOperators

			void ZeroVector(void);
			void Limit(const VectorType &limit);
			bool IsZero() const;
			VectorType Magnitude() const;
			void Normalize();
			VectorType Heading();
			VECTOR4D<VectorType> Clone() const;
			void Normalize(const VECTOR4D<VectorType> &value);

			static VECTOR4D<VectorType> GetZeroVector(void);

		};



		template<typename VectorType>
		void Aurora::Math::VECTOR4D<VectorType>::Normalize(const VECTOR4D<VectorType> &value)
		{
			VectorType magnitude = value.Magnitude();
			if (magnitude != 0)
				*this = value / magnitude;
		}

		template<typename VectorType>
		VECTOR4D<VectorType> Aurora::Math::VECTOR4D<VectorType>::GetZeroVector(void)
		{
			return(VECTOR4D<VectorType>(0, 0, 0, 0));
		}

		template<typename VectorType>
		VECTOR4D<VectorType> Aurora::Math::VECTOR4D<VectorType>::Clone() const
		{
			return(VECTOR4D<VectorType>(this->X, this->Y, this->Z, this->W));
		}

		template<typename VectorType>
		VectorType Aurora::Math::VECTOR4D<VectorType>::Heading()
		{
			return(atan(Y, X));
		}

		template<typename VectorType>
		void Aurora::Math::VECTOR4D<VectorType>::Normalize()
		{
			VectorType magnitude = this->Magnitude();
			if (magnitude != 0)
				*this /= magnitude;
		}

		template<typename VectorType>
		VectorType Aurora::Math::VECTOR4D<VectorType>::Magnitude() const
		{
			return(sqrt(this->X*this->X + this->Y*this->Y + this->Z*this->Z + this->W*this->W));
		}

		template<typename VectorType>
		bool Aurora::Math::VECTOR4D<VectorType>::IsZero() const
		{
			bool isZero = false;

			if (this->X == 0 && this->Y == 0 && this->Z == 0 && this->W == 0)
				isZero = true;

			return(isZero);
		}

		template<typename VectorType>
		void Aurora::Math::VECTOR4D<VectorType>::Limit(const VectorType &limit)
		{
			if (this->X > limit) {
				this->X = limit;
			}

			if (this->Y > limit) {
				this->Y = limit;
			}

			if (this->Z > limit) {
				this->Z = limit;
			}

			if (this->W > limit) {
				this->W = limit;
			}

			if (this->X < -limit) {
				this->X = -limit;
			}

			if (this->Y < -limit) {
				this->Y = -limit;
			}

			if (this->Z < -limit) {
				this->Z = -limit;
			}

			if (this->W < -limit) {
				this->W = -limit;
			}
		}


		template<typename VectorType>
		void Aurora::Math::VECTOR4D<VectorType>::ZeroVector(void)
		{
			this->X = this->Y = this->Z = this->W = 0;
		}

		template<typename VectorType>
		bool Aurora::Math::VECTOR4D<VectorType>::operator!=(const VECTOR4D<VectorType> &value)
		{
			bool isEqual = false;

			if (this->X != value.X && this->Y != value.Y && this->Z != value.Z  && this->W != value.W)
				isEqual = true;

			return(isEqual);
		}

		template<typename VectorType>
		bool Aurora::Math::VECTOR4D<VectorType>::operator==(const VECTOR4D<VectorType> &value)
		{
			bool isEqual = false;

			if (this->X == value.X && this->Y == value.Y && this->Z == value.Z  && this->W == value.W)
				isEqual = true;

			return(isEqual);
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> Aurora::Math::VECTOR4D<VectorType>::operator*(const MATRIX2X2<VectorType> &value)
		{
			return(VECTOR4D<VectorType>(this->X * value.M11 + this->Y * value.M21,
				this->X * value.M12 + this->Y * value.M22));
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator*=(const MATRIX2X2<VectorType> &value)
		{
			this->X = this->X * value.M11 + this->Y * value.M21;
			this->Y = this->X * value.M12 + this->Y * value.M22;

			return(*this);
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator/=(const VectorType &value)
		{
			this->X /= value;
			this->Y /= value;
			this->Z /= value;
			this->W /= value;
			return(*this);
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> Aurora::Math::VECTOR4D<VectorType>::operator/(const VectorType &value) const
		{
			return(VECTOR4D<VectorType>(this->X / value, this->Y / value, this->Z / value, this->W / value));
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator*=(const VectorType &value)
		{
			this->X *= value;
			this->Y *= value;
			this->Z *= value;
			this->W *= value;
			return(*this);
		}

		template<typename VectorType>
		const VectorType Aurora::Math::VECTOR4D<VectorType>::operator*(const VECTOR4D<VectorType> &value)
		{
			return((this->X * value.X) + (this->Y * value.Y) + (this->Z * value.Z) + (this->W * value.W));
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> Aurora::Math::VECTOR4D<VectorType>::operator*(const VectorType &value)
		{
			return(VECTOR4D<VectorType>(this->X * value, this->Y * value, this->Z * value, this->W * value));
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator-=(const VECTOR4D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X -= value.X;
			this->Y -= value.Y;
			this->Z -= value.Z;
			this->W -= value.W;
			return(*this);
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator-=(const VectorType &value)
		{
			this->X -= value;
			this->Y -= value;
			this->Z -= value;
			this->W -= value;
			return(*this);
		}

		template<typename VectorType>
		VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator+=(const VECTOR4D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X += value.X;
			this->Y += value.Y;
			this->Z += value.Z;
			this->W += value.W;
			return(*this);
		}

		template<typename VectorType>
		VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator+=(const VectorType &value)
		{
			this->X += value;
			this->Y += value;
			this->Z += value;
			this->W += value;
			return(*this);
		}

		template<typename VectorType>
		VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator=(const VectorType &value)
		{
			this->X = value;
			this->Y = value;
			this->Z = value;
			this->W = value;
			return(*this);
		}


		template<typename VectorType>
		const VECTOR4D<VectorType> Aurora::Math::VECTOR4D<VectorType>::operator-(const VECTOR4D<VectorType> &value)
		{
			return(VECTOR4D<VectorType>(this->X - value.X, this->Y - value.Y, this->Z - value.Z, this->W - value.W));
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> Aurora::Math::VECTOR4D<VectorType>::operator-(const VectorType &value)
		{
			return(VECTOR4D<VectorType>(this->X - value, this->Y - value, this->Z - value, this->W - value));
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> Aurora::Math::VECTOR4D<VectorType>::operator+(const VECTOR4D<VectorType> &value)
		{
			return(VECTOR4D<VectorType>(this->X + value.X, this->Y + value.Y, this->Z + value.Z, this->W + value.W));
		}

		template<typename VectorType>
		const VECTOR4D<VectorType> Aurora::Math::VECTOR4D<VectorType>::operator+(const VectorType &value)
		{

			return(VECTOR4D<VectorType>(this->X + value, this->Y + value, this->Z + value, this->W + valu));
		}


		template<typename VectorType>
		VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator=(const VECTOR4D<VectorType> &value)
		{
			if (this == &value)
				return *this;

			this->X = value.X;
			this->Y = value.Y;
			this->Z = value.Z;
			this->W = value.W;
			return(*this);
		}

		template<typename VectorType>
		VECTOR4D<VectorType> & Aurora::Math::VECTOR4D<VectorType>::operator=(VECTOR4D<VectorType> && value)
		{
			if (this == &value)
				return *this;

			this->X = std::move(value.X);
			this->Y = std::move(value.Y);
			this->Z = std::move(value.Z);
			this->W = std::move(value.W);
			return(*this);
		}

		template<typename VectorType>
		Aurora::Math::VECTOR4D<VectorType>::VECTOR4D(VECTOR4D<VectorType> &&value) : X(std::move(value.X)), Y(std::move(value.Y)), Z(std::move(value.Z)), W(std::move(value.W))
		{

		}

		template<typename VectorType>
		Aurora::Math::VECTOR4D<VectorType>::~VECTOR4D()
		{

		}

		template<typename VectorType>
		Aurora::Math::VECTOR4D<VectorType>::VECTOR4D(const VECTOR4D<VectorType> &value) : X(value.X), Y(value.Y), Z(value.Z), W(value.W)
		{

		}

		template<typename VectorType>
		Aurora::Math::VECTOR4D<VectorType>::VECTOR4D(VectorType x, VectorType y, VectorType z, VectorType w) : X(x), Y(y), Z(z), W(w)
		{
		}

		template<typename VectorType>
		Aurora::Math::VECTOR4D<VectorType>::VECTOR4D() : X(0), Y(0), Z(0), W(0)
		{

		}

	}
}

#endif
