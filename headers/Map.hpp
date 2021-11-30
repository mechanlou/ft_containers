#pragma once

#include "ft.hpp"
#include "Base_iterator.hpp"
#include "Pair.hpp"
#include "Iterator_traits.hpp"
#include "Reverse_iterator.hpp"
#include <limits>

template <class Key, class T, class Compare, class Alloc>
class	ft::map
{
	public :

// member types
	typedef Key											key_type;
	typedef T											mapped_type;
	typedef pair<const Key, T>							value_type;
	typedef Compare										key_compare;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef	typename allocator_type::pointer			pointer;
	typedef	typename allocator_type::const_pointer		const_pointer;
	typedef size_t										size_type;

	class	value_compare;
	struct	node;
	class	iterator;
	class	const_iterator;
	typedef	typename iterator_traits<typename iterator::base_iterator>::difference_type	difference_type;
	typedef	ft::reverse_iterator<iterator>			reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

// constructors
	explicit	map(const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		: _comp(comp), _alloc(alloc), _root(NULL) {}
	template <class InputIterator>
	map(InputIterator first_it, InputIterator last_it,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		: _comp(comp), _alloc(alloc), _root(NULL)
	{
		while (first_it != last_it)
		{
			if (!_bst_lookup((*first_it).first, _root))
				_root = _bst_insert(*first_it, _root);
			first_it++;
		}
	}
	map(const map& x) : _comp(x._comp), _alloc(x._alloc)
	{
		_root = _bst_deep_copy(x._root);
	}
	map	&operator=(const map& x)
	{
		_bst_clear(_root);
		_root = _bst_deep_copy(x._root);
		return (*this);
	}

// destructor
	~map(void)
	{
		_bst_clear(_root);
	}

// iterator functions
	iterator	begin(void)
	{
		return (iterator(_root, _get_min(_root)));
	}
	const_iterator	begin(void) const
	{
		return (const_iterator(_root, _get_min(_root)));
	}
	iterator	end(void)
	{
		return (iterator(_root, NULL));
	}
	const_iterator	end(void) const
	{
		return (const_iterator(_root, NULL));
	}
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

// size functions
	bool		empty(void) const
	{
		return (_root == NULL);
	}
	size_type	size(void) const
	{
		return (_bst_size(_root));
	}
	size_type	max_size(void) const
	{
		return (std::numeric_limits<size_type>::max() / sizeof(node));
	}

// access function
	mapped_type	&operator[](const key_type& k)
	{
		node	*current;

		current = _bst_lookup(k, _root);
		if (!current)
		{
			_root = _bst_insert(value_type(k, mapped_type()), _root);
			current = _bst_lookup(k, _root);
		}
		return (current->data->second);
	}

// modifier functions (some are defined outside the class because of a weird ass "variable has incomplete type")
	pair<iterator,bool>	insert(const value_type& val)
	{
		node	*tmp;

		tmp = _bst_lookup(val.first, _root);
		if (tmp)
			return (make_pair(iterator(_root, tmp), false));
		_root = _bst_insert(val, _root);
		return (make_pair(iterator(_root, _bst_lookup(val.first, _root)), true));
	}
	iterator	insert(typename map<Key, T, Compare, Alloc>::iterator position, const value_type& val);
	template <class InputIterator>
	void	insert(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			if (!_bst_lookup((*first).first, _root))
				_root = _bst_insert(*first, _root);
			first++;
		}
	}
	void	erase(iterator position);
	size_type	erase(const key_type& k)
	{
		size_type	tmp;

		tmp = 0;
		if (_bst_lookup(k, _root))
			tmp = 1;
		_root = _bst_remove(k, _root);
		return (tmp);
	}
	void	erase(iterator first, iterator last);
	void	swap(map& x)
	{
		key_compare		comp_tmp = _comp;
		allocator_type	alloc_tmp = _alloc;
		node			*node_tmp = _root;

		_comp = x._comp;
		_alloc = x._alloc;
		_root = x._root;
		
		x._comp = comp_tmp;
		x._alloc = alloc_tmp;
		x._root = node_tmp;
	}
	void	clear(void)
	{
		_bst_clear(_root);
		_root = NULL;
	}
// observer functions
	key_compare	key_comp(void) const
	{
		return (_comp);
	}
	value_compare	value_comp(void) const
	{
		return (_comp);
	}
	allocator_type	get_allocator(void) const
	{
		return (_alloc);
	}
//operation functions
	iterator	find(const key_type& k)
	{
		return (iterator(_root, _bst_lookup(k, _root)));
	}
	const_iterator find (const key_type& k) const
	{
		return (const_iterator(_root, _bst_lookup(k, _root)));
	}
	size_type	count(const key_type& k) const
	{
		return (_bst_size_key(_root, k));
	}
	iterator	lower_bound(const key_type& k)
	{
		iterator	it = begin();
		iterator	it_end = end();

		while (it != it_end && _comp((*it).first, k))
			it++;
		return (it);
	}
	const_iterator	lower_bound(const key_type& k) const
	{
		const_iterator	it = begin();
		const_iterator	it_end = end();

		while (it != it_end && _comp((*it).first, k))
			it++;
		return (it);
	}
	iterator	upper_bound(const key_type& k)
	{
		reverse_iterator	it = rbegin();
		reverse_iterator	it_end = rend();

		while (it != it_end && _comp(k, (*it).first))
			it++;
		return (it.base());
	}
	const_iterator	upper_bound(const key_type& k) const
	{
		const_reverse_iterator	it = rbegin();
		const_reverse_iterator	it_end = rend();

		while (it != it_end && _comp(k, (*it).first))
			it++;
		return (it.base());
	}
	pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
	{
		return (make_pair(lower_bound(k), upper_bound(k)));
	}
	pair<iterator,iterator>				equal_range(const key_type& k)
	{
		return (make_pair(lower_bound(k), upper_bound(k)));
	}
	void		print(void)				// temporary function /!/
	{
		_bst_print("", _root, false);
	}

	private :

	typedef	typename allocator_type::template rebind<node>::other	node_allocator_type;

	key_compare		_comp;
	allocator_type	_alloc;
	node			*_root;

//BST functions
	size_type	_bst_size_key(node *curr, const key_type& k) const
	{
		if (!curr)
			return (0);
		return (_bst_size_key(curr->left, k) + _bst_size_key(curr->right, k)
			+ (curr->data->first == k));
	}
	void _bst_print(const std::string& prefix, const node* node, bool isLeft)
	{
		if( node != NULL )
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──" );

			// print the value of the node
			std::cout << node->data->first << " " << node->data->second << std::endl;

			// enter the next tree level - left and right branch
			_bst_print( prefix + (isLeft ? "│   " : "    "), node->left, true);
			_bst_print( prefix + (isLeft ? "│   " : "    "), node->right, false);
		}
	}
	node	*_bst_deep_copy(node const *other)
	{
		node		*curr;
	
		if (other == NULL)
		{
			std::cout << "Bro wtf u doin" << std::endl; // à enlever plus tard /!/
		}
		curr = node_allocator_type(_alloc).allocate(1);
		curr = new (curr) node(NULL, NULL, NULL, NULL);
		curr->data = _alloc.allocate(1);
		curr->data = new (curr->data) value_type(*(other->data));
		if (other->left)
		{
			curr->left = _bst_deep_copy(other->left);
			curr->left->parent = curr;
		}
		if (other->right)
		{
			curr->right = _bst_deep_copy(other->right);
			curr->right->parent = curr;
		}
		return (curr);
	}
	node	*_bst_lookup(const key_type &key, node *curr) const
	{
		if (!curr)
			return (NULL);
		if (curr->data->first == key)
			return (curr);
		if (_comp(key, curr->data->first))
			return (_bst_lookup(key, curr->left));
		return (_bst_lookup(key, curr->right));
	}
	node	*_bst_insert_get_parent(value_type data, node *curr) //parent of to-be-born child
	{
		if (!curr)
			return (NULL);
		if (_comp(data.first, curr->data->first))
		{
			if (curr->left)
				return (_bst_insert_get_parent(data, curr->left));
			return (curr);
		}
		if (curr->right)
			return (_bst_insert_get_parent(data, curr->right));
		return (curr);
	}
	node	*_bst_insert(value_type new_data, node *root)
	{	
		node		*new_node;
	
		new_node = node_allocator_type(_alloc).allocate(1);
		new_node = new (new_node)
			node(_bst_insert_get_parent(new_data, root), NULL, NULL, NULL);
		new_node->data = _alloc.allocate(1);
		new_node->data = new (new_node->data) value_type(new_data);
		if (!new_node->parent)
			return (new_node);
		if (_comp(new_data.first, new_node->parent->data->first))
			new_node->parent->left = new_node;
		else
			new_node->parent->right = new_node;
		return (root);
	}
	node	*_bst_highest_parent(node *root)
	{
		if (!root->parent)
			return (root);
		return (_bst_highest_parent(root->parent));
	}
	node	*_bst_remove_zero_child(node *to_remove)
	{
		node	*new_root = _bst_highest_parent(to_remove);

		if (new_root == to_remove)
			new_root = NULL;
		if (to_remove->parent->left == to_remove)
			to_remove->parent->left = NULL;
		else if (to_remove->parent->right == to_remove)
			to_remove->parent->right = NULL;
		_alloc.deallocate(to_remove->data, 1);
		node_allocator_type(_alloc).deallocate(to_remove, 1);
		return (new_root);
	}
	node	*_bst_remove_one_child(node *to_remove)
	{
		node	*child;

		child = to_remove->left != NULL ? to_remove->left : to_remove->right;
		if (to_remove->parent)
		{
			if (to_remove->parent->left == to_remove)
				to_remove->parent->left = child;
			else if (to_remove->parent->right == to_remove)
				to_remove->parent->right = child;
		}
		child->parent = to_remove->parent;
		_alloc.deallocate(to_remove->data, 1);
		node_allocator_type(_alloc).deallocate(to_remove, 1);
		return (_bst_highest_parent(child));
	}
	node	*_bst_remove_two_children(node *to_remove)
	{
		node	*child;

		child = to_remove->right;
		while (child->left)
		{
			child = child->left;
		}
		_alloc.deallocate(to_remove->data, 1);
		to_remove->data = _alloc.allocate(1);
		to_remove->data = new (to_remove->data) value_type(*(child->data));
		if (child->left || child->right)
			_bst_remove_one_child(child);
		else
			_bst_remove_zero_child(child);
		return (_bst_highest_parent(to_remove));
	}
	node	*_bst_remove(const key_type &key, node *root)
	{
		node		*to_remove;

		if (!(to_remove = _bst_lookup(key, root)))
			return (root);
		if (to_remove->left && to_remove->right)
			return (_bst_remove_two_children(to_remove));
		else if ((to_remove->left != NULL) != (to_remove->right != NULL))
			return (_bst_remove_one_child(to_remove));
		else
			return (_bst_remove_zero_child(to_remove));
	}

