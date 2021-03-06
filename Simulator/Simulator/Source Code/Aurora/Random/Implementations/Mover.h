#ifndef NatureOfCodeCocos2DX_Mover_h
#define NatureOfCodeCocos2DX_Mover_h

#include "..\BaseClasses\ObjectBase.h"
#include "..\..\Physics\PhysicsOperations.h"

using namespace Aurora::Physics;

namespace Aurora {
	namespace Random {
		using namespace Aurora::Math;
		using namespace Aurora::Math::DataTypes;
		using namespace Aurora::Physics;
		class Mover : public RandomBaseComplete, public IPhysicsImplementor<float>
		{

		private:
			/*mutable VECTOR2D position;
			mutable VECTOR2D velocity;
			mutable VECTOR2D acceleration;*/
			//std::shared_ptr<Physics::Force> objectPhysics;
			

			mutable Vector2D<float> target;
			mutable Vector3DFloat perlinNoiseTime_PositionX;
			mutable Vector3DFloat perlinNoiseTime_PositionY;

			/*Float maximiunVelocity;
			Float minimumVelocity;*/
			
			Float probalitityFactor;

			void MoveTowardsTarget();
			
			void Constrain() final;

			void UniformCalculations() final;

			void GaussianCalculations() final;

			void PerlinNoiseCalculations() final;

			void NormalCalculations();

			virtual void init() override;
			virtual void init(const Mover &value);
			virtual void init(const Mover &&value);
			//virtual void init(const VECTOR2D &position, const VECTOR2D &velocity, const VECTOR2D &acceleration, const mRECT &areaSize, const float &mass);

		public:
			Mover();
			Mover(const mRECT<float> &areaSize);
			Mover(const Mover &value);
			Mover& operator=(const Mover& value);
			//Mover(const VECTOR2D &position, const VECTOR2D &velocity, const mRECT &areaSize);
			//Mover(const VECTOR2D &position, const VECTOR2D &velocity, const VECTOR2D &acceleration, const mRECT &areaSize, const float &mass);
			~Mover();
			Mover(Mover &&value);
			Mover & operator=(Mover && value);
			void DoCalculations() override;

			void SetTarget(const Vector2D<float> &target);
			//void SetPosition(const VECTOR2D &position);
			void SetVelocityRange(const Float moverMaximumVelocity, const Float moverMinimumVelocity);
			const Vector2D<float> GetCurentPosition() const;
			const Vector2D<float> GetCurentTarget() const;

			const float GetMoverMass() const;

			
			void Accelerate();
			void Decellerate();

			bool MoveAutomatically = true;
		};

		class IMoverImplementor : public IObjectBaseBasic, public IPhysicsAccessPoint<float>
		{
		public:
			IMoverImplementor() = default;
			virtual ~IMoverImplementor() = default;
			virtual void Render() override;

			//virtual void SetMoverTarget(const VECTOR2D &target);

			virtual void MoveMover();

			virtual void SetMoverRandomNumberMode(RandomNumberMode randomNumberMode);

			virtual std::shared_ptr < Force<float> > AccessObjectPhysics() const override;

		};


		

	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora


#endif