#include "binary_trees.h"

/**
* binary_tree_leaves -  counts the leaves in a binary tree
* @tree: pointer to the root node of the tree to measure the size
* Return: size of the tree or 0 if the tree is NULL
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	leaves = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (leaves);

}
