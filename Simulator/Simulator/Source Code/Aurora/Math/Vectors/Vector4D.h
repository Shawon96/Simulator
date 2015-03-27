#ifndef Vector4D_H
#define Vector4D_H

#include "../Matrices/Matrix4D.h"
#include "Vector3D.h"

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
		class Vector4D
		{
		public:
			VectorType X;
			VectorType Y;
			VectorType Z;
			VectorType W;
			Vector4D();
			Vector4D(Vector3D<VectorType>, VectorType w);
			Vector4D(Vector2D<VectorType>, VectorType z, VectorType w);
			Vector4D(VectorType x, VectorType y, VectorType z, VectorType w);
			Vector4D(const Vector4D<VectorType> &value);
			virtual ~Vector4D();
			Vector4D(Vector4D<VectorType> &&value);
			Vector4D<VectorType> & operator=(Vector4D<VectorType> && value);
			Vector4D<VectorType> &operator=(const Vector4D<VectorType>		&value);


#pragma region AdditionAndSubstractionOperators
			const Vector4D<VectorType> operator+(const VectorType			&value);
			const Vector4D<VectorType> operator+(const VectorType			&value) const;

			const Vector4D<VectorType> operator+(const Vector4D<VectorType>		&value);
			const Vector4D<VectorType> operator+(const Vector4D<VectorType>		&value) const;

			const Vector4D<VectorType> operator-(const VectorType			&value);
			const Vector4D<VectorType> operator-(const VectorType			&value) const;

			const Vector4D<VectorType> operator-(const Vector4D<VectorType>		&value);
			const Vector4D<VectorType> operator-(const Vector4D<VectorType>		&value) const;

			Vector4D<VectorType> &operator=(const VectorType			&value);

			Vector4D<VectorType> &operator+=(const VectorType		&value);

			Vector4D<VectorType> &operator+=(const Vector4D<VectorType>		&value);

			const Vector4D<VectorType> &operator-=(const VectorType		&value);

			const Vector4D<VectorType> &operator-=(const Vector4D<VectorType>		&value);

			Vector4D<VectorType> Add(const Vector4D<VectorType>		&value);

			Vector4D<VectorType> Subtract(const Vector4D<VectorType>		&value);
#pragma endregion AdditionAndSubstractionOperators

#pragma region DivisionAndMultiplicationOperators

			const Vector4D<VectorType> operator*(const VectorType		&value);
			const Vector4D<VectorType> operator*(const VectorType		&value) const;

			const VectorType operator*(const Vector4D<VectorType>		&value);
			const VectorType operator*(const Vector4D<VectorType>		&value) const;

			const Vector4D<VectorType> &operator*=(const VectorType		&value);

			const Vector4D<VectorType> operator/(const VectorType		&value) const;
			const Vector4D<VectorType> &operator/=(const VectorType		&value);

			const Vector4D<VectorType> &operator*=(const Matrix4D<VectorType>		&value);

			const Vector4D<VectorType> operator*(const Matrix4D<VectorType>		&value);

			Vector4D<VectorType> Multiply(const VectorType &scalar);

			Vector4D<VectorType> MultiplyComponents(const Vector4D<VectorType>		&value);

			Vector4D<VectorType> Divide(const VectorType &scalar);

#pragma endregion DivisionAndMultiplicationOperators

#pragma region ComparisonOperators
			bool operator==(const Vector4D<VectorType>		&value);

			bool operator!=(const Vector4D<VectorType>		&value);

			bool operator<(const VectorType &scalar) const;

			bool operator>(const VectorType &scalar) const;

			bool operator<(const Vector4D<VectorType>		&value) const;

			bool operator>(const Vector4D<VectorType>		&value) const;

#pragma endregion ComparisonOperators

			Vector4D<bool> ToBoolean() const;
			Vector4D<float> ToFloat() const;
			Vector4D<double> ToDouble() const;
			Vector4D<int> ToInt() const;
			Vector4D<half_float::half> ToHalfPrecision() const;

			void Zero(void);
			void Limit(const VectorType &limit);
			bool IsZero() const;
			VectorType Magnitude() const;
			Vector4D<VectorType> Normalize();
			VectorType Heading();
			Vector4D<VectorType> Clone() const;
			Vector4D<VectorType> Normalize(const Vector4D<VectorType> &value);

			static Vector4D<VectorType> GetZero(void);



			static Vector4D<VectorType> UnitX();

			static Vector4D<VectorType> UnitY();

			static Vector4D<VectorType> UnitZ();

			static Vector4D<VectorType> UnitW();

			static Vector4D<VectorType> Undefined();


			Vector2D<VectorType> XY() const;
			Vector3D<VectorType> XYZ() const;
			VectorType MagnitudeSquared() const;
			bool IsUndefined() const;
			Vector4D<VectorType> Normalize(VectorType &value);
			Vector4D<VectorType> MostOrthogonalAxis() const;
			Vector4D<VectorType> Negate() const;
			bool EqualsEpsilon(const Vector4D<VectorType> &value, double epsilon);

			std::string ToString() const;

			int GetHashCode() const;

			bool Equals(const Vector4D<VectorType> &value) const;

			VectorType Dot(const Vector4D<VectorType> &value) const;
		};

		

		

		using Vector4DBool = Vector4D < bool >;
		using Vector4DDouble = Vector4D < double >;
		using Vector4DFloat = Vector4D < float >;
		using Vector4DInt = Vector4D < int >;
		using Vector4DHalfPrecision = Vector4D < half_float::half >;

		using UniqueVector4DBool = std::unique_ptr < Vector4DBool > ;
		using UniqueVector4DDouble = std::unique_ptr < Vector4DDouble > ;
		using UniqueVector4DFloat = std::unique_ptr < Vector4DFloat > ;
		using UniqueVector4DInt = std::unique_ptr < Vector4DInt > ;
		using UniqueVector4DHalfPrecision = std::unique_ptr < Vector4DHalfPrecision > ;
		template<typename DataType>
		using UniqueVector4DDynamicType = std::unique_ptr < Vector4D<DataType> > ;

		using UniqueVector4DBoolVector = std::vector < UniqueVector4DBool > ;
		using UniqueVector4DDoubleVector = std::vector < UniqueVector4DDouble > ;
		using UniqueVector4DFloatVector = std::vector < UniqueVector4DFloat > ;
		using UniqueVector4DIntVector = std::vector < UniqueVector4DInt > ;
		using UniqueVector4DHalfPrecisionVector = std::vector < UniqueVector4DHalfPrecision > ;
		template<typename DataType>
		using UniqueVector4DDynamicTypeVector = std::vector < UniqueVector4DDynamicType<DataType> > ;

		using DoubleLinkedListUniqueVector4DDouble = std::list < UniqueVector4DDouble >;
		using LinkedListUniqueVector4DDouble = std::forward_list < UniqueVector4DDouble >;

		template<typename DataType>
		using DynamicTypeArrayVector4D = DynamicTypeArray < Vector3D<DataType> > ;

		using DynamicTypeArrayVector4DBool = DynamicTypeArray < Vector4DBool > ;
		using DynamicTypeArrayVector4DDouble = DynamicTypeArray < Vector4DDouble > ;
		using DynamicTypeArrayVector4DFloat = DynamicTypeArray < Vector4DFloat > ;
		using DynamicTypeArrayVector4DInt = DynamicTypeArray < Vector4DInt > ;
		using DynamicTypeArrayVector4DHalfPrecision = DynamicTypeArray < Vector4DHalfPrecision > ;

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::operator>(const Vector4D<VectorType> &value) const
		{
			return(this->X > value.X && this->Y > value.Y && this->Z > value.Z  && this->W > value.W);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::operator<(const Vector4D<VectorType> &value) const
		{
			return(this->X < value.X && this->Y < value.Y && this->Z < value.Z  && this->W < value.W);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::operator>(const VectorType &scalar) const
		{
			return(this->X > scalar && this->Y > scalar && this->Z > scalar  && this->W > scalar);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::operator<(const VectorType &scalar) const
		{
			return(this->X < scalar && this->Y < scalar && this->Z < scalar  && this->W < scalar);
		}

		template<typename VectorType>
		Vector4D<half_float::half> Aurora::Math::Vector4D<VectorType>::ToHalfPrecision() const
		{
			return(Vector4D<half_float::half>(static_cast<half_float::half>(this->X), static_cast<half_float::half>(this->Y), static_cast<half_float::half>(this->Z)));
		}

		template<typename VectorType>
		Vector4D<int> Aurora::Math::Vector4D<VectorType>::ToInt() const
		{
			return(Vector4D<int>(static_cast<int>(this->X), static_cast<int>(this->Y), static_cast<int>(this->Z)));
		}

		template<typename VectorType>
		Vector4D<double> Aurora::Math::Vector4D<VectorType>::ToDouble() const
		{
			return(Vector4D<double>(static_cast<double>(this->X), static_cast<double>(this->Y), static_cast<double>(this->Z)));
		}

		template<typename VectorType>
		Vector4D<float> Aurora::Math::Vector4D<VectorType>::ToFloat() const
		{
			return(Vector4D<float>(static_cast<float>(this->X), static_cast<float>(this->Y), static_cast<float>(this->Z)));
		}

		template<typename VectorType>
		Vector4D<bool> Aurora::Math::Vector4D<VectorType>::ToBoolean() const
		{
			return(Vector4D<bool>(static_cast<bool>(this->X), static_cast<bool>(this->Y), static_cast<bool>(this->Z)));
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Divide(const VectorType &scalar)
		{
			return this / scalar;
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::MultiplyComponents(const Vector4D<VectorType> &value)
		{
			return Vector4D<VectorType>(X * scale.X, Y * scale.Y, Z * scale.Z, W * scale.W);
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Multiply(const VectorType &scalar)
		{
			return this * scalar;
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Subtract(const Vector4D<VectorType> &value)
		{
			return this - value;
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Add(const Vector4D<VectorType> &value)
		{
			return this + value;
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector4D<VectorType>::Dot(const Vector4D<VectorType> &value) const
		{
			return X * value.X + Y * value.Y + Z * value.Z + W * value.W;
		}

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::Equals(const Vector4D<VectorType> &value) const
		{
			return(this->X == value.X && this->Y == value.Y && this->Z == value.Z  && this->W == value.W);
		}

		template<typename VectorType>
		int Aurora::Math::Vector4D<VectorType>::GetHashCode() const
		{
			std::hash<VectorType> hash;
			return hash(this->X) ^ hash(this->Y) ^ hash(this->Z) ^ hash(this->W);
		}

		template<typename VectorType>
		std::string Aurora::Math::Vector4D<VectorType>::ToString() const
		{
			return("X:" + std::to_string(this->X) + " Y:" + std::to_string(this->Y) + " Z:" + std::to_string(this->Z) + " W:" + std::to_string(this->W));
		}

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::EqualsEpsilon(const Vector4D<VectorType> &value, double epsilon)
		{
			return  (abs(this->X - other.X) <= epsilon) &&
					(abs(this->Y - other.Y) <= epsilon) &&
					(abs(this->Z - other.Z) <= epsilon) &&
					(abs(this->W - other.W) <= epsilon);
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Negate() const
		{
			return -this;
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::MostOrthogonalAxis() const
		{
			double x = abs(X);
			double y = abs(Y);
			double z = abs(Z);
			double w = abs(W);

			if ((x < y) && (x < z) && (x < w))
			{
				return UnitX;
			}
			else if ((y < x) && (y < z) && (y < w))
			{
				return UnitY;
			}
			else if ((z < x) && (z < y) && (z < w))
			{
				return UnitZ;
			}
			else
			{
				return UnitW;
			}
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Normalize(VectorType &value)
		{
			magnitude = this->Magnitude();
			return this / magnitude;
		}

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::IsUndefined() const
		{
			return(isnan(this->X));
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector4D<VectorType>::MagnitudeSquared() const
		{
			return this->X * this->X + this->Y * this->Y + this->Z * this->Z + this->W * this->W;
		}

		template<typename VectorType>
		Vector3D<VectorType> Aurora::Math::Vector4D<VectorType>::XYZ() const
		{
			return Vector3D<VectorType>(X, Y, Z);
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector4D<VectorType>::XY() const
		{
			return Vector2D<VectorType>(X, Y);
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Undefined()
		{
			double nanValue;
			return Vector4D<VectorType>(nanValue, nanValue, nanValue, nanValue);
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::UnitW()
		{
			return Vector4D<VectorType>(0.0, 0.0, 0.0, 1.0);
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::UnitZ()
		{
			return Vector4D<VectorType>(0.0, 0.0, 1.0, 0.0);
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::UnitY()
		{
			return Vector4D<VectorType>(0.0, 1.0, 0.0, 0.0);
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::UnitX()
		{
			return Vector4D<VectorType>(1.0, 0.0, 0.0, 0.0);
		}



		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Normalize(const Vector4D<VectorType> &value)
		{
			VectorType magnitude = value.Magnitude();
			if (magnitude != 0)
				*this = value / magnitude;

			return(*this);
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::GetZero(void)
		{
			return(Vector4D<VectorType>(0, 0, 0, 0));
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Clone() const
		{
			return(Vector4D<VectorType>(this->X, this->Y, this->Z, this->W));
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector4D<VectorType>::Heading()
		{
			return(atan(Y, X));
		}

		template<typename VectorType>
		Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::Normalize()
		{
			VectorType magnitude = this->Magnitude();
			if (magnitude != 0)
				*this /= magnitude;

			return(*this);
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector4D<VectorType>::Magnitude() const
		{
			return(sqrt(this->X*this->X + this->Y*this->Y + this->Z*this->Z + this->W*this->W));
		}

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::IsZero() const
		{
			bool isZero = false;

			if (this->X == 0 && this->Y == 0 && this->Z == 0 && this->W == 0)
				isZero = true;

			return(isZero);
		}

		template<typename VectorType>
		void Aurora::Math::Vector4D<VectorType>::Limit(const VectorType &limit)
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
		void Aurora::Math::Vector4D<VectorType>::Zero(void)
		{
			this->X = this->Y = this->Z = this->W = 0;
		}

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::operator!=(const Vector4D<VectorType> &value)
		{
			return(this->X != value.X && this->Y != value.Y && this->Z != value.Z  && this->W != value.W);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector4D<VectorType>::operator==(const Vector4D<VectorType> &value)
		{
			return(this->X == value.X && this->Y == value.Y && this->Z == value.Z  && this->W == value.W);
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator*(const Matrix4D<VectorType> &value)
		{
			return(Vector4D<VectorType>(	this->X * value.M11 + this->Y * value.M21 + this->Z * value.M31 + this->W * value.M41,
								this->X * value.M12 + this->Y * value.M22 + this->Z * value.M32 + this->W * value.M42,
								this->X * value.M13 + this->Y * value.M23 + this->Z * value.M33 + this->W * value.M43,
								this->X * value.M14 + this->Y * value.M24 + this->Z * value.M34 + this->W * value.M44));
		}

		template<typename VectorType>
		const Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator*=(const Matrix4D<VectorType> &value)
		{
			this->X = this->X * value.M11 + this->Y * value.M21 + this->Z * value.M31 + this->W * value.M41;
			this->Y = this->X * value.M12 + this->Y * value.M22 + this->Z * value.M32 + this->W * value.M42;
			this->Z = this->X * value.M13 + this->Y * value.M23 + this->Z * value.M33 + this->W * value.M43;
			this->W = this->X * value.M14 + this->Y * value.M24 + this->Z * value.M34 + this->W * value.M44;
			return(*this);
		}

		template<typename VectorType>
		const Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator/=(const VectorType &value)
		{
			this->X /= value;
			this->Y /= value;
			this->Z /= value;
			this->W /= value;
			return(*this);
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator/(const VectorType &value) const
		{
			return(Vector4D<VectorType>(this->X / value, this->Y / value, this->Z / value, this->W / value));
		}

		template<typename VectorType>
		const Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator*=(const VectorType &value)
		{
			this->X *= value;
			this->Y *= value;
			this->Z *= value;
			this->W *= value;
			return(*this);
		}

		template<typename VectorType>
		const VectorType Aurora::Math::Vector4D<VectorType>::operator*(const Vector4D<VectorType> &value)
		{
			return((this->X * value.X) + (this->Y * value.Y) + (this->Z * value.Z) + (this->W * value.W));
		}

		template<typename VectorType>
		const VectorType Aurora::Math::Vector4D<VectorType>::operator*(const Vector4D<VectorType> &value) const
		{
			return((this->X * value.X) + (this->Y * value.Y) + (this->Z * value.Z) + (this->W * value.W));
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator*(const VectorType &value)
		{
			return(Vector4D<VectorType>(this->X * value, this->Y * value, this->Z * value, this->W * value));
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator*(const VectorType &value) const
		{
			return(Vector4D<VectorType>(this->X * value, this->Y * value, this->Z * value, this->W * value));
		}

		template<typename VectorType>
		const Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator-=(const Vector4D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X -= value.X;
			this->Y -= value.Y;
			this->Z -= value.Z;
			this->W -= value.W;
			return(*this);
		}

		template<typename VectorType>
		const Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator-=(const VectorType &value)
		{
			this->X -= value;
			this->Y -= value;
			this->Z -= value;
			this->W -= value;
			return(*this);
		}

		template<typename VectorType>
		Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator+=(const Vector4D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X += value.X;
			this->Y += value.Y;
			this->Z += value.Z;
			this->W += value.W;
			return(*this);
		}

		template<typename VectorType>
		Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator+=(const VectorType &value)
		{
			this->X += value;
			this->Y += value;
			this->Z += value;
			this->W += value;
			return(*this);
		}

		template<typename VectorType>
		Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator=(const VectorType &value)
		{
			this->X = value;
			this->Y = value;
			this->Z = value;
			this->W = value;
			return(*this);
		}


		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator-(const Vector4D<VectorType> &value)
		{
			return(Vector4D<VectorType>(this->X - value.X, this->Y - value.Y, this->Z - value.Z, this->W - value.W));
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator-(const Vector4D<VectorType> &value) const
		{
			return(Vector4D<VectorType>(this->X - value.X, this->Y - value.Y, this->Z - value.Z, this->W - value.W));
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator-(const VectorType &value)
		{
			return(Vector4D<VectorType>(this->X - value, this->Y - value, this->Z - value, this->W - value));
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator-(const VectorType &value) const
		{
			return(Vector4D<VectorType>(this->X - value, this->Y - value, this->Z - value, this->W - value));
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator+(const Vector4D<VectorType> &value)
		{
			return(Vector4D<VectorType>(this->X + value.X, this->Y + value.Y, this->Z + value.Z, this->W + value.W));
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator+(const Vector4D<VectorType> &value) const
		{
			return(Vector4D<VectorType>(this->X + value.X, this->Y + value.Y, this->Z + value.Z, this->W + value.W));
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator+(const VectorType &value)
		{

			return(Vector4D<VectorType>(this->X + value, this->Y + value, this->Z + value, this->W + valu));
		}

		template<typename VectorType>
		const Vector4D<VectorType> Aurora::Math::Vector4D<VectorType>::operator+(const VectorType &value) const
		{

			return(Vector4D<VectorType>(this->X + value, this->Y + value, this->Z + value, this->W + valu));
		}


		template<typename VectorType>
		Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator=(const Vector4D<VectorType> &value)
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
		Vector4D<VectorType> & Aurora::Math::Vector4D<VectorType>::operator=(Vector4D<VectorType> && value)
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
		Aurora::Math::Vector4D<VectorType>::Vector4D(Vector4D<VectorType> &&value) : X(std::move(value.X)), Y(std::move(value.Y)), Z(std::move(value.Z)), W(std::move(value.W))
		{

		}

		template<typename VectorType>
		Aurora::Math::Vector4D<VectorType>::~Vector4D()
		{

		}

		template<typename VectorType>
		Aurora::Math::Vector4D<VectorType>::Vector4D(const Vector4D<VectorType> &value) : X(value.X), Y(value.Y), Z(value.Z), W(value.W)
		{

		}

		template<typename VectorType>
		Aurora::Math::Vector4D<VectorType>::Vector4D(VectorType x, VectorType y, VectorType z, VectorType w) : X(x), Y(y), Z(z), W(w)
		{
		}

		template<typename VectorType>
		Aurora::Math::Vector4D<VectorType>::Vector4D() : X(0), Y(0), Z(0), W(0)
		{

		}

	}
}

#endif
