#include "binary_trees.h"
/**
 * binary_tree_rotate_left - function that rotate a binary tree in the left
 * @tree: point to the root of the tree
 * Return: return NULL if it fail or tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (tree == NULL || tree->right == NULL)
		return (0);
	tmp = tree->right;
	tree->right = tmp->left;
	if (tmp->left != NULL)
		tmp->left->parent = tree;
	tmp->parent = tree->parent;
	tmp->left = tree;
	tree->parent = tmp;
	tree = tmp;
	return (tree);
}
