#include "Oscillator.h"

namespace Aurora {
	namespace Random {
		template<typename Type>
		void Aurora::Random::Oscillator<Type>::DoCalculations()
		{
			this->Oscillate();
			this->ImplementorObjectPhysics()->Position(VECTOR2D(this->StartPosition().X + (sin(this->angle.X) * this->amplitude.X), this->StartPosition().Y + cos(this->angle.Y) * this->amplitude.Y));
		}
		template<typename Type>
		Aurora::Random::Oscillator<Type>::Oscillator() : RandomBaseComplete()
		{
			this->init();
		}
		template<typename Type>
		Aurora::Random::Oscillator<Type>::Oscillator(const Oscillator &value) : RandomBaseComplete(value), angle(value.angle), amplitude(value.amplitude), velocity(value.velocity)
		{
			this->ImplementorObjectPhysics(value.ImplementorObjectPhysics());
		}
		template<typename Type>
		Aurora::Random::Oscillator<Type>::Oscillator(Oscillator &&value) : RandomBaseComplete(std::move(value)), angle(std::move(value.angle)), amplitude(std::move(value.amplitude)), velocity(std::move(value.velocity))
		{
			this->ImplementorObjectPhysics(std::move(value.ImplementorObjectPhysics()));
		}
		template<typename Type>
		Aurora::Random::Oscillator<Type>::~Oscillator()
		{
			RandomBaseComplete::~RandomBaseComplete();
			IPhysicsImplementor::~IPhysicsImplementor();
		}
		template<typename Type>
		Oscillator<Type> & Aurora::Random::Oscillator<Type>::operator=(Oscillator && value)
		{
			if (this == &value)
				return *this;

			this->init(std::move(value));

			return *this;
		}
		template<typename Type>
		Oscillator<Type>& Aurora::Random::Oscillator<Type>::operator=(const Oscillator& value)
		{
			if (this == &value)
				return *this;

			this->init(value);

			return *this;
		}
		template<typename Type>
		void Aurora::Random::IOscillatorImplementor<Type>::Render()
		{

		}
		template<typename Type>
		std::shared_ptr<Aurora::Physics::Force<Type>> Aurora::Random::IOscillatorImplementor<Type>::AccessObjectPhysics() const
		{
			return nullptr;
		}
		template<typename Type>
		void Oscillator<Type>::init()
		{
			this->angle = VECTOR2D::GetZeroVector();
			this->velocity = VECTOR2D(RandomNumberGenerator::GetRandomFloat(-0.05, 0.05), RandomNumberGenerator::GetRandomFloat(-0.05, 0.05));
			this->amplitude = VECTOR2D(RandomNumberGenerator::GetRandomFloat(this->GetConstrainsRange().Width / 2), RandomNumberGenerator::GetRandomFloat(this->GetConstrainsRange().Height / 2));
		}
		template<typename Type>
		void Oscillator<Type>::init(const Oscillator & value)
		{
			this->angle = value.angle;
			this->amplitude = value.amplitude;
			this->velocity = value.velocity;
			this->ImplementorObjectPhysics(value.ImplementorObjectPhysics());
		}
		template<typename Type>
		void Oscillator<Type>::init(Oscillator && value)
		{
			this->angle = std::move(value.angle);
			this->amplitude = std::move(value.amplitude);
			this->velocity = std::move(value.velocity);
			this->ImplementorObjectPhysics(std::move(value.ImplementorObjectPhysics()));
		}
		template<typename Type>
		void Oscillator<Type>::Oscillate()
		{
			this->angle += velocity;
		}
		template<typename Type>
		Oscillator<Type>::Oscillator(const mRECT &areaSize) : RandomBaseComplete()
		{
			this->SetConstrainsRange(areaSize);
			this->init();
		}

		

	}
}


