#pragma once

#include "externals.hpp"
#include "Iterator_traits.hpp"

template <class iterator>
class	ft::reverse_iterator
{
	public :

//member types
	typedef iterator								iterator_type;
	typedef typename iterator::iterator_category	iterator_category;
	typedef typename iterator::value_type			value_type;
	typedef typename iterator::difference_type		difference_type;
	typedef typename iterator::pointer				pointer;
	typedef typename iterator::reference			reference;

//constructors
	reverse_iterator(void){}
	template <class Iter>
	reverse_iterator(const reverse_iterator<Iter>& rev_it)
	{
		_iterator = rev_it._iterator;
	}
	explicit reverse_iterator(iterator_type src)
	{
		_iterator = src;
	}
//destructor
	virtual	~reverse_iterator(void){}

//functions and operator overloads
	iterator_type	base(void)	const
	{
		return (_iterator);
	}
	reference	operator*(void) const
	{
		return (*(_iterator - 1));
	}
	reverse_iterator operator+(difference_type n) const
	{
		return (reverse_iterator(_iterator - n));
	}
	reverse_iterator operator-(difference_type n) const
	{
		return (reverse_iterator(_iterator + n));
	}
	reverse_iterator operator++(int) //postfix
	{
		reverse_iterator temp = *this;
		++(*this);
		return (temp);
	}
	reverse_iterator &operator++() //prefix
	{
		--_iterator;
		return (*this);
	}
	reverse_iterator &operator--()
	{
		++_iterator;
		return (*this);
	}
	reverse_iterator operator--(int)
	{
		reverse_iterator temp = *this;
		--(*this);
		return (temp);
	}
	reverse_iterator &operator+=(difference_type n)
	{
		_iterator -= n;
		return (*this);
	}
	reverse_iterator &operator-=(difference_type n)
	{
		_iterator += n;
		return (*this);
	}
	pointer			operator->() const
	{
		return &(operator*());
	}
	reference		operator[](difference_type n) const
	{
		return (*(_iterator - (n + 1)));
	}
	
	private :

	iterator_type	_iterator;
};

namespace ft
{
//relational operators
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
						const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

// const x non-const specialization
	template <class IteratorL, class IteratorR>
	bool operator==(const reverse_iterator<IteratorL>& lhs,
						const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator!=(const reverse_iterator<IteratorL>& lhs,
						const reverse_iterator<IteratorR>& rhs)
	{
		return (lhs.base()._data != rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<(const reverse_iterator<IteratorL>& lhs,
						const reverse_iterator<IteratorR>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<=(const reverse_iterator<IteratorL>& lhs,
						const reverse_iterator<IteratorR>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator> (const reverse_iterator<IteratorL>& lhs,
						const reverse_iterator<IteratorR>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator>=(const reverse_iterator<IteratorL>& lhs,
						const reverse_iterator<IteratorR>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
};
