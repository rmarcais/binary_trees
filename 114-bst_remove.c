#include "binary_trees.h"

/**
 * bst_min_value - function that search the min value of a node
 * @node: a pointer to the node of the beginning of the tree
 * Return: the node with the min value
 */
bst_t *bst_min_value(bst_t *node)
{
	bst_t *tmp = node;

	while (tmp != NULL && tmp->left != NULL)
		tmp = tmp->left;
	return (tmp);
}

/**
 * bst_remove - function that removes a node from a BST
 * @root: a pointer to the root node of the tree
 * @value: is the value to remove in the tree
 * Return: NULL if tree is NULL or if nothing is found
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = bst_min_value(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
