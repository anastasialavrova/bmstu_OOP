#ifndef BASE_CONTAINER_H_INCLUDED
#define BASE_CONTAINER_H_INCLUDED

#include <cstddef>

namespace sset_base {
	class base_container {
	public:
		explicit base_container();
		virtual ~base_container();

		bool is_empty() const;
		size_t get_element_count() const;

	protected:
		size_t element_count;
	};
}

#endif // BASE_CONTAINER_H_INCLUDED

