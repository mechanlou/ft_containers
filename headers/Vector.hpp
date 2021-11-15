#pragma once

#include "externals.hpp"
#include "Base_iterator.hpp"
#include "Is_integral.hpp"
#include "ft.hpp"

#define CAPACITY_SCALE 2

template <typename T, class Alloc>
class	ft::vector
{
	public:

//member types
	typedef				T									value_type;
	typedef				Alloc								allocator_type;
	typedef	typename	allocator_type::reference			reference;
	typedef	typename	allocator_type::const_reference		const_reference;
	typedef	typename	allocator_type::pointer				pointer;
	typedef	typename	allocator_type::const_pointer		const_pointer;
	typedef				size_t								size_type;

	class	iterator;
	class	const_iterator;
	typedef	ft::reverse_iterator<iterator>			reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

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
	vector(const vector& src) : _allocator(allocator_type(src._allocator)), _size(src._size), _capacity(src._capacity)
	{
		size_type	i;

		i = 0;
		_data = _allocator.allocate(_capacity);
		while (i < _size)
		{
			_data[i] = src._data[i];
			i++;
		}
	}
	//assign
	vector	&operator=(vector const &src)
	{
		size_type	i;
		
		i = 0;
		_allocator.deallocate(_data, _capacity);
		_size = src._size;
		_capacity = src._capacity;
		_data = _allocator.allocate(_capacity);
		while (i < _size)
		{
			_data[i] = src._data[i];
			i++;
		}
		return (*this);
	}


//destructor
	virtual		~vector(void)
	{
		allocator_type().deallocate(_data, _capacity);
	}

//iterator functions
	reverse_iterator		rbegin(void)
	{
		return (reverse_iterator(end()));
	}
	reverse_iterator		rend(void)
	{
		return (reverse_iterator(begin()));
	}
	const_reverse_iterator	rbegin(void) const
	{
		return (const_reverse_iterator(end()));
	}
	const_reverse_iterator	rend(void) const
	{
		return (const_reverse_iterator(begin()));
	}

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

//capacity functions
	size_type	size(void) const
	{
		return (_size);
	}
	size_type	max_size(void) const
	{
		return (_capacity);
	}
	void		resize(size_type n, value_type val = value_type())
	{
		value_type	*new_data;
		size_type	new_capacity;
		size_type	i;

		if (n > _capacity)
		{
			new_capacity = n * CAPACITY_SCALE;
			new_data = _allocator.allocate(new_capacity);
			i = 0;
			while (i < _size)
			{
				new_data[i] = _data[i];
				i++;
			}
			while (i < n)
				new_data[i++] = val;
			_allocator.deallocate(_data, _capacity);
			_data = new_data;
			_capacity = new_capacity;
		}
		else if (n > _size)
		{
			i = _size;
			while (i < n)
				_data[i++] = val;
		}
		else
		{
			i = n;
			while (i < _size)
				_data[i++].~value_type();
		}
		_size = n;
	}
	size_type	capacity(void) const
	{
		return (_capacity);
	}
	bool		empty(void) const
	{
		return (_size == 0);
	}
	void		reserve(size_type n)
	{
		value_type	*new_data;
		size_type	i;

		if (n > _capacity)
		{
			new_data = _allocator.allocate(n);
			i = 0;
			while (i < _size)
			{
				new_data[i] = _data[i];
				i++;
			}
			_allocator.deallocate(_data, _capacity);
			_data = new_data;
			_capacity = n;
		}
	}

//element access funcitons
	reference		operator[](size_type n)
	{
		return (_data[n]);
	}
	const_reference	operator[](size_type n)	const
	{
		return (_data[n]);
	}
	reference		at(size_type n)
	{
		if (n >= _size)
			throw(std::out_of_range("vector::at too far"));
		return (_data[n]);
	}
	const_reference	at(size_type n)	const
	{
		if (n >= _size)
			throw(std::out_of_range("vector::at too far"));
		return (_data[n]);
	}
	reference		front(void)
	{
		return (*_data);
	}
	const_reference	front(void)	const
	{
		return (*_data);
	}
	reference		back(void)
	{
		return (*(_data + _size - 1));
	}
	const_reference	back(void)	const
	{
		return (*(_data + _size - 1));
	}

//modifier functions
	template <class InputIterator>
	void	assign(InputIterator first, enable_if(!is_integral InputIterator last)
	{
		
	}
	void	assign(size_type n, const value_type& val)
	{
		size_type	i;
	
		i = 0;
		while (i < _size)
			_data[i++].~value_type();
		_size = n;
		if (_size > _capacity)
		{
			_allocator.deallocate(_data, _capacity);
			_capacity = _size * CAPACITY_SCALE;
			_data = _allocator.allocate(_capacity);
		}
		i = 0;
		while (i < _size)
			_data[i++] = val;
	}

	private:

	allocator_type	_allocator;
	size_type		_size;
	size_type		_capacity;
	value_type		*_data;

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
	template <class InputIterator>
	void	_range_assign(InputIterator first, InputIterator last)
	{
		size_type	i;
	
		i = 0;
		while (i < _size)
			_data[i++].~value_type();
		_size = last - first;
		if (_size > _capacity)
		{
			_allocator.deallocate(_data, _capacity);
			_capacity = _size * CAPACITY_SCALE;
			_data = _allocator.allocate(_capacity);
		}
		i = 0;
		while (first != last)
		{
			_data[i++] = *first;
			first++;
		}
	}
};

//iterator
template <class T, class Alloc>
class	ft::vector<T, Alloc>::iterator : public base_iterator<random_access_iterator_tag, T>
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
	operator	const_iterator() const
	{
		return (const_iterator(_data));
	}

	private :

	T *_data;
};

//const_iterator
template <class T, class Alloc>
class	ft::vector<T, Alloc>::const_iterator : public base_iterator<random_access_iterator_tag, const T>
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
