#pragma once

#include "ft.hpp"
#include "Base_iterator.hpp"
#include "Pair.hpp"

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
	// typedef	typename iterator_traits<iterator>::difference_type	difference_type;
	// typedef	ft::reverse_iterator<iterator>			reverse_iterator;
	// typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

// constructors
	explicit	map(const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		: _comp(comp), _alloc(alloc), _root(NULL) {}
	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		: _comp(comp), _alloc(alloc), _root(NULL)
	{
		while (first != last)
		{
			if (!_bst_lookup((*first).first, _root))
				_root = _bst_insert(*first, _root);
			first++;
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
	}

// destructor
	~map(void)
	{
		_bst_clear(_root);
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
		return (current->data.second);
	}

// modifier functions
	pair<iterator,bool>	insert(const value_type& val)
	{
		node	*tmp;

		tmp = _bst_lookup(val.first, _root);
		if (tmp)
			return (make_pair(iterator(_root, tmp), false));
		_root = _bst_insert(val, _root);
		return (make_pair(iterator(_root, _bst_lookup(val.first, _root)), true));
	}
	iterator	insert(iterator position, const value_type& val)
	{
		node	*tmp;

		tmp = _bst_lookup(val.first, _root);
		if (tmp)
			return (iterator(_root, tmp));
		_root = _bst_insert(val, _root);
		return (iterator(_root, _bst_lookup(val.first, _root)));
	}
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
	void		print(void)				// temporary function /!/
	{
		_bst_print("", _root, false);
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

	private :

	typedef	typename allocator_type::template rebind<node>::other	node_allocator_type;

	key_compare		_comp;
	allocator_type	_alloc;
	node			*_root;

//BST functions
	void _bst_print(const std::string& prefix, const node* node, bool isLeft)
	{
		if( node != nullptr )
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──" );

			// print the value of the node
			std::cout << node->data.first << " " << node->data.second << std::endl;

			// enter the next tree level - left and right branch
			_bst_print( prefix + (isLeft ? "│   " : "    "), node->left, true);
			_bst_print( prefix + (isLeft ? "│   " : "    "), node->right, false);
		}
	}
	node	*_bst_deep_copy(node const *other)
	{
		node	*curr;

		if (other == NULL)
		{
			std::cout << "Bro wtf u doin" << std::endl; // à enlever plus tard /!/
		}
		curr = node_allocator_type(_alloc).allocate(1);
		curr = new (curr) node(NULL, NULL, NULL, other->data);
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
	node	*_bst_lookup(const key_type &key, node *curr)
	{
		if (!curr)
			return (NULL);
		if (curr->data.first == key)
			return (curr);
		if (key < curr->data.first)
			return (_bst_lookup(key, curr->left));
		return (_bst_lookup(key, curr->right));
	}
	node	*_bst_insert_get_parent(value_type data, node *curr) //parent of to-be-born child
	{
		if (!curr)
			return (NULL);
		if (data.first <= curr->data.first)
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
		node	*new_node;

		new_node = node_allocator_type(_alloc).allocate(1);
		new_node = new (new_node)
			node(_bst_insert_get_parent(new_data, root), NULL, NULL, new_data);
		if (!new_node->parent)
			return (new_node);
		if (new_data.first <= new_node->parent->data.first)
			new_node->parent->left = new_node;
		else
			new_node->parent->right = new_node;
		return (root);
	}
	void	_bst_remove_zero_child(node *to_remove)
	{
		if (to_remove->parent->left == to_remove)
			to_remove->parent->left = NULL;
		else if (to_remove->parent->right == to_remove)
			to_remove->parent->right = NULL;
		node_allocator_type(_alloc).deallocate(to_remove, 1);
	}
	void	_bst_remove_one_child(node *to_remove)
	{
		node	*child;

		child = to_remove->left != NULL ? to_remove->left : to_remove->right;
		if (to_remove->parent->left == to_remove)
			to_remove->parent->left = child;
		else if (to_remove->parent->right == to_remove)
			to_remove->parent->right = child;
		node_allocator_type(_alloc).deallocate(to_remove, 1);
	}
	void	_bst_remove_two_children(node *to_remove)
	{
		node	*child;

		child = to_remove->right;
		while (child->left)
		{
			child = child->left;
		}
		to_remove->data = child->data;
		if (child->left || child->right)
			_bst_remove_one_child(child);
		else
			_bst_remove_zero_child(child);
	}
	node	*_bst_remove(value_type data, node *root)
	{
		node	*to_remove;

		if (!(to_remove = _bst_lookup(data.first, root)))
			return (root);
		if (to_remove->left && to_remove->right)
			_bst_remove_two_children(to_remove);
		else if ((to_remove->left != NULL) != (to_remove->right != NULL))
			_bst_remove_one_child(to_remove);
		else
			_bst_remove_zero_child(to_remove);
		return (root == to_remove ? NULL : root);
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
	value_type	data;

	node(node *new_parent, node *new_left, node *new_right, const value_type &new_data)
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
		return (_current->data);
	}
	value_type const	&operator*(void) const
	{
		return (_current->data);
	}
	value_type			*operator->(void)
	{
		return (&(_current->data));
	}
	value_type const		*operator->() const
	{
		return (&(_current->data));
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
	// operator	const_iterator() const
	// {
	// 	return (const_iterator(_data));
	// }

	private :

	node *_root;
	node *_current;

// private functions
	
	node	*_get_next_bigger_parent(node *origin)
	{
		if (!origin->parent)
			return (NULL);
		else if (origin->parent->data > origin->data)
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
		else if (origin->parent->data < origin->data)
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
		return (_current->data);
	}
	value_type const	&operator*(void) const
	{
		return (_current->data);
	}
	value_type	const	*operator->(void)
	{
		return (&(_current->data));
	}
	value_type const	*operator->() const
	{
		return (&(_current->data));
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
		else if (origin->parent->data > origin->data)
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
		else if (origin->parent->data < origin->data)
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