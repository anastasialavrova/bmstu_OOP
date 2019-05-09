#ifndef BASE_ITERATOR_H_INCLUDED
#define BASE_ITERATOR_H_INCLUDED

#include <cstddef>

namespace sset_iter {
	template<typename ValueType>
	class base_iterator
	{
	public:
		base_iterator(const base_iterator<ValueType>&);
		virtual ~base_iterator();

		base_iterator<ValueType>& operator =(const base_iterator<ValueType>&);

		base_iterator<ValueType>& operator ++();
		base_iterator<ValueType> operator ++(int);
		base_iterator<ValueType>& operator --();
		base_iterator<ValueType> operator --(int);

		bool operator ==(const base_iterator<ValueType>&);
		bool operator !=(const base_iterator<ValueType>&);

	protected:
		ValueType *ptr;

		base_iterator(ValueType*);
	};
}

#include "BaseIterator_imp.h"

#endif // BASE_ITERATOR_H