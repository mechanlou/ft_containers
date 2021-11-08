#pragma once

#include "externals.hpp"
#include "Base_iterator.hpp"
#include "Is_integral.hpp"
#include "ft.hpp"

#define CAPACITY_SCALE 3

template <typename T, class Alloc>
class	ft::vector
{
	public:

	typedef				T									value_type;
	typedef				Alloc								allocator_type;
	typedef	typename	allocator_type::reference			reference;
	typedef	typename	allocator_type::const_reference		const_reference;
	typedef	typename	allocator_type::pointer				pointer;
	typedef	typename	allocator_type::const_pointer		const_pointer;
	typedef				size_t								size_type;

//constructors
	//default
	explicit vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(5)
	{
		_data = allocator_type(alloc).allocate(_capacity, 0);
	}
	//range
	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _allocator(alloc)
	{
		_range_fill_constructor(first, last, alloc, typename ft::is_integral<InputIterator>::type());
	}
	//fill	
	explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(n), _capacity(CAPACITY_SCALE * _size)
	{
		size_t	i;

		_data = allocator_type(alloc).allocate(_capacity, 0);
		i = 0;
		while (i < _size)
			_data[i++] = val;
	}
	//copy
	// vector(const vector& x);
//destructor
	virtual		~vector(void)
	{
		allocator_type().deallocate(_data, _capacity);
	}

//iterator
	class	iterator : public base_iterator<random_access_iterator_tag, T>
	{
		public :

		iterator(void) {}
		iterator(T *src) : _data(src) {}
		iterator(iterator const &src) : _data(src._data) {}
		virtual	~iterator(void) {}

		iterator	&operator=(iterator const &src)
		{
			_data = src._data;
			return (*this);
		}
		bool		operator==(iterator const &src) const
		{
			return (_data == src._data);
		}
		bool		operator!=(iterator const &src) const
		{
			return (_data != src._data);
		}
		T			&operator*(void)
		{
			return (*_data);
		}
		T const		&operator*(void) const
		{
			return (*_data);
		}
		T			*operator->(void)
		{
			return (_data);
		}
		T const		*operator->() const
		{
			return (_data);
		}
		iterator	&operator++() //prefix
		{
			_data++;
			return (*this);
		}
		iterator	operator++(int) //postfix
		{
			iterator	copy(*this);
			_data++;
			return (copy);
		}
		iterator	&operator--() //prefix
		{
			_data--;
			return (*this);
		}
		iterator	operator--(int) //postfix
		{
			iterator	copy(*this);
			_data--;
			return (copy);
		}
		iterator	operator+(typename base_iterator<random_access_iterator_tag, T>::difference_type const &len) const
		{
			iterator	result;

			result._data = _data + len;
			return (result);
		}
		typename base_iterator<random_access_iterator_tag, T>::difference_type	operator-(iterator const &other) const
		{
			typename base_iterator<random_access_iterator_tag, T>::difference_type	diff;

			diff = _data - other._data;
			return (diff);
		}
		iterator	operator-(typename base_iterator<random_access_iterator_tag, T>::difference_type const &n) const
		{
			iterator	result;

			result._data = _data - n;
			return (result);
		}
		bool		operator<(iterator const &other) const
		{
			return (_data < other._data);
		}
		bool		operator>(iterator const &other) const
		{
			return (_data > other._data);
		}
		bool		operator<=(iterator const &other) const
		{
			return (_data <= other._data);
		}
		bool		operator>=(iterator const &other) const
		{
			return (_data >= other._data);
		}
		iterator	&operator+=(typename base_iterator<random_access_iterator_tag, T>::difference_type const &n)
		{
			_data += n;
			return (*this);
		}
		iterator	&operator-=(typename base_iterator<random_access_iterator_tag, T>::difference_type const &n)
		{
			_data -= n;
			return (*this);
		}
		T			&operator[](typename base_iterator<random_access_iterator_tag, T>::difference_type const &n)
		{
			return (_data[n]);
		}

		private :

		T *_data;
	};

	class	const_iterator : public base_iterator<random_access_iterator_tag, const T>
	{
		public :

		const_iterator(void) {}
		const_iterator(T const *src) : _data(src) {}
		const_iterator(const_iterator const &src) : _data(src._data) {}
		virtual	~const_iterator(void) {}

