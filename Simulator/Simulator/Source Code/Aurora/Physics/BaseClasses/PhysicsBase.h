#ifndef NatureOfCodeCocos2DX_ForceBase_h
#define NatureOfCodeCocos2DX_ForceBase_h



#include "..\..\Math\MathOperations.h"
#include "CalculationsBase.h"

using namespace Aurora::Math;

namespace Aurora {
	namespace Physics {

		template<typename Type>
		class IPhysicsBase 
		{
		protected:
			mRECT<Type> areaSize;
			Vector2D<Type> position;
			Type mass;
			
		public:
			IPhysicsBase() = default;
			virtual ~IPhysicsBase() = default;
			virtual void init() = 0;
			
			Aurora::Math::mRECT<Type> AreaSize() const { return areaSize; }
			template<typename T>
			void AreaSize(T &&value) { areaSize = std::forward<T>(value); }

			Aurora::Math::Vector2D<Type> Position() const { return position; }
			template<typename T>
			void Position(T &&value) { position = std::forward<T>(value); }

			Type Mass() const { return mass; }
			template<typename T>
			void Mass(T &&value) { mass = std::forward<T>(value); }
		};

	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora


#endif