#ifndef EmulatedVector3D_H
#define EmulatedVector3D_H
#include "Vector4D.h"
namespace Aurora
{
	namespace Math
	{
		class EmulatedVector3D
		{
		public:
			EmulatedVector3D(const Vector3DDouble &v)
			{
				// TODO: Memory usage Optimization here??
				high = v.ToFloat();
				low = (v.Clone() - high.ToDouble()).ToFloat();
			}
			virtual ~EmulatedVector3D() = default;
			

				bool Equals(const EmulatedVector3D &other)
					{
						return high == other.high && low == other.low;
					}

					bool operator ==(const EmulatedVector3D &right)
					{
						return this->Equals(right);
					}

					bool operator !=(const EmulatedVector3D &right)
					{
						return !this->Equals(right);
					}

					std::string ToString()
					{
						return("High:" + this->high.ToString() + " Low:" + this->low.ToString());
					}

					int GetHashCode()
					{
						return this->high.GetHashCode() ^ this->low.GetHashCode();
					}

		private:
					Vector3DFloat high;
					Vector3DFloat low;
		};
	};
};
#endif