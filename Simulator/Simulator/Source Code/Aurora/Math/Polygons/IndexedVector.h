#ifndef Math_Polygons_IndexedVector_H
#define Math_Polygons_IndexedVector_H

#include "../Globals/DynamicArray.h"
#include "../Vectors/EmulatedVector3D.h"
#include <list>
#include <forward_list>

namespace Aurora
{

	namespace Math
	{
		namespace Polygons
		{
			using namespace Aurora::Math;
			using namespace Aurora::Global;
			template<typename T>
			class IndexedVector
			{
			private:
				T vector;
				int index;
			public:
				IndexedVector(const T &vector, int index)
				{
					vector = vector;
					index = index;
				}

				T Vector() const {
					return vector;
				}

				int Index() const {
					return index;
				}

				bool operator ==(const IndexedVector<T> &right)
				{
					return this->Equals(right);
				}

				bool operator !=(const IndexedVector<T> &right)
				{
					return !this->Equals(right);
				}

				std::string ToString()
				{
					if(std::is_same<Vector2DDouble, T>::value)
						return("Vector data:" + std::to_string(static_cast<Vector2DDouble>(this->vector).ToString()) + " Index:" + std::to_string(this->index));
					//return string.Format(CultureInfo.CurrentCulture, "{0}, {1}", _vector, _index);

					return nullptr;
				}

				std::size_t GetHashCode()
				{
					std::hash<T> tHash;
					std::hash<int> intHash;
					return tHash(this->vector) ^ intHash(this->index);
				}

				bool Equals(const IndexedVector<T> &other)
				{
					return (this->vector.Equals(other.vector)) && (this->index == other.index);
				}
						
			};

			using IndexedVector2DDouble =IndexedVector<Vector2DDouble>;
			using IndexedVector3DDouble =IndexedVector<Vector3DDouble>;
			using IndexedVector4DDouble =IndexedVector<Vector4DDouble>;

			using DynamicArrayIndexedVector2DDouble = DynamicArray<IndexedVector < Vector2DDouble >>;
			using DynamicArrayIndexedVector3DDouble = DynamicArray < IndexedVector < Vector3DDouble > > ;
			using DynamicArrayIndexedVector4DDouble = DynamicArray < IndexedVector < Vector4DDouble > > ;


			using UniqueIndexedVector2DDouble = std::unique_ptr<IndexedVector2DDouble>;
			using UniqueIndexedVector3DDouble = std::unique_ptr<IndexedVector3DDouble>;
			using UniqueIndexedVector4DDouble = std::unique_ptr<IndexedVector4DDouble>;

			using DoubleLinkedListUniqueIndexedVector2DDouble = std::list < UniqueIndexedVector2DDouble >;
			using DoubleLinkedListUniqueIndexedVector3DDouble = std::list < UniqueIndexedVector3DDouble >;
			using DoubleLinkedListUniqueIndexedVector4DDouble = std::list < UniqueIndexedVector4DDouble >;

			using LinkedListUniqueIndexedVector2DDouble = std::forward_list < UniqueIndexedVector2DDouble >;
			using LinkedListUniqueIndexedVector3DDouble = std::forward_list < UniqueIndexedVector3DDouble >;
			using LinkedListUniqueIndexedVector4DDouble = std::forward_list < UniqueIndexedVector4DDouble >;

			using SharedIndexedVector2DDouble = std::shared_ptr < IndexedVector2DDouble > ;
			using SharedIndexedVector3DDouble = std::shared_ptr < IndexedVector3DDouble >;
			using SharedIndexedVector4DDouble = std::shared_ptr < IndexedVector4DDouble >;

			using WeakIndexedVector2DDouble = std::weak_ptr < IndexedVector2DDouble > ;
			using WeakIndexedVector3DDouble = std::weak_ptr < IndexedVector3DDouble >;
			using WeakIndexedVector4DDouble = std::weak_ptr < IndexedVector4DDouble >;

			using DoubleLinkedListSharedIndexedVector2DDouble = std::list < SharedIndexedVector2DDouble >;
			using DoubleLinkedListSharedIndexedVector3DDouble = std::list < SharedIndexedVector3DDouble >;
			using DoubleLinkedListSharedIndexedVector4DDouble = std::list < SharedIndexedVector4DDouble >;

			using LinkedListSharedIndexedVector2DDouble = std::forward_list < SharedIndexedVector2DDouble >;
			using LinkedListSharedIndexedVector3DDouble = std::forward_list < SharedIndexedVector3DDouble >;
			using LinkedListSharedIndexedVector4DDouble = std::forward_list < SharedIndexedVector4DDouble >;
		};
	};
};

#endif