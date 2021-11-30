#pragma once

#include "externals.hpp"
#include "ft.hpp"

template <class Iterator>
struct	ft::iterator_traits
{
	
};

template <class T>
struct	ft::iterator_traits<ft::base_iterator<ft::random_access_iterator_tag, T> >
{
	typedef	typename base_iterator<random_access_iterator_tag, T>::difference_type		difference_type;
	typedef	typename base_iterator<random_access_iterator_tag, T>::value_type			value_type;
	typedef	typename base_iterator<random_access_iterator_tag, T>::pointer				pointer;
	typedef	typename base_iterator<random_access_iterator_tag, T>::reference			reference;
	typedef	typename base_iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
};

template <class T>
struct	ft::iterator_traits<ft::base_iterator<ft::bidirectional_iterator_tag, T> >
{
	typedef	typename base_iterator<bidirectional_iterator_tag, T>::difference_type		difference_type;
	typedef	typename base_iterator<bidirectional_iterator_tag, T>::value_type			value_type;
	typedef	typename base_iterator<bidirectional_iterator_tag, T>::pointer				pointer;
	typedef	typename base_iterator<bidirectional_iterator_tag, T>::reference			reference;
	typedef	typename base_iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
};

template <class T>
struct	ft::iterator_traits<T*>
{
	// typedef	ptrdiff_t					difference_type;
	typedef	long						difference_type;
	typedef	T							value_type;
	typedef	T*							pointer;
	typedef	T&							reference;
	typedef	random_access_iterator_tag	iterator_category;
};

template <class T>
struct	ft::iterator_traits<const T*>
{
	// typedef	ptrdiff_t					difference_type;
	typedef	long						difference_type;
	typedef	T							value_type;
	typedef	const T*					pointer;
	typedef const T&					reference;
	typedef	random_access_iterator_tag	iterator_category;
};
