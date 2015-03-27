#ifndef Globals_ExtendedDynamicTypeArray_H
#define Globals_ExtendedDynamicTypeArray_H

#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include "DynamicTypeArray.h"

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
		class ExtendedDynamicTypeArray
		{
		private:
			std::unique_ptr<DataType[]> data;
			unsigned int size = 0;
			std::shared_ptr<std::vector<unsigned int>> disabledArrayElementsIndex;

		public:
			ExtendedDynamicTypeArray() = default;

			virtual ~ExtendedDynamicTypeArray() = default;

			ExtendedDynamicTypeArray(unsigned int arraySize)
			{
				this->data = std::make_unique<DataType[]>(arraySize);
				this->size = arraySize;
				this->disabledArrayElementsIndex = std::make_shared<std::vector<unsigned int>>();
			}

			ExtendedDynamicTypeArray(const ExtendedDynamicTypeArray &value) : data(std::make_unique<ArrayItemStatus[]>(value.Size())), size(value.Size())
			{
				CopyData(value);
			}
			ExtendedDynamicTypeArray(ExtendedDynamicTypeArray &&value) : data(std::move(value.Data())), size(value.Size())
			{

			}
			ExtendedDynamicTypeArray &operator=(ExtendedDynamicTypeArray && value)
			{
				if (this == &value)
					return *this;

				this->data = std::move(value.Data());
				this->size = value.Size();

				return *this;
			}

			ExtendedDynamicTypeArray& operator=(const ExtendedDynamicTypeArray& value)
			{
				if (this == &value)
					return *this;

				CopyData(value);
				this->size = value.Size();

				return *this;
			}

			unsigned int Size() const {
				return this->size;
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
				iterator(pointer ptr, std::vector<unsigned int> &disabledArrayElementsIndex, unsigned int size, unsigned int startLocation) : ptr_(ptr), disabledArrayElementsIndex(disabledArrayElementsIndex), size(size), iteratorLocation(startLocation) { }
				self_type operator++() { 
					unsigned int currentIteratorLocation = iteratorLocation;
					iteratorLocation = DynamicTypeArrayHelper::GetNextActiveElementFromPosition(iteratorLocation, size, disabledArrayElementsIndex);
					ptr_ = ptr_ + (iteratorLocation - currentIteratorLocation);
					return *this;
				}
				self_type operator++(int junk) { 
					self_type i = *this; 
					unsigned int currentIteratorLocation = iteratorLocation;
					iteratorLocation = DynamicTypeArrayHelper::GetNextActiveElementFromPosition(iteratorLocation, size, disabledArrayElementsIndex);
					ptr_ = ptr_ + (iteratorLocation - currentIteratorLocation);
					return i; }

				self_type operator--() {
					unsigned int currentIteratorLocation = iteratorLocation;
					iteratorLocation = DynamicTypeArrayHelper::GetPreviousActiveElementFromPosition(iteratorLocation, size, disabledArrayElementsIndex);
					ptr_ = ptr_ - (currentIteratorLocation - iteratorLocation);
					return *this;
				}
				self_type operator--(int junk) {
					self_type i = *this;
					unsigned int currentIteratorLocation = iteratorLocation;
					iteratorLocation = DynamicTypeArrayHelper::GetPreviousActiveElementFromPosition(iteratorLocation, size, disabledArrayElementsIndex);
					ptr_ = ptr_ - (currentIteratorLocation - iteratorLocation);
					return i;
				}

				reference operator*() { return *ptr_; }
				pointer operator->() { return ptr_; }
				bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
				bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
				int IteratorLocation() const {
					return iteratorLocation;
				}
			private:
				
				pointer ptr_;
				unsigned int iteratorLocation = 0;
				unsigned int size;
				std::vector<unsigned int> &disabledArrayElementsIndex;
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
				const_iterator(pointer ptr, std::vector<unsigned int> &disabledArrayElementsIndex, unsigned int size, unsigned int startLocation) : ptr_(ptr), disabledArrayElementsIndex(disabledArrayElementsIndex), size(size), iteratorLocation(startLocation){}
				self_type operator++() {
					unsigned int currentIteratorLocation = iteratorLocation;
					iteratorLocation = DynamicTypeArrayHelper::GetNextActiveElementFromPosition(iteratorLocation, size, disabledArrayElementsIndex);
					ptr_ = ptr_ + (iteratorLocation - currentIteratorLocation);
					return *this;
				}
				self_type operator++(int junk) {
					self_type i = *this;
					unsigned int currentIteratorLocation = iteratorLocation;
					iteratorLocation = DynamicTypeArrayHelper::GetNextActiveElementFromPosition(iteratorLocation, size, disabledArrayElementsIndex);
					ptr_ = ptr_ + (iteratorLocation - currentIteratorLocation);
					return i;
				}

				self_type operator--() {
					unsigned int currentIteratorLocation = iteratorLocation;
					iteratorLocation = DynamicTypeArrayHelper::GetPreviousActiveElementFromPosition(iteratorLocation, size, disabledArrayElementsIndex);
					ptr_ = ptr_ - (currentIteratorLocation - iteratorLocation);
					return *this;
				}
				self_type operator--(int junk) {
					self_type i = *this;
					unsigned int currentIteratorLocation = iteratorLocation;
					iteratorLocation = DynamicTypeArrayHelper::GetPreviousActiveElementFromPosition(iteratorLocation, size, disabledArrayElementsIndex);
					ptr_ = ptr_ - (currentIteratorLocation - iteratorLocation);
					return i;
				}
				const value_type& const_iterator::operator*()  { return *ptr_; }
				const value_type* const_iterator::operator->() { return ptr_; }
				bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
				bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
				int IteratorLocation() const {
					return iteratorLocation;
				}
			private:
				pointer ptr_;
				unsigned int iteratorLocation = 0;
				unsigned int size;
				std::vector<unsigned int> &disabledArrayElementsIndex;
				
			};

			// Notice this does not remove, only marks a location that is not to be used
			void DisableElement(unsigned int index)
			{
				if (index < size && index >= 0)
					this->disabledArrayElementsIndex->push_back(index);
			}

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
				return iterator(this->data.get(), *this->disabledArrayElementsIndex.get(), this->Size(), index);
			}

			iterator begin()
			{
				return iterator(this->data.get(), *this->disabledArrayElementsIndex.get(), this->Size(), 0); 
			}

			iterator end()
			{
				return iterator(this->data.get() + *this->Size(), this->disabledArrayElementsIndex.get(), this->Size(), this->Size() - 1);
			}

			const_iterator begin() const
			{
				return const_iterator(this->data.get(), *this->disabledArrayElementsIndex.get(), this->Size(), );
			}

			const_iterator end() const
			{
				return const_iterator(this->data.get() + *this->Size(), this->disabledArrayElementsIndex.get(), this->Size(), this->Size() - 1);
			}

		};

	};

};

#endif