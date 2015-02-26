#ifndef Trig_H
#define Trig_H

#include <functional>
#include <stdlib.h>
#include "Geodetic2D.h"
#include "Geodetic3D.h"
#include <memory>
#include "../../Math/MathOperations.h"
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

				template<typename GeodeticType>
				static std::shared_ptr<Geodetic3D> ToRadians(const GeodeticType &&geodetic);
			};

			template<typename GeodeticType>
			static std::shared_ptr<Geodetic3D>
				Aurora::Math::Globe::Trig::ToRadians(const GeodeticType &&geodetic)
			{
				static_assert(!is_same<Geodetic3D, GeodeticType>::value, Aurora::Errors::ErrorMessages::TypeMismatch.c_str());
				auto geodeticAuto = std::forward<Geodetic3D>(geodetic);
				return std::make_shared<Geodetic3D>(MathOperations::Degrees_To_Radians(geodeticAuto.Longitude()), MathOperations::Degrees_To_Radians(geodeticAuto.Latitude()), geodeticAuto.Height());
			}

		}
	}
}

#endif