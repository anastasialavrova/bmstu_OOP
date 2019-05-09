#ifndef SOK_SET_IMP_H_INCLUDED
#define SOK_SET_IMP_H_INCLUDED

#include "SokSet.h"

namespace sset {
	template<typename T>
	Set<T>::Set() :base_container()
	{
		size = 0;
		element_count = 0;
		mul_par = 2;
		els = nullptr;
	}

	template<typename T>
	Set<T>::Set(unsigned int num, ...)
	{
		va_list arg;
		va_start(arg, num);
		this->element_count = 0;
		this->mul_par = 2;
		this->size = num;

		try
		{
			std::shared_ptr<T> sp(new T[num]);
			els = sp;
		}
		catch (std::bad_alloc)
		{
			throw set_memory_error();
		}

		T elem;
		for (; num; --num)
		{
			elem = va_arg(arg, T);
			this->add_elem(elem);
		}

		va_end(arg);
	}

	template<typename T>
	Set<T>::Set(const T *arr, size_t num)
	{
		this->size = num;
		this->element_count = 0;
		this->mul_par = 2;
		try
		{
			std::shared_ptr<T> sp(new T[num]);
			els = sp;
		}
		catch (std::bad_alloc)
		{
			throw set_memory_error();
		}

		for (unsigned int i = 0; i < num; i++)
			this->add_elem(arr[i]);
	}

	template<typename T>
	Set<T>::Set(std::initializer_list<T> lst) :base_container()
	{
		this->size = 0;
		this->element_count = 0;
		this->mul_par = 2;
		this->els = nullptr;
		auto iter = lst.begin();

		for (; iter != lst.end(); ++iter)
		{
			this->add_elem(*iter);
		}
	}

	template<typename T>
	Set<T>::Set(const T& elem)
	{
		this->size = 0;
		this->element_count = 0;
		this->mul_par = 2;
		this->els = nullptr;
		this->add_elem(elem);
	}

	template<typename T>
	Set<T>& Set<T>::operator =(const Set<T>& s)
	{
		if (this != &s)
		{
			this->size = s.size;
			this->element_count = s.get_element_count();
			this->mul_par = 2;
			try
			{
				els.reset();
				std::shared_ptr<T> sp(new T[size]);
				els = sp;
			}
			catch (std::bad_alloc)
			{
				throw set_memory_error();
			}

			for (unsigned int i = 0; i < this->get_element_count(); i++)
				this->els.get()[i] = s.els.get()[i];
		}
		return *this;
	}

	template<typename T>
	Set<T>& Set<T>::operator =(const Set<T>&& s)
	{
		if (this != &s)
		{
			this->size = s.size;
			this->element_count = s.get_element_count();
			this->mul_par = 2;
			try
			{
				els.reset();
				std::shared_ptr<T> sp(new T[size]);
				els = sp;
			}
			catch (std::bad_alloc)
			{
				throw set_memory_error();
			}

			for (unsigned int i = 0; i < this->get_element_count(); i++)
				this->els.get()[i] = s.els.get()[i];
		}
		return *this;
	}

	template<typename T>
	Set<T>::Set(const Set<T>& s)
	{
		this->size = s.size;
		this->element_count = s.get_element_count();
		this->mul_par = 2;
		try
		{
			//this->els = new T[this->size];
			std::shared_ptr<T> sp(new T[this->size]);
			els = sp;
		}
		catch (std::bad_alloc)
		{
			throw set_memory_error();
		}

		for (size_t i = 0; i < this->size; i++)
		{
			this->els.get()[i] = s.els.get()[i];
		}
	}

	template<typename T>
	Set<T>::Set(const Set<T>&& s)
	{
		this->size = s.size;
		this->element_count = s.get_element_count();
		this->mul_par = 2;
		try
		{
			//this->els = new T[this->size];
			std::shared_ptr<T> sp(new T[this->size]);
			els = sp;
		}
		catch (std::bad_alloc)
		{
			throw set_memory_error();
		}

		for (size_t i = 0; i < this->size; i++)
		{
			this->els.get()[i] = s.els.get()[i];
		}
	}

