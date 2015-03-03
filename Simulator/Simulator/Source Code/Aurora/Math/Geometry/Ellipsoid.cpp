#include "Ellipsoid.h"


namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{

			Ellipsoid::Ellipsoid()
			{

			}

			Ellipsoid::Ellipsoid(double x, double y, double z)
			{
				Ellipsoid(Vector3D<double>(x,y,x));
			}

			Ellipsoid::Ellipsoid(const Vector3D<double> &radii)
			{
				if ((radii.X <= 0.0) || (radii.Y <= 0.0) || (radii.Z <= 0.0))
				{
					throw std::bad_function_call(Aurora::Errors::ErrorMessages::RadiiEllipsoidError.c_str());
				}

				this->radii = radii;
				radiiSquared = Vector3D<double>(
					radii.X * radii.X,
					radii.Y * radii.Y,
					radii.Z * radii.Z);
				radiiToTheFourth = Vector3D<double>(
					radiiSquared.X * radiiSquared.X,
					radiiSquared.Y * radiiSquared.Y,
					radiiSquared.Z * radiiSquared.Z);
				oneOverRadiiSquared = Vector3D<double>(
					1.0 / (radii.X * radii.X),
					1.0 / (radii.Y * radii.Y),
					1.0 / (radii.Z * radii.Z));
			}

			Ellipsoid::Ellipsoid(const Ellipsoid &value) : radii(value.radii), radiiSquared(value.radiiSquared), radiiToTheFourth(value.radiiToTheFourth), oneOverRadiiSquared(value.oneOverRadiiSquared)
			{
				
			}

			Ellipsoid::Ellipsoid(Ellipsoid &&value) : radii(std::move(value.radii)), radiiSquared(std::move(value.radiiSquared)), radiiToTheFourth(std::move(value.radiiToTheFourth)), oneOverRadiiSquared(std::move(value.oneOverRadiiSquared))
			{

			}

			Ellipsoid::~Ellipsoid()
			{

			}

			Ellipsoid & Ellipsoid::operator=(Ellipsoid && value)
			{
				if (this == &value)
					return *this;

				this->radii = std::move(value.radii);
				this->radiiSquared = std::move(value.radiiSquared);
				this->radiiToTheFourth = std::move(value.radiiToTheFourth);
				this->oneOverRadiiSquared = std::move(value.oneOverRadiiSquared);

				return *this;
			}

			Ellipsoid& Ellipsoid::operator=(const Ellipsoid& value)
			{
				if (this == &value)
					return *this;

				this->radii = value.radii;
				this->radiiSquared = value.radiiSquared;
				this->radiiToTheFourth = value.radiiToTheFourth;
				this->oneOverRadiiSquared = value.oneOverRadiiSquared;

				return *this;
			}

			Vector3D<double> Ellipsoid::CentricSurfaceNormal(const Vector3D<double> &positionOnEllipsoid)
			{
				return positionOnEllipsoid.Clone().Normalize();
			}

			Vector3D<double> Ellipsoid::GeodeticSurfaceNormal(const Vector3D<double> &positionOnEllipsoid)
			{
				return (positionOnEllipsoid.Clone().MultiplyComponents(oneOverRadiiSquared)).Normalize();
			}

			Vector3D<double> Ellipsoid::GeodeticSurfaceNormal(const Geodetic3D &geodetic)
			{
				double cosLatitude = cos(geodetic.Latitude());

				return Vector3D<double>(
                cosLatitude * cos(geodetic.Longitude()),
                cosLatitude * sin(geodetic.Longitude()),
                sin(geodetic.Latitude()));
			}

			double Ellipsoid::MinimumRadius()
			{
				return std::min(radii.X, std::min(radii.Y, radii.Z));
			}

			double Ellipsoid::MaximumRadius()
			{
				return std::max(radii.X, std::max(radii.Y, radii.Z));
			}

			std::vector<double> Ellipsoid::Intersections(const Vector3D<double> &origin, Vector3D<double> &direction)
			{
				direction.Normalize();
				std::vector<double> returnArray;

				// By laborious algebraic manipulation....
				double a = direction.X * direction.X * oneOverRadiiSquared.X +
				           direction.Y * direction.Y * oneOverRadiiSquared.Y +
				           direction.Z * direction.Z * oneOverRadiiSquared.Z;
				double b = 2.0 *
				           (origin.X * direction.X * oneOverRadiiSquared.X +
				            origin.Y * direction.Y * oneOverRadiiSquared.Y +
				            origin.Z * direction.Z * oneOverRadiiSquared.Z);
				double c = origin.X * origin.X * oneOverRadiiSquared.X +
				           origin.Y * origin.Y * oneOverRadiiSquared.Y +
				           origin.Z * origin.Z * oneOverRadiiSquared.Z - 1.0;

				// Solve the quadratic equation: ax^2 + bx + c = 0.
				// Algorithm is from Wikipedia's "Quadratic equation" topic, and Wikipedia credits
				// Numerical Recipes in C, section 5.6: "Quadratic and Cubic Equations"
				double discriminant = b * b - 4 * a * c;
				if (discriminant < 0.0)
				{
				    // no intersections
					return returnArray; 
				}
				else if (discriminant == 0.0)
				{
					returnArray.push_back( -0.5 * b / a );
				    // one intersection at a tangent point
					return returnArray;
				}

				double t = -0.5 * (b + (b > 0.0 ? 1.0 : -1.0) * sqrt(discriminant));
				double root1 = t / a;
				double root2 = c / t;

				// Two intersections - return the smallest first.
				if (root1 < root2)
				{
					returnArray.push_back(root1);
					returnArray.push_back(root2);
				    return returnArray;
				}
				else
				{
					returnArray.push_back(root2);
				    returnArray.push_back(root1);
				    return returnArray;
				}
			}

			Vector3D<double> Ellipsoid::ToVector3D(const Geodetic2D &geodetic)
			{
				return ToVector3D(Geodetic3D(geodetic.Longitude(), geodetic.Latitude(), 0.0));
			}

			Vector3D<double> Ellipsoid::ToVector3D(const Geodetic3D &geodetic)
			{
				Vector3D<double> n = GeodeticSurfaceNormal(geodetic);
				Vector3D<double> k = radiiSquared.MultiplyComponents(n);
				double gamma = sqrt(
				    (k.X * n.X) +
				    (k.Y * n.Y) +
				    (k.Z * n.Z));

				Vector3D<double> rSurface = k / gamma;
				return rSurface + (n * geodetic.Height());
			}

			std::vector<Geodetic3D> Ellipsoid::ToGeodetic3D(const std::vector<Vector3D<double>> &positions)
			{
				/*if (positions == nullptr)
				{
				    throw std::bad_function_call(Aurora::Errors::ErrorMessages::RadiiEllipsoidError.c_str());
				}*/

				std::vector<Geodetic3D> geodetics(positions.size());

				for (auto position : positions)
				{
					geodetics.push_back(ToGeodetic3D(position));
				}

				return geodetics;
			}

			Aurora::Math::Globe::Geodetic3D Ellipsoid::ToGeodetic3D(const Vector3D<double> &position)
			{
				Vector3D<double> p = ScaleToGeodeticSurface(position);
				Vector3D<double> h = position.Clone() - p;
				int sign = 0;
				double dotValue = h.Dot(position);
				if (dotValue < 0)
					sign = -1;
				else if (dotValue > 0)
					sign = 1;
				double height = sign * h.Magnitude();
				return Geodetic3D(ToGeodetic2D(p), height);
			}

			std::vector<Geodetic2D> Ellipsoid::ToGeodetic2D(const std::vector<Vector3D<double>> &positions)
			{
				/*if (positions == null)
				{
					throw new ArgumentNullException("positions");
				}*/

				std::vector<Geodetic2D> geodetics(positions.size());

				for (auto position : positions)
				{
					geodetics.push_back(ToGeodetic2D(position));
				}

				return geodetics;
			}

			Aurora::Math::Globe::Geodetic2D Ellipsoid::ToGeodetic2D(const Vector3D<double> &positionOnEllipsoid)
			{
				Vector3D<double> n = GeodeticSurfaceNormal(positionOnEllipsoid);
				return Geodetic2D(
					atan2(n.Y, n.X),
					asin(n.Z / n.Magnitude()));
			}

			Vector3D<double> Ellipsoid::ScaleToGeodeticSurface(const Vector3D<double> &position)
			{
				double beta = 1.0 / sqrt(
					(position.X * position.X) * oneOverRadiiSquared.X +
					(position.Y * position.Y) * oneOverRadiiSquared.Y +
					(position.Z * position.Z) * oneOverRadiiSquared.Z);
				double n = Vector3D<double>(
					beta * position.X * oneOverRadiiSquared.X,
					beta * position.Y * oneOverRadiiSquared.Y,
					beta * position.Z * oneOverRadiiSquared.Z).Magnitude();
				double alpha = (1.0 - beta) * (position.Magnitude() / n);

				double x2 = position.X * position.X;
				double y2 = position.Y * position.Y;
				double z2 = position.Z * position.Z;

				double da = 0.0;
				double db = 0.0;
				double dc = 0.0;

				double s = 0.0;
				double dSdA = 1.0;

				do
				{
					alpha -= (s / dSdA);

					da = 1.0 + (alpha * oneOverRadiiSquared.X);
					db = 1.0 + (alpha * oneOverRadiiSquared.Y);
					dc = 1.0 + (alpha * oneOverRadiiSquared.Z);

					double da2 = da * da;
					double db2 = db * db;
					double dc2 = dc * dc;

					double da3 = da * da2;
					double db3 = db * db2;
					double dc3 = dc * dc2;

					s = x2 / (radiiSquared.X * da2) +
						y2 / (radiiSquared.Y * db2) +
						z2 / (radiiSquared.Z * dc2) - 1.0;

					dSdA = -2.0 *
						(x2 / (radiiToTheFourth.X * da3) +
						y2 / (radiiToTheFourth.Y * db3) +
						z2 / (radiiToTheFourth.Z * dc3));
				} while (abs(s) > 1e-10);

				return Vector3D<double>(
					position.X / da,
					position.Y / db,
					position.Z / dc);
			}

			Vector3D<double> Ellipsoid::ScaleToGeocentricSurface(const Vector3D<double> &position)
			{
				double beta = 1.0 / sqrt(
					(position.X * position.X) * oneOverRadiiSquared.X +
					(position.Y * position.Y) * oneOverRadiiSquared.Y +
					(position.Z * position.Z) * oneOverRadiiSquared.Z);

				return position.Clone() * beta;
			}

			std::vector<Vector3D<double>> Ellipsoid::ComputeCurve(const Vector3D<double> &start, const Vector3D<double> &stop, const double &granularity)
			{
				if (granularity <= 0.0)
				{
					throw std::bad_function_call(Aurora::Errors::ErrorMessages::EllipsoidGranularityError.c_str());
				}
				auto startClone = start.Clone();
				Vector3D<double> normal = start.Cross(stop).Normalize();
				double theta = startClone.AngleBetween(stop);
				int n = std::max((int)(theta / granularity) - 1, 0);

				std::vector<Vector3D<double>> positions(2 + n);

				positions.push_back(start);

				for (int i = 1; i <= n; ++i)
				{
					double phi = (i * granularity);

					positions.push_back((ScaleToGeocentricSurface(startClone.RotateAroundAxis(normal, phi))));
				}

				positions.push_back(stop);

				return positions;
			}

		}
	}
}