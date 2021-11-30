#pragma once

#include "externals.hpp"

namespace	ft
{
// iterator stuff
	struct		random_access_iterator_tag {};
	struct		bidirectional_iterator_tag {};
	template<class Category, class T, class Distance = long,
		class Pointer = T*, class Reference = T&> struct 	base_iterator;
	template <class iterator> class	reverse_iterator;

// iterator_traits
	template <class T> struct 		iterator_traits;
	template <class T> struct 		iterator_traits<T*>;
	template <class T> struct 		iterator_traits<const T*>;
	template <class T> struct		iterator_traits<base_iterator<random_access_iterator_tag, T> >;
	template <class T> struct		iterator_traits<base_iterator<bidirectional_iterator_tag, T> >;
	template <class iterator> struct	iterator_traits< reverse_iterator<iterator> >;

// pair
	template <class T1, class T2> struct pair;
	template <class T1, class T2> pair<T1,T2>	make_pair(T1 x, T2 y);

// equal 
	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2);
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool	equal(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, BinaryPredicate pred);

// lexicographical compare
	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2);
	template <class InputIterator1, class InputIterator2, class Compare>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2,
									Compare comp);

// enable_if
	template<bool Cond, class T> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

// containers
	template <typename T, class Alloc = std::allocator<T> > class	vector;
	template < class Key, class T, class Compare = std::less<Key>,
		class Alloc = std::allocator<pair<const Key,T> > > class 	map;
	template <class T, class Container = vector<T> > class 			stack;
}
