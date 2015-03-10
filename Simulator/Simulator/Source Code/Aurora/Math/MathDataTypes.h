#ifndef MATHDATATYPES_H
#define MATHDATATYPES_H
#include "Vector4D.h"
#include "..\Globals\GlobalOperations.h"
#include <math.h>
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

#define EPSILON_E3 (Type)(1E-3) 
#define EPSILON_E4 (Type)(1E-4) 
#define EPSILON_E5 (Type)(1E-5)
#define EPSILON_E6 (Type)(1E-6)

		template<typename Type>
			class mRECT
			{
			public:
				mRECT();
				mRECT(Type width, Type height);
				~mRECT();
				mRECT(const mRECT<Type> &value);
				mRECT & operator=(const mRECT<Type> & value);
				mRECT(mRECT<Type> &&value);
				mRECT & operator=(mRECT<Type> && value);

				Type Width;
				Type Height;

				bool operator==(const mRECT<Type>		&value);

				bool operator!=(const mRECT<Type>		&value);

				bool IsZero() const;
			};

			template<typename Type>
			class Rectangle
			{
			private:
				Vector2D<Type> point;
				mRECT<Type> size;
			public:
				Rectangle();
				Rectangle(Type x, Type y, Type heigh, Type width);
				Rectangle(const Vector2D<Type> &point, const mRECT<Type> &size);
				Rectangle<Type> & operator=(const Rectangle<Type> & value);
				Rectangle(Rectangle<Type> &&value);
				Rectangle<Type> & operator=(Rectangle<Type> && value);
				virtual ~Rectangle();

				Vector2D<Type> Point() const {
					return point;
				}
				template<typename T>
				void Point(T &&value) {
					point = std::forward<T>(value);
				}

				mRECT<Type> Size() const {
					return size;
				}
				template<typename T>
				void Size(T &&value) {
					size = std::forward<T>(value);
				}
			};

			template<typename Type>
			Rectangle<Type> & Aurora::Math::Rectangle<Type>::operator=(Rectangle<Type> && value)
			{
				if (this == &value) { return(*this); }
				this->point = std::move(value.Point());
				this->size = std::move(value.Size());
				return(*this);
			}

			template<typename Type>
			Aurora::Math::Rectangle<Type>::Rectangle(Rectangle<Type> &&value) : point(std::move(value.Point())), size(std::move(value.Size()))
			{

			}

			template<typename Type>
			Rectangle<Type> & Aurora::Math::Rectangle<Type>::operator=(const Rectangle<Type> & value)
			{
				if (this == &value) { return(*this); }
				this->point = value.Point();
				this->size = value.Size();
				return(*this);
			}

			template<typename Type>
			Aurora::Math::Rectangle<Type>::~Rectangle()
			{

			}

			template<typename Type>
			Aurora::Math::Rectangle<Type>::Rectangle(const Vector2D<Type> &point, const mRECT<Type> &size) : point(point), size(size)
			{
			}

			template<typename Type>
			Aurora::Math::Rectangle<Type>::Rectangle(Type x, Type y, Type heigh, Type width) : Rectangle(Vector2D<Type>(x, y), mRECT<Type>(width, heigh))
			{

			}

			template<typename Type>
			Aurora::Math::Rectangle<Type>::Rectangle() : point(Vector2D<Type>::GetZero()), size(mRECT<Type>())
			{

			}

			/*!
				\brief Datatype for a 2D parametric line
			*/
			template<typename Type>
			class mPARAMETRICLINE2D
			{
				public:
					mPARAMETRICLINE2D(Vector2D<Type> &init, Vector2D<Type> &term);
					~mPARAMETRICLINE2D();
					Vector2D<Type> point1;		/*!< Start point of parametric line					*/
					Vector2D<Type> point2;		/*!< End point of parametric line					*/
					Vector2D<Type> v;				/*!< Direction vector of line segment |v|=|p0->p1|.	*/
			};

			/*!
				\brief Datatype for a 3D parametric line
			*/
			template<typename Type>
			class mPARAMETRICLINE3D
			{
				public:
					mPARAMETRICLINE3D(Vector3D<Type> &init, Vector3D<Type> &term);
					~mPARAMETRICLINE3D();
					Vector3D<Type> point1;		/*!< Start point of parametric line			*/
					Vector3D<Type> point2;		/*!< End point of parametric line			*/
					Vector3D<Type> v;				/*!< Direction vector of line segment		*/
			};

			/*!
				\brief 3D Plane
			*/
			template<typename Type>
			class mPLANE3D
			{
				public:
					mPLANE3D(const Vector3D<Type> &point, const Vector3D<Type> &normal, bool Normalize);
					~mPLANE3D();
					Vector3D<Type> point;			/*!< Point on the plane.									*/
					Vector3D<Type> normal;		/*!< Normal to the plane. (not necessarily a unit vector)	*/
			};

			/*!
			\brief 2D polar coordinates
			*/
			template<typename Type>
			class mPOLAR2D
			{
				public:
					Type r;				/*!< The radius of the point.	*/
					Type theta;			/*!< The angle in rads.			*/
			};

			/*!
			\brief 3D cylindrical coordinates
			*/
			template<typename Type>
			class mCYLINDRICAL3D
			{
				public:
					Type r;				/*!< The radius of the point.				*/
					Type theta;			/*!< The angle in degrees about the z axis. */
					Type z;				/*!< The z-height of the point.				*/
			};

			/*!
			\brief 3D spherical coordinates
			*/
			template<typename Type>
			class mSPHERICAL3D
			{
				public:
					Type p;				/*!< Rho, the distance to the point from the origin.							*/
					Type theta;			/*!< The angle from the z-axis and the line segment o->p.						*/
					Type phi;				/*!< The angle from the projection if o->p onto the x-y plane and the x-axis.	*/
			};

			typedef int FIXP16;			/*!< fixed point type */
			typedef int *FIXP16_PTR;	/*!< fixed point type */

		/*!
		\brief 4d quaternion
		*/
		template<typename Type>
		class mQUATERNION4D
		{
			public:
				mQUATERNION4D();
				mQUATERNION4D(Type q0, Vector3D<Type> qv);
				mQUATERNION4D(const mQUATERNION4D<Type> &value);
				~mQUATERNION4D();
				mQUATERNION4D<Type> &operator=(const mQUATERNION4D<Type>		&value);
				mQUATERNION4D<Type> operator+(const mQUATERNION4D<Type>			&value);
				mQUATERNION4D<Type> &operator+=(const mQUATERNION4D<Type>		&value);
				mQUATERNION4D<Type> operator-(const mQUATERNION4D<Type>			&value);
				mQUATERNION4D<Type> &operator-=(const mQUATERNION4D<Type>		&value);
				mQUATERNION4D<Type> operator*(const mQUATERNION4D<Type>			&value);
				mQUATERNION4D<Type> operator*(const Type					&value);
				mQUATERNION4D<Type> &operator*=(const Type				&value);
				mQUATERNION4D<Type> &operator*=(const mQUATERNION4D<Type>		&value);
				Type		q0;			/*!< The real part.						*/
				Vector3D<Type>	qV;			/*!< The imaginary part xi+yj+zk.		*/
				void ZeroQuarternion(void);
		};

		template<typename Type>
		mQUATERNION4D<Type>::mQUATERNION4D()
		{
			this->q0 = 0;
		}
		template<typename Type>
		mQUATERNION4D<Type>::mQUATERNION4D(Type q0, Vector3D<Type> qv)
		{
			this->q0 = q0;
			this->qV = qv;
		}
		template<typename Type>
		mQUATERNION4D<Type>::mQUATERNION4D(const mQUATERNION4D<Type> &value)
		{
			this->q0 = value.q0;
			this->qV = value.qV;
		}
		template<typename Type>
		mQUATERNION4D<Type>::~mQUATERNION4D()
		{

		}
		template<typename Type>
		mQUATERNION4D<Type> &mQUATERNION4D<Type>::operator=(const mQUATERNION4D<Type>		&value)
		{
			if (this == &value) { return(*this); }
			this->q0 = value.q0;
			this->qV = value.qV;
			return(*this);
		}
		template<typename Type>
		mQUATERNION4D<Type> mQUATERNION4D<Type>::operator+(const mQUATERNION4D<Type>		&value)
		{
			return(mQUATERNION4D(this->q0 + value.q0, Vector3D(this->qV.X + value.qV.X, this->qV.Y + value.qV.Y, this->qV.Z + value.qV.Z)));
		}
		template<typename Type>
		mQUATERNION4D<Type> mQUATERNION4D<Type>::operator-(const mQUATERNION4D<Type>		&value)
		{
			return(mQUATERNION4D(this->q0 - value.q0, Vector3D(this->qV.X - value.qV.X, this->qV.Y - value.qV.Y, this->qV.Z - value.qV.Z)));
		}
		template<typename Type>
		mQUATERNION4D<Type> &mQUATERNION4D<Type>::operator+=(const mQUATERNION4D<Type>		&value)
		{
			if (this == &value) { return(*this); }
			this->q0 += value.q0;
			this->qV += value.qV;
			return(*this);
		}
		template<typename Type>
		mQUATERNION4D<Type> &mQUATERNION4D<Type>::operator-=(const mQUATERNION4D<Type>		&value)
		{
			if (this == &value) { return(*this); }
			this->q0 -= value.q0;
			this->qV -= value.qV;
			return(*this);
		}
		template<typename Type>
		mQUATERNION4D<Type> mQUATERNION4D<Type>::operator*(const Type		&value)
		{
			return(mQUATERNION4D<Type>(this->q0 * value, Vector3D<Type>(this->qV.X * value, this->qV.Y * value, this->qV.Z * value)));
		}
		template<typename Type>
		mQUATERNION4D<Type> &mQUATERNION4D<Type>::operator*=(const mQUATERNION4D<Type>		&value)
		{
			if (this == &value) { return(*this); }
			this->q0 *= value.q0;
			this->qV.X *= value.qV.X;
			this->qV.Y *= value.qV.Y;
			this->qV.Z *= value.qV.Z;
			return(*this);
		}
		template<typename Type>
		void mQUATERNION4D<Type>::ZeroQuarternion()
		{
			this->q0 = 0.0;
			this->qV.Zero();
		}
		template<typename Type>
		mPARAMETRICLINE2D<Type>::mPARAMETRICLINE2D(Vector2D<Type> &init, Vector2D<Type> &term)
		{
			this->point1 = init;
			this->point2 = term;
			this->v = term - init;
		}
		template<typename Type>
		mPARAMETRICLINE2D<Type>::~mPARAMETRICLINE2D()
		{

		}
		template<typename Type>
		mPARAMETRICLINE3D<Type>::mPARAMETRICLINE3D(Vector3D<Type> &init, Vector3D<Type> &term)
		{
			this->point1 = init;
			this->point2 = term;
			this->v = term - init;
		}

		template<typename Type>
		mPLANE3D<Type>::mPLANE3D(const Vector3D<Type> &point, const Vector3D<Type> &normal, bool Normalize)
		{
			this->point = point;
			if (!Normalize)
			{
				this->normal = normal;
			}
			else {
				//NormalizeVector(&this->normal, normal);
			}
		}
		template<typename Type>
		mPLANE3D<Type>::~mPLANE3D()
		{

		}

		template<typename Type>
		mRECT<Type>::mRECT(Type width, Type height)
		{
			this->Width = width;
			this->Height = height;
		}
		template<typename Type>
		mRECT<Type>::mRECT() : Width(0), Height(0)
		{
			this->Width = 0;
			this->Height = 0;
		}
		template<typename Type>
		mRECT<Type>::mRECT(mRECT<Type> &&value) : Width(value.Width), Height(value.Height)
		{

		}
		template<typename Type>
		mRECT<Type>::mRECT(const mRECT<Type> &value) : Width(value.Width), Height(value.Height)
		{

		}
		template<typename Type>
		mRECT<Type>::~mRECT()
		{

		}
		template<typename Type>
		bool mRECT<Type>::operator==(const mRECT<Type> &value)
		{
			bool isEqual = false;

			if (this->Width == value.Width && this->Height == value.Height)
				isEqual = true;

			return(isEqual);
		}
		template<typename Type>
		bool mRECT<Type>::operator!=(const mRECT<Type> &value)
		{
			bool isEqual = false;

			if (this->Width != value.Width && this->Height != value.Height)
				isEqual = true;

			return(isEqual);
		}
		template<typename Type>
		bool mRECT<Type>::IsZero() const
		{
			bool isZero = false;

			if (this->Width == 0 && this->Height == 0)
				isZero = true;

			return(isZero);
		}
		template<typename Type>
		mRECT<Type> & mRECT<Type>::operator=(mRECT<Type> && value)
		{
			this->Width = value.Width;
			this->Height = value.Height;
			return(*this);
		}
		template<typename Type>
		mRECT<Type> & mRECT<Type>::operator=(const mRECT<Type> & value)
		{
			this->Width = value.Width;
			this->Height = value.Height;
			return(*this);
		}

	}; // END OF NAMESPACE
}; // END OF NAMESPACE

#endif