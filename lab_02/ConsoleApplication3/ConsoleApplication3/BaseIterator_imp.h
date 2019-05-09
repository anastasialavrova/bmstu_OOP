#ifndef BASE_ITERATOR_IMP_H_INCLUDED
#define BASE_ITERATOR_IMP_H_INCLUDED

#include "BaseIterator.h"

namespace sset_iter {
	template<typename ValueType>
	base_iterator<ValueType>::base_iterator(const base_iterator &iter)
	{
		this->ptr = iter.ptr;
	}

	template<typename ValueType>
	base_iterator<ValueType>::base_iterator(ValueType *ptr)
	{
		this->ptr = ptr;
	}

	template<typename ValueType>
	base_iterator<ValueType>::~base_iterator()
	{
		this->ptr = nullptr;
	}

	template<typename ValueType>
	base_iterator<ValueType> &base_iterator<ValueType>::operator =(const base_iterator &iter)
	{
		if (this != &iter)
		{
			this->ptr = iter.ptr;
		}
		return *this;
	}

	template<typename ValueType>
	base_iterator<ValueType> &base_iterator<ValueType>::operator ++()
	{
		++this->ptr;

		return *this;
	}

	template<typename ValueType>
	base_iterator<ValueType> base_iterator<ValueType>::operator ++(int)
	{
		base_iterator temp = (*this);
		this->operator ++();

		return temp;
	}

	template<typename ValueType>
	base_iterator<ValueType>& base_iterator<ValueType>::operator --()
	{
		--this->ptr;

		return *this;
	}

	template<typename ValueType>
	base_iterator<ValueType> base_iterator<ValueType>::operator --(int)
	{
		base_iterator temp = (*this);
		this->operator --();

		return temp;
	}


	template<typename ValueType>
	bool base_iterator<ValueType>::operator ==(const base_iterator& iter)
	{
		return this->ptr == iter.ptr;
	}

	template<typename ValueType>
	bool base_iterator<ValueType>::operator !=(const base_iterator& iter)
	{
		return this->ptr != iter.ptr;
	}
}

#endif