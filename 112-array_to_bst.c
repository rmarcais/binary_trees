#include "binary_trees.h"

/**
 * array_to_bst - function that builds a Binary Search Tree from an array.
 * @array: a pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 * Return: 0 on success, error code on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}

	return (tree);
}
