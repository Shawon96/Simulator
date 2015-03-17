#ifndef Vector3D_H
#define Vector3D_H

#include "Vector2D.h"
#include "../Matrices/Matrix3D.h"

/*
template <typename T>
class test {
friend test operator+( test const & lhs, test const & rhs ) {  // [1]
return test();
}
}
test<int> t;
*/

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
		class Vector3D
		{
		public:
			VectorType X;
			VectorType Y;
			VectorType Z;
			Vector3D();
			Vector3D(VectorType x, VectorType y, VectorType z);
			Vector3D(const Vector3D<VectorType> &value);
			virtual ~Vector3D();
			Vector3D(Vector3D<VectorType> &&value);
			Vector3D<VectorType> & operator=(Vector3D<VectorType> && value);
			Vector3D<VectorType> &operator=(const Vector3D<VectorType>		&value);


#pragma region AdditionAndSubstractionOperators
			const Vector3D<VectorType> operator+(const VectorType			&value);

			const Vector3D<VectorType> operator+(const Vector3D<VectorType>		&value);

			const Vector3D<VectorType> operator-(const VectorType			&value);

			const Vector3D<VectorType> operator-(const Vector3D<VectorType>		&value);

			Vector3D<VectorType> &operator=(const VectorType			&value);

			Vector3D<VectorType> &operator+=(const VectorType		&value);

			Vector3D<VectorType> &operator+=(const Vector3D<VectorType>		&value);

			const Vector3D<VectorType> &operator-=(const VectorType		&value);

			const Vector3D<VectorType> &operator-=(const Vector3D<VectorType>		&value);

			Vector3D<VectorType> Add(const Vector3D<VectorType>		&value);

			Vector3D<VectorType> Subtract(const Vector3D<VectorType>		&value);
#pragma endregion AdditionAndSubstractionOperators

#pragma region DivisionAndMultiplicationOperators

			const Vector3D<VectorType> operator*(const VectorType		&value);

			const VectorType operator*(const Vector3D<VectorType>		&value);

			const Vector3D<VectorType> &operator*=(const VectorType		&value);

			const Vector3D<VectorType> operator/(const VectorType		&value) const;
			const Vector3D<VectorType> &operator/=(const VectorType		&value);

			const Vector3D<VectorType> &operator*=(const Matrix3D<VectorType>		&value);

			const Vector3D<VectorType> operator*(const Matrix3D<VectorType>		&value);

			Vector3D<VectorType> Multiply(const VectorType &scalar);

			Vector3D<VectorType> MultiplyComponents(const Vector3D<VectorType>		&value);

			Vector3D<VectorType> Divide(const VectorType &scalar);
#pragma endregion DivisionAndMultiplicationOperators

#pragma region ComparisonOperators
			bool operator==(const Vector3D<VectorType>		&value);

			bool operator!=(const Vector3D<VectorType>		&value);

			bool operator<(const VectorType &scalar) const;

			bool operator>(const VectorType &scalar) const;

			bool operator<(const Vector3D<VectorType>		&value) const;

			bool operator>(const Vector3D<VectorType>		&value) const;
#pragma endregion ComparisonOperators

			
			
			
			
			Vector3D<bool> ToBoolean() const;
			Vector3D<float> ToFloat() const;
			Vector3D<double> ToDouble() const;
			Vector3D<int> ToInt() const;
			Vector3D<half_float::half> ToHalfPrecision() const;

			

			void Zero(void);
			void Limit(const VectorType &limit);
			bool IsZero() const;
			VectorType Magnitude() const;
			Vector3D<VectorType> Normalize();
			VectorType Heading();
			Vector3D<VectorType> Clone() const;
			Vector3D<VectorType> Normalize(const Vector3D<VectorType> &value);

			static Vector3D<VectorType> GetZero(void);

			Vector3D<VectorType> Cross(Vector3D<VectorType> value);

			static Vector3D<VectorType> UnitX();

			static Vector3D<VectorType> UnitY();

			static Vector3D<VectorType> UnitZ();

			static Vector3D<VectorType> Undefined();


			Vector2D<VectorType> XY() const;
			VectorType MagnitudeSquared() const;
			bool IsUndefined() const;
			Vector3D<VectorType> Normalize(VectorType &value);
			Vector3D<VectorType> MostOrthogonalAxis() const;
			Vector3D<VectorType> Negate() const;
			bool EqualsEpsilon(const Vector3D<VectorType> &value, double epsilon);

			std::string ToString() const;

			int GetHashCode() const;

			bool Equals(const Vector3D<VectorType> &value) const;

			VectorType Dot(const Vector3D<VectorType> &value);
			Vector3D<VectorType> Cross(const Vector3D<VectorType> &value) const;
			VectorType AngleBetween(const Vector3D<VectorType> &other);
			Vector3D<VectorType> RotateAroundAxis(const Vector3D<VectorType> &axis, double theta);
		};

		
		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::operator>(const Vector3D<VectorType> &value) const
		{
			return(this->X > value.X && this->Y > value.Y && this->Z > value.Z);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::operator<(const Vector3D<VectorType> &value) const
		{
			return(this->X < value.X && this->Y < value.Y && this->Z < value.Z);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::operator>(const VectorType &scalar) const
		{
			return(this->X > scalar && this->Y > scalar && this->Z > scalar);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::operator<(const VectorType &scalar) const
		{
			return(this->X < scalar && this->Y < scalar && this->Z < scalar);
		}
		

		using Vector3DBool = Vector3D < bool >;
		using Vector3DDouble = Vector3D < double >;
		using Vector3DFloat = Vector3D < float >;
		using Vector3DInt = Vector3D < int >;
		using Vector3DHalfPrecision = Vector3D < half_float::half >;

		template<typename VectorType>
		Vector3D<half_float::half> Aurora::Math::Vector3D<VectorType>::ToHalfPrecision() const
		{
			return(Vector3D<half_float::half>(static_cast<half_float::half>(this->X), static_cast<half_float::half>(this->Y), static_cast<half_float::half>(this->Z)));
		}

		template<typename VectorType>
		Vector3D<int> Aurora::Math::Vector3D<VectorType>::ToInt() const
		{
			return(Vector3D<int>(static_cast<int>(this->X), static_cast<int>(this->Y), static_cast<int>(this->Z)));
		}

		template<typename VectorType>
		Vector3D<double> Aurora::Math::Vector3D<VectorType>::ToDouble() const
		{
			return(Vector3D<double>(static_cast<double>(this->X), static_cast<double>(this->Y), static_cast<double>(this->Z)));
		}

		template<typename VectorType>
		Vector3D<float> Aurora::Math::Vector3D<VectorType>::ToFloat() const
		{
			return(Vector3D<float>(static_cast<float>(this->X), static_cast<float>(this->Y), static_cast<float>(this->Z)));
		}

		template<typename VectorType>
		Vector3D<bool> Aurora::Math::Vector3D<VectorType>::ToBoolean() const
		{
			return(Vector3D<bool>(static_cast<bool>(this->X), static_cast<bool>(this->Y), static_cast<bool>(this->Z)));
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::RotateAroundAxis(const Vector3D<VectorType> &axis, double theta)
		{
			double u = axis.X;
			double v = axis.Y;
			double w = axis.Z;

			double cosTheta = cos(theta);
			double sinTheta = sin(theta);

			double ms = axis.MagnitudeSquared();
			double m = sqrt(ms);

			return Vector3D<VectorType>(
				((u * (u * X + v * Y + w * Z)) +
				(((X * (v * v + w * w)) - (u * (v * Y + w * Z))) * cosTheta) +
				(m * ((-w * Y) + (v * Z)) * sinTheta)) / ms,

				((v * (u * X + v * Y + w * Z)) +
				(((Y * (u * u + w * w)) - (v * (u * X + w * Z))) * cosTheta) +
				(m * ((w * X) - (u * Z)) * sinTheta)) / ms,

				((w * (u * X + v * Y + w * Z)) +
				(((Z * (u * u + v * v)) - (w * (u * X + v * Y))) * cosTheta) +
				(m * (-(v * X) + (u * Y)) * sinTheta)) / ms);
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector3D<VectorType>::AngleBetween(const Vector3D<VectorType> &other)
		{
			this->Normalize();
			return acos(this->Dot(other.Clone().Normalize()));
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Cross(const Vector3D<VectorType> &value) const
		{
			return Vector3D<VectorType>(Y * value.Z - Z * value.Y,
										Z * value.X - X * value.Z,
										X * value.Y - Y * value.X);
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Divide(const VectorType &scalar)
		{
			return this / scalar;
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::MultiplyComponents(const Vector3D<VectorType> &value)
		{
			return Vector3D<VectorType>(X * value.X, Y * value.Y, Z * value.Z);
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Multiply(const VectorType &scalar)
		{
			return this * scalar;
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Subtract(const Vector3D<VectorType> &value)
		{
			return this - value;
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Add(const Vector3D<VectorType> &value)
		{
			return this + value;
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector3D<VectorType>::Dot(const Vector3D<VectorType> &value)
		{
			return X * value.X + Y * value.Y + Z * value.Z;
		}

		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::Equals(const Vector3D<VectorType> &value) const
		{
			return(this->X == value.X && this->Y == value.Y && this->Z == value.Z);
		}

		template<typename VectorType>
		int Aurora::Math::Vector3D<VectorType>::GetHashCode() const
		{
			std::hash<VectorType> hash;
			return hash(this->X) ^ hash(this->Y) ^ hash(this->Z);
		}

		template<typename VectorType>
		std::string Aurora::Math::Vector3D<VectorType>::ToString() const
		{
			return("X:" + std::to_string(this->X) + " Y:" + std::to_string(this->Y) + " Z:" + std::to_string(this->Z));
		}

		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::EqualsEpsilon(const Vector3D<VectorType> &value, double epsilon)
		{
			return  (abs(this->X - other.X) <= epsilon) &&
					(abs(this->Y - other.Y) <= epsilon) &&
					(abs(this->Z - other.Z) <= epsilon);
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Negate() const
		{
			return -this;
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::MostOrthogonalAxis() const
		{
			double x = abs(X);
			double y = abs(Y);
			double z = abs(Z);

			if ((x < y) && (x < z))
            {
                return UnitX;
            }
            else if ((y < x) && (y < z))
            {
                return UnitY;
            }
            else
            {
                return UnitZ;
            }
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Normalize(VectorType &value)
		{
			magnitude = this->Magnitude();
			return this / magnitude;
		}

		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::IsUndefined() const
		{
			return(isnan(this->X));
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector3D<VectorType>::MagnitudeSquared() const
		{
			return this->X * this->X + this->Y * this->Y + this->Z * this->Z;
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector3D<VectorType>::XY() const
		{
			return Vector2D<VectorType>(X, Y);
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Undefined()
		{
			double nanValue;
			return Vector3D<VectorType>(nanValue, nanValue, nanValue);
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::UnitZ()
		{
			return Vector3D<VectorType>(0.0, 0.0, 1.0);
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::UnitY()
		{
			return Vector3D<VectorType>(0.0, 1.0, 0.0);
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::UnitX()
		{
			return Vector3D<VectorType>(1.0, 0.0, 0.0);
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Normalize(const Vector3D<VectorType> &value)
		{
			VectorType magnitude = value.Magnitude();
			if (magnitude != 0)
				*this = value / magnitude;

			return(*this);
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::GetZero(void)
		{
			return(Vector3D<VectorType>(0, 0, 0));
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Clone() const
		{
			return(Vector3D<VectorType>(this->X, this->Y, this->Z));
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector3D<VectorType>::Heading()
		{
			return(atan2(Y, X));
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::Normalize()
		{
			VectorType magnitude = this->Magnitude();
			if (magnitude != 0)
				*this /= magnitude;

			return(*this);
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector3D<VectorType>::Magnitude() const
		{
			return(sqrt(this->X*this->X + this->Y*this->Y + this->Z*this->Z));
		}

		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::IsZero() const
		{
			bool isZero = false;

			if (this->X == 0 && this->Y == 0 && this->Z == 0)
				isZero = true;

			return(isZero);
		}

		template<typename VectorType>
		void Aurora::Math::Vector3D<VectorType>::Limit(const VectorType &limit)
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
		void Aurora::Math::Vector3D<VectorType>::Zero(void)
		{
			this->X = this->Y = this->Z = 0;
		}

		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::operator!=(const Vector3D<VectorType> &value)
		{
			return(this->X != value.X && this->Y != value.Y && this->Z != value.Z);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector3D<VectorType>::operator==(const Vector3D<VectorType> &value)
		{
			return(this->X == value.X && this->Y == value.Y && this->Z == value.Z);
		}

		template<typename VectorType>
		const Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::operator*(const Matrix3D<VectorType> &value)
		{
			return(Vector3D<VectorType>(	this->X * value.M11 + this->Y * value.M21 + this->Z * value.M31,
                                this->X * value.M12 + this->Y * value.M22 + this->Z * value.M32,
                                this->X * value.M13 + this->Y * value.M23 + this->Z * value.M33));
		}

		template<typename VectorType>
		const Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator*=(const Matrix3D<VectorType> &value)
		{
			this->X = this->X * value.M11 + this->Y * value.M21 + this->Z * value.M31;
            this->Y = this->X * value.M12 + this->Y * value.M22 + this->Z * value.M32;
            this->Z = this->X * value.M13 + this->Y * value.M23 + this->Z * value.M33;
            return(*this);
		}

		template<typename VectorType>
		const Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator/=(const VectorType &value)
		{
			this->X /= value;
			this->Y /= value;
			this->Z /= value;
			return(*this);
		}

		template<typename VectorType>
		const Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::operator/(const VectorType &value) const
		{
			return(Vector3D<VectorType>(this->X / value, this->Y / value, this->Z / value));
		}

		template<typename VectorType>
		const Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator*=(const VectorType &value)
		{
			this->X *= value;
			this->Y *= value;
			this->Z *= value;
			return(*this);
		}

		template<typename VectorType>
		const VectorType Aurora::Math::Vector3D<VectorType>::operator*(const Vector3D<VectorType> &value)
		{
			return((this->X * value.X) + (this->Y * value.Y) + (this->Z * value.Z));
		}

		template<typename VectorType>
		const Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::operator*(const VectorType &value)
		{
			return(Vector3D<VectorType>(this->X * value, this->Y * value, this->Z * value));
		}

		template<typename VectorType>
		const Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator-=(const Vector3D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X -= value.X;
			this->Y -= value.Y;
			this->Z -= value.Z;
			return(*this);
		}

		template<typename VectorType>
		const Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator-=(const VectorType &value)
		{
			this->X -= value;
			this->Y -= value;
			this->Z -= value;
			return(*this);
		}

		template<typename VectorType>
		Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator+=(const Vector3D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X += value.X;
			this->Y += value.Y;
			this->Z += value.Z;
			return(*this);
		}

		template<typename VectorType>
		Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator+=(const VectorType &value)
		{
			this->X += value;
			this->Y += value;
			this->Z += value;
			return(*this);
		}

		template<typename VectorType>
		Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator=(const VectorType &value)
		{
			this->X = value;
			this->Y = value;
			this->Z = value;
			return(*this);
		}

		template<typename VectorType>
		const Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::operator-(const Vector3D<VectorType> &value)
		{
			return(Vector3D<VectorType>(this->X - value.X, this->Y - value.Y, this->Z - value.Z));
		}

		template<typename VectorType>
		const Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::operator-(const VectorType &value)
		{
			return(Vector3D<VectorType>(this->X - value, this->Y - value, this->Z - value));
		}

		template<typename VectorType>
		const Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::operator+(const Vector3D<VectorType> &value)
		{
			return(Vector3D<VectorType>(this->X + value.X, this->Y + value.Y, this->Z + value.Z));
		}

		template<typename VectorType>
		const Vector3D<VectorType> Aurora::Math::Vector3D<VectorType>::operator+(const VectorType &value)
		{

			return(Vector3D<VectorType>(this->X + value, this->Y + value, this->Z + value));
		}


		template<typename VectorType>
		Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator=(const Vector3D<VectorType> &value)
		{
			if (this == &value)
				return *this;

			this->X = value.X;
			this->Y = value.Y;
			this->Z = value.Z;
			return(*this);
		}

		template<typename VectorType>
		Vector3D<VectorType> & Aurora::Math::Vector3D<VectorType>::operator=(Vector3D<VectorType> && value)
		{
			if (this == &value)
				return *this;

			this->X = std::move(value.X);
			this->Y = std::move(value.Y);
			this->Z = std::move(value.Z);
			return(*this);
		}

		template<typename VectorType>
		Aurora::Math::Vector3D<VectorType>::Vector3D(Vector3D<VectorType> &&value) : X(std::move(value.X)), Y(std::move(value.Y)), Z(std::move(value.Z))
		{

		}

		template<typename VectorType>
		Aurora::Math::Vector3D<VectorType>::~Vector3D()
		{

		}

		template<typename VectorType>
		Aurora::Math::Vector3D<VectorType>::Vector3D(const Vector3D<VectorType> &value) : X(value.X), Y(value.Y), Z(value.Z)
		{

		}

		template<typename VectorType>
		Aurora::Math::Vector3D<VectorType>::Vector3D(VectorType x, VectorType y, VectorType z) : X(x), Y(y), Z(z)
		{
		}

		template<typename VectorType>
		Aurora::Math::Vector3D<VectorType>::Vector3D() : X(0), Y(0), Z(0)
		{

		}

	}
}

#endif