	size_type	_bst_size(node *root) const
	{
		if (!root)
			return (0);
		return (_bst_size(root->left) + _bst_size(root->right) + 1);
	}
	void	_bst_clear(node *root)
	{
		if (root)
		{
			_bst_clear(root->left);
			_bst_clear(root->right);
			_alloc.deallocate(root->data, 1);
			node_allocator_type(_alloc).deallocate(root, 1);
		}
	}
	node	*_get_min(node *tree) const
	{
		if (tree->left)
			return (_get_min(tree->left));
		return (tree);
	}
};

template <class Key, class T, class Compare, class Alloc> // node
struct	ft::map<Key,T,Compare,Alloc>::node
{
	node		*parent;
	node		*left;
	node		*right;
	value_type	*data;

	node(node *new_parent, node *new_left, node *new_right, value_type *new_data)
		: parent(new_parent), left(new_left), right(new_right), data(new_data) {}
};

template <class Key, class T, class Compare, class Alloc>
class ft::map<Key,T,Compare,Alloc>::value_compare
{
	friend class	map;

	protected:

	Compare	comp;
	value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object

	public:

	typedef bool result_type;
	typedef value_type	first_argument_type;
	typedef value_type	second_argument_type;

	bool	operator()(const value_type& x, const value_type& y) const
	{
		return comp(x.first, y.first);
	}
};

