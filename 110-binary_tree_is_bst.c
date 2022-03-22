#include "binary_trees.h"

/**
 * binary_bst_traverse - function that traverses down the tree keeping track
 * of the narrowing min and max allowed values
 * @node: a pointer to the node of the root to check
 * @min: the min value of a node
 * @max: the max value of a node
 * -1 and +1 in the last return is for checkin no duplicate value
 * Return: 1 if the binary tree is a BST, 0 otherwise
 */
int binary_bst_traverse(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);
	if (node->n < min || node->n > max)
		return (0);
	return (binary_bst_traverse(node->left, min, node->n - 1) &&
		binary_bst_traverse(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - function that checks if a binary tree is a valid BST
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_bst_traverse(tree, INT_MIN, INT_MAX));
}
