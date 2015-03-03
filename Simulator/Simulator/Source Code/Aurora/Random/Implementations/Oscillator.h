#ifndef NatureOfCodeCocos2DX_Oscillator_h
#define NatureOfCodeCocos2DX_Oscillator_h

#include "..\BaseClasses\ObjectBase.h"
#include "..\..\Math\MathOperations.h"
#include "..\..\Physics\PhysicsOperations.h"
#include <type_traits>


using namespace Aurora::Math;
using namespace Aurora::Physics;

namespace Aurora {
	namespace Random {
		class Oscillator : public RandomBaseComplete, public IPhysicsImplementor<float>
		{
			private:
				Vector2D<float> angle;
				Vector2D<float> velocity;
				Vector2D<float> amplitude;
				Vector2D<float> startPosition;
				
				void init(const Oscillator & value);
				void init(Oscillator && value);

				virtual void init() override;
				
			public:
				Oscillator();
				virtual ~Oscillator();
				Oscillator(const Oscillator &value);
				Oscillator(Oscillator &&value);
				Oscillator &operator=(Oscillator && value);
				Oscillator& operator=(const Oscillator& value);
				Oscillator(const mRECT<float> &areaSize);


				Aurora::Math::Vector2D<float> Angle() const {
					return angle;
				}
				template<typename T>
				void Angle(T &&value) { angle = std::forward<T>(value); }

				Aurora::Math::Vector2D<float> Velocity() const {
					return velocity;
				}

				template<typename T>
				void Velocity(T &&value) { velocity = std::forward<T>(value); }

				Aurora::Math::Vector2D<float> Amplitude() const {
					return amplitude;
				}

				template<typename T>
				void Amplitude(T &&value) { amplitude = std::forward<T>(value); }

				virtual void DoCalculations() override;

				void Oscillate();

				Aurora::Math::Vector2D<float> StartPosition() const {
					return startPosition;
				}
				template<typename T>
				void StartPosition(T &&value) {
					//static_assert(!is_same<objectPhysics, T>::value, Aurora::Errors::ErrorMessages::TypeMismatch.c_str());

					startPosition = std::forward<T>(value);
				}

				

		};
		
		
		class IOscillatorImplementor : public IObjectBaseBasic, public IPhysicsAccessPoint<float>
		{
			public:
				IOscillatorImplementor() = default;
				virtual ~IOscillatorImplementor() = default;

				virtual void Render() override;

				virtual std::shared_ptr < Force<float> > AccessObjectPhysics() const override;

		};

	};
}
#endif