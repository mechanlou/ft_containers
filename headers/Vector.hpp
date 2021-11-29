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
	typedef			 T											value_type;
	typedef			 Alloc										allocator_type;
	typedef	typename allocator_type::reference					reference;
	typedef	typename allocator_type::const_reference			const_reference;
	typedef	typename allocator_type::pointer					pointer;
	typedef	typename allocator_type::const_pointer				const_pointer;
	typedef			 size_t										size_type;

	class	iterator;
	class	const_iterator;
	typedef	ft::reverse_iterator<iterator>			reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef	typename ft::iterator_traits<typename iterator::base_iterator>::difference_type	difference_type;

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
	void		assign(InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
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
	void		assign(size_type n, const value_type& val)
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
	void		push_back(const value_type& val)
	{
		value_type	*new_data;
		size_type	i;

		if (_size == _capacity)
		{
			_capacity = (_size + 1) * CAPACITY_SCALE;
			new_data = _allocator.allocate(_capacity);
			i = 0;
			while (i < _size)
			{
				new_data[i] = _data[i];
				i++;
			}
			_allocator.deallocate(_data, _size);
			_data = new_data;
		}
		_data[_size++] = val;
	}
	void		pop_back(void)
	{
		_data[_size--].~value_type();
	}
	iterator	insert(typename vector<T>::iterator position, const value_type& val)
	{
		value_type	*new_data;
		iterator	it;
		iterator	it_end;
		size_type	i;
		size_type	location;

		if (_size == _capacity)
		{
			_capacity = (_size + 1) * CAPACITY_SCALE;
			new_data = _allocator.allocate(_capacity);
			i = 0;
			it = begin();
			it_end = end();
			while (it != position)
				new_data[i++] = *(it++);
			location = i;
			new_data[i++] = val;
			while (it != it_end)
				new_data[i++] = *(it++);
			_allocator.deallocate(_data, _size);
			_data = new_data;
		}
		else
		{
			it = end();
			while (it != position)
			{
				*it = *(it - 1);
				it--;
			}
			location = position - begin();
			*it = val;
		}
		_size++;
		return (iterator(_data + location));
	}
	void	insert(typename vector<T>::iterator position, size_type n, const value_type& val)
	{
		value_type	*new_data;
		iterator	it;
		iterator	it_end;
		size_type	i;

		if (_capacity < _size + n)
		{
			_capacity = (_size + n) * CAPACITY_SCALE;
			new_data = _allocator.allocate(_capacity);
			i = 0;
			it = begin();
			it_end = end();
			while (it != position)
				new_data[i++] = *(it++);
			n += i;
			while (i < n)
				new_data[i++] = val;
			new_data[i++] = val;
			while (it != it_end)
				new_data[i++] = *(it++);
			_allocator.deallocate(_data, _size);
			_data = new_data;
		}
		else
		{
			it = end() + (n - 1);
			while (it != position + (n - 1))
			{
				*it = *(it - n);
				it--;
			}
			while (it != position - 1)
				*(it--) = val;
		}
		_size += n;
	}
	template <class InputIterator>
    void	insert(typename vector<T>::iterator position, InputIterator first,
		typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
	{
		value_type	*new_data;
		size_type	insertion_size;
		iterator	data_it;
		iterator	data_end;
		size_type	i;

		insertion_size = last - first;
		if (_capacity < _size + insertion_size)
		{
			_capacity = (_size + insertion_size) * CAPACITY_SCALE;
			new_data = _allocator.allocate(_capacity);
			data_it = begin();
			i = 0;
			while (data_it != position)
				new_data[i++] = *(data_it++);
			while (first != last)
				new_data[i++] = *(first++);
			while (data_it != data_end)
				new_data[i++] = *(data_it++);
			_allocator.deallocate(_data, _size);
			_data = new_data;
		}
		else
		{
			data_it = end() + (insertion_size - 1);
			while (data_it != position + (insertion_size - 1))
			{
				*data_it = *(data_it - insertion_size);
				data_it--;
			}
			while (last != first)
				*(data_it--) = *(--last);
		}
		_size += insertion_size;
	}
	iterator	erase(typename vector<T>::iterator position)
	{
		iterator	it(position);
		iterator	it_end = end();
		iterator	next = position + 1;

		_size--;
		(*(position)).~value_type();
		while (it != it_end)
			*(it++) = *(next++);
		return (position);
	}
	iterator	erase(typename vector<T>::iterator first, typename vector<T>::iterator last)
	{
		iterator	it(first);
		iterator	next(last);
		iterator	it_end = end();

		while (it != last)
		{
			(*it).~value_type();
			*(it++) = *(next++);
		}
		while (next != it_end)
			*(it++) = *(next++);
		_size -= last - first;
		return (last);
	}
	void	swap(vector& x)
	{
		allocator_type	alloc;
		size_type		size;
		size_type		capacity;
		value_type		*data;
		
		alloc = _allocator;
		size = _size;
		capacity = _capacity;
		data = _data;
		_allocator = x._allocator;
		_size = x._size;
		_capacity = x._capacity;
		_data = x._data;
		x._allocator = alloc;
		x._size = size;
		x._capacity = capacity;
		x._data = data;
	}
	void	clear(void)
	{
		size_type	i;

		i = 0;
		while (i < _size)
			_data[i++].~value_type();
		_size = 0;
	}
//allocator
	allocator_type	get_allocator(void) const
	{
		return (_allocator);
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

namespace	ft
{
	template <class T, class Alloc>
	bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename vector<T, Alloc>::const_iterator	lit;
		typename vector<T, Alloc>::const_iterator	rit;
		typename vector<T, Alloc>::const_iterator	lend;
	
		if (lhs.size() == rhs.size())
		{
			lit = lhs.begin();
			rit = rhs.begin();
			lend = lhs.end();
			while (lit != lend && *lit == *rit)
			{
				lit++;
				rit++;
			}
			if (lit == lend)
				return (true);
		}
		return (false);
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename vector<T, Alloc>::const_iterator	first1 = lhs.begin();
		typename vector<T, Alloc>::const_iterator	first2 = rhs.begin();
		typename vector<T, Alloc>::const_iterator	last1 = lhs.end();
		typename vector<T, Alloc>::const_iterator	last2 = rhs.end();

		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) return false;
			else if (*first1 < *first2) return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}