// iterator
template <class Key, class T, class Compare, class Alloc>
class	ft::map<Key, T, Compare, Alloc>::iterator : public ft::base_iterator<bidirectional_iterator_tag, ft::pair<const Key, T> >
{
	public :

	iterator(void) {}
	iterator(node *root, node *start) : _root(root), _current(start) {}
	iterator(iterator const &src) : _root(src._root), _current(src._current) {}
	virtual	~iterator(void) {}

	iterator	&operator=(iterator const &src)
	{
		_current = src._current;
		_root = src._root;
		return (*this);
	}
	bool		operator==(iterator const &src) const
	{
		return (_root == src._root && _current == src._current);
	}
	bool		operator!=(iterator const &src) const
	{
		return (_current != src._current || _root != src._root);
	}
	value_type			&operator*(void)
	{
		return (*(_current->data));
	}
	value_type const	&operator*(void) const
	{
		return (_current->data);
	}
	value_type			*operator->(void)
	{
		return (_current->data);
	}
	value_type const		*operator->() const
	{
		return (_current->data);
	}
	iterator	&operator++() //prefix
	{
		_current = _get_next_node(_current);
		return (*this);
	}
	iterator	operator++(int) //postfix
	{
		iterator	copy(*this);

		_current = _get_next_node(_current);
		return (copy);
	}
	iterator	&operator--() //prefix
	{
		if (!_current)
			_current = _get_max(_root);
		else
			_current = _get_previous_node(_current);
		return (*this);
	}
	iterator	operator--(int) //postfix
	{
		iterator	copy(*this);

		if (!_current)
			_current = _get_max(_root);
		else
			_current = _get_previous_node(_current);
		return (copy);
	}
	operator	const_iterator() const
	{
		return (const_iterator(_root, _current));
	}

