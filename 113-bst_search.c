#include "binary_trees.h"

/**
 * bst_search - function that searches for a value in a BST
 * @tree: a pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 * Return: NULL if tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp = (bst_t *)tree;

	if (tree == NULL)
		return (NULL);
	else if (tree->n == value)
		return ((bst_t *)tree);

	while (tmp != NULL)
	{
		if (tmp->n < value)
			return (bst_search(tmp->right, value));
		return (bst_search(tmp->left, value));
	}
	return (NULL);
}
