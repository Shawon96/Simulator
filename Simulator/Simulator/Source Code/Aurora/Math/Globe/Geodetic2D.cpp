#include "Geodetic2D.h"

namespace Aurora
{
	namespace Math
	{
		namespace Globe
		{
			Geodetic2D::Geodetic2D() : latitude(0), longitude(0)
			{

			}

			Geodetic2D::Geodetic2D(const Geodetic2D &value)
			{
				this->init(value);
			}

			Geodetic2D::Geodetic2D(Geodetic2D &&value)
			{
				this->init(std::move(value));
			}

			Geodetic2D::Geodetic2D(double longitude, double latitude)
			{
				this->longitude = longitude;
				this->latitude = latitude;
			}

			Geodetic2D::~Geodetic2D()
			{

			}

			Geodetic2D & Geodetic2D::operator=(Geodetic2D && value)
			{
				if (this == &value)
					return *this;

				this->init(std::move(value));

				return *this;
			}

			Geodetic2D& Geodetic2D::operator=(const Geodetic2D& value)
			{
				if (this == &value)
					return *this;

				this->init(value);

				return *this;
			}

			bool Geodetic2D::EqualsEpsilon(const Geodetic2D &value, double epsilon)
			{
				return (abs(longitude - value.longitude) <= epsilon) &&
					(abs(latitude - value.latitude) <= epsilon);
			}

			bool Geodetic2D::Equals(const Geodetic2D &value)
			{
				return longitude == value.longitude && latitude == value.latitude;
			}

			bool Geodetic2D::operator==(const Geodetic2D &value)
			{
				return this->Equals(value);
			}

			bool Geodetic2D::operator!=(const Geodetic2D &value)
			{
				return !this->Equals(value);
			}

			std::size_t Geodetic2D::GetHashCode()
			{
				std::hash<double> doubleHash;
				return doubleHash(this->longitude) ^ doubleHash(this->latitude);
			}

			void Geodetic2D::init()
			{
				this->latitude = 0;
				this->longitude = 0;
			}

			void Geodetic2D::init(const Geodetic2D &value)
			{
				this->latitude = value.latitude;
				this->longitude = value.longitude;
			}

			void Geodetic2D::init(const Geodetic2D &&value)
			{
				this->latitude = std::move(value.latitude);
				this->longitude = std::move(value.longitude);
			}

		}
	}
}