#ifndef BASE_CONTAINER_IMP_H_INCLUDED
#define BASE_CONTAINER_IMP_H_INCLUDED

#include "BaseContainer.h"

using namespace sset_base;

base_container::base_container() : element_count(0) {}

base_container::~base_container()
{
	this->element_count = 0;
}

bool base_container::is_empty() const
{
	return this->element_count == 0;
}

size_t base_container::get_element_count() const
{
	return this->element_count;
}

#endif // BASE_CONTAINER_H_INCLUDED
