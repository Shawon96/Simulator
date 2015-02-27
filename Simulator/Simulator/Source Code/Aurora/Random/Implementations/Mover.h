#ifndef NatureOfCodeCocos2DX_Mover_h
#define NatureOfCodeCocos2DX_Mover_h

#include "..\BaseClasses\ObjectBase.h"
#include "..\..\Physics\PhysicsOperations.h"

using namespace Aurora::Physics;

namespace Aurora {
	namespace Random {

		template<typename Type>
		class Mover : public RandomBaseComplete, public IPhysicsImplementor<Type>
		{

		private:
			/*mutable VECTOR2D position;
			mutable VECTOR2D velocity;
			mutable VECTOR2D acceleration;*/
			//std::shared_ptr<Physics::Force> objectPhysics;
			

			mutable VECTOR2D<Type> target;
			mutable VECTOR3D perlinNoiseTime_PositionX;
			mutable VECTOR3D perlinNoiseTime_PositionY;

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
			Mover(const mRECT &areaSize);
			Mover(const Mover &value);
			Mover& operator=(const Mover& value);
			//Mover(const VECTOR2D &position, const VECTOR2D &velocity, const mRECT &areaSize);
			//Mover(const VECTOR2D &position, const VECTOR2D &velocity, const VECTOR2D &acceleration, const mRECT &areaSize, const float &mass);
			~Mover();
			Mover(Mover &&value);
			Mover & operator=(Mover && value);
			void DoCalculations() override;

			void SetTarget(const VECTOR2D<Type> &target);
			//void SetPosition(const VECTOR2D &position);
			void SetVelocityRange(const Float moverMaximumVelocity, const Float moverMinimumVelocity);
			const VECTOR2D<Type> GetCurentPosition() const;
			const VECTOR2D<Type> GetCurentTarget() const;

			const float GetMoverMass() const;

			
			void Accelerate();
			void Decellerate();

			bool MoveAutomatically = true;
		};

		template<typename Type>
		class IMoverImplementor : public IObjectBaseBasic, public IPhysicsAccessPoint<Type>
		{
		public:
			IMoverImplementor() = default;
			virtual ~IMoverImplementor() = default;
			virtual void Render() override;

			//virtual void SetMoverTarget(const VECTOR2D &target);

			virtual void MoveMover();

			virtual void SetMoverRandomNumberMode(RandomNumberMode randomNumberMode);

			virtual std::shared_ptr < Force<Type> > AccessObjectPhysics() const override;

		};


		template<typename Type>
		void Mover<Type>::Accelerate()
		{
			this->ImplementorObjectPhysics()->Update();
			this->ImplementorObjectPhysics()->UpdateAngular();
			//VECTOR2D emptyVector;
			/*if (this->target != emptyVector)
			{
			MoveTowardsTarget();
			}*/
			/*this->velocity += this->acceleration;
			this->velocity.Limit(this->maximiunVelocity);
			this->position += this->velocity;*/
		}

		template<typename Type>
		void Mover<Type>::Decellerate()
		{
			this->ImplementorObjectPhysics()->Update();
			this->ImplementorObjectPhysics()->UpdateAngular();
			/*VECTOR2D emptyVector;
			if (this->target != emptyVector)
			{
			MoveTowardsTarget();
			}*/
			/*this->velocity -= this->acceleration;
			this->velocity.Limit(this->maximiunVelocity);
			this->position -= this->velocity;*/
		}

		template<typename Type>
		void Mover<Type>::SetTarget(const VECTOR2D<Type> &target)
		{
			this->target = target;
		}

		template<typename Type>
		const VECTOR2D<Type> Mover<Type>::GetCurentPosition() const
		{
			return(this->ImplementorObjectPhysics()->Position());
		}

		template<typename Type>
		const VECTOR2D<Type>  Mover<Type>::GetCurentTarget() const
		{
			return(this->target);
		}

