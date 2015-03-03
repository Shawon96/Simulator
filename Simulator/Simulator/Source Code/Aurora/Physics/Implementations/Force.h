#ifndef NatureOfCodeCocos2DX_Force_h
#define NatureOfCodeCocos2DX_Force_h


#include "../BaseClasses/PhysicsBase.h"

using namespace Aurora::Math;

namespace Aurora {
	namespace Physics {
		
		template<typename Type>
		class Force : public IPhysicsBase<Type>
		{
		protected:

			Vector2D<Type> velocity;
			
			Vector2D<Type> acceleration;

			Vector2D<Type> friction;
			
			Type frictionCoefficient;
			
			Type maximiunVelocity;

			Type normal;

			Type angularVelocity;
			

			Type angularAcceleration;
			
			Type angle;

			Type minimumAngularVelocity;
			
			Type maximumAngularVelocity;

			void ConstrainToAreaSize();

			void CalculateFriction();

			

		public:

#pragma region Initializations and Constructs
			Force();
			virtual ~Force();
			Force(const Force &value);
			Force& operator=(const Force& value);
			Force(Force &&value);
			Force & operator=(Force && value);

			virtual void init() override;
			virtual void init(const Force &value);
			virtual void init(Force &&value);
#pragma endregion Initializations and Constructs

#pragma region Encapsulated Properties

			Aurora::Math::Vector2D<Type> Velocity() const { return velocity; }
			template<typename T>
			void Velocity(T &&value) { velocity = std::forward<T>(value); }

			Aurora::Math::Vector2D<Type> Acceleration() const { return acceleration; }
			template<typename T>
			void Acceleration(T &&value) { acceleration = std::forward<T>(value); }
			
			Aurora::Math::Vector2D<Type> Friction() const { return friction; }
			template<typename T>
			void Friction(T &&value) { friction = std::forward<T>(value); }

			
			Type FrictionCoefficient() const { return frictionCoefficient; }
			template<typename T>
			void FrictionCoefficient(T &&value) { frictionCoefficient = std::forward<T>(value); }

			
			Type MaximiunVelocity() const { return maximiunVelocity; }
			template<typename T>
			void MaximiunVelocity(T &&value) { maximiunVelocity = std::forward<T>(value); }
			
			Type Normal() const { return normal; }
			template<typename T>
			void Normal(T &&value) { normal = std::forward<T>(value); }

			Type AngularVelocity() const { return angularVelocity; }
			template<typename T>
			void AngularVelocity(T &&value) { angularVelocity = std::forward<T>(value); }

			Type AngularAcceleration() const { return angularAcceleration; }
			template<typename T>
			void AngularAcceleration(T &&value) { angularAcceleration = std::forward<T>(value); }

			Type Angle() const { return angle; }
			template<typename T>
			void Angle(T &&value) { angle = std::forward<T>(value); }

			Type MinimumAngularVelocity() const {
				return minimumAngularVelocity;
			}
			template<typename T>
			void MinimumAngularVelocity(T &&value) { minimumAngularVelocity = std::forward<T>(value); }

			Type MaximumAngularVelocity() const {
				return maximumAngularVelocity;
			}
			template<typename T>
			void MaximumAngularVelocity(T &&value) { maximumAngularVelocity = std::forward<T>(value); }


			
#pragma endregion Encapsulated Properties

			void ApplyForce(const Vector2D<Type> &value);
			
			void Update();

			void UpdateAngular();
			
			
			
		};


