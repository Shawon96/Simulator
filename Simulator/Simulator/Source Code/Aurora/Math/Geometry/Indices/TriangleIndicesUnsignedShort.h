#ifndef GeometryOperations_Indices_TriangleIndicesUnsignedShort_H
#define GeometryOperations_Indices_TriangleIndicesUnsignedShort_H

#include "..\..\..\Globals\GlobalOperations.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			using namespace Aurora::Global;
			using namespace Aurora::DataTypes;
			class TriangleIndicesUnsignedShort
			{
			private:
				UInt16 ui0;
				UInt16 ui1;
				UInt16 ui2;
			public:
				TriangleIndicesUnsignedShort(UInt16 ui0, UInt16 ui1, UInt16 ui2)
				{
					this->ui0 = ui0;
					this->ui1 = ui1;
					this->ui2 = ui2;
				}

				TriangleIndicesUnsignedShort(Int16 i0, Int16 i1, Int16 i2)
				{
					if (i0 < 0)
					{
						throw std::bad_function_call("i0");
					}

					if (i1 < 0)
					{
						throw std::bad_function_call("i1");
					}

					if (i2 < 0)
					{
						throw std::bad_function_call("i2");
					}

					ui0 = (UInt16)i0;
					ui1 = (UInt16)i1;
					ui2 = (UInt16)i2;
				}

				TriangleIndicesUnsignedShort(const TriangleIndicesUnsignedShort &other)
				{
					ui0 = other.UI0();
					ui1 = other.UI1();
					ui2 = other.UI2();
				}

				bool operator ==(const TriangleIndicesUnsignedShort &right)
				{
					return this->Equals(right);
				}

				bool operator !=(const TriangleIndicesUnsignedShort &right)
				{
					return !this->Equals(right);
				}


				std::string ToString()
				{
					return("i0:" + std::to_string(this->ui0) + " i1:" + std::to_string(this->ui1) + " i2:" + std::to_string(this->ui2));
				}

				std::size_t GetHashCode()
				{
					std::hash<UInt16> intHash;
					return intHash(this->ui0) ^ intHash(this->ui1) ^ intHash(this->ui2);
				}

				bool Equals(const TriangleIndicesUnsignedShort &other)
				{
					return
						(ui0 == other.UI0()) &&
						(ui1 == other.UI1()) &&
						(ui2 == other.UI2());
				}

				Int16 I0() const {
					return (Int16)ui0;
				}

				Int16 I1() const {
					return (Int16)ui1;
				}

				Int16 I2() const{
					return (Int16)ui2;
				}

				UInt16 UI0() const{
					return ui0;
				}

				UInt16 UI1() const{
					return ui1;
				}

				UInt16 UI2() const{
					return ui2;
				}

			};
		};
	};
};

#endif