		const_iterator	&operator=(const_iterator const &src)
		{
			_data = src._data;
			return (*this);
		}
		bool			operator==(const_iterator const &src) const
		{
			return (_data == src._data);
		}
		bool			operator!=(const_iterator const &src) const
		{
			return (_data != src._data);
		}
		T const			&operator*(void)
		{
			return (*_data);
		}
		T const			&operator*(void) const
		{
			return (*_data);
		}
		T const			*operator->(void)
		{
			return (_data);
		}
		T const			*operator->() const
		{
			return (_data);
		}
		const_iterator	&operator++() //prefix
		{
			_data++;
			return (*this);
		}
		const_iterator	operator++(int) //postfix
		{
			const_iterator	copy(*this);
			_data++;
			return (copy);
		}
		const_iterator	&operator--() //prefix
		{
			_data--;
			return (*this);
		}
		const_iterator	operator--(int) //postfix
		{
			const_iterator	copy(*this);
			_data--;
			return (copy);
		}
		const_iterator	operator+(typename base_iterator<random_access_iterator_tag, T>::difference_type const &len) const
		{
			const_iterator	result;

			result._data = _data + len;
			return (result);
		}
		typename base_iterator<random_access_iterator_tag, T>::difference_type	operator-(const_iterator const &other) const
		{
			typename base_iterator<random_access_iterator_tag, T>::difference_type	diff;

			diff = _data - other._data;
			return (diff);
		}
		const_iterator	operator-(typename base_iterator<random_access_iterator_tag, T>::difference_type const &n) const
		{
			const_iterator	result;

			result._data = _data - n;
			return (result);
		}
		bool			operator<(const_iterator const &other) const
		{
			return (_data < other._data);
		}
		bool			operator>(const_iterator const &other) const
		{
			return (_data > other._data);
		}
		bool			operator<=(const_iterator const &other) const
		{
			return (_data <= other._data);
		}
		bool			operator>=(const_iterator const &other) const
		{
			return (_data >= other._data);
		}
		const_iterator	&operator+=(typename base_iterator<random_access_iterator_tag, T>::difference_type const &n)
		{
			_data += n;
			return (*this);
		}
		const_iterator	&operator-=(typename base_iterator<random_access_iterator_tag, T>::difference_type const &n)
		{
			_data -= n;
			return (*this);
		}
		T const 		&operator[](typename base_iterator<random_access_iterator_tag, T>::difference_type const &n)
		{
			return (_data[n]);
		}

		private :

		T const	*_data;
	};

//typedef for reverse_iterator
	typedef	ft::reverse_iterator<iterator>			reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

//iterator functions
	const_iterator	begin(void)	const
	{
		return (const_iterator(_data));
	}
	const_iterator	end(void) const
	{
		return (const_iterator(_data + _size));
	}
	iterator		begin(void)
	{
		return	(iterator(_data));
	}
	iterator		end(void)
	{
		return (iterator(_data + _size));
	}

	const_reverse_iterator	rbegin(void) const
	{
		return (const_reverse_iterator(end()));
	}
	const_reverse_iterator	rend(void) const
	{
		return (const_reverse_iterator(begin()));
	}
	reverse_iterator		rbegin(void)
	{
		return (reverse_iterator(end()));
	}
	reverse_iterator		rend(void)
	{
		return (reverse_iterator(begin()));
	}

	allocator_type	_allocator;
	size_type		_size;
	size_type		_capacity;
	value_type		*_data;

	private:

	template <class InputIterator>
	void	_range_fill_constructor(InputIterator &first, const InputIterator &last, const allocator_type& alloc, void *)
	{
		size_t	i;

		_size = last - first;
		_capacity = CAPACITY_SCALE * _size;
		_data = allocator_type(alloc).allocate(_capacity, 0);
		i = 0;
		while (i < _size)
			_data[i++] = *(first++);
	}
	template <class InputIterator>
	void	_range_fill_constructor(InputIterator &n, const InputIterator &val, const allocator_type &alloc, int)
	{
		size_t	i;

		_size = n;
		_capacity = CAPACITY_SCALE * _size;
		_data = allocator_type(alloc).allocate(_capacity, 0);
		i = 0;
		while (i < _size)
			_data[i++] = val;
	}
};