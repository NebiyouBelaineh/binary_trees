#include "binary_trees.h"

/**
* bst_search - searches for a value in a Binary Search Tree
* @tree: pointer to the root node of a BST
* @value: the value to search in the tree
* Return: pointer to the node with the value, NULL otherwise.
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found;

	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	if (tree->n > value)
		found = bst_search(tree->left, value);
	else
		found = bst_search(tree->right, value);

	return (found);
}
