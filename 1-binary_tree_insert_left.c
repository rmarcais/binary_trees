#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node as the
 * left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: is the value of the data
 * Return: a pointer to the created node, or NULL on
 * failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	if (parent == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = binary_tree_node(parent, value);

	else if (parent->left != NULL)
	{
		tmp = parent->left;
		parent->left = binary_tree_node(parent, value);
		tmp->parent = parent->left;
		parent->left->left = tmp;
	}
	return (parent->left);
}