		template<typename Type>
		void Force<Type>::init()
		{
			this->acceleration = Vector2D<Type>::GetZero();
			this->maximiunVelocity = 2;
			this->mass = 10;
			this->position = Vector2D<Type>::GetZero();
			this->velocity = Vector2D<Type>::GetZero();
			this->normal = 1;
			this->frictionCoefficient = 0.01f;
			this->angle = 0;
			this->angularVelocity = 0;
			this->angularAcceleration = 0;
			this->minimumAngularVelocity = -0.5f;
			this->maximumAngularVelocity = 0.5f;
		}
		template<typename Type>
		void Force<Type>::init(const Force &value)
		{
			this->acceleration = value.acceleration;
			this->maximiunVelocity = value.maximiunVelocity;
			this->position = value.position;
			this->velocity = value.velocity;
			this->mass = value.mass;
			this->normal = value.normal;
			this->friction = value.friction;
			this->frictionCoefficient = value.frictionCoefficient;
			this->angle = value.angle;
			this->angularAcceleration = value.angularAcceleration;
			this->angularVelocity = value.angularVelocity;
			this->minimumAngularVelocity = value.minimumAngularVelocity;
			this->maximumAngularVelocity = value.maximumAngularVelocity;
		}
		template<typename Type>
		void Force<Type>::init(Force &&value)
		{
			this->acceleration = std::move(value.acceleration);
			this->maximiunVelocity = std::move(value.maximiunVelocity);
			this->position = std::move(value.position);
			this->velocity = std::move(value.velocity);
			this->mass = std::move(value.mass);
			this->normal = std::move(value.normal);
			this->friction = std::move(value.friction);
			this->frictionCoefficient = std::move(value.frictionCoefficient);
			this->angle = std::move(value.angle);
			this->angularAcceleration = std::move(value.angularAcceleration);
			this->angularVelocity = std::move(value.angularVelocity);
			this->minimumAngularVelocity = std::move(value.minimumAngularVelocity);
			this->maximumAngularVelocity = std::move(value.maximumAngularVelocity);
		}
		template<typename Type>
		Force<Type>::Force()
		{
			this->init();
		}
		template<typename Type>
		Force<Type>::Force(const Force &value) : IPhysicsBase(value)
		{
			this->init(value);
		}
		template<typename Type>
		Force<Type>::Force(Force &&value) : IPhysicsBase(std::move(value))
		{
			this->init(std::move(value));
		}
		template<typename Type>
		Force<Type>::~Force()
		{
			IPhysicsBase::~IPhysicsBase();
		}
		template<typename Type>
		Force<Type>& Force<Type>::operator=(const Force& value)
		{
			this->init(value);
			return(*this);
		}
		template<typename Type>
		Force<Type> &Force<Type>::operator=(Force && value)
		{
			this->init(std::move(value));
			return(*this);
		}
		template<typename Type>
		void Force<Type>::ApplyForce(const Vector2D<Type> &value)
		{
			this->acceleration += (value / this->mass);
			//this->acceleration += value;
		}
		template<typename Type>
		void Force<Type>::Update()
		{
			//this->ApplyForce(this->callbacks->call(PhysicsConstants::Callbacks_FrictionCalculations_FunctionName, ))
			this->velocity += this->acceleration;
			this->velocity.Limit(maximiunVelocity);
			this->position += velocity;
			this->acceleration = Vector2D<Type>::GetZero();

			this->ConstrainToAreaSize();
		}
		template<typename Type>
		void Force<Type>::ConstrainToAreaSize()
		{
			if (position.X > this->areaSize.Width) {
				position.X = this->areaSize.Width;
				velocity.X *= -1;
			}
			else if (position.X < 0) {
				velocity.X *= -1;
				position.X = 0;
			}

			if (position.Y > this->areaSize.Height) {
				velocity.Y *= -1;
				position.Y = this->areaSize.Height;
			}
			else if (position.Y < 0) {
				velocity.Y *= -1;
				position.Y = 0;
			}
		}
		template<typename Type>
		void Force<Type>::UpdateAngular()
		{
			this->angularVelocity += angularAcceleration;
			this->angularVelocity += velocity.Heading();

			if (this->angularVelocity < this->minimumAngularVelocity)
				this->angularVelocity = this->minimumAngularVelocity;

			if (this->angularVelocity > this->maximumAngularVelocity)
				this->angularVelocity = this->maximumAngularVelocity;

			if (this->angularVelocity > 360)
				this->angularVelocity = 360;

			if (this->angularVelocity < -360)
				this->angularVelocity = -360;



			this->angle += angularVelocity;
		}

		/*template<typename Type>
		using std::shared_ptr < Force<Type> > = std::shared_ptr < Force<Type> >;*/

	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora


#endif