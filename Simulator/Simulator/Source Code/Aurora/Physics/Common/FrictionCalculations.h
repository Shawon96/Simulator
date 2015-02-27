#ifndef FrictionCalculations_H
#define FrictionCalculations_H

#include "CommonCalculations.h"

using namespace Aurora::Math;
namespace Aurora
{

	namespace Physics
	{
		class FrictionCalculations 
		{

		public:
			template<typename Type>
			static VECTOR2D<Type> NormalFrictionCalculations(const VECTOR2D<Type>& velocity, float frictionCoefficient, float normal);

			template<typename Type>
			static VECTOR2D<Type> SimplifiedDragForceCalculations(const VECTOR2D<Type>& velocity, float coefficientDrag);
			
		};

		template<typename Type>
		static VECTOR2D<Type>
			Aurora::Physics::FrictionCalculations::SimplifiedDragForceCalculations(const VECTOR2D<Type>& velocity, float coefficientDrag)
		{
			float speed = velocity.Magnitude();
			float dragMagnitude = coefficientDrag * speed * speed;

			VECTOR2D<Type> drag = velocity.Clone();
			drag *= -1;
			drag *= dragMagnitude;
			return(drag);
		}

		template<typename Type>
		static VECTOR2D<Type>
			Aurora::Physics::FrictionCalculations::NormalFrictionCalculations(const VECTOR2D<Type>& velocity, float frictionCoefficient, float normal)
		{
			float frictionMagnitude = frictionCoefficient * normal;
			VECTOR2D<Type> friction = velocity.Clone();
			friction *= -1;
			friction.Normalize();
			friction *= frictionMagnitude;
			return friction;
		}

	};

};

#endif