#include "Walker.h"

namespace Aurora {
	namespace Random {

		template<typename Type>
		void Walker<Type>::Constrain()
		{
			RandomBaseComplete::Constrain();
			if(this->position.X < 0)
			{
				this->position.X = 0;
			}
			if(this->position.X > this->GetConstrainsRange().Width)
			{
				this->position.X = this->GetConstrainsRange().Width;
			}
			if(this->position.Y < 0)
			{
				this->position.Y = 0;
			}

			if(this->position.Y > this->GetConstrainsRange().Height)
			{
				this->position.Y = this->GetConstrainsRange().Height;
			}
		}

		template<typename Type>
		void Walker<Type>::UniformCalculations()
		{
			RandomBaseComplete::UniformCalculations();
			VECTOR2D emptyVector;

			if(this->target == emptyVector)
			{
				auto choice = static_cast<int>(RandomNumberGenerator::GetRandomPositiveFloat(0,4));
				auto randomMovementMagnitude = RandomNumberGenerator::GetRandomPositiveFloat(4);
				switch(choice)
				{
				case 0:
				{
						  this->position.X += randomMovementMagnitude;
				} break;
				case 1:
				{
						  this->position.Y += randomMovementMagnitude;
				} break;
				case 2:
				{
						  this->position.X -= randomMovementMagnitude;
				} break;
				case 3:
				{
						  this->position.Y -= randomMovementMagnitude;
				} break;
				default:
				{
						   this->position.X++;
				} break;
				}
			} else
			{
				MoveWalkerTowardsTarget();
			}
		}

		template<typename Type>
		void Walker<Type>::GaussianCalculations()
		{
			RandomBaseComplete::GaussianCalculations();
		}

		template<typename Type>
		void Walker<Type>::PerlinNoiseCalculations()
		{
			RandomBaseComplete::PerlinNoiseCalculations();
			auto tempX = this->perlinNoiseCalculator->GetValue(this->perlinNoiseTime_PositionX.X, this->perlinNoiseTime_PositionX.Y, this->perlinNoiseTime_PositionX.Z);
			auto tempY = this->perlinNoiseCalculator->GetValue(this->perlinNoiseTime_PositionY.X, this->perlinNoiseTime_PositionY.Y, this->perlinNoiseTime_PositionY.Z);

			if(tempX < 0)
			{
				tempX *= -1;
			}

			if(tempY < 0)
			{
				tempY *= -1;
			}
			
			this->position.X = PerlinNoiseTool::Map(tempX, 0, 1, 0, this->GetConstrainsRange().Width);
			this->position.Y = PerlinNoiseTool::Map(tempY, 0, 1, 0, this->GetConstrainsRange().Height);

			this->perlinNoiseTime_PositionX += 0.1f;
			this->perlinNoiseTime_PositionY += 0.1f;

			VECTOR2D emptyVector;

			if(this->target != emptyVector)
			{
				this->MoveWalkerTowardsTarget();
			}
		}

		template<typename Type>
		void Walker<Type>::NormalCalculations()
		{
			RandomBaseComplete::NormalCalculations();
		}

		template<typename Type>
		Walker<Type>::Walker(const mRECT &areaSize) : RandomBaseComplete()
		{
			this->init(areaSize, VECTOR2D::GetZeroVector());
		}

		template<typename Type>
		Walker<Type>::Walker(const mRECT &areaSize, const VECTOR2D<Type> &walkerStartPosition) : RandomBaseComplete(), position(walkerStartPosition)
		{
			this->init(areaSize, walkerStartPosition);
		}

		template<typename Type>
		Walker<Type>::Walker() : RandomBaseComplete()
		{
			this->init();
		}

		template<typename Type>
		Walker<Type>::Walker(const Walker &value) : RandomBaseComplete(value)
		{
			this->init(value);
		}

		template<typename Type>
		Walker<Type>::Walker(Walker &&value) : RandomBaseComplete(std::move(value))
		{
			this->position = std::move(value.position);
			this->probalitityFactor = value.probalitityFactor;
			this->perlinNoiseTime_PositionX = std::move(value.perlinNoiseTime_PositionX);
			this->perlinNoiseTime_PositionY = std::move(value.perlinNoiseTime_PositionY);
			this->target = std::move(value.target);
		}

		template<typename Type>
		Walker<Type>::~Walker()
		{
			RandomBaseComplete::~RandomBaseComplete();
			IPhysicsImplementor::~IPhysicsImplementor();
		}

