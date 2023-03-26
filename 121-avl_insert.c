#include "binary_trees.h"

/**
 * balance_tree - Balances the tree
 *
 * @balance_factor: the balance factor of the node
 * @unbalanced_node: the unbalanced node
 * Return: the unbalanced node
 */
avl_t *balance_tree(int balance_factor, avl_t *unbalanced_node)
{
	if (balance_factor > 1)
	{
		if (binary_tree_balance(unbalanced_node->left) >= 0)
		{
			unbalanced_node = binary_tree_rotate_right(unbalanced_node);
			return (unbalanced_node);
		}
		else if (binary_tree_balance(unbalanced_node->left) == -1)
		{
			unbalanced_node->left = binary_tree_rotate_left(unbalanced_node->left);
			unbalanced_node = binary_tree_rotate_right(unbalanced_node);
			return (unbalanced_node);
		}
	}
	else
	{
		if (binary_tree_balance(unbalanced_node->right) <= -0)
		{
			unbalanced_node = binary_tree_rotate_left(unbalanced_node);
			return (unbalanced_node);
		}
		else if (binary_tree_balance(unbalanced_node->right) == 1)
		{
			unbalanced_node->right = binary_tree_rotate_right(unbalanced_node->right);
			unbalanced_node = binary_tree_rotate_left(unbalanced_node);
			return (unbalanced_node);
		}
	}
	return (unbalanced_node);
}

/**
 * insert_node_avl - Inserts the node in the AVL tree
 *
 * @root: the root of the tree (or subtree during recursion)
 * @new_node: the node to be inserted
 * Return: the root of the tree (or subtree during recursion)
 */
avl_t *insert_node_avl(avl_t *root, avl_t *new_node)
{
	int bf;

	if (root == NULL)
	{
		root = new_node;
		return (root);
	}

	if (new_node->n < root->n)
		root->left = insert_node_avl(root->left, new_node);
	else if (new_node->n > root->n)
		root->right = insert_node_avl(root->right, new_node);

	bf = binary_tree_balance(root);

	if (bf < -1 || bf > 1)
		root = balance_tree(bf, root);
	return (root);
}

/**
 * avl_insert - Inserts a value in an AVL tree
 *
 * @tree: double pointer to the root node of the tree for inserting the value
 * @value: the value of the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new;

	if (!tree)
		return (NULL);

	new = binary_tree_node(*tree, value);
	*tree = insert_node_avl(*tree, new);

	return (new);
}
