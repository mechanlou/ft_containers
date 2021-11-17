#pragma once

#include "externals.hpp"

namespace	ft
{
	struct												random_access_iterator_tag {};
	template <typename T, class Alloc = std::allocator<T> > class	vector;
	template<class Category, class T, class Distance = long,
	class Pointer = T*, class Reference = T&> struct 	base_iterator;
	template <class iterator> class	reverse_iterator;
	template <class T> struct 		iterator_traits;
	template <class T> struct 		iterator_traits<T*>;
	template <class T> struct 		iterator_traits<const T*>;
	template <class T> struct		iterator_traits<base_iterator<random_access_iterator_tag, T> >;
	template <class iterator> struct					iterator_traits< reverse_iterator<iterator> >;
// enable_if
	template<bool Cond, class T> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };
}