		template<typename Type>
		void Walker<Type>::MoveWalkerTowardsTarget()
		{
			Float choice = RandomNumberGenerator::GetRandomPositiveFloat(0,1);

			if(choice < this->probalitityFactor)
			{
				auto xdir = (this->target.X - this->position.X);
				auto ydir = (this->target.Y - this->position.Y);

				if(xdir != 0)
				{
					xdir /= abs(xdir);
				}

				if(ydir != 0)
				{
					ydir /= abs(ydir);
				}

				this->position.X += xdir;
				this->position.Y += ydir;
			} else
			{
				this->position.X += RandomNumberGenerator::GetRandomFloat(2);
				this->position.Y += RandomNumberGenerator::GetRandomFloat(2);
			}
			this->target = VECTOR2D::GetZeroVector();
		}

		template<typename Type>
		void Walker<Type>::SetTarget(const VECTOR2D<Type> &target)
		{
			this->target = target;
		}

		template<typename Type>
		const VECTOR2D<Type>  Walker<Type>::GetCurentPosition() const
		{
			return(this->position);
		}

		template<typename Type>
		void Walker<Type>::SetProbalitiyFactor(Float probalitityFactor)
		{
			this->probalitityFactor = probalitityFactor;
		}

		template<typename Type>
		void Walker<Type>::SetPosition(const VECTOR2D<Type> &position)
		{
			this->position = position;
		}

		template<typename Type>
		Walker<Type>& Walker<Type>::operator=(const Walker& value)
		{
			if(this == &value) { return(*this); }
			RandomBaseComplete::operator=(value);

			this->init(value);
			
			return(*this);
		}

		template<typename Type>
		Walker<Type> & Walker<Type>::operator=(Walker && value)
		{
			if (this == &value)
				return *this;

			
			this->position = std::move(value.position);
			this->probalitityFactor = value.probalitityFactor;
			this->perlinNoiseTime_PositionX = std::move(value.perlinNoiseTime_PositionX);
			this->perlinNoiseTime_PositionY = std::move(value.perlinNoiseTime_PositionY);
			this->target = std::move(value.target);
			
			RandomBaseComplete::operator=(std::move(value));
			return(*this);
		}

		template<typename Type>
		void Walker<Type>::init()
		{
			this->SetConstrainsRange(mRECT(0,0));
			this->target.ZeroVector();
			this->perlinNoiseTime_PositionX = VECTOR3D(0,0,0);
			this->perlinNoiseTime_PositionY = VECTOR3D(10000,10000,10000);
			this->probalitityFactor = 0.9f;
			this->position.ZeroVector();
			this->SetRandomNumberMode(RandomNumberMode::Uniform);
		}

		template<typename Type>
		void Walker<Type>::init(const Walker &value)
		{
			this->SetConstrainsRange(value.GetConstrainsRange());
			//this->PerlinNoiseCalculator = value.PerlinNoiseCalculator;
			this->position = value.position;
			this->probalitityFactor = value.probalitityFactor;
			this->SetRandomNumberMode(value.GetRandomNumberMode());
			this->perlinNoiseTime_PositionX = value.perlinNoiseTime_PositionX;
			this->perlinNoiseTime_PositionY = value.perlinNoiseTime_PositionY;
			this->target = value.target;
		}

		template<typename Type>
		void Walker<Type>::init(const mRECT &areaSize, const VECTOR2D<Type> &walkerStartPosition)
		{
			this->target.ZeroVector();
			this->perlinNoiseTime_PositionX = VECTOR3D(0,0,0);
			this->perlinNoiseTime_PositionY = VECTOR3D(10000,10000,10000);
			this->probalitityFactor = 0.9f;

			if(!areaSize.IsZero())
				this->SetConstrainsRange(areaSize);

			if(!walkerStartPosition.IsZero())
				this->position = walkerStartPosition;

			this->SetRandomNumberMode(RandomNumberMode::Uniform);
		}

		template<typename Type>
		void IWalkerImplementor<Type>::Render()
		{

		}

		template<typename Type>
		void IWalkerImplementor<Type>::SetWalkerRandomNumberMode(RandomNumberMode randomNumberMode)
		{

		}

		template<typename Type>
		void IWalkerImplementor<Type>::RenderWalkerByPosition(const VECTOR2D<Type> &position)
		{

		}

		template<typename Type>
		void IWalkerImplementor<Type>::SetWalkerTarget(const VECTOR2D<Type> &target)
		{

		}

		template<typename Type>
		void IWalkerImplementor<Type>::StepWalker()
		{

		}
		template<typename Type>
		std::shared_ptr<Physics::Force<Type>> IWalkerImplementor<Type>::AccessObjectPhysics() const
		{
			return nullptr;
		}


	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora