#include "PhysicsCalculator.h"

namespace Aurora {
	namespace Physics {

		template<typename Type>
		std::shared_ptr<PhysicsCalculator<Type>> PhysicsCalculator<Type>::instance = nullptr;

		template<typename Type>
		void PhysicsCalculator<Type>::PerformCalculationsOnForce(std::shared_ptr < Force<Type> > value)
		{

		}
		template<typename Type>
		void PhysicsCalculator<Type>::init()
		{

		}
		template<typename Type>
		void PhysicsCalculator<Type>::DoCalculations()
		{

		}


		/*template<typename ConstantForce, typename Type>
		void Aurora::Physics::PhysicsCalculator<Type>::AddConstantForceToCalculator(ConstantForce &&constantForce)
		{
			this->constantForces.push_back(std::forward<VECTOR2D<Type>>(constantForce));
		}*/

		template<typename Type>
		std::shared_ptr<PhysicsCalculator<Type>> PhysicsCalculator<Type>::GetInstance()
		{
			if (instance == nullptr)
			{
				instance = std::make_shared<PhysicsCalculator<Type>>();
			}
			/**/
			return instance;
		}

		template<typename Type>
		void PhysicsCalculator<Type>::CreateInstanceOfPhysicsCalculatorOption(PhysicsCalculationMode calculationMode)
		{
			//this->_callbacks.emplace(name, std::make_shared<Callback>());
			std::string enumName = "";
			switch (calculationMode)
			{
			case Aurora::Physics::PhysicsCalculationMode::Base:
				this->physicsCalculatorInstances.emplace(calculationMode, std::make_shared<PhysicsCalculator<Type>>());
				enumName = "Base";
				break;
			case Aurora::Physics::PhysicsCalculationMode::Normal:
				this->physicsCalculatorInstances.emplace(calculationMode, std::make_shared<NormalPhysicsCalculator<Type>>());
				enumName = "Normal";
				break;
			default:
				if (this->physicsCalculatorInstances.find(calculationMode) != this->physicsCalculatorInstances.end()) {
					//CCLOG("The Physics calculator instance already exists: %s", enumName);
				} 
				break;
			}
		}

		template<typename Type>
		std::shared_ptr<PhysicsCalculator<Type>> PhysicsCalculator<Type>::GetPhysicsCalculatorOption(PhysicsCalculationMode calculationMode)
		{
			std::shared_ptr<PhysicsCalculator<Type>> calculator = nullptr;
			
			if (this->physicsCalculatorInstances.find(calculationMode) == this->physicsCalculatorInstances.end())
			{
				this->CreateInstanceOfPhysicsCalculatorOption(calculationMode);	
			}
			
			return this->physicsCalculatorInstances.at(calculationMode);
		}

		template<typename Type>
		void NormalPhysicsCalculator<Type>::PerformCalculationsOnForce(std::shared_ptr < Force<Type> > value)
		{
			PhysicsCalculator::PerformCalculationsOnForce(value);
			VECTOR2D<Type> gravityForce = CommonCalculations::NormalEarthGravityCalculations(PhysicsConstants::EarthGravity, value->Mass());
			VECTOR2D<Type> frictionForce = FrictionCalculations::NormalFrictionCalculations(value->Velocity(), PhysicsConstants::NormalSurfaceFrictionCoefficient, value->Normal());
			/*VECTOR2D gravityForce = cc->Calculations->call(PhysicsConstants::Callbacks_NormalEarthGravityCalculations_FunctionName, VECTOR2D::GetZeroVector(), PhysicsConstants::EarthGravity, this->moverPhysic->Mass());
			VECTOR2D friction = VECTOR2D::GetZeroVector();
			VECTOR2D gravityForce2 = cc->Calculations->call(PhysicsConstants::Callbacks_NormalEarthGravityCalculations_FunctionName, VECTOR2D::GetZeroVector(), friction, this->moverPhysic->Mass());*/
			//VECTOR2D gravityForce2 = cc->Calculations->call(PhysicsConstants::Callbacks_NormalEarthGravityCalculations_FunctionName, PhysicsConstants::EarthGravity, this->moverPhysic->Mass());

			// TO BE REMOVED TEST PURPOSES: Adds gravity simulation, NOTICE the mass multiplication to simulate gravity
			value->ApplyForce(frictionForce);
			value->ApplyForce(VECTOR2D<Type>(0.01f, 0));
			value->ApplyForce(gravityForce);
		}

		template<typename Type>
		void NormalPhysicsCalculator<Type>::init()
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		template<typename Type>
		void NormalPhysicsCalculator<Type>::DoCalculations()
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

	};
};