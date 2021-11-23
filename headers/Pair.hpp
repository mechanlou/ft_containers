#pragma once
#include "ft.hpp"

template <class T1, class T2>
struct	ft::pair
{
// types
	typedef	T1	first_type;
	typedef	T2	second_type;

// variables
	first_type first;
	second_type second;

// constructors
	pair(void) : first(), second() {}
	template<class U, class V>
	pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
	pair(const first_type& a, const second_type& b) : first(a), second(b) {}

// functions
	pair	&operator=(const pair &pr)
	{
		first = pr.first;
		second = pr.second;
		return (*this);
	}
};

namespace	ft
{
	template <class T1, class T2>
	bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first == rhs.first && lhs.second == rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs == rhs); }

	template <class T1, class T2>
	bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

	template <class T1, class T2>
	bool	operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs < lhs); }

	template <class T1, class T2>
	bool	operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs < lhs; }

	template <class T1, class T2>
	bool	operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs < rhs); }
}

template <class T1, class T2>
ft::pair<T1,T2>	ft::make_pair(T1 x, T2 y)
{
    return (ft::pair<T1,T2>(x, y));
}