#ifndef Trig_H
#define Trig_H

#include <functional>
#include <stdlib.h>
#include "GeodeticExtent.h"
#include "Geodetic3D.h"
#include <type_traits>
#include <memory>
//#include "../../Math/MathOperations.h"
#include "../../Globals/GlobalDatatypes.h"

using namespace Aurora::DataTypes;

namespace Aurora
{
	namespace Math
	{
		namespace Globe
		{
			class Trig
			{
			public:
				static const double OneOverPi;
				static const double PiOverTwo;
				static const double PiOverThree;
				static const double PiOverFour;
				static const double PiOverSix;
				static const double ThreePiOver2;
				static const double TwoPi;
				static const double OneOverTwoPi;
				static const double RadiansPerDegree;


				static std::shared_ptr<Geodetic3D> ToRadians(const Geodetic3D &geodetic);

				static std::shared_ptr<Geodetic2D> ToRadians(const Geodetic2D &geodetic);

				static std::shared_ptr<Geodetic3D> ToDegrees(const Geodetic3D &geodetic);

				static std::shared_ptr<Geodetic2D> ToDegrees(const Geodetic2D &geodetic);

			};

		}
	}
}

#endif