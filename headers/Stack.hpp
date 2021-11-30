#pragma once

#include "ft.hpp"
#include "Vector.hpp"

template <class T, class Container>
class ft::stack
{
	public :

//member types
	typedef T			value_type;
	typedef Container	container_type;
	typedef size_t		size_type;

//constructor
	explicit	stack(const container_type& ctnr = container_type())
		: _container(ctnr) {}
//functions
	bool		empty(void) const
	{
		return (_container.empty());
	}
	size_type	size(void) const
	{
		return (_container.size());
	}
	value_type	&top(void)
	{
		return (_container.back());
	}
	const value_type	&top(void) const
	{
		return (_container.back());
	}
	void	push(const value_type& val)
	{
		_container.push_back(val);
	}
	void	pop(void)
	{
		_container.pop_back();
	}
	friend	bool	operator== <T, Container>(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	friend	bool	operator!= <T, Container>(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	friend	bool	operator< <T, Container>(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	friend	bool	operator<= <T, Container>(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	friend	bool	operator> <T, Container>(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	friend	bool	operator>= <T, Container>(const stack<T, Container> &lhs, const stack<T, Container> &rhs);

	private :

	container_type	_container;
};


namespace ft
{
	template <class T, class Container>
	bool	operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container == rhs._container);
	}
	template <class T, class Container>
	bool	operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container != rhs._container);
	}
	template <class T, class Container>
	bool	operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container < rhs._container);
	}
	template <class T, class Container>
	bool	operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container <= rhs._container);
	}
	template <class T, class Container>
	bool	operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container > rhs._container);
	}
	template <class T, class Container>
	bool	operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container >= rhs._container);
	}
}