	private :

	node *_root;
	node *_current;

// private functions
	
	node	*_get_next_bigger_parent(node *origin)
	{
		if (!origin->parent)
			return (NULL);
		else if (key_compare()(origin->data->first, origin->parent->data->first))
			return (origin->parent);
		else
			return (_get_next_bigger_parent(origin->parent));
	}
	node	*_get_next_node(node *src)
	{
		if (src->right)
			return (_get_min(src->right));
		else
			return (_get_next_bigger_parent(src));
	}
	node	*_get_min(node *tree)
	{
		if (tree->left)
			return (_get_min(tree->left));
		return (tree);
	}
	node	*_get_next_smaller_parent(node *origin)
	{
		if (!origin->parent)
			return (NULL);
		else if (key_compare()(origin->parent->data->first, origin->data->first))
			return (origin->parent);
		else
			return (_get_next_smaller_parent(origin->parent));
	}
	node	*_get_previous_node(node *src)
	{
		if (src->left)
			return (_get_max(src->left));
		else
			return (_get_next_smaller_parent(src));
	}
	node	*_get_max(node *tree) const
	{
		if (tree->right)
			return (_get_max(tree->right));
		return (tree);
	}
};

// const_iterator

template <class Key, class T, class Compare, class Alloc>
class	ft::map<Key, T, Compare, Alloc>::const_iterator : public ft::base_iterator<bidirectional_iterator_tag, const ft::pair<const Key, T> >
{
	public :

	const_iterator(void) {}
	const_iterator(node *root, node *start) : _root(root), _current(start) {}
	const_iterator(const_iterator const &src) : _root(src._root), _current(src._current) {}
	virtual	~const_iterator(void) {}

