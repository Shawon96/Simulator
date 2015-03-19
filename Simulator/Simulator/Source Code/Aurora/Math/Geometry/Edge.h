#ifndef GeometryOperations_Edge_H
#define GeometryOperations_Edge_H
#include <functional>
#include <stdlib.h> 
#include "..\..\Globals\GlobalDatatypes.h"

namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			using namespace Aurora::DataTypes;

			class Edge
			{
			public:
				Edge(int index0, int index1)
				{
					this->index0 = index0;
					this->index1 = index1;
				}

				virtual ~Edge() = default;

				int Index0() const {
					return index0;
				}

				int Index1() const {
					return index1;
				}


				bool operator ==(const Edge &right)
				{
					return this->Equals(right);
				}

				bool operator !=(const Edge &right)
				{
					return !this->Equals(right);
				}

				std::string ToString()
				{
					return("Edge Index0:" + std::to_string(this->index0) + " Edge Index1:" + std::to_string(this->index1));
				}

				std::size_t GetHashCode()
				{
					std::hash<int> intHash;
					return intHash(this->index0) ^ intHash(this->index1);
				}



				bool Equals(const Edge &other)
				{
					return (index0 == other.index0) && (index1 == other.index1);
				}


				private:
					int index0;
					int index1;
			};

		};
	};
};

#endif