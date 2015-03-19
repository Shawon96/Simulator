#ifndef NatureOfCodeCocos2DX_Liquid_h
#define NatureOfCodeCocos2DX_Liquid_h



#include "IPhysicsRepresentationBase.h"
#include "IPhysicsForceRepresentationBase.h"

using namespace Aurora::Math;

namespace Aurora {
	namespace Physics {
		template<typename Type>
		class Liquid : public IPhysicsRepresentationBase<Type>
		{
			protected:
				virtual void init() override;
				float coefficientDrag;
				UniqueVector2DDynamicTypeVector<Type> liquidArea;
				


		public:
			Liquid() = default;
			virtual ~Liquid() = default;

			Liquid(float coefficientDrag);

			
			bool IsInside(const Vector2D<Type> &value);

			float CoefficientDrag() const { return coefficientDrag; }
			template<typename T>
			void CoefficientDrag(T &&value) { coefficientDrag = std::forward<T>(value); }
			
			UniqueVector2DDynamicTypeVector<Type> LiquidArea() const { return liquidArea; }
			
			void AddEdgePoint(const Vector2D<Type> &value);

		};
		
		class ILiquid
		{
		public:
			ILiquid() = default;
			virtual ~ILiquid() = default;

			virtual void Render() = 0;



			//virtual void SetMoverTarget(const VECTOR2D &target);
		};
	};
};

#endif