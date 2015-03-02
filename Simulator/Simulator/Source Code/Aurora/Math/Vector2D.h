#ifndef VectorExtended_H
#define VectorExtended_H

#include "Matrix2D.h"

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
		class VECTOR2D
		{
		public:
			VectorType X;
			VectorType Y;
			VECTOR2D();
			VECTOR2D(VectorType x, VectorType y);
			VECTOR2D(const VECTOR2D<VectorType> &value);
			virtual ~VECTOR2D();
			VECTOR2D(VECTOR2D<VectorType> &&value);
			VECTOR2D<VectorType> & operator=(VECTOR2D<VectorType> && value);
			VECTOR2D<VectorType> &operator=(const VECTOR2D		&value);


#pragma region AdditionAndSubstractionOperators
			const VECTOR2D<VectorType> operator+(const VectorType			&value);

			const VECTOR2D<VectorType> operator+(const VECTOR2D<VectorType>		&value);

			const VECTOR2D<VectorType> operator-(const VectorType			&value);

			const VECTOR2D<VectorType> operator-(const VECTOR2D<VectorType>		&value);

			VECTOR2D<VectorType> &operator=(const VectorType			&value);

			VECTOR2D<VectorType> &operator+=(const VectorType		&value);

			VECTOR2D<VectorType> &operator+=(const VECTOR2D<VectorType>		&value);

			const VECTOR2D<VectorType> &operator-=(const VectorType		&value);

			const VECTOR2D<VectorType> &operator-=(const VECTOR2D<VectorType>		&value);
#pragma endregion AdditionAndSubstractionOperators

#pragma region DivisionAndMultiplicationOperators

			const VECTOR2D<VectorType> operator*(const VectorType		&value);

			const VectorType operator*(const VECTOR2D<VectorType>		&value);

			const VECTOR2D<VectorType> &operator*=(const VectorType		&value);

			const VECTOR2D<VectorType> operator/(const VectorType		&value) const;
			const VECTOR2D<VectorType> &operator/=(const VectorType		&value);

			const VECTOR2D<VectorType> &operator*=(const MATRIX2X2<VectorType>		&value);

			const VECTOR2D<VectorType> operator*(const MATRIX2X2<VectorType>		&value);
#pragma endregion DivisionAndMultiplicationOperators

#pragma region ComparisonOperators
			bool operator==(const VECTOR2D<VectorType>		&value);

			bool operator!=(const VECTOR2D<VectorType>		&value);
#pragma endregion ComparisonOperators

			void ZeroVector(void);
			void Limit(const VectorType &limit);
			bool IsZero() const;
			VectorType Magnitude() const;
			void Normalize();
			VectorType Heading();
			VECTOR2D<VectorType> Clone() const;
			void Normalize(const VECTOR2D<VectorType> &value);

			static VECTOR2D<VectorType> GetZeroVector(void);

		};

		template<typename VectorType>
		void Aurora::Math::VECTOR2D<VectorType>::Normalize(const VECTOR2D<VectorType> &value)
		{
			VectorType magnitude = value.Magnitude();
			if (magnitude != 0)
				*this = value / magnitude;
		}

		template<typename VectorType>
		VECTOR2D<VectorType> Aurora::Math::VECTOR2D<VectorType>::GetZeroVector(void)
		{
			return(VECTOR2D<VectorType>(0, 0));
		}

		template<typename VectorType>
		VECTOR2D<VectorType> Aurora::Math::VECTOR2D<VectorType>::Clone() const
		{
			return(VECTOR2D<VectorType>(this->X, this->Y));
		}

		template<typename VectorType>
		VectorType Aurora::Math::VECTOR2D<VectorType>::Heading()
		{
			return(atan2(Y, X));
		}

		template<typename VectorType>
		void Aurora::Math::VECTOR2D<VectorType>::Normalize()
		{
			VectorType magnitude = this->Magnitude();
			if (magnitude != 0)
				*this /= magnitude;
		}

		template<typename VectorType>
		VectorType Aurora::Math::VECTOR2D<VectorType>::Magnitude() const
		{
			return(sqrt(this->X*this->X + this->Y*this->Y));
		}

		template<typename VectorType>
		bool Aurora::Math::VECTOR2D<VectorType>::IsZero() const
		{
			bool isZero = false;

			if (this->X == 0 && this->Y == 0)
				isZero = true;

			return(isZero);
		}

		template<typename VectorType>
		void Aurora::Math::VECTOR2D<VectorType>::Limit(const VectorType &limit)
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
		void Aurora::Math::VECTOR2D<VectorType>::ZeroVector(void)
		{
			this->X = this->Y = 0;
		}

		template<typename VectorType>
		bool Aurora::Math::VECTOR2D<VectorType>::operator!=(const VECTOR2D<VectorType> &value)
		{
			bool isEqual = false;

			if (this->X != value.X && this->Y != value.Y)
				isEqual = true;

			return(isEqual);
		}

		template<typename VectorType>
		bool Aurora::Math::VECTOR2D<VectorType>::operator==(const VECTOR2D<VectorType> &value)
		{
			bool isEqual = false;

			if (this->X == value.X && this->Y == value.Y)
				isEqual = true;

			return(isEqual);
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> Aurora::Math::VECTOR2D<VectorType>::operator*(const MATRIX2X2<VectorType> &value)
		{
			return(VECTOR2D<VectorType>(this->X * value.M11 + this->Y * value.M21,
				this->X * value.M12 + this->Y * value.M22));
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator*=(const MATRIX2X2<VectorType> &value)
		{
			this->X = this->X * value.M11 + this->Y * value.M21;
			this->Y = this->X * value.M12 + this->Y * value.M22;

			return(*this);
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator/=(const VectorType &value)
		{
			this->X /= value;
			this->Y /= value;
			return(*this);
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> Aurora::Math::VECTOR2D<VectorType>::operator/(const VectorType &value) const
		{
			return(VECTOR2D<VectorType>(this->X / value, this->Y / value));
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator*=(const VectorType &value)
		{
			this->X *= value;
			this->Y *= value;
			return(*this);
		}

		template<typename VectorType>
		const VectorType Aurora::Math::VECTOR2D<VectorType>::operator*(const VECTOR2D<VectorType> &value)
		{
			return((this->X * value.X) + (this->Y * value.Y));
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> Aurora::Math::VECTOR2D<VectorType>::operator*(const VectorType &value)
		{
			return(VECTOR2D<VectorType>(this->X * value, this->Y * value));
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator-=(const VECTOR2D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X -= value.X;
			this->Y -= value.Y;
			return(*this);
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator-=(const VectorType &value)
		{
			this->X -= value;
			this->Y -= value;
			return(*this);
		}

		template<typename VectorType>
		VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator+=(const VECTOR2D<VectorType> &value)
		{
			if (this == &value) { return(*this); }
			this->X += value.X;
			this->Y += value.Y;
			return(*this);
		}

		template<typename VectorType>
		VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator+=(const VectorType &value)
		{
			this->X += value;
			this->Y += value;
			return(*this);
		}

		template<typename VectorType>
		VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator=(const VectorType &value)
		{
			this->X = value;
			this->Y = value;
			return(*this);
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> Aurora::Math::VECTOR2D<VectorType>::operator-(const VECTOR2D<VectorType> &value)
		{
			return(VECTOR2D<VectorType>(this->X - value.X, this->Y - value.Y));
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> Aurora::Math::VECTOR2D<VectorType>::operator-(const VectorType &value)
		{
			return(VECTOR2D<VectorType>(this->X - value, this->Y - value));
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> Aurora::Math::VECTOR2D<VectorType>::operator+(const VECTOR2D<VectorType> &value)
		{
			return(VECTOR2D<VectorType>(this->X + value.X, this->Y + value.Y));
		}

		template<typename VectorType>
		const VECTOR2D<VectorType> Aurora::Math::VECTOR2D<VectorType>::operator+(const VectorType &value)
		{

			return(VECTOR2D<VectorType>(this->X + value, this->Y + value));
		}
		

		template<typename VectorType>
		VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator=(const VECTOR2D<VectorType> &value)
		{
			if (this == &value)
				return *this;

			this->X = value.X;
			this->Y = value.Y;
			return(*this);
		}

		template<typename VectorType>
		VECTOR2D<VectorType> & Aurora::Math::VECTOR2D<VectorType>::operator=(VECTOR2D<VectorType> && value)
		{
			if (this == &value)
				return *this;

			this->X = std::move(value.X);
			this->Y = std::move(value.Y);
			return(*this);
		}

		template<typename VectorType>
		Aurora::Math::VECTOR2D<VectorType>::VECTOR2D(VECTOR2D<VectorType> &&value) : X(std::move(value.X)), Y(std::move(value.Y))
		{

		}

		template<typename VectorType>
		Aurora::Math::VECTOR2D<VectorType>::~VECTOR2D()
		{

		}

		template<typename VectorType>
		Aurora::Math::VECTOR2D<VectorType>::VECTOR2D(const VECTOR2D<VectorType> &value) : X(value.X), Y(value.Y)
		{

		}

		template<typename VectorType>
		Aurora::Math::VECTOR2D<VectorType>::VECTOR2D(VectorType x, VectorType y) : X(x), Y(y)
		{
		}

		template<typename VectorType>
		Aurora::Math::VECTOR2D<VectorType>::VECTOR2D() : X(0), Y(0)
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