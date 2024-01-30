#include "binary_trees.h"

/**
* binary_tree_depth -  Measures the depth of a node in a binary tree
* @tree: pointer to the root node of the tree to measure the height.
* Return: Depth of the binary tree, 0 if tree is NULL.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);

	height = binary_tree_depth(tree->parent);

	if (!tree->parent)
		return (height);
	else
		return (height + 1);
}
