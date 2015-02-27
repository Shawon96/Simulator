#include "IPhysicsForceRepresentationBase.h"

namespace Aurora {
	namespace Physics {

		template<typename Type>
		Aurora::Physics::IPhysicsForceRepresentationBase<Type>::IPhysicsForceRepresentationBase()
		{
			this->init();
		}

		template<typename Type>
		Aurora::Physics::IPhysicsForceRepresentationBase<Type>::IPhysicsForceRepresentationBase(const IPhysicsForceRepresentationBase &value) : objectPhysics(value.objectPhysics)
		{
			this->init();
		}
		template<typename Type>
		Aurora::Physics::IPhysicsForceRepresentationBase<Type>::IPhysicsForceRepresentationBase(IPhysicsForceRepresentationBase &&value) : objectPhysics(std::move(value.objectPhysics))
		{
			value.objectPhysics = nullptr;
		}
		template<typename Type>
		Aurora::Physics::IPhysicsForceRepresentationBase<Type>::~IPhysicsForceRepresentationBase()
		{

		}
		template<typename Type>
		IPhysicsForceRepresentationBase<Type> &Aurora::Physics::IPhysicsForceRepresentationBase<Type>::operator=(IPhysicsForceRepresentationBase && value)
		{
			if (this == &value)
				return *this;

			this->objectPhysics = std::move(value.objectPhysics);

			value.objectPhysics = nullptr;

			return *this;
		}
		template<typename Type>
		void Aurora::Physics::IPhysicsForceRepresentationBase<Type>::init()
		{
			this->objectPhysics = std::make_shared<Physics::Force<Type>>();
		}
		template<typename Type>
		IPhysicsForceRepresentationBase<Type>& IPhysicsForceRepresentationBase<Type>::operator=(const IPhysicsForceRepresentationBase& value)
		{
			if (this == &value) { return(*this); }
			this->init(value);

			return *this;
		}
		template<typename Type>
		void IPhysicsForceRepresentationBase<Type>::init(const IPhysicsForceRepresentationBase &value)
		{
			this->objectPhysics = value.objectPhysics;
		}

	}
}
