#ifndef Vector3D_H
#define Vector3D_H

#include "Matrix3D.h"

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
		class VECTOR3D
		{
		public:
			VectorType X;
			VectorType Y;
			VectorType Z;
			VECTOR3D();
			VECTOR3D(VectorType x, VectorType y, VectorType z);
			VECTOR3D(const VECTOR3D<VectorType> &value);
			virtual ~VECTOR3D();
			VECTOR3D(VECTOR3D<VectorType> &&value);
			VECTOR3D<VectorType> & operator=(VECTOR3D<VectorType> && value);
			VECTOR3D<VectorType> &operator=(const VECTOR3D<VectorType>		&value);


#pragma region AdditionAndSubstractionOperators
			const VECTOR3D<VectorType> operator+(const VectorType			&value);

			const VECTOR3D<VectorType> operator+(const VECTOR3D<VectorType>		&value);

			const VECTOR3D<VectorType> operator-(const VectorType			&value);

			const VECTOR3D<VectorType> operator-(const VECTOR3D<VectorType>		&value);

			VECTOR3D<VectorType> &operator=(const VectorType			&value);

			VECTOR3D<VectorType> &operator+=(const VectorType		&value);

			VECTOR3D<VectorType> &operator+=(const VECTOR3D<VectorType>		&value);

			const VECTOR3D<VectorType> &operator-=(const VectorType		&value);

			const VECTOR3D<VectorType> &operator-=(const VECTOR3D<VectorType>		&value);
#pragma endregion AdditionAndSubstractionOperators

#pragma region DivisionAndMultiplicationOperators

			const VECTOR3D<VectorType> operator*(const VectorType		&value);

			const VectorType operator*(const VECTOR3D<VectorType>		&value);

			const VECTOR3D<VectorType> &operator*=(const VectorType		&value);

			const VECTOR3D<VectorType> operator/(const VectorType		&value) const;
			const VECTOR3D<VectorType> &operator/=(const VectorType		&value);

			const VECTOR3D<VectorType> &operator*=(const MATRIX2X2<VectorType>		&value);

			const VECTOR3D<VectorType> operator*(const MATRIX2X2<VectorType>		&value);
#pragma endregion DivisionAndMultiplicationOperators

#pragma region ComparisonOperators
			bool operator==(const VECTOR3D<VectorType>		&value);

			bool operator!=(const VECTOR3D<VectorType>		&value);
#pragma endregion ComparisonOperators

			void ZeroVector(void);
			void Limit(const VectorType &limit);
			bool IsZero() const;
			VectorType Magnitude() const;
			void Normalize();
			VectorType Heading();
			VECTOR3D<VectorType> Clone() const;
			void Normalize(const VECTOR3D<VectorType> &value);

			static VECTOR3D<VectorType> GetZeroVector(void);

		};

		template<typename VectorType>
		void Aurora::Math::VECTOR3D<VectorType>::Normalize(const VECTOR3D<VectorType> &value)
		{
			VectorType magnitude = value.Magnitude();
			if (magnitude != 0)
				*this = value / magnitude;
		}

		template<typename VectorType>
		VECTOR3D<VectorType> Aurora::Math::VECTOR3D<VectorType>::GetZeroVector(void)
		{
			return(VECTOR3D<VectorType>(0, 0, 0));
		}

		template<typename VectorType>
		VECTOR3D<VectorType> Aurora::Math::VECTOR3D<VectorType>::Clone() const
		{
			return(VECTOR3D<VectorType>(this->X, this->Y, this->Z));
		}

		template<typename VectorType>
		VectorType Aurora::Math::VECTOR3D<VectorType>::Heading()
		{
			return(atan2(Y, X));
		}

		template<typename VectorType>
		void Aurora::Math::VECTOR3D<VectorType>::Normalize()
		{
			VectorType magnitude = this->Magnitude();
			if (magnitude != 0)
				*this /= magnitude;
		}

		template<typename VectorType>
		VectorType Aurora::Math::VECTOR3D<VectorType>::Magnitude() const
		{
			return(sqrt(this->X*this->X + this->Y*this->Y + this->Z*this->Z));
		}

		template<typename VectorType>
		bool Aurora::Math::VECTOR3D<VectorType>::IsZero() const
		{
			bool isZero = false;

			if (this->X == 0 && this->Y == 0 && this->Z == 0)
				isZero = true;

			return(isZero);
		}

		template<typename VectorType>
		void Aurora::Math::VECTOR3D<VectorType>::Limit(const VectorType &limit)
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

			if (this->X < -limit) {
				this->X = -limit;
			}

			if (this->Y < -limit) {
				this->Y = -limit;
			}

			if (this->Z < -limit) {
				this->Z = -limit;
			}
		}

		template<typename VectorType>
		void Aurora::Math::VECTOR3D<VectorType>::ZeroVector(void)
		{
			this->X = this->Y = this->Z = 0;
		}

		template<typename VectorType>
		bool Aurora::Math::VECTOR3D<VectorType>::operator!=(const VECTOR3D<VectorType> &value)
		{
			bool isEqual = false;

			if (this->X != value.X && this->Y != value.Y && this->Z != value.Z)
				isEqual = true;

			return(isEqual);
		}

		template<typename VectorType>
		bool Aurora::Math::VECTOR3D<VectorType>::operator==(const VECTOR3D<VectorType> &value)
		{
			bool isEqual = false;

			if (this->X == value.X && this->Y == value.Y && this->Z == value.Z)
				isEqual = true;

			return(isEqual);
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> Aurora::Math::VECTOR3D<VectorType>::operator*(const MATRIX2X2<VectorType> &value)
		{
			return(VECTOR3D<VectorType>(this->X * value.M11 + this->Y * value.M21,
				this->X * value.M12 + this->Y * value.M22));
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator*=(const MATRIX2X2<VectorType> &value)
		{
			this->X = this->X * value.M11 + this->Y * value.M21;
			this->Y = this->X * value.M12 + this->Y * value.M22;

			return(*this);
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator/=(const VectorType &value)
		{
			this->X /= value;
			this->Y /= value;
			this->Z /= value;
			return(*this);
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> Aurora::Math::VECTOR3D<VectorType>::operator/(const VectorType &value) const
		{
			return(VECTOR3D<VectorType>(this->X / value, this->Y / value, this->Z / value));
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator*=(const VectorType &value)
		{
			this->X *= value;
			this->Y *= value;
			this->Z *= value;
			return(*this);
		}

		template<typename VectorType>
		const VectorType Aurora::Math::VECTOR3D<VectorType>::operator*(const VECTOR3D<VectorType> &value)
		{
			return((this->X * value.X) + (this->Y * value.Y) + (this->Z * value.Z));
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> Aurora::Math::VECTOR3D<VectorType>::operator*(const VectorType &value)
		{
			return(VECTOR3D<VectorType>(this->X * value, this->Y * value, this->Z * value));
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator-=(const VECTOR3D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X -= value.X;
			this->Y -= value.Y;
			this->Z -= value.Z;
			return(*this);
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator-=(const VectorType &value)
		{
			this->X -= value;
			this->Y -= value;
			this->Z -= value;
			return(*this);
		}

		template<typename VectorType>
		VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator+=(const VECTOR3D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X += value.X;
			this->Y += value.Y;
			this->Z += value.Z;
			return(*this);
		}

		template<typename VectorType>
		VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator+=(const VectorType &value)
		{
			this->X += value;
			this->Y += value;
			this->Z += value;
			return(*this);
		}

		template<typename VectorType>
		VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator=(const VectorType &value)
		{
			this->X = value;
			this->Y = value;
			this->Z = value;
			return(*this);
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> Aurora::Math::VECTOR3D<VectorType>::operator-(const VECTOR3D<VectorType> &value)
		{
			return(VECTOR3D<VectorType>(this->X - value.X, this->Y - value.Y, this->Z - value.Z));
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> Aurora::Math::VECTOR3D<VectorType>::operator-(const VectorType &value)
		{
			return(VECTOR3D<VectorType>(this->X - value, this->Y - value, this->Z - value));
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> Aurora::Math::VECTOR3D<VectorType>::operator+(const VECTOR3D<VectorType> &value)
		{
			return(VECTOR3D<VectorType>(this->X + value.X, this->Y + value.Y, this->Z + value.Z));
		}

		template<typename VectorType>
		const VECTOR3D<VectorType> Aurora::Math::VECTOR3D<VectorType>::operator+(const VectorType &value)
		{

			return(VECTOR3D<VectorType>(this->X + value, this->Y + value, this->Z + value));
		}


		template<typename VectorType>
		VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator=(const VECTOR3D<VectorType> &value)
		{
			if (this == &value)
				return *this;

			this->X = value.X;
			this->Y = value.Y;
			this->Z = value.Z;
			return(*this);
		}

		template<typename VectorType>
		VECTOR3D<VectorType> & Aurora::Math::VECTOR3D<VectorType>::operator=(VECTOR3D<VectorType> && value)
		{
			if (this == &value)
				return *this;

			this->X = std::move(value.X);
			this->Y = std::move(value.Y);
			this->Z = std::move(value.Z);
			return(*this);
		}

		template<typename VectorType>
		Aurora::Math::VECTOR3D<VectorType>::VECTOR3D(VECTOR3D<VectorType> &&value) : X(std::move(value.X)), Y(std::move(value.Y)), Z(std::move(value.Z))
		{

		}

		template<typename VectorType>
		Aurora::Math::VECTOR3D<VectorType>::~VECTOR3D()
		{

		}

		template<typename VectorType>
		Aurora::Math::VECTOR3D<VectorType>::VECTOR3D(const VECTOR3D<VectorType> &value) : X(value.X), Y(value.Y), Z(value.Z)
		{

		}

		template<typename VectorType>
		Aurora::Math::VECTOR3D<VectorType>::VECTOR3D(VectorType x, VectorType y, VectorType z) : X(x), Y(y), Z(z)
		{
		}

		template<typename VectorType>
		Aurora::Math::VECTOR3D<VectorType>::VECTOR3D() : X(0), Y(0), Z(0)
		{

		}

	}
}

#endif