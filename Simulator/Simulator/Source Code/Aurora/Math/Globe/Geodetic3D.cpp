#include "Geodetic3D.h"

namespace Aurora
{
	namespace Math
	{
		namespace Globe
		{

			void Geodetic3D::init()
			{
				this->latitude = 0;
				this->longitude = 0;
				this->height = 0;
			}

			void Geodetic3D::init(const Geodetic3D &value)
			{
				this->latitude = value.latitude;
				this->longitude = value.longitude;
				this->height = value.height;
			}

			void Geodetic3D::init(const Geodetic3D &&value)
			{
				this->latitude = std::move(value.latitude);
				this->longitude = std::move(value.longitude);
				this->height = std::move(value.height);
			}

			Geodetic3D::Geodetic3D() : latitude(0), longitude(0), height(0)
			{

			}

			Geodetic3D::Geodetic3D(const Geodetic3D &value)
			{
				this->init(value);
			}

			Geodetic3D::Geodetic3D(Geodetic3D &&value)
			{
				this->init(std::move(value));
			}

			Geodetic3D::Geodetic3D(double longitude, double latitude)
			{
				this->longitude = longitude;
				this->latitude = latitude;
				this->height = 0;
			}

			Geodetic3D::Geodetic3D(double longitude, double latitude, double height)
			{
				this->longitude = longitude;
				this->latitude = latitude;
				this->height = height;
			}

			Geodetic3D::~Geodetic3D()
			{

			}

			Geodetic3D & Geodetic3D::operator=(Geodetic3D && value)
			{
				if (this == &value)
					return *this;

				this->init(std::move(value));

				return *this;
			}

			Geodetic3D& Geodetic3D::operator=(const Geodetic3D& value)
			{
				if (this == &value)
					return *this;

				this->init(value);

				return *this;
			}

			bool Geodetic3D::Equals(const Geodetic3D &value)
			{
				return longitude == value.longitude && latitude == value.latitude && height == value.height;
			}

			bool Geodetic3D::operator==(const Geodetic3D &value)
			{
				return this->Equals(value);
			}

			bool Geodetic3D::operator!=(const Geodetic3D &value)
			{
				return !this->Equals(value);
			}

			std::size_t Geodetic3D::GetHashCode()
			{
				std::hash<double> doubleHash;
				return doubleHash(this->longitude) ^ doubleHash(this->latitude) ^ doubleHash(this->height);
			}

		}
	}
}