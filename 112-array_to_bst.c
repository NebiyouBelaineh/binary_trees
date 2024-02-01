#include "binary_trees.h"

/**
* array_to_bst - builds a Binary Search Tree from an array
* @array: pointer to the first element of the array to be converted
* @size: number of elements in the array
* Return: returns the pointer to the root node of the create BST.
*/
bst_t *array_to_bst(int *array, size_t size)
{
	int exist = 0;
	size_t index, i;
	bst_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);


	for (index = 0; index < size; index++)
	{
		exist = 0;
		for (i = 0; i < index ; i++)
			if (array[index] == array[i])
			{
				exist = 1;
			}
		if (exist)
			continue;
		if (!(bst_insert(&root, array[index])))
			return (NULL);
	}
	return (root);
}