	const_iterator		&operator=(const_iterator const &src)
	{
		_current = src._current;
		_root = src._root;
		return (*this);
	}
	bool				operator==(const_iterator const &src) const
	{
		return (_root == src._root && _current == src._current);
	}
	bool				operator!=(const_iterator const &src) const
	{
		return (_current != src._current || _root != src._root);
	}
	value_type const	&operator*(void)
	{
		return (*(_current->data));
	}
	value_type const	&operator*(void) const
	{
		return (*(_current->data));
	}
	value_type	const	*operator->(void)
	{
		return (_current->data);
	}
	value_type const	*operator->() const
	{
		return (_current->data);
	}
	const_iterator		&operator++() //prefix
	{
		_current = _get_next_node(_current);
		return (*this);
	}
	const_iterator		operator++(int) //postfix
	{
		const_iterator	copy(*this);

		_current = _get_next_node(_current);
		return (copy);
	}
	const_iterator		&operator--() //prefix
	{
		if (!_current)
			_current = _get_max(_root);
		else
			_current = _get_previous_node(_current);
		return (*this);
	}
	const_iterator		operator--(int) //postfix
	{
		const_iterator	copy(*this);

		if (!_current)
			_current = _get_max(_root);
		else
			_current = _get_previous_node(_current);
		return (copy);
	}
	// operator	const_iterator() const
	// {
	// 	return (const_iterator(_data));
	// }

	private :

	node const *_root;
	node const *_current;

// private functions
	
	node const	*_get_next_bigger_parent(node const *origin) const
	{
		if (!origin->parent)
			return (NULL);
		else if (key_compare()(origin->data->first, origin->parent->data->first))
			return (origin->parent);
		else
			return (_get_next_bigger_parent(origin->parent));
	}
	node const	*_get_next_node(node const *src) const
	{
		if (src->right)
			return (_get_min(src->right));
		else
			return (_get_next_bigger_parent(src));
	}
	node const	*_get_min(node const *tree) const
	{
		if (tree->left)
			return (_get_min(tree->left));
		return (tree);
	}
	node const	*_get_next_smaller_parent(node const *origin) const
	{
		if (!origin->parent)
			return (NULL);
		else if (key_compare()(origin->parent->data->first, origin->data->first))
			return (origin->parent);
		else
			return (_get_next_smaller_parent(origin->parent));
	}
	node const	*_get_previous_node(node const *src) const
	{
		if (src->left)
			return (_get_max(src->left));
		else
			return (_get_next_smaller_parent(src));
	}
	node const	*_get_max(node const *tree) const
	{
		if (tree->right)
			return (_get_max(tree->right));
		return (tree);
	}
};

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
	ft::map<Key, T, Compare, Alloc>::insert(
	typename ft::map<Key, T, Compare, Alloc>::iterator position,
	const typename ft::map<Key, T, Compare, Alloc>::value_type& val)
{
	node	*tmp;

	(void) position;
	tmp = _bst_lookup(val.first, _root);
	if (tmp)
		return (iterator(_root, tmp));
	_root = _bst_insert(val, _root);
	return (iterator(_root, _bst_lookup(val.first, _root)));
}
template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase
	(typename ft::map<Key, T, Compare, Alloc>::iterator position)
{
	_root = _bst_remove((*position).first, _root);
}

template <class Key, class T, class Compare, class Alloc>
void	ft::map<Key, T, Compare, Alloc>::erase(typename ft::map<Key, T, Compare, Alloc>::iterator first, typename ft::map<Key, T, Compare, Alloc>::iterator last)
{
	iterator	first_clone(first);
	size_type	size;
	size_type	i;
	key_type	*targets;
	typename allocator_type::template rebind<key_type>::other tmp_alloc(_alloc);

	size = 0;
	while (first != last)
	{
		size++;
		first++;
	}
	targets = tmp_alloc.allocate(size);
	i = 0;
	while (first_clone != last)
	{
		targets[i++] = (*first_clone).first;
		first_clone++;
	}
	i = 0;
	while (_comp(i, size))
		_root = _bst_remove(targets[i++], _root);
	tmp_alloc.deallocate(targets, i);
}