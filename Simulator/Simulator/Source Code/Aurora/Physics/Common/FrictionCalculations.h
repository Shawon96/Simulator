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
			static Vector2D<Type> NormalFrictionCalculations(const Vector2D<Type>& velocity, float frictionCoefficient, float normal);

			template<typename Type>
			static Vector2D<Type> SimplifiedDragForceCalculations(const Vector2D<Type>& velocity, float coefficientDrag);
			
		};

		template<typename Type>
		static Vector2D<Type>
			Aurora::Physics::FrictionCalculations::SimplifiedDragForceCalculations(const Vector2D<Type>& velocity, float coefficientDrag)
		{
			float speed = velocity.Magnitude();
			float dragMagnitude = coefficientDrag * speed * speed;

			Vector2D<Type> drag = velocity.Clone();
			drag *= -1;
			drag *= dragMagnitude;
			return(drag);
		}

		template<typename Type>
		static Vector2D<Type>
			Aurora::Physics::FrictionCalculations::NormalFrictionCalculations(const Vector2D<Type>& velocity, float frictionCoefficient, float normal)
		{
			float frictionMagnitude = frictionCoefficient * normal;
			Vector2D<Type> friction = velocity.Clone();
			friction *= -1;
			friction.Normalize();
			friction *= frictionMagnitude;
			return friction;
		}

	};

};

#endif