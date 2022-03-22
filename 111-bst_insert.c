#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree.
 * @tree: a double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: A pointer to the new node or NULL.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = *tree, *tmp2 = NULL;

	if (tree == NULL || *tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	while (tmp != NULL)
	{
		tmp2 = tmp;
		if (value == tmp->n)
			return (NULL);
		else if (value < tmp->n)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if (value < tmp2->n)
	{
		tmp2->left = binary_tree_node(tmp2, value);
		tmp2 = tmp2->left;
	}
	else
	{
		tmp2->right = binary_tree_node(tmp2, value);
		tmp2 = tmp2->right;
	}
	return (tmp2);
}
