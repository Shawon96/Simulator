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
		template<typename Type>
		class Oscillator : public RandomBaseComplete, public IPhysicsImplementor<Type>
		{
			private:
				VECTOR2D<Type> angle;
				VECTOR2D<Type> velocity;
				VECTOR2D<Type> amplitude;
				VECTOR2D<Type> startPosition;
				
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
				Oscillator(const mRECT &areaSize);


				Aurora::Math::VECTOR2D<Type> Angle() const {
					return angle;
				}
				template<typename T>
				void Angle(T &&value) { angle = std::forward<T>(value); }

				Aurora::Math::VECTOR2D<Type> Velocity() const {
					return velocity;
				}

				template<typename T>
				void Velocity(T &&value) { velocity = std::forward<T>(value); }

				Aurora::Math::VECTOR2D<Type> Amplitude() const {
					return amplitude;
				}

				template<typename T>
				void Amplitude(T &&value) { amplitude = std::forward<T>(value); }

				virtual void DoCalculations() override;

				void Oscillate();

				Aurora::Math::VECTOR2D<Type> StartPosition() const {
					return startPosition;
				}
				template<typename T>
				void StartPosition(T &&value) {
					//static_assert(!is_same<objectPhysics, T>::value, Aurora::Errors::ErrorMessages::TypeMismatch.c_str());

					startPosition = std::forward<T>(value);
				}

				

		};
		
		
		template<typename Type>
		class IOscillatorImplementor : public IObjectBaseBasic, public IPhysicsAccessPoint<Type>
		{
			public:
				IOscillatorImplementor() = default;
				virtual ~IOscillatorImplementor() = default;

				virtual void Render() override;

				virtual std::shared_ptr < Force<Type> > AccessObjectPhysics() const override;

		};

	};
}
#endif