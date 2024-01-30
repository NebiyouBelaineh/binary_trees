#include "binary_trees.h"

/**
* binary_tree_height -  Measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height.
* Return: height of the binary tree, 0 if tree is NULL.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_depth, right_depth;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left_depth = binary_tree_height(tree->left);
	right_depth = binary_tree_height(tree->right);

	if (left_depth > right_depth)
		return (left_depth + 1);
	else
		return (right_depth + 1);
}
