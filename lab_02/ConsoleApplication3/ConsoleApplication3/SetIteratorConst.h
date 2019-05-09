#ifndef SET_ITERATOR_CONST_H_INCLUDED
#define SET_ITERATOR_CONST_H_INCLUDED

#include "BaseIterator.h"
#include "SokSet.h"

namespace sset_iter {
	template <typename ValueType>
	class SetIteratorConst : public base_iterator<ValueType>
	{
	public:
		SetIteratorConst(const SetIteratorConst<ValueType> &);

		const ValueType &operator *() const;
		const ValueType *operator ->() const;

		SetIteratorConst(ValueType *);
	};
}

#include "SetIteratorConst_imp.h"

#endif