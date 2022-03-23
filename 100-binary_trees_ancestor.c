#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that finds the lowest common ancestor
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *parent_1 = first->parent;
	binary_tree_t *parent_2 = second->parent;

	if (first == NULL || second == NULL)
		return (NULL);
	else if (first == second)
		return ((binary_tree_t *)first);
	else if (first == parent_2 || parent_1 == NULL)
		return (binary_trees_ancestor(first, parent_2));
	else if (second == parent_1 || parent_2 == NULL)
		return (binary_trees_ancestor(parent_1, second));
	else
		return (binary_trees_ancestor(parent_1, parent_2));
}
