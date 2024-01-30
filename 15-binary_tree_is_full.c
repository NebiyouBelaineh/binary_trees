#include "binary_trees.h"

/**
* binary_tree_is_full - checks if a binary tree is full
* @tree: measures the balance factor of a binary tree
* Return: the balance factor of a the binary tree, 0 if tree is NULL
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If a node has only one child, the tree is not full */
	if ((tree->left && !tree->right) || (tree->left && !tree->right))
		return (0);

	/* If both left and right subtrees are NULL, */
	/* it is a leaf and considered full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively check the left and right subtrees */
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
