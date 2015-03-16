#ifndef GeometryOperations_Indices_TriangleIndicesUnsignedInt_H
#define GeometryOperations_Indices_TriangleIndicesUnsignedInt_H

#include "..\..\..\Globals\GlobalOperations.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			using namespace Aurora::Global;
			using namespace Aurora::DataTypes;
			class TriangleIndicesUnsignedInt
			{
			private:
				UInt32 ui0;
				UInt32 ui1;
				UInt32 ui2;
			public:
				TriangleIndicesUnsignedInt(UInt32 ui0, UInt32 ui1, UInt32 ui2)
				{
					this->ui0 = ui0;
					this->ui1 = ui1;
					this->ui2 = ui2;
				}

				TriangleIndicesUnsignedInt(int i0, int i1, int i2)
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

					ui0 = (UInt32)i0;
					ui1 = (UInt32)i1;
					ui2 = (UInt32)i2;
				}

				TriangleIndicesUnsignedInt(const TriangleIndicesUnsignedInt &other)
				{
					ui0 = other.UI0();
					ui1 = other.UI1();
					ui2 = other.UI2();
				}

				bool operator ==(const TriangleIndicesUnsignedInt &right)
				{
					return this->Equals(right);
				}

				bool operator !=(const TriangleIndicesUnsignedInt &right)
				{
					return !this->Equals(right);
				}


				std::string ToString()
				{
					return("i0:" + std::to_string(this->ui0) + " i1:" + std::to_string(this->ui1) + " i2:" + std::to_string(this->ui2));
				}

				std::size_t GetHashCode()
				{
					std::hash<UInt32> intHash;
					return intHash(this->ui0) ^ intHash(this->ui1) ^ intHash(this->ui2);
				}

				bool Equals(const TriangleIndicesUnsignedInt &other)
				{
					return
						(ui0 == other.UI0()) &&
						(ui1 == other.UI1()) &&
						(ui2 == other.UI2());
				}

				int I0() const {
					return (int)ui0;
				}

				int I1() const {
					return (int)ui1;
				}

					int I2() const{
					return (int)ui2;
				}

					UInt32 UI0() const{
					return ui0;
				}

					UInt32 UI1() const{
					return ui1;
				}

					UInt32 UI2() const{
					return ui2;
				}
				
			};
		};
	};
};

#endif