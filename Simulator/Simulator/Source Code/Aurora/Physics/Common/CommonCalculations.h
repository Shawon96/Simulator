#ifndef NatureOfCodeCocos2DX_CommonCalculations_h
#define NatureOfCodeCocos2DX_CommonCalculations_h



#include "PhysicsConstants.h"

using namespace Aurora::Math;

namespace Aurora {
	namespace Physics {


		class CommonCalculations 
		{
		public:
			template<typename Type>
			static Aurora::Math::Vector2D<Type> NormalEarthGravityCalculations(const Vector2D<Type> &gravity, float mass);

			template<typename Type>
			static Aurora::Math::Vector2D<Type> GravitationalAttractionCalculations(float objectGraviationalAttractionConstant, const Aurora::Math::Vector2D<Type>& attractor, float attractorMass, const Aurora::Math::Vector2D<Type>& toBeAttracted, float toBeAttractedMass, float distanceMinValue, float distanceMaxValue);
		};

		template<typename Type>
		static Aurora::Math::Vector2D<Type>
			Aurora::Physics::CommonCalculations::GravitationalAttractionCalculations(float objectGraviationalAttractionConstant, const Aurora::Math::Vector2D<Type>& attractor, float attractorMass, const Aurora::Math::Vector2D<Type>& toBeAttracted, float toBeAttractedMass, float distanceMinValue, float distanceMaxValue)
		{
			Vector2D<Type> attractionForce = attractor.Clone() - toBeAttracted;
			float distance = attractionForce.Magnitude();
			if (distance < distanceMinValue)
				distance = distanceMinValue;
			else if (distance > distanceMaxValue)
				distance = distanceMaxValue;

			attractionForce.Normalize();
			float strength = (objectGraviationalAttractionConstant * attractorMass * toBeAttractedMass) / (distance * distance);
			attractionForce *= strength;

			return attractionForce;
		}

		template<typename Type>
		static Aurora::Math::Vector2D<Type>
			Aurora::Physics::CommonCalculations::NormalEarthGravityCalculations(const Vector2D<Type> &gravity, float mass)
		{
			return Vector2D<Type>(gravity.X, gravity.Y * mass);
		}

	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora


#endif