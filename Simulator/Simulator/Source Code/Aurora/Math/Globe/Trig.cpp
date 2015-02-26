#include "Trig.h"

using namespace Aurora::Math;

namespace Aurora
{
	namespace Math
	{
		namespace Globe
		{


			const double Trig::OneOverPi = 1.0 / PI;


			const double Trig::PiOverTwo = PI * 0.5;


			const double Trig::PiOverThree = PI / 3.0;


			const double Trig::PiOverFour = PI / 4.0;


			const double Trig::PiOverSix = PI / 6.0;


			const double Trig::ThreePiOver2 = (3.0 * PI) * 0.5;


			const double Trig::TwoPi = 2.0 * PI;


			const double Trig::OneOverTwoPi = 1.0 / (2.0 * PI);


			const double Trig::RadiansPerDegree = PI / 180.0;

			std::shared_ptr<Aurora::Math::Globe::Geodetic3D> Trig::ToRadians(const Geodetic3D &geodetic)
			{
				return std::make_shared<Geodetic3D>(MathOperations::Degrees_To_Radians(geodetic.Longitude()), MathOperations::Degrees_To_Radians(geodetic.Latitude()), geodetic.Height());
			}

			std::shared_ptr<Aurora::Math::Globe::Geodetic2D> Trig::ToRadians(const Geodetic2D &geodetic)
			{
				return std::make_shared<Geodetic2D>(MathOperations::Degrees_To_Radians(geodetic.Longitude()), MathOperations::Degrees_To_Radians(geodetic.Latitude()));
			}

			std::shared_ptr<Aurora::Math::Globe::Geodetic3D> Trig::ToDegrees(const Geodetic3D &geodetic)
			{
				return std::make_shared<Geodetic3D>(MathOperations::Radians_To_Degrees(geodetic.Longitude()), MathOperations::Radians_To_Degrees(geodetic.Latitude()), geodetic.Height());
			}

			std::shared_ptr<Aurora::Math::Globe::Geodetic2D> Trig::ToDegrees(const Geodetic2D &geodetic)
			{
				return std::make_shared<Geodetic2D>(MathOperations::Radians_To_Degrees(geodetic.Longitude()), MathOperations::Radians_To_Degrees(geodetic.Latitude()));
			}

		}
	}
}