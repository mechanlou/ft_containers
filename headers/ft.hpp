#pragma once

#include "externals.hpp"

namespace	ft
{
	struct		random_access_iterator_tag {};
	struct		bidirectional_iterator_tag {};
	template <typename T, class Alloc = std::allocator<T> > class	vector;
	template<class Category, class T, class Distance = long,
		class Pointer = T*, class Reference = T&> struct 	base_iterator;
	template <class iterator> class	reverse_iterator;
	template <class T> struct 		iterator_traits;
	template <class T> struct 		iterator_traits<T*>;
	template <class T> struct 		iterator_traits<const T*>;
	template <class T> struct		iterator_traits<base_iterator<random_access_iterator_tag, T> >;
	template <class T> struct		iterator_traits<base_iterator<bidirectional_iterator_tag, T> >;
	template <class iterator> struct					iterator_traits< reverse_iterator<iterator> >;
	template <class T1, class T2> struct pair;
	template <class T1, class T2> pair<T1,T2>	make_pair(T1 x, T2 y);
	template < class Key, class T, class Compare = std::less<Key>,
		class Alloc = std::allocator<pair<const Key,T> > > class map;
	template <class T, class Container = vector<T> > class stack;

// enable_if
	template<bool Cond, class T> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };
}
