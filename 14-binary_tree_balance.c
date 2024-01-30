#include "binary_trees.h"
size_t tree_height(const binary_tree_t *tree);

/**
* binary_tree_balance - measures the balance factor of a binary tree
* @tree: measures the balance factor of a binary tree
* Return: the balance factor of a the binary tree, 0 if tree is NULL
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor;
	size_t hL, hR;

	if (!tree)
		return (0);

	hL = tree_height(tree->left);
	hR = tree_height(tree->right);
	balance_factor = hL - hR;
	return (balance_factor);
}


/**
* tree_height -  Measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height.
* Return: height of the binary tree, 0 if tree is NULL.
*/
size_t tree_height(const binary_tree_t *tree)
{
	int left_depth, right_depth;

	if (!tree)
		return (0);

	left_depth = tree_height(tree->left);
	right_depth = tree_height(tree->right);

	if (left_depth > right_depth)
		return (left_depth + 1);
	else
		return (right_depth + 1);
}
