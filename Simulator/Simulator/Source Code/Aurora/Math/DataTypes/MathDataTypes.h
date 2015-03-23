#ifndef MATH_DATATYPES_MathDataTypes_H
#define MATH_DATATYPES_MathDataTypes_H
#include "QUATERNION4D.h"
#include "..\..\Globals\GlobalOperations.h"
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

		

	}; // END OF NAMESPACE
}; // END OF NAMESPACE

#endif