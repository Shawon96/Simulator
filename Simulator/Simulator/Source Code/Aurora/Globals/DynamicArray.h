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
		template<typename DataType>
		class DynamicArray
		{
		private:
			std::unique_ptr<DataType[]> data; 
			
			unsigned int size = 0;

			void CopyData(const DynamicArray &value)
			{
				if (value.Size() > this->size)
					throw std::bad_function_call("target array is larger than destination array");

				unsigned int index = 0;
				for (DynamicArray<DataType>::const_iterator i = value.begin(); i != value.end(); i++)
				{
					this->data[index] = *i;
					++index;
				}
			}
			
			
		public:
			DynamicArray() = default;

			virtual ~DynamicArray() = default;

			DynamicArray(unsigned int arraySize)
			{
				this->data = std::make_unique<DataType[]>(size);
				this->size = arraySize;
			}

			DynamicArray(const DynamicArray &value) : data(std::make_unique<DataType[]>(value.Size())), size(value.Size())
			{
				CopyData(value);
			}
			DynamicArray(DynamicArray &&value) : data(std::move(value.Data())), size(value.Size())
			{

			}
			DynamicArray &operator=(DynamicArray && value)
			{
				if (this == &value)
					return *this;
				
				this->data = std::move(value.Data());
				this->size = value.Size();

				return *this;
			}
			DynamicArray& operator=(const DynamicArray& value)
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

			std::unique_ptr<DataType[]> Data() const {
				return data;
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
				iterator(pointer ptr) : ptr_(ptr) { }
				self_type operator++() { ptr_++; return *this; }
				self_type operator++(int junk) { self_type i = *this; ptr_++; return i; }
				reference operator*() { return *ptr_; }
				pointer operator->() { return ptr_; }
				bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
				bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
			private:
				pointer ptr_;
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
				const_iterator(pointer ptr) : ptr_(ptr) { }
				self_type operator++() { ptr_++; return *this; }
				self_type operator++(int junk) {  self_type i = *this; ptr_++; return i; }
				const value_type& const_iterator::operator*()  { return *ptr_; }
				const value_type* const_iterator::operator->() { return ptr_; }
				bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
				bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
			private:
				pointer ptr_;
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

			iterator begin()
			{
				return iterator(data.get());
			}

			iterator end()
			{
				return iterator(data.get() + size);
			}

			const_iterator begin() const
			{
				return const_iterator(data.get());
			}

			const_iterator end() const
			{
				return const_iterator(data.get() + size);
			}
			
		};

	};

};

#endif