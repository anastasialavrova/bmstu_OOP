#ifndef MY_SET_H_INCLUDED
#define MY_SET_H_INCLUDED

#include "BaseContainer.h"
#include "ClassIter.h"
#include "SetExceptions.h"
#include <iostream>
#include <stdarg.h>
#include <memory>

using namespace std;
//using namespace sset_iter;

namespace sset {
	template<typename T>
	class Set : public sset_base::base_container
	{
	public:
		friend class Iterator<T>;

		Set();
		Set(unsigned int num, ...);
		Set(const T *arr, size_t num);
		Set(std::initializer_list<T> lst);

		Set(const T& elem);
		explicit Set(const Set<T>& s);
		Set(const Set<T>&& s);

		Set<T>& operator =(const Set<T>& s);                                    // копирование
		Set<T>& operator =(const Set<T>&& s);

		virtual ~Set();

		bool in_set(const T& elem) const;
		bool add_elem(const T& elem);
		bool remove_elem(const T& elem);


		// Объединение
		Set<T>& set_union(const Set<T>& s1);									// this = s1 or this
		Set<T>& operator +=(const Set<T>& s2);
		Set<T>& operator |=(const Set<T>& s2);
		template<typename T>
		friend Set<T> operator +(const Set<T>& left, const Set<T>& right);	    // Бинарный плюс
		template<typename T>
		friend Set<T> operator |(const Set<T>& left, const Set<T>& right);	    // Побитовое ИЛИ


		// Разность																	
		Set<T>& set_difference(const Set<T>& s1);								// this = this without s1
		Set<T>& operator -=(const Set<T>& s2);
		Set<T>& operator /=(const Set<T>& s2);
		template<typename T>                                                    // ???
		friend Set<T> operator -(const Set<T>& left, const Set<T>& right);	    // Бинарный минус
		template<typename T>
		friend Set<T> operator /(const Set<T>& left, const Set<T>& right);      // Бинарное деление


		// Пересечение																	
		Set<T>& set_crossing(const Set<T>& s1);								   // this = this and s1
		Set<T>& operator *=(const Set<T>& s2);
		Set<T>& operator &=(const Set<T>& s2);
		template<typename T>
		friend Set<T> operator *(const Set<T>& left, const Set<T>& right);     // Бинарное умножение
		template<typename T>
		friend Set<T> operator &(const Set<T>& left, const Set<T>& right);     // Побитовое И


		// Симметрическая разность																	
		Set<T>& set_sym_diff(const Set<T>& s1);								   // this = this <> s1
		Set<T>& operator %=(const Set<T>& s2);
		Set<T>& operator ^=(const Set<T>& s2);
		template<typename T>
		friend Set<T> operator %(const Set<T>& left, const Set<T>& right);     //Бинарный остаток от деления
		template<typename T>
		friend Set<T> operator ^(const Set<T>& left, const Set<T>& right);	   //Побитовое Исключающее ИЛИ


		// Операции сравнения																	
		bool is_subsetof(const Set<T>& s1) const;							   // this is subset of s1
		bool contains(const Set<T>& s1) const;								   // this contains s1 or s1 is subset of this

		template<typename T>
		friend bool operator >=(const Set<T>& s1, const Set<T>& s2);
		template<typename T>
		friend bool operator <=(const Set<T>& s1, const Set<T>& s2);
		template<typename T>
		friend bool operator ==(const Set<T>& s1, const Set<T>& s2);
		template<typename T>
		friend bool operator !=(const Set<T>& s1, const Set<T>& s2);
		template<typename T>
		friend bool operator >(const Set<T>& s1, const Set<T>& s2);
		template<typename T>
		friend bool operator <(const Set<T>& s1, const Set<T>& s2);


		// Потоковый вывод
		template<typename T>
		friend ostream& operator <<(ostream& os, const Set<T>& s);


	private:
		size_t size;	                                                   // allocated size
		size_t mul_par;
		std::shared_ptr<T> els;                                            // ???  shared_ptr<T>
	};
}

#include "SokSet_imp.h"

#endif // MY_SET_H_INCLUDED
