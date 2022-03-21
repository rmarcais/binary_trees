#include "binary_trees.h"
#include <stdio.h>
/**
 * max - function that computes the max between two integers.
 * @a: first integer.
 * @b: second_integer.
 * Return: a or b.
 */
int max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
/**
 * height - function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: The height.
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (max(height(tree->left), height(tree->right)) + 1);
}
/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: 0, 1 or 2
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	return (height(tree) - 1);
}

/**
 * binary_tree_balance - function that measures the balance
 * factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: Always 0 (Success)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		hl = binary_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		hr = binary_tree_height(tree->right) + 1;
	return (hl - hr);
}