		template<typename Type>
		void Mover<Type>::Constrain()
		{
			if (this->ImplementorObjectPhysics()->Position().X > this->GetConstrainsRange().Width) {
				this->ImplementorObjectPhysics()->Position(VECTOR2D<double>(0, this->ImplementorObjectPhysics()->Position().Y));
			}
			else if (this->ImplementorObjectPhysics()->Position().X < 0) {
				this->ImplementorObjectPhysics()->Position(VECTOR2D<double>(this->GetConstrainsRange().Width, this->ImplementorObjectPhysics()->Position().Y));
			}

			if (this->ImplementorObjectPhysics()->Position().Y > this->GetConstrainsRange().Height) {
				this->ImplementorObjectPhysics()->Position(VECTOR2D<double>(this->ImplementorObjectPhysics()->Position().X, 0));
			}
			else if (this->ImplementorObjectPhysics()->Position().Y < 0) {
				this->ImplementorObjectPhysics()->Position(VECTOR2D<double>(this->ImplementorObjectPhysics()->Position().X, this->GetConstrainsRange().Height));
			}
		}

		template<typename Type>
		void Mover<Type>::MoveTowardsTarget()
		{
			Float choice = RandomNumberGenerator::GetRandomPositiveFloat(0, 1);
			VECTOR2D<double> distanceBetweenTargetAndPosition = this->target - this->ImplementorObjectPhysics()->Position();
			VECTOR2D<double> normalizedDistancetweenTargetAndPosition = distanceBetweenTargetAndPosition;
			normalizedDistancetweenTargetAndPosition.Normalize();

			if (choice < this->probalitityFactor)
			{
				/*auto xdir = (this->target.X - this->position.X);
				auto ydir = (this->target.Y - this->position.Y);

				if (xdir != 0)
				{
				xdir /= abs(xdir);
				}

				if (ydir != 0)
				{
				ydir /= abs(ydir);
				}*/
				/*this->acceleration.X += xdir;
				this->acceleration.Y += ydir;*/

				this->ImplementorObjectPhysics()->ApplyForce(normalizedDistancetweenTargetAndPosition * 0.5f);
				//CCLOG("Mover target - Address: %X", this);
				//CCLOG("Mover target - position Magnitude: %f", distanceBetweenTargetAndPosition.Magnitude());
				//CCLOG("Mover target location X: %f Y: %f", this->target.X, this->target.Y);
				//CCLOG("Mover position location X: %f Y: %f", this->ImplementorObjectPhysics()->Position().X, this->ImplementorObjectPhysics()->Position().Y);
				//CCLOG("Mover distanceBetweenTargetAndPosition location X: %f Y: %f", distanceBetweenTargetAndPosition.X, distanceBetweenTargetAndPosition.Y);
				// Notice that if a targe is specified the mover must move towards that target untill it has reached it then only we can null the target and allow the mover to go on randomly
				if (this->MoveAutomatically && (distanceBetweenTargetAndPosition.Magnitude() <= 10))
				{
					this->target = VECTOR2D<double>::GetZeroVector();
					//CCLOG("Mover towards target has been reached. Automatic movement stopped!");
				}


			}
			else
			{
				this->ImplementorObjectPhysics()->Acceleration(VECTOR2D<double>(RandomNumberGenerator::GetRandomFloat(2), RandomNumberGenerator::GetRandomFloat(2)));
			}

			if (!this->MoveAutomatically)
				this->target = VECTOR2D<double>::GetZeroVector();

		}

		template<typename Type>
		void Mover<Type>::DoCalculations()
		{
			RandomBaseComplete::DoCalculations();
			VECTOR2D<double> emptyVector;
			if (this->target != emptyVector)
			{
				MoveTowardsTarget();
			}
			// TO BE REMOVED TEST PURPOSES: Adds wind simulation

			//std::shared_ptr<CommonCalculations> cc = CommonCalculations::GetInstance();
			/*PhysicsCalculatorAlias physicsCalculator = PhysicsCalculator::GetInstance()->GetPhysicsCalculatorOption(PhysicsCalculationMode::Normal);
			physicsCalculator->PerformCalculationsOnForce(this->objectPhysics);*/
		}