	template<typename T>
	Set<T>::~Set()
	{
		els.reset();
	}

	template<typename T>
	bool Set<T>::in_set(const T& elem) const
	{
		if (this->is_empty())
			return false;

		size_t i = 0;
		bool res = false;
		while (true)
		{
			if (res == true || i >= this->element_count)
				break;

			if (elem == this->els.get()[i])
				res = true;

			i++;
		}

		return res;
	}

	template<typename T>
	bool Set<T>::add_elem(const T& elem)
	{
		if (!this->in_set(elem))
		{
			if (this->element_count + 1 < this->size)
			{
				this->els.get()[this->element_count++] = elem;
			}
			else
			{
				std::shared_ptr<T> tmp;
				try
				{
					if (this->size == 0)
						this->size = 1;
					//tmp = new T[this->size * this->mul_par]; //
					std::shared_ptr<T> sp(new T[this->size * this->mul_par]);           ////////////////////////////////////////
					tmp = sp;
				}
				catch (std::bad_alloc)
				{
					throw set_memory_error();
				}

				this->size *= this->mul_par;

				for (size_t i = 0; i < (this->element_count); i++)
				{
					tmp.get()[i] = this->els.get()[i];
				}

				tmp.get()[this->element_count] = elem;
				els.reset(); //els.reset()
				els = tmp;
				this->element_count++;
			}
			return true;
		}
		return false;
	}

	template<typename T>
	bool Set<T>::remove_elem(const T& elem)
	{
		if (this->in_set(elem))
		{
			size_t tmp = 0;
			for (int i = this->get_element_count() - 1; i >= 0; i--)
			{
				if (this->els.get()[i] == elem) //
					tmp = i;
			}
			this->els.get()[tmp] = this->els.get()[this->get_element_count() - 1];
			this->element_count--;
			return true;
		}
		return false;
	}

	// this = s1 or this
	template<typename T>
	Set<T>& Set<T>::set_union(const Set<T>& s1)
	{
		for (size_t i = 0; i < s1.get_element_count(); i++)
			this->add_elem(s1.els.get()[i]);

		return *this;
	}

	// this = this without s1
	template<typename T>
	Set<T>& Set<T>::set_difference(const Set<T>& s1)
	{
		for (size_t i = 0; i < this->get_element_count(); i++)
		{
			if (s1.in_set(this->els.get()[i]))
				this->remove_elem(this->els.get()[i]);
		}

		return *this;
	}

	// this = this and s1
	template<typename T>
	Set<T>& Set<T>::set_crossing(const Set<T>& s1)
	{
		for (size_t i = 0; i < this->get_element_count(); i++)
		{
			if (!s1.in_set(this->els.get()[i]))
				this->remove_elem(this->els.get()[i]);
		}

		return *this;
	}

	// this = this <> s1
	template<typename T>
	Set<T>& Set<T>::set_sym_diff(const Set<T>& s1)
	{
		*this = (*this / s1) + (s1 / *this);
		return (*this);
	}

	template<typename T>
	Set<T>& Set<T>::operator +=(const Set<T>& s2)
	{
		this->set_union(s2);
		return *this;
	}

	template<typename T>
	Set<T>& Set<T>::operator |=(const Set<T>& s2)
	{
		this->set_union(s2);
		return *this;
	}

	template<typename T>
	Set<T> operator +(const Set<T>& left, const Set<T>& right)
	{
		Set<T> res = Set<T>(left);
		res.set_union(right);
		return res;
	}

	template<typename T>
	Set<T> operator |(const Set<T>& left, const Set<T>& right)
	{
		Set<T> res = Set<T>(left);
		res.set_union(right);
		return res;
	}

	template<typename T> // �������� ���������, �����������
	Set<T> operator *(const Set<T>& left, const Set<T>& right)
	{
		Set<T> res = Set<T>(left);
		res.set_crossing(right);
		return res;
	}

