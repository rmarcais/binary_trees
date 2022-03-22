#include "binary_trees.h"
/**
 * binary_tree_rotate_right - function that rotate a binary tree in the right
 * @tree: point to the root of the tree
 * Return: return NULL if it fail or tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (tree == NULL || tree->left == NULL)
		return (0);
	tmp = tree->left;
	tree->left = tmp->right;
	if (tmp->right != NULL)
		tmp->right->parent = tree;
	tmp->parent = tree->parent;
	tmp->right = tree;
	tree->parent = tmp;
	tree = tmp;
	return (tree);
}