		template<typename Type>
		void Mover<Type>::UniformCalculations()
		{
			RandomBaseComplete::UniformCalculations();
		}

		template<typename Type>
		void Mover<Type>::GaussianCalculations()
		{
			RandomBaseComplete::GaussianCalculations();
		}

		template<typename Type>
		void Mover<Type>::PerlinNoiseCalculations()
		{
			RandomBaseComplete::PerlinNoiseCalculations();
			auto tempX = this->perlinNoiseCalculator->GetValue(this->perlinNoiseTime_PositionX.X, this->perlinNoiseTime_PositionX.Y, this->perlinNoiseTime_PositionX.Z);
			auto tempY = this->perlinNoiseCalculator->GetValue(this->perlinNoiseTime_PositionY.X, this->perlinNoiseTime_PositionY.Y, this->perlinNoiseTime_PositionY.Z);

			/*if (tempX < 0)
			{
			tempX *= -1;
			}

			if (tempY < 0)
			{
			tempY *= -1;
			}*/

			this->perlinNoiseTime_PositionX += 0.1f;
			this->perlinNoiseTime_PositionY += 0.1f;


			//this->objectPhysics->Acceleration(VECTOR2D(tempX, tempY));
			////this->moverPhysic->Acceleration(this->moverPhysic->Acceleration().Normalize());
			//
			//this->objectPhysics->Acceleration().Normalize();
			//auto accelerationMultiple = RandomNumberGenerator::GetRandomPositiveFloat(3);
			//this->objectPhysics->Acceleration(this->objectPhysics->Acceleration() * accelerationMultiple);
		}

		template<typename Type>
		void Mover<Type>::NormalCalculations()
		{
			RandomBaseComplete::NormalCalculations();
		}

		template<typename Type>
		Mover<Type>::Mover(const mRECT &areaSize) : RandomBaseComplete()
		{
			this->SetConstrainsRange(areaSize);
			this->init();
			//this->ImplementorObjectPhysics()->AreaSize(areaSize);
		}

		/*Mover<Type>::Mover(const VECTOR2D &position, const VECTOR2D &velocity, const mRECT &areaSize) : RandomBaseComplete()
		{
		this->init(position, velocity, VECTOR2D::GetZeroVector(), areaSize, 1);
		}*/

		/*Mover<Type>::Mover(const VECTOR2D &position, const VECTOR2D &velocity, const VECTOR2D &acceleration, const mRECT &areaSize, const float &mass) : RandomBaseComplete()
		{
		this->init(position, velocity, acceleration, areaSize, mass);
		}*/

		template<typename Type>
		Mover<Type>::Mover(const Mover &value) : RandomBaseComplete(value)
		{
			this->init(value);
		}

		template<typename Type>
		Mover<Type>::Mover() : RandomBaseComplete()
		{
			this->init();
		}

		template<typename Type>
		Mover<Type>::Mover(Mover &&value) : RandomBaseComplete(std::move(value))
		{
			this->init(std::move(value));
		}

		template<typename Type>
		Mover<Type>::~Mover()
		{
			IRandomBaseComplete::~IRandomBaseComplete();
			IPhysicsImplementor::~IPhysicsImplementor();
		}




		template<typename Type>
		Mover<Type>& Mover<Type>::operator=(const Mover& value)
		{
			if (this == &value) { return(*this); }

			RandomBaseComplete::operator=(value);
			this->init(value);

			return(*this);
		}

