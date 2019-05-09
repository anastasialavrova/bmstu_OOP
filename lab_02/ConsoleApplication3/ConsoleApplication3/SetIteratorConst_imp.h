#ifndef SET_ITERATOR_CONST_IMP_H_INCLUDED
#define SET_ITERATOR_CONST_IMP_H_INCLUDED

#include "SetIteratorConst.h"

namespace sset_iter {

	template<typename ValueType>
	const ValueType& SetIteratorConst<ValueType>::operator *() const
	{
		return *(this->ptr);
	}

	template<typename ValueType>
	const ValueType* SetIteratorConst<ValueType>::operator ->() const
	{
		return this->ptr;
	}

	template<typename ValueType>
	SetIteratorConst<ValueType>::SetIteratorConst(const SetIteratorConst &iter)
		: base_iterator(iter.ptr) {}

	template<typename ValueType>
	SetIteratorConst<ValueType>::SetIteratorConst(ValueType *ptr)
		: base_iterator(ptr) {}
}

#endif