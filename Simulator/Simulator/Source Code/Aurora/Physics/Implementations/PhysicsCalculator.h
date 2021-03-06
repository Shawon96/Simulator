#ifndef NatureOfCodeCocos2DX_BasePhysicsCalculator_h
#define NatureOfCodeCocos2DX_BasePhysicsCalculator_h


#include "../Common/FrictionCalculations.h"
#include "Force.h"

using namespace Aurora::Math;

namespace Aurora {
	namespace Physics {
		// Use Singleton?;Factory + Builder?
		template<typename Type>
		class PhysicsCalculator : public ICalculationsBase
		{
			protected:
				static std::shared_ptr<PhysicsCalculator<Type>> instance;
			virtual void init() override;
			UniqueVector2DDynamicTypeVector<Type> constantForces;
			std::map<PhysicsCalculationMode, std::shared_ptr<PhysicsCalculator<Type>>> physicsCalculatorInstances;
			
		public:
			PhysicsCalculator() = default;
			virtual ~PhysicsCalculator() = default;

			/*template<typename ConstantForce>
			void AddConstantForceToCalculator(ConstantForce &&constantForce);*/
			
			virtual void PerformCalculationsOnForce(std::shared_ptr < Force<Type> > value);

			

			virtual void DoCalculations() override;

			static std::shared_ptr<PhysicsCalculator<Type>> GetInstance();

			std::shared_ptr<PhysicsCalculator> GetPhysicsCalculatorOption(PhysicsCalculationMode calculationMode);
			void CreateInstanceOfPhysicsCalculatorOption(PhysicsCalculationMode calculationMode);
		};
		template<typename Type>
		class NormalPhysicsCalculator : public PhysicsCalculator<Type>
		{
		private:
			virtual void init() override;
		public:

			NormalPhysicsCalculator() = default;
			virtual ~NormalPhysicsCalculator() = default;

			virtual void PerformCalculationsOnForce(std::shared_ptr < Force<Type> > value) override;

			

			virtual void DoCalculations() override;

		};
	};
};

#endif