		template<typename Type>
		Mover<Type> & Mover<Type>::operator=(Mover && value)
		{
			if (this == &value)
				return *this;

			/*this->position = std::move(value.position);
			this->probalitityFactor = std::move(value.probalitityFactor);

			this->target = std::move(value.target);
			this->velocity = std::move(value.velocity);
			this->acceleration = std::move(value.acceleration);
			this->maximiunVelocity = std::move(value.maximiunVelocity);
			this->minimumVelocity = std::move(value.minimumVelocity);*/
			this->init(std::move(value));
			RandomBaseComplete::operator=(std::move(value));

			return(*this);
		}

		template<typename Type>
		void Mover<Type>::init()
		{
			this->probalitityFactor = 0.9f;
			this->perlinNoiseTime_PositionX = VECTOR3D(0, 0, 0);
			this->perlinNoiseTime_PositionY = VECTOR3D(10000, 10000, 10000);
		}

		template<typename Type>
		void Mover<Type>::init(const Mover &value)
		{
			this->SetConstrainsRange(value.GetConstrainsRange());
			this->ImplementorObjectPhysics()->AreaSize(value.GetConstrainsRange());
			//this->PerlinNoiseCalculator = value.PerlinNoiseCalculator;
			this->ImplementorObjectPhysics(value.ImplementorObjectPhysics());
			this->probalitityFactor = value.probalitityFactor;
			this->SetRandomNumberMode(value.GetRandomNumberMode());
			this->target = value.target;

			this->perlinNoiseTime_PositionX = value.perlinNoiseTime_PositionX;
			this->perlinNoiseTime_PositionY = value.perlinNoiseTime_PositionY;
		}

		template<typename Type>
		void Mover<Type>::init(const Mover &&value)
		{
			this->SetConstrainsRange(value.GetConstrainsRange());
			//this->PerlinNoiseCalculator = value.PerlinNoiseCalculator;
			this->ImplementorObjectPhysics(std::move(value.ImplementorObjectPhysics()));
			this->probalitityFactor = std::move(value.probalitityFactor);
			this->target = std::move(value.target);
			this->perlinNoiseTime_PositionX = std::move(value.perlinNoiseTime_PositionX);
			this->perlinNoiseTime_PositionY = std::move(value.perlinNoiseTime_PositionY);
		}

		/*void Mover<Type>::init(const VECTOR2D &position, const VECTOR2D &velocity, const VECTOR2D &acceleration, const mRECT &areaSize, const float &mass)
		{
		this->init();

		if (!areaSize.IsZero())
		{
		this->SetConstrainsRange(areaSize);
		this->ImplementorObjectPhysics()->AreaSize(areaSize);
		}

		if(!position.IsZero())
		this->ImplementorObjectPhysics()->Position(position);

		if(!velocity.IsZero())
		this->ImplementorObjectPhysics()->Velocity(velocity);

		if(!acceleration.IsZero())
		this->ImplementorObjectPhysics()->Acceleration(acceleration);

		this->ImplementorObjectPhysics()->Mass(mass);
		}*/

		template<typename Type>
		void Mover<Type>::SetVelocityRange(const Float moverMaximumVelocity, const Float moverMinimumVelocity)
		{
			this->ImplementorObjectPhysics()->MaximiunVelocity(moverMaximumVelocity);
		}

		/*void Mover<Type>::SetPosition(const VECTOR2D &position)
		{
		this->ImplementorObjectPhysics()->Position(position);
		}*/

		template<typename Type>
		const float Mover<Type>::GetMoverMass() const
		{
			return(this->ImplementorObjectPhysics()->Mass());
		}

		template<typename Type>
		void IMoverImplementor<Type>::Render()
		{

		}

		template<typename Type>
		void IMoverImplementor<Type>::MoveMover()
		{

		}

		template<typename Type>
		void IMoverImplementor<Type>::SetMoverRandomNumberMode(RandomNumberMode randomNumberMode)
		{

		}

		template<typename Type>
		std::shared_ptr < Force<Type> > IMoverImplementor<Type>::AccessObjectPhysics() const
		{
			return nullptr;
		}

	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora


#endif