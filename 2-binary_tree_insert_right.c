#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node as the
 * right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: is the value of the data
 * Return: a pointer to the created node, or NULL on
 * failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	if (parent == NULL)
		return (NULL);

	if (parent->right == NULL)
		parent->right = binary_tree_node(parent, value);

	else if (parent->right != NULL)
	{
		tmp = parent->right;
		parent->right = binary_tree_node(parent, value);
		tmp->parent = parent->right;
		parent->right->right = tmp;
	}
	return (parent->right);
}
