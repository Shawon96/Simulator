#include "IPhysicsRepresentationBase.h"

namespace Aurora {
	namespace Physics {


		

		template<typename Type>
		IPhysicsRepresentationBase<Type>::IPhysicsRepresentationBase() : IPhysicsBase()
		{
			this->init();
		}
		template<typename Type>
		IPhysicsRepresentationBase<Type>::IPhysicsRepresentationBase(const IPhysicsRepresentationBase &value) : IPhysicsBase()
		{
			this->objectPhysics = value.objectPhysics;
		}
		template<typename Type>
		IPhysicsRepresentationBase<Type>::IPhysicsRepresentationBase(IPhysicsRepresentationBase &&value) : IPhysicsBase(), objectPhysics(std::move(value.objectPhysics))
		{
			value.objectPhysics = nullptr;
		}
		template<typename Type>
		IPhysicsRepresentationBase<Type>::~IPhysicsRepresentationBase()
		{
			IPhysicsBase::~IPhysicsBase();
		}
		template<typename Type>
		IPhysicsRepresentationBase<Type> & IPhysicsRepresentationBase<Type>::operator=(IPhysicsRepresentationBase && value)
		{
			if (this == &value)
				return *this;

			this->objectPhysics = std::move(value.objectPhysics);

			value.objectPhysics = nullptr;

			return *this;
		}
		template<typename Type>
		IPhysicsRepresentationBase<Type>& IPhysicsRepresentationBase<Type>::operator=(const IPhysicsRepresentationBase& value)
		{
			if (this == &value) { return(*this); }

			this->objectPhysics = value.objectPhysics;

			return *this;
		}


	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora