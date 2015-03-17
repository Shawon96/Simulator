#ifndef VectorExtended_H
#define VectorExtended_H

#include "../Matrices/Matrix2D.h"

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
		class Vector2D
		{
		public:
			VectorType X;
			VectorType Y;
			Vector2D();
			Vector2D(VectorType x, VectorType y);
			Vector2D(const Vector2D<VectorType> &value);
			virtual ~Vector2D();
			Vector2D(Vector2D<VectorType> &&value);
			Vector2D<VectorType> & operator=(Vector2D<VectorType> && value);
			Vector2D<VectorType> &operator=(const Vector2D		&value);


#pragma region AdditionAndSubstractionOperators
			const Vector2D<VectorType> operator+(const VectorType			&value);

			const Vector2D<VectorType> operator+(const Vector2D<VectorType>		&value);

			const Vector2D<VectorType> operator-(const VectorType			&value);

			const Vector2D<VectorType> operator-(const Vector2D<VectorType>		&value);

			Vector2D<VectorType> &operator=(const VectorType			&value);

			Vector2D<VectorType> &operator+=(const VectorType		&value);

			Vector2D<VectorType> &operator+=(const Vector2D<VectorType>		&value);

			const Vector2D<VectorType> &operator-=(const VectorType		&value);

			const Vector2D<VectorType> &operator-=(const Vector2D<VectorType>		&value);

			Vector2D<VectorType> Add(const Vector2D<VectorType>		&value);

			Vector2D<VectorType> Subtract(const Vector2D<VectorType>		&value);
#pragma endregion AdditionAndSubstractionOperators

#pragma region DivisionAndMultiplicationOperators

			const Vector2D<VectorType> operator*(const VectorType		&value);

			const VectorType operator*(const Vector2D<VectorType>		&value);

			const Vector2D<VectorType> &operator*=(const VectorType		&value);

			const Vector2D<VectorType> operator/(const VectorType		&value) const;
			const Vector2D<VectorType> &operator/=(const VectorType		&value);

			const Vector2D<VectorType> &operator*=(const Matrix2D<VectorType>		&value);

			const Vector2D<VectorType> operator*(const Matrix2D<VectorType>		&value);

			Vector2D<VectorType> Multiply(const VectorType &scalar);

			Vector2D<VectorType> MultiplyComponents(const Vector2D<VectorType>		&value);

			Vector2D<VectorType> Divide(const VectorType &scalar);
#pragma endregion DivisionAndMultiplicationOperators

#pragma region ComparisonOperators
			bool operator==(const Vector2D<VectorType>		&value);

			bool operator!=(const Vector2D<VectorType>		&value);

			bool operator<(const VectorType &scalar) const;

			bool operator>(const VectorType &scalar) const;

			bool operator<(const Vector2D<VectorType>		&value) const;

			bool operator>(const Vector2D<VectorType>		&value) const;
#pragma endregion ComparisonOperators

			Vector2D<bool> ToBoolean() const;
			Vector2D<float> ToFloat() const;
			Vector2D<double> ToDouble() const;
			Vector2D<int> ToInt() const;
			Vector2D<half_float::half> ToHalfPrecision() const;

			void Zero(void);
			void Limit(const VectorType &limit);
			bool IsZero() const;
			VectorType Magnitude() const;
			Vector2D<VectorType> Normalize();
			VectorType Heading();
			Vector2D<VectorType> Clone() const;
			Vector2D<VectorType> Normalize(const Vector2D<VectorType> &value);

			static Vector2D<VectorType> GetZero(void);

			static Vector2D<VectorType> UnitX();

			static Vector2D<VectorType> UnitY();

			static Vector2D<VectorType> Undefined();

			VectorType MagnitudeSquared() const;
			bool IsUndefined() const;
			Vector2D<VectorType> Normalize(VectorType &value);
			Vector2D<VectorType> MostOrthogonalAxis() const;
			Vector2D<VectorType> Negate() const;
			bool EqualsEpsilon(const Vector2D<VectorType> &value, double epsilon);

			std::string ToString() const;

			int GetHashCode() const;

			bool Equals(const Vector2D<VectorType> &value) const;

			VectorType Dot(const Vector2D<VectorType> &value);
		};
		using Vector2DBool = Vector2D < bool >;
		using Vector2DDouble = Vector2D < double >;
		using Vector2DFloat = Vector2D < float >;
		using Vector2DInt = Vector2D < int >;
		using Vector2DHalfPrecision = Vector2D < half_float::half >;

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::operator>(const Vector2D<VectorType> &value) const
		{
			return(this->X > value.X && this->Y > value.Y);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::operator<(const Vector2D<VectorType> &value) const
		{
			return(this->X < value.X && this->Y < value.Y);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::operator>(const VectorType &scalar) const
		{
			return(this->X > scalar && this->Y > scalar);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::operator<(const VectorType &scalar) const
		{
			return(this->X < scalar && this->Y < scalar);
		}

		template<typename VectorType>
		Vector2D<half_float::half> Aurora::Math::Vector2D<VectorType>::ToHalfPrecision() const
		{
			return(Vector2D<half_float::half>(static_cast<half_float::half>(this->X), static_cast<half_float::half>(this->Y), static_cast<half_float::half>(this->Z)));
		}

		template<typename VectorType>
		Vector2D<int> Aurora::Math::Vector2D<VectorType>::ToInt() const
		{
			return(Vector2D<int>(static_cast<int>(this->X), static_cast<int>(this->Y), static_cast<int>(this->Z)));
		}

		template<typename VectorType>
		Vector2D<double> Aurora::Math::Vector2D<VectorType>::ToDouble() const
		{
			return(Vector2D<double>(static_cast<double>(this->X), static_cast<double>(this->Y), static_cast<double>(this->Z)));
		}

		template<typename VectorType>
		Vector2D<float> Aurora::Math::Vector2D<VectorType>::ToFloat() const
		{
			return(Vector2D<float>(static_cast<float>(this->X), static_cast<float>(this->Y), static_cast<float>(this->Z)));
		}

		template<typename VectorType>
		Vector2D<bool> Aurora::Math::Vector2D<VectorType>::ToBoolean() const
		{
			return(Vector2D<bool>(static_cast<bool>(this->X), static_cast<bool>(this->Y), static_cast<bool>(this->Z)));
		}


		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Divide(const VectorType &scalar)
		{
			return this / scalar;
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::MultiplyComponents(const Vector2D<VectorType> &value)
		{
			return Vector2D<VectorType>(X * scale.X, Y * scale.Y);
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Multiply(const VectorType &scalar)
		{
			return this * scalar;
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Subtract(const Vector2D<VectorType> &value)
		{
			return this - value;
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Add(const Vector2D<VectorType> &value)
		{
			return this + value;
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector2D<VectorType>::Dot(const Vector2D<VectorType> &value)
		{
			return X * value.X + Y * value.Y;
		}

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::Equals(const Vector2D<VectorType> &value) const
		{
			return(this->X == value.X && this->Y == value.Y);
		}

		template<typename VectorType>
		int Aurora::Math::Vector2D<VectorType>::GetHashCode() const
		{
			std::hash<VectorType> hash;
			return hash(this->X) ^ hash(this->Y);
		}

		template<typename VectorType>
		std::string Aurora::Math::Vector2D<VectorType>::ToString() const
		{
			return("X:" + std::to_string(this->X) + " Y:" + std::to_string(this->Y));
		}

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::EqualsEpsilon(const Vector2D<VectorType> &value, double epsilon)
		{
			return  (abs(this->X - other.X) <= epsilon) &&
					(abs(this->Y - other.Y) <= epsilon);
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Negate() const
		{
			return -this;
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Normalize(VectorType &value)
		{
			magnitude = this->Magnitude();
			return this / magnitude;
		}

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::IsUndefined() const
		{
			return(isnan(this->X));
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector2D<VectorType>::MagnitudeSquared() const
		{
			return this->X * this->X + this->Y * this->Y;
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Undefined()
		{
			double nanValue;
			return Vector2D<VectorType>(nanValue, nanValue);
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::UnitY()
		{
			return Vector2D<VectorType>(0.0, 1.0);
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::UnitX()
		{
			return Vector2D<VectorType>(1.0, 0.0);
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Normalize(const Vector2D<VectorType> &value)
		{
			VectorType magnitude = value.Magnitude();
			if (magnitude != 0)
				*this = value / magnitude;

			return(*this);
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::GetZero(void)
		{
			return(Vector2D<VectorType>(0, 0));
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Clone() const
		{
			return(Vector2D<VectorType>(this->X, this->Y));
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector2D<VectorType>::Heading()
		{
			return(atan2(Y, X));
		}

		template<typename VectorType>
		Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::Normalize()
		{
			VectorType magnitude = this->Magnitude();
			if (magnitude != 0)
				*this /= magnitude;

			return(*this);
		}

		template<typename VectorType>
		VectorType Aurora::Math::Vector2D<VectorType>::Magnitude() const
		{
			return(sqrt(this->X*this->X + this->Y*this->Y));
		}

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::IsZero() const
		{
			bool isZero = false;

			if (this->X == 0 && this->Y == 0)
				isZero = true;

			return(isZero);
		}

		template<typename VectorType>
		void Aurora::Math::Vector2D<VectorType>::Limit(const VectorType &limit)
		{
			if (this->X > limit) {
				this->X = limit;
			}

			if (this->Y > limit) {
				this->Y = limit;
			}

			if (this->X < -limit) {
				this->X = -limit;
			}

			if (this->Y < -limit) {
				this->Y = -limit;
			}
		}

		template<typename VectorType>
		void Aurora::Math::Vector2D<VectorType>::Zero(void)
		{
			this->X = this->Y = 0;
		}

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::operator!=(const Vector2D<VectorType> &value)
		{
			return(this->X != value.X && this->Y != value.Y);
		}

		template<typename VectorType>
		bool Aurora::Math::Vector2D<VectorType>::operator==(const Vector2D<VectorType> &value)
		{
			return(this->X == value.X && this->Y == value.Y);
		}

		template<typename VectorType>
		const Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::operator*(const Matrix2D<VectorType> &value)
		{
			return(Vector2D<VectorType>(this->X * value.M11 + this->Y * value.M21,
				this->X * value.M12 + this->Y * value.M22));
		}

		template<typename VectorType>
		const Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator*=(const Matrix2D<VectorType> &value)
		{
			this->X = this->X * value.M11 + this->Y * value.M21;
			this->Y = this->X * value.M12 + this->Y * value.M22;

			return(*this);
		}

		template<typename VectorType>
		const Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator/=(const VectorType &value)
		{
			this->X /= value;
			this->Y /= value;
			return(*this);
		}

		template<typename VectorType>
		const Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::operator/(const VectorType &value) const
		{
			return(Vector2D<VectorType>(this->X / value, this->Y / value));
		}

		template<typename VectorType>
		const Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator*=(const VectorType &value)
		{
			this->X *= value;
			this->Y *= value;
			return(*this);
		}

		template<typename VectorType>
		const VectorType Aurora::Math::Vector2D<VectorType>::operator*(const Vector2D<VectorType> &value)
		{
			return((this->X * value.X) + (this->Y * value.Y));
		}

		template<typename VectorType>
		const Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::operator*(const VectorType &value)
		{
			return(Vector2D<VectorType>(this->X * value, this->Y * value));
		}

		template<typename VectorType>
		const Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator-=(const Vector2D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X -= value.X;
			this->Y -= value.Y;
			return(*this);
		}

		template<typename VectorType>
		const Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator-=(const VectorType &value)
		{
			this->X -= value;
			this->Y -= value;
			return(*this);
		}

		template<typename VectorType>
		Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator+=(const Vector2D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X += value.X;
			this->Y += value.Y;
			return(*this);
		}

		template<typename VectorType>
		Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator+=(const VectorType &value)
		{
			this->X += value;
			this->Y += value;
			return(*this);
		}

		template<typename VectorType>
		Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator=(const VectorType &value)
		{
			this->X = value;
			this->Y = value;
			return(*this);
		}

		template<typename VectorType>
		const Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::operator-(const Vector2D<VectorType> &value)
		{
			return(Vector2D<VectorType>(this->X - value.X, this->Y - value.Y));
		}

		template<typename VectorType>
		const Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::operator-(const VectorType &value)
		{
			return(Vector2D<VectorType>(this->X - value, this->Y - value));
		}

		template<typename VectorType>
		const Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::operator+(const Vector2D<VectorType> &value)
		{
			return(Vector2D<VectorType>(this->X + value.X, this->Y + value.Y));
		}

		template<typename VectorType>
		const Vector2D<VectorType> Aurora::Math::Vector2D<VectorType>::operator+(const VectorType &value)
		{

			return(Vector2D<VectorType>(this->X + value, this->Y + value));
		}
		

		template<typename VectorType>
		Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator=(const Vector2D<VectorType> &value)
		{
			if (this == &value)
				return *this;

			this->X = value.X;
			this->Y = value.Y;
			return(*this);
		}

		template<typename VectorType>
		Vector2D<VectorType> & Aurora::Math::Vector2D<VectorType>::operator=(Vector2D<VectorType> && value)
		{
			if (this == &value)
				return *this;

			this->X = std::move(value.X);
			this->Y = std::move(value.Y);
			return(*this);
		}

		template<typename VectorType>
		Aurora::Math::Vector2D<VectorType>::Vector2D(Vector2D<VectorType> &&value) : X(std::move(value.X)), Y(std::move(value.Y))
		{

		}

		template<typename VectorType>
		Aurora::Math::Vector2D<VectorType>::~Vector2D()
		{

		}

		template<typename VectorType>
		Aurora::Math::Vector2D<VectorType>::Vector2D(const Vector2D<VectorType> &value) : X(value.X), Y(value.Y)
		{

		}

		template<typename VectorType>
		Aurora::Math::Vector2D<VectorType>::Vector2D(VectorType x, VectorType y) : X(x), Y(y)
		{
		}

		template<typename VectorType>
		Aurora::Math::Vector2D<VectorType>::Vector2D() : X(0), Y(0)
		{

		}

	}
}

/*

#include <iostream>
#include <math.h>
#ifndef FM_COORD
#define FM_COORD
typedef float FM_coord;
#endif
template <int N, typename T> class FM_vector;
template <typename T>
struct FM_traits
{
	typedef T element_type;
};
template <int N, typename T>
struct FM_traits < FM_vector<N, T> >
{
	typedef typename FM_traits<T>::element_type element_type;
};
template <int N, typename T>
T FM_dot(const FM_vector<N, T>&, const FM_vector<N, T>&);
template <typename T>
FM_vector<3, T> FM_cross(const FM_vector<3, T>&, const FM_vector<3, T>&);
template <int N, typename T = FM_coord>
class FM_vector
{
public:
	FM_vector() {}
	FM_vector(const T dat[])
	{
		for (int i = 0; i < N; i++)
			d[i] = dat[i];
	}
	template <typename S>
	explicit FM_vector(const FM_vector<N, S>& dat)
	{
		for (int i = 0; i < N; i++)
			d[i] = (T)dat[i];
	}
	T& operator[](int i) { return d[i]; }
	const T& operator[](int i) const { return d[i]; }
	operator const T*() const
	{
		return (typename FM_traits<T>::element_type*) d;
	}
	friend bool operator==(const FM_vector<N, T>& lhs,
		const FM_vector<N, T>& rhs)
	{

	bool res = true;
	for (int i = 0; i < N; i++) {
	if (!(lhs[i] == rhs[i])) {
	res = false;
	break;
	}
	}
	return res;
	}
	FM_vector<N,T>& operator+=(const FM_vector<N,T>& v) {
	for (int i = 0; i < N; i++)
	d[i] += v[i];
	return *this;
	}
	FM_vector<N,T>& operator-=(const FM_vector<N,T>& v) {
	for (int i = 0; i < N; i++)
	d[i] -= v[i];
	return *this;
	}
	FM_vector<N,T>& operator*=(typename FM_traits<T>::element_type s) {
	for (int i = 0; i < N; i++)
	d[i] *= s;
	return *this;
	}
	FM_vector<N,T>& operator/=(typename FM_traits<T>::element_type s) {
	for (int i = 0; i < N; i++)
	d[i] /= s;
	return *this;
	}
	friend FM_vector<N,T> operator-(const FM_vector<N,T>& u)
	{
	T tmp[N];
	for (int i = 0; i < N; i++)
	tmp[i] = -u[i];
	return FM_vector<N,T>(tmp);
	}
	friend FM_vector<N,T> operator+(const FM_vector<N,T>& lhs,
	const FM_vector<N,T>& rhs)
	{
	T tmp[N];
	for (int i = 0; i < N; i++)
	tmp[i] = lhs[i] + rhs[i];
	return FM_vector<N,T>(tmp);
	}
	friend FM_vector<N,T> operator-(const FM_vector<N,T>& lhs,
	const FM_vector<N,T>& rhs)
	{
	T tmp[N];
	for (int i = 0; i < N; i++)
	tmp[i] = lhs[i] - rhs[i];
	return FM_vector<N,T>(tmp);
	}
	friend FM_vector<N,T>
	operator*(typename FM_traits<T>::element_type lhs,
	const FM_vector<N,T>& rhs)
	{
	T tmp[N];
	for (int i = 0; i < N; i++)
	tmp[i] = lhs * rhs[i];
	return FM_vector<N,T>(tmp);
	}
	13friend FM_vector<N,T>
	operator*(const FM_vector<N,T>& lhs,
	typename FM_traits<T>::element_type rhs)
	{
	T tmp[N];
	for (int i = 0; i < N; i++)
	tmp[i] = lhs[i] * rhs;
	return FM_vector<N,T>(tmp);
	}
	private:
	T d[N];
	};
	template <typename T>
	class FM_vector<1,T>
	{
	public:
	FM_vector() {}
	FM_vector(const T dat[])
	{
	d[0] = dat[0];
	}
	template <typename S>
	explicit FM_vector(const FM_vector<1,S>& dat)
	{
	d[0] = (T) dat[0];
	}
	FM_vector(const T& a0)
	{
	d[0] = a0;
	}
	T& operator[](int i) { return d[i]; }
	const T& operator[](int i) const { return d[i]; }
	operator const T*() const
	{
	return (typename FM_traits<T>::element_type*) d;
	}
	friend bool operator==(const FM_vector<1,T>& lhs,
	const FM_vector<1,T>& rhs)
	{
	return
	lhs.d[0] == rhs.d[0];
	}
	FM_vector<1,T>& operator+=(const FM_vector<1,T>& v) {
	d[0] += v[0];
	return *this;
	}
	FM_vector<1,T>& operator-=(const FM_vector<1,T>& v) {
	d[0] -= v[0];
	return *this;
	}
	FM_vector<1,T>& operator*=(typename FM_traits<T>::element_type s) {
	d[0] *= s;
	return *this;
	}
	FM_vector<1,T>& operator/=(typename FM_traits<T>::element_type s) {
	d[0] /= s;
	return *this;
	14}
	friend FM_vector<1,T> operator-(const FM_vector<1,T>& u)
	{
	return FM_vector<1,T>(-u.d[0]);
	}
	friend FM_vector<1,T> operator+(const FM_vector<1,T>& lhs,
	const FM_vector<1,T>& rhs)
	{
	return FM_vector<1,T>(lhs.d[0] + rhs.d[0]);
	}
	friend FM_vector<1,T> operator-(const FM_vector<1,T>& lhs,
	const FM_vector<1,T>& rhs)
	{
	return FM_vector<1,T>(lhs.d[0] - rhs.d[0]);
	}
	friend FM_vector<1,T>
	operator*(typename FM_traits<T>::element_type lhs,
	const FM_vector<1,T>& rhs)
	{
	return FM_vector<1,T>(lhs * rhs.d[0]);
	}
	friend FM_vector<1,T>
	operator*(const FM_vector<1,T>& lhs,
	typename FM_traits<T>::element_type rhs)
	{
	return FM_vector<1,T>(lhs.d[0] * rhs);
	}
	friend T FM_dot<T>(const FM_vector<1,T>&,
	const FM_vector<1,T>&);
	private:
	T d[1];
	};
	template <typename T>
	class FM_vector<2,T>
	{
	public:
	FM_vector() {}
	FM_vector(const T dat[])
	{
	d[0] = dat[0];
	d[1] = dat[1];
	}
	template <typename S>
	explicit FM_vector(const FM_vector<2,S>& dat)
	{
	d[0] = (T) dat[0];
	d[1] = (T) dat[1];
	}
	FM_vector(const T& a0, const T& a1)
	{
	d[0] = a0;
	d[1] = a1;
	}
	T& operator[](int i) { return d[i]; }
	const T& operator[](int i) const { return d[i]; }
	operator const T*() const
	{
	return (typename FM_traits<T>::element_type*) d;
	}
	15friend bool operator==(const FM_vector<2,T>& lhs,
	const FM_vector<2,T>& rhs)
	{
	return
	lhs.d[0] == rhs.d[0] &&
	lhs.d[1] == rhs.d[1];
	}
	FM_vector<2,T>& operator+=(const FM_vector<2,T>& v) {
	d[0] += v[0];
	d[1] += v[1];
	return *this;
	}
	FM_vector<2,T>& operator-=(const FM_vector<2,T>& v) {
	d[0] -= v[0];
	d[1] -= v[1];
	return *this;
	}
	FM_vector<2,T>& operator*=(typename FM_traits<T>::element_type s) {
	d[0] *= s;
	d[1] *= s;
	return *this;
	}
	FM_vector<2,T>& operator/=(typename FM_traits<T>::element_type s) {
	d[0] /= s;
	d[1] /= s;
	return *this;
	}
	friend FM_vector<2,T> operator-(const FM_vector<2,T>& u)
	{
	return FM_vector<2,T>(-u.d[0], -u.d[1]);
	}
	friend FM_vector<2,T> operator+(const FM_vector<2,T>& lhs,
	const FM_vector<2,T>& rhs)
	{
	return FM_vector<2,T>(lhs.d[0] + rhs.d[0],
	lhs.d[1] + rhs.d[1]);
	}
	friend FM_vector<2,T> operator-(const FM_vector<2,T>& lhs,
	const FM_vector<2,T>& rhs)
	{
	return FM_vector<2,T>(lhs.d[0] - rhs.d[0],
	lhs.d[1] - rhs.d[1]);
	}
	friend FM_vector<2,T>
	operator*(typename FM_traits<T>::element_type lhs,
	const FM_vector<2,T>& rhs)
	{
	return FM_vector<2,T>(lhs * rhs.d[0],
	lhs * rhs.d[1]);
	}
	friend FM_vector<2,T>
	operator*(const FM_vector<2,T>& lhs,
	typename FM_traits<T>::element_type rhs)
	{
	return FM_vector<2,T>(lhs.d[0] * rhs,
	lhs.d[1] * rhs);
	}
	friend T FM_dot<T>(const FM_vector<2,T>&,
	const FM_vector<2,T>&);
	16private:
	T d[2];
	};
	template <typename T>
	class FM_vector<3,T>
	{
	public:
	FM_vector() {}
	FM_vector(const T dat[])
	{
	d[0] = dat[0];
	d[1] = dat[1];
	d[2] = dat[2];
	}
	template <typename S>
	explicit FM_vector(const FM_vector<3,S>& dat)
	{
	d[0] = (T) dat[0];
	d[1] = (T) dat[1];
	d[2] = (T) dat[2];
	}
	FM_vector(const T& a0, const T& a1, const T& a2)
	{
	d[0] = a0;
	d[1] = a1;
	d[2] = a2;
	}
	T& operator[](int i) { return d[i]; }
	const T& operator[](int i) const { return d[i]; }
	operator const T*() const
	{
	return (typename FM_traits<T>::element_type*) d;
	}
	friend bool operator==(const FM_vector<3,T>& lhs,
	const FM_vector<3,T>& rhs)
	{
	return
	lhs.d[0] == rhs.d[0] &&
	lhs.d[1] == rhs.d[1] &&
	lhs.d[2] == rhs.d[2];
	}
	FM_vector<3,T>& operator+=(const FM_vector<3,T>& v) {
	d[0] += v[0];
	d[1] += v[1];
	d[2] += v[2];
	return *this;

	FM_vector<2,T>& operator+=(const FM_vector<2,T>& v) {
	d[0] += v[0];
	d[1] += v[1];
	return *this;
	}
	FM_vector<2,T>& operator-=(const FM_vector<2,T>& v) {
	d[0] -= v[0];
	d[1] -= v[1];
	return *this;
	}
	FM_vector<2,T>& operator*=(typename FM_traits<T>::element_type s) {
	d[0] *= s;
	d[1] *= s;
	return *this;
	}
	FM_vector<2,T>& operator/=(typename FM_traits<T>::element_type s) {
	d[0] /= s;
	d[1] /= s;
	return *this;
	}
	friend FM_vector<2,T> operator-(const FM_vector<2,T>& u)
	{
	return FM_vector<2,T>(-u.d[0], -u.d[1]);
	}
	friend FM_vector<2,T> operator+(const FM_vector<2,T>& lhs,
	const FM_vector<2,T>& rhs)
	{
	return FM_vector<2,T>(lhs.d[0] + rhs.d[0],
	lhs.d[1] + rhs.d[1]);
	}
	friend FM_vector<2,T> operator-(const FM_vector<2,T>& lhs,
	const FM_vector<2,T>& rhs)
	{
	return FM_vector<2,T>(lhs.d[0] - rhs.d[0],
	lhs.d[1] - rhs.d[1]);
	}
	friend FM_vector<2,T>
	operator*(typename FM_traits<T>::element_type lhs,
	const FM_vector<2,T>& rhs)
	{
	return FM_vector<2,T>(lhs * rhs.d[0],
	lhs * rhs.d[1]);
	}
	friend FM_vector<2,T>
	operator*(const FM_vector<2,T>& lhs,
	typename FM_traits<T>::element_type rhs)
	{
	return FM_vector<2,T>(lhs.d[0] * rhs,
	lhs.d[1] * rhs);
	}
	friend T FM_dot<T>(const FM_vector<2,T>&,
	const FM_vector<2,T>&);
	16private:
	T d[2];
	};
	template <typename T>
	class FM_vector<3,T>
	{
	public:
	FM_vector() {}
	FM_vector(const T dat[])
	{
	d[0] = dat[0];
	d[1] = dat[1];
	d[2] = dat[2];
	}
	template <typename S>
	explicit FM_vector(const FM_vector<3,S>& dat)
	{
	d[0] = (T) dat[0];
	d[1] = (T) dat[1];
	d[2] = (T) dat[2];
	}
	FM_vector(const T& a0, const T& a1, const T& a2)
	{
	d[0] = a0;
	d[1] = a1;
	d[2] = a2;
	}
	T& operator[](int i) { return d[i]; }
	const T& operator[](int i) const { return d[i]; }
	operator const T*() const
	{
	return (typename FM_traits<T>::element_type*) d;
	}
	friend bool operator==(const FM_vector<3,T>& lhs,
	const FM_vector<3,T>& rhs)
	{
	return
	lhs.d[0] == rhs.d[0] &&
	lhs.d[1] == rhs.d[1] &&
	lhs.d[2] == rhs.d[2];
	}
	FM_vector<3,T>& operator+=(const FM_vector<3,T>& v) {
	d[0] += v[0];
	d[1] += v[1];
	d[2] += v[2];
	return *this;
	}
	FM_vector<3,T>& operator-=(const FM_vector<3,T>& v) {
	d[0] -= v[0];
	d[1] -= v[1];
	d[2] -= v[2];
	return *this;
	}
	FM_vector<3,T>& operator*=(typename FM_traits<T>::element_type s) {
	d[0] *= s;
	d[1] *= s;
	d[2] *= s;
	return *this;
	}
	17FM_vector<3,T>& operator/=(typename FM_traits<T>::element_type s) {
	d[0] /= s;
	d[1] /= s;
	d[2] /= s;
	return *this;
	}
	friend FM_vector<3,T> operator-(const FM_vector<3,T>& u)
	{
	return FM_vector<3,T>(-u.d[0], -u.d[1], -u.d[2]);
	}
	friend FM_vector<3,T> operator+(const FM_vector<3,T>& lhs,
	const FM_vector<3,T>& rhs)
	{
	return FM_vector<3,T>(lhs.d[0] + rhs.d[0],
	lhs.d[1] + rhs.d[1],
	lhs.d[2] + rhs.d[2]);
	}
	friend FM_vector<3,T> operator-(const FM_vector<3,T>& lhs,
	const FM_vector<3,T>& rhs)
	{
	return FM_vector<3,T>(lhs.d[0] - rhs.d[0],
	lhs.d[1] - rhs.d[1],
	lhs.d[2] - rhs.d[2]);
	}
	friend FM_vector<3,T>
	operator*(typename FM_traits<T>::element_type lhs,
	const FM_vector<3,T>& rhs)
	{
	return FM_vector<3,T>(lhs * rhs.d[0],
	lhs * rhs.d[1],
	lhs * rhs.d[2]);
	}
	friend FM_vector<3,T>
	operator*(const FM_vector<3,T>& lhs,
	typename FM_traits<T>::element_type rhs)
	{
	return FM_vector<3,T>(lhs.d[0] * rhs,
	lhs.d[1] * rhs,
	lhs.d[2] * rhs);
	}
	friend T FM_dot<T>(const FM_vector<3,T>&,
	const FM_vector<3,T>&);
	friend FM_vector<3,T> FM_cross<T>(const FM_vector<3,T>&,
	const FM_vector<3,T>&);
	private:
	T d[3];
	};
	template <typename T>
	class FM_vector<4,T>
	{
	public:
	FM_vector() {}
	FM_vector(const T dat[])
	{
	d[0] = dat[0];
	d[1] = dat[1];
	d[2] = dat[2];
	d[3] = dat[3];
	}
	template <typename S>
*/

#endif