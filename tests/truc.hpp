#pragma once

#include <memory>

struct	random_access_iterator_tag {};

template<class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>
struct base_iterator
{
	typedef T			value_type;
	typedef Distance 	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category 	iterator_category;
};

template <class T>
class	Vector
{
	public :

	class iterator : public base_iterator<random_access_iterator_tag, T>
	{
		
	};
};