#ifndef Globals_DynamicArray_H
#define Globals_DynamicArray_H

#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

namespace Aurora
{
	// http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
	/*!
	Namespace: DataTypes

	\brief This namespace holds the engines different datatypes that are used allover the project. It holds datatypes from basic types supported by C/C++ to complex struct, enumerations and STL specific types.
	*/
	namespace Global
	{
		class DynamicTypeArrayHelper
		{
		public:
			static unsigned int GetNextActiveElementFromPosition(unsigned int index, unsigned int arraySize, const std::vector<unsigned int> &disabledArrayElementsIndex)
			{
				bool isIndexRemoved = false;
				if (index >= arraySize)
					return arraySize - 1;

				if (index < 0)
					index = -1;

				unsigned int returnIndex = index + 1;
				for (auto disabledElementIndex : disabledArrayElementsIndex)
				{
					if (disabledElementIndex == returnIndex)
					{
						isIndexRemoved = true;
						break;
					}
				}

				if (isIndexRemoved)
					returnIndex = DynamicTypeArrayHelper::GetNextActiveElementFromPosition(returnIndex, arraySize, disabledArrayElementsIndex);

				return returnIndex;
			}

			static unsigned int GetPreviousActiveElementFromPosition(unsigned int index, unsigned int arraySize, const std::vector<unsigned int> &disabledArrayElementsIndex)
			{
				bool isIndexRemoved = false;

				if (index < 0)
					return 0;

				if (index >= arraySize)
					index = arraySize;

				unsigned int returnIndex = index - 1;
				for (auto disabledElementIndex : disabledArrayElementsIndex)
				{
					if (disabledElementIndex == returnIndex)
					{
						isIndexRemoved = true;
						break;
					}
				}

				if (isIndexRemoved)
					returnIndex = DynamicTypeArrayHelper::GetPreviousActiveElementFromPosition(returnIndex, arraySize, disabledArrayElementsIndex);

				return returnIndex;
			}
		};

		// Notice this array does not have boundry check with incrementing
		template<typename DataType>
		class DynamicTypeArray
		{
		private:
			std::unique_ptr<DataType[]> data; 
			
			unsigned int size = 0;

			void CopyData(const DynamicTypeArray &value)
			{
				if (value.Size() > this->size)
					throw std::bad_function_call("target array is larger than destination array");

				unsigned int index = 0;
				for (DynamicTypeArray<DataType>::const_iterator i = value.begin(); i != value.end(); i++)
				{
					this->data[index] = *i;
					++index;
				}
			}
			
			
		public:
			

			DynamicTypeArray() = default;

			virtual ~DynamicTypeArray() = default;

			DynamicTypeArray(unsigned int arraySize)
			{
				this->data = std::make_unique<DataType[]>(size);
				this->size = arraySize;
			}

			DynamicTypeArray(const DynamicTypeArray &value) : data(std::make_unique<DataType[]>(value.Size())), size(value.Size())
			{
				CopyData(value);
			}
			DynamicTypeArray(DynamicTypeArray &&value) : data(std::move(value.Data())), size(value.Size())
			{

			}
			DynamicTypeArray &operator=(DynamicTypeArray && value)
			{
				if (this == &value)
					return *this;
				
				this->data = std::move(value.Data());
				this->size = value.Size();

				return *this;
			}
			DynamicTypeArray& operator=(const DynamicTypeArray& value)
			{
				if (this == &value)
					return *this;

				CopyData(value);
				this->size = value.Size();

				return *this;
			}

			unsigned int Size() const {
				return size;
			}


