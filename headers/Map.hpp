#pragma once

#include "ft.hpp"

template <class Key, class T, class Compare, class Alloc>
class	ft::map
{
	public :

// member types
	typedef Key											key_type;
	typedef T											mapped_value;
	typedef pair<const Key, T>							value_type;
	typedef std::less<key_type>							key_compare;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef	typename allocator_type::pointer			pointer;
	typedef	typename allocator_type::const_pointer		const_pointer;
	typedef size_t										size_type;
	// typedef	typename iterator_traits<iterator>::difference_type	difference_type;

	class	value_compare;
	struct	node;
	// class	iterator;
	// class	const_iterator;
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
			_root = _bst_insert(*(first++), _root);
	}
	map(const map& x) : _comp(x._comp), _alloc(x._alloc)
	{
		_root = _bst_deep_copy(x._root);
	}
// destructor
	~map(void)
	{
		_bst_clear()
	}

// functions

	void	print(void)
	{
		_bst_print("", _root, false);
	}

	private :

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
		allocate
		curr = new node(NULL, NULL, NULL, other->data);
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
	node	*_bst_lookup(value_type data, node *curr)
	{
		if (!curr)
			return (NULL);
		if (curr->data == data)
			return (curr);
		if (data < curr->data)
			return (_bst_lookup(data, curr->left));
		return (_bst_lookup(data, curr->right));
	}
	node	*_bst_insert_get_parent(value_type data, node *curr) //parent of to-be-born child
	{
		if (!curr)
			return (NULL);
		if (data <= curr->data)
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

		new_node = new node(_bst_insert_get_parent(new_data, root), NULL, NULL, new_data);
		if (!new_node->parent)
			return (new_node);
		if (new_data <= new_node->parent->data)
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
		delete to_remove;
	}

	void	_bst_remove_one_child(node *to_remove)
	{
		node	*child;

		child = to_remove->left != NULL ? to_remove->left : to_remove->right;
		if (to_remove->parent->left == to_remove)
			to_remove->parent->left = child;
		else if (to_remove->parent->right == to_remove)
			to_remove->parent->right = child;
		delete to_remove;
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

		if (!(to_remove = _bst_lookup(data, root)))
			return (root);
		if (to_remove->left && to_remove->right)
			_bst_remove_two_children(to_remove);
		else if ((to_remove->left != NULL) != (to_remove->right != NULL))
			_bst_remove_one_child(to_remove);
		else
			_bst_remove_zero_child(to_remove);
		return (root == to_remove ? NULL : root);
	}

	int	_bst_size(node *root)
	{
		if (!root)
			return (0);
		return (_bst_size(root->left) + _bst_size(root->right) + 1);
	}
};

template <class Key, class T, class Compare, class Alloc>
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
