#include "binary_trees.h"
void print_level(const binary_tree_t *tree, int level, void (*func)(int));
/**
 * height - functions that c=returns the height of a binary tree.
 * @tree: a pointer to the root node of the tree to traverse
 * Return: The height of the binary tree.
 */
int height(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);
	lh = height(tree->left);
	rh = height(tree->right);
	if (lh > rh)
		return (lh + 1);
	else
		return (rh + 1);
}
/**
 * print_level_order - functions that print the tree using the level-order.
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function
 * Return: Nothing
 */
void print_level_order(const binary_tree_t *tree, void(*func)(int))
{
	int h = height(tree) + 1;
	int i;

	for (i = 1; i <= h; i++)
		print_level(tree, i, func);
}

/**
 * print_level - function that prints the values of the current level.
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function
 * @level: The level to print.
 * Return: Nothing
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - function that goes
 * through a binary tree using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	print_level_order(tree, func);
}