	template<typename T> // ��������� �, �����������
	Set<T> operator &(const Set<T>& left, const Set<T>& right)
	{
		Set<T> res = Set<T>(left);
		res.set_crossing(right);
		return res;
	}

	template<typename T>
	Set<T>& Set<T>::operator *=(const Set<T>& s2)
	{
		this->set_crossing(s2);
		return *this;
	}

	template<typename T>
	Set<T>& Set<T>::operator &=(const Set<T>& s2)
	{
		this->set_crossing(s2);
		return *this;
	}

	// �������� �����, ��������
	template<typename T>
	Set<T> operator -(const Set<T>& left, const Set<T>& right)
	{
		Set<T> res = Set<T>(left);
		res.set_difference(right);
		return res;
	}

	// �������� �������, ��������
	template<typename T>
	Set<T> operator /(const Set<T>& left, const Set<T>& right)
	{
		Set<T> res = Set<T>(left);
		res.set_difference(right);
		return res;
	}

	template<typename T>
	Set<T>& Set<T>::operator -=(const Set<T>& s2)
	{
		this->set_difference(s2);
		return *this;
	}

	template<typename T>
	Set<T>& Set<T>::operator /=(const Set<T>& s2)
	{
		this->set_difference(s2);
		return *this;
	}

	// �������� ������� �� �������, �������������� ��������
	template<typename T>
	Set<T> operator %(const Set<T>& left, const Set<T>& right)
	{
		Set<T> res = Set<T>(left);
		res.set_sym_diff(right);
		return res;
	}

	// ��������� ����������� ���, �������������� ��������
	template<typename T>
	Set<T> operator ^(const Set<T>& left, const Set<T>& right)
	{
		Set<T> res = Set<T>(left);
		res.set_sym_diff(right);
		return res;
	}

	template<typename T>
	Set<T>& Set<T>::operator %=(const Set<T>& s2)
	{
		this->set_sym_diff(s2);
		return *this;
	}

	template<typename T>
	Set<T>& Set<T>::operator ^=(const Set<T>& s2)
	{
		this->set_sym_diff(s2);
		return *this;
	}

	template<typename T>
	bool Set<T>::is_subsetof(const Set<T>& s1) const
	{
		if (this->is_empty())
			return true;

		size_t i = 0;
		bool res = true;
		while (true)
		{
			if (res == false || i >= this->element_count)
				break;

			if (!s1.in_set(this->els[i]))
				res = false;

			i++;
		}

		return res;
	}

	template<typename T>
	bool Set<T>::contains(const Set<T>& s1) const
	{
		if (this->is_empty())
			return false;

		return s1.is_subsetof(*this);
	}

	template<typename T>
	bool operator >=(const Set<T>& s1, const Set<T>& s2)
	{
		return s2.is_subsetof(s1);
	}

	template<typename T>
	bool operator <=(const Set<T>& s1, const Set<T>& s2)
	{
		return s1.is_subsetof(s2);
	}

	template<typename T>
	bool operator ==(const Set<T>& s1, const Set<T>& s2)
	{
		return s1.is_subsetof(s2) && s2.is_subsetof(s1);
	}

	template<typename T>
	bool operator !=(const Set<T>& s1, const Set<T>& s2)
	{
		return !(s1.is_subsetof(s2) && s2.is_subsetof(s1));
	}

	template<typename T>
	bool operator >(const Set<T>& s1, const Set<T>& s2)
	{
		return s2.is_subsetof(s1) && !s1.is_subsetof(s2);
	}

	template<typename T>
	bool operator <(const Set<T>& s1, const Set<T>& s2)
	{
		return s1.is_subsetof(s2) && !s2.is_subsetof(s1);
	}

	template<typename T>
	ostream& operator <<(ostream& os, const Set<T>& s)
	{
		os << "{";
		for (size_t i = 0; i < s.get_element_count(); i++)
			os << " " << s.els.get()[i];
		os << " }" << std::endl;
		return os;
	}
}

#endif // SOK_SET_IMP_H_INCLUDED
