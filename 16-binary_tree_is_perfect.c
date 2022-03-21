#include "binary_trees.h"

/**
 * left_depth - function that returns the depth of leftmost leaf.
 * @tree: a pointer to the node to measure the depth
 * Return: The depth.
 */
size_t left_depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}
/**
 * is_perfect - function that checks if a binary tree is perfect.
 * @tree: a pointer to the node to measure the depth.
 * @d: The depth.
 * @level: The level of the leaves.
 * Return: 0 or 1.
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
	{
		if (d == level + 1)
			return (1);
		else
			return (0);
	}
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, d, level + 1) &&
		is_perfect(tree->right, d, level + 1));
}
/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect.
 * @tree: a pointer to the node to measure the depth
 * Return: 0 or 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = left_depth(tree);

	if (tree == NULL)
		return (0);
	return (is_perfect(tree, d, 0));
}
