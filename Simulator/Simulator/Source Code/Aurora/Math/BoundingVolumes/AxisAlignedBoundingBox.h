#ifndef Math_BoundingVolumes_AxisAlignedBoundingBox_H
#define Math_BoundingVolumes_AxisAlignedBoundingBox_H

#include "../Vectors/Vector3D.h"
#include <limits>

namespace Aurora
{
	namespace Math
	{
		namespace BoundingVolumes
		{
/*!
 * \class AxisAlignedBoundingBox
 *
 * \ingroup GroupName
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note 
 *
 * \author Adrian Simionescu
 *
 * \version 1.0
 *
 * \date March 2015
 *
 * Contact: user@company.com
 *
 */
			class AxisAlignedBoundingBox
			{
			private:
				Vector3DDouble minimum;
				Vector3DDouble maximum;
			public:
				AxisAlignedBoundingBox(const UniqueVector3DDoubleVector &positions)
				{
					/*if (positions == null)
					{
						throw new ArgumentNullException("positions");
					}*/

					double minimumX = std::numeric_limits<double>::max();
					double minimumY = std::numeric_limits<double>::max();
					double minimumZ = std::numeric_limits<double>::max();

					double maximumX = -std::numeric_limits<double>::max();
					double maximumY = -std::numeric_limits<double>::max();
					double maximumZ = -std::numeric_limits<double>::max();

					for(auto &position : positions)
					{
						if (position->X < minimumX)
						{
							minimumX = position->X;
						}

						if (position->X > maximumX)
						{
							maximumX = position->X;
						}

						if (position->Y < minimumY)
						{
							minimumY = position->Y;
						}

						if (position->Y > maximumY)
						{
							maximumY = position->Y;
						}

						if (position->Z < minimumZ)
						{
							minimumZ = position->Z;
						}

						if (position->Z > maximumZ)
						{
							maximumZ = position->Z;
						}
					}

					Vector3DDouble minimum = Vector3DDouble(minimumX, minimumY, minimumZ);
					Vector3DDouble maximum = Vector3DDouble(maximumX, maximumY, maximumZ);

					if (minimum > maximum)
					{
						std::swap(minimum, maximum);
					}

					this->minimum = minimum;
					this->maximum = maximum;
				}

				Vector3DDouble Minimum() const {
					return this->minimum;
				}

				Vector3DDouble Maximum() const {
					return maximum;
				}

				Vector3DDouble Center() {
					double divisionBy = 0.5;
					// TODO: Optimization of operators
					return(this->minimum + this->maximum).Clone() * divisionBy;
				}
				
			};

		};
	};
};

#endif