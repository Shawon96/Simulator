#ifndef NatureOfCodeCocos2DX_ForceBase_h
#define NatureOfCodeCocos2DX_ForceBase_h



#include "..\..\Math\MathOperations.h"

using namespace Aurora::Math;

namespace Aurora {
	namespace Physics {

		template<typename Type>
		class IPhysicsBase 
		{
		protected:
			mRECT<Type> areaSize;

			
			
		public:
			IPhysicsBase() = default;
			virtual ~IPhysicsBase() = default;
			virtual void init() = 0;
			
			Aurora::Math::mRECT AreaSize() const { return areaSize; }
			void AreaSize(const mRECT<Type> &value) { areaSize = value; }
			void AreaSize(mRECT<Type> &&value) { areaSize = std::move(value); }

		};

	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora


#endif