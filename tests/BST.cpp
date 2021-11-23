#include <iostream>
#include <string>

struct node
{
	int	data;
	node *left;
	node *right;
	node *parent;
};

void printBT(const std::string& prefix, const node* node, bool isLeft)
{
	if( node != nullptr )
	{
		std::cout << prefix;

		std::cout << (isLeft ? "├──" : "└──" );

		// print the value of the node
		std::cout << node->data << std::endl;

		// enter the next tree level - left and right branch
		printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
		printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
	}
}

void printBT(const node* node)
{
    printBT("", node, false);
}

node	*lookup(int data, node *curr)
{
	if (!curr)
		return (NULL);
	if (curr->data == data)
		return (curr);
	if (data < curr->data)
		return (lookup(data, curr->left));
	return (lookup(data, curr->right));
}

node	*_insert_get_parent(int data, node *curr) //parent of to-be-born child
{
	if (!curr)
		return (NULL);
	if (data <= curr->data)
	{
		if (curr->left)
			return (_insert_get_parent(data, curr->left));
		return (curr);
	}
	if (curr->right)
		return (_insert_get_parent(data, curr->right));
	return (curr);
}

node	*insert(int data, node *root)
{	
	node	*new_node;

	new_node = new node;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = _insert_get_parent(data, root);
	if (!new_node->parent)
		return (new_node);
	if (data <= new_node->parent->data)
		new_node->parent->left = new_node;
	else
		new_node->parent->right = new_node;
	return (root);
}

void	_remove_zero_child(node *to_remove)
{
	if (to_remove->parent->left == to_remove)
		to_remove->parent->left = NULL;
	else if (to_remove->parent->right == to_remove)
		to_remove->parent->right = NULL;
	delete to_remove;
}

void	_remove_one_child(node *to_remove)
{
	node	*child;
	
	child = to_remove->left != NULL ? to_remove->left : to_remove->right;
	if (to_remove->parent->left == to_remove)
		to_remove->parent->left = child;
	else if (to_remove->parent->right == to_remove)
		to_remove->parent->right = child;
	delete to_remove;
}

void	_remove_two_children(node *to_remove)
{
	node	*child;

	child = to_remove->right;
	while (child->left)
	{
		child = child->left;
	}
	to_remove->data = child->data;
	if (child->left || child->right)
		_remove_one_child(child);
	else
		_remove_zero_child(child);
}

node	*remove(int data, node *root)
{
	node	*to_remove;

	if (!(to_remove = lookup(data, root)))
		return (root);
	if (to_remove->left && to_remove->right)
		_remove_two_children(to_remove);
	else if ((to_remove->left != NULL) != (to_remove->right != NULL))
		_remove_one_child(to_remove);
	else
		_remove_zero_child(to_remove);
	return (root == to_remove ? NULL : root);
}

int	size(node *root)
{
	if (!root)
		return (0);
	return (size(root->left) + size(root->right) + 1);
}

node	*deep_copy(node const *other)
{
	node	*curr;

	if (other == NULL)
	{
		std::cout << "Bro wtf u doin" << std::endl;
	}
	curr = new node;
	curr->data = other->data;
	curr->left = NULL;
	curr->right = NULL;
	if (other->left)
		curr->left = deep_copy(other->left);
	if (other->right)
		curr->right = deep_copy(other->right);
	return (curr);
}

int main(void)
{
	node	*root = NULL;
	node	*clone = NULL;

	root = insert(12, root);
	root = insert(5, root);
	root = insert(15, root);
	root = insert(3, root);
	root = insert(7, root);
	root = insert(13, root);
	root = insert(17, root);
	root = insert(1, root);
	root = insert(9, root);
	root = insert(14, root);
	root = insert(20, root);
	root = insert(8, root);
	root = insert(11, root);
	root = insert(18, root);
	printBT(root);

	std::cout << "size : " << size(root) << std::endl;

	remove(5, root);
	printBT(root);
	remove(20, root);
	printBT(root);
	remove(1, root);
	printBT(root);
	remove(12, root);
	printBT(root);

	std::cout << "size : " << size(root) << std::endl << std::endl;

	std::cout << "Clone one :" << std::endl;
	clone = deep_copy(root);
	printBT(clone);
	std::cout << "size : " << size(clone) << std::endl;


	return (0);
}