			class iterator
			{
			public:
				typedef iterator self_type;
				typedef DataType value_type;
				typedef DataType& reference;
				typedef DataType* pointer;
				typedef std::forward_iterator_tag iterator_category;
				typedef int difference_type;
				iterator(pointer ptr, unsigned int size, unsigned int startLocation) : ptr_(ptr), size(size), iteratorLocation(startLocation){}
				self_type operator++() { 
					/*unsigned int currentIteratorLocation = iteratorLocation;
					++iteratorLocation;
					if (iteratorLocation >= size)
					iteratorLocation = size - 1;

					if (iteratorLocation < 0)
					iteratorLocation = 0;

					ptr_ = ptr_ + (iteratorLocation - currentIteratorLocation);*/
					ptr_++;
					return *this; 
				}
				self_type operator++(int junk) { 
					self_type i = *this;
					/*unsigned int currentIteratorLocation = iteratorLocation;
					++iteratorLocation;

					if (iteratorLocation >= size)
						iteratorLocation = size - 1;

					if (iteratorLocation < 0)
						iteratorLocation = 0;
					
					ptr_ = ptr_ + (iteratorLocation - currentIteratorLocation);*/
					ptr_++;
					return i; }

				self_type operator--() {
					/*unsigned int currentIteratorLocation = iteratorLocation;
					--iteratorLocation;
					if (iteratorLocation >= size)
						iteratorLocation = size - 1;

					if (iteratorLocation < 0)
						iteratorLocation = 0;

					ptr_ = ptr_ - (currentIteratorLocation - iteratorLocation);*/
					ptr_--;
					return *this;
				}
				self_type operator--(int junk) {
					self_type i = *this;
					/*unsigned int currentIteratorLocation = iteratorLocation;
					if (iteratorLocation >= size)
						iteratorLocation = size - 1;

					if (iteratorLocation < 0)
						iteratorLocation = 0;

					ptr_ = ptr_ - (currentIteratorLocation - iteratorLocation);*/
					ptr_--;
					return i;
				}

				reference operator*() { return *ptr_; }
				pointer operator->() { return ptr_; }
				bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
				bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
			private:
				pointer ptr_;
				unsigned int iteratorLocation = 0;
				unsigned int size;
			};

			class const_iterator
			{
			public:
				typedef const_iterator self_type;
				typedef DataType value_type;
				typedef DataType& reference;
				typedef DataType* pointer;
				typedef int difference_type;
				typedef std::forward_iterator_tag iterator_category;
				const_iterator(pointer ptr, unsigned int size, unsigned int startLocation) : ptr_(ptr), size(size), iteratorLocation(startLocation){}
				self_type operator++() {
					if (iteratorLocation >= size)
						iteratorLocation = size - 1;

					if (iteratorLocation < 0)
						iteratorLocation = 0;

					ptr_ = ptr_ + iteratorLocation;
					return *this; 
				}
				self_type operator++(int junk) {  
					self_type i = *this; 
					if (iteratorLocation >= size)
						iteratorLocation = size - 1;

					if (iteratorLocation < 0)
						iteratorLocation = 0;

					ptr_ = ptr_ + iteratorLocation;
					return i; 
				}
				const value_type& const_iterator::operator*()  { return *ptr_; }
				const value_type* const_iterator::operator->() { return ptr_; }
				bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
				bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
			private:
				pointer ptr_;
				unsigned int iteratorLocation = 0;
				unsigned int size;
			};

			DataType &at(unsigned int index)
			{
				assert(index < size);
				return data[index];
			}

			DataType& operator[](unsigned int index)
			{
				assert(index < size);
				return data[index];
			}

			const DataType& operator[](unsigned int index) const
			{
				assert(index < size);
				return data[index];
			}

			iterator from(unsigned int index)
			{
				return iterator(this->data.get(),  size, index);
			}

			iterator begin()
			{
				return iterator(data.get(), this->Size(), 0);
			}

			iterator end()
			{
				return iterator(data.get() + size, size, size - 1);
			}

			const_iterator begin() const
			{
				return const_iterator(data.get(), size, 0);
			}

			const_iterator end() const
			{
				return const_iterator(data.get() + size, size, size - 1);
			}
			
		};

	};

};

#endif