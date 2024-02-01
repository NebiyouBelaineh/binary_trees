#include "binary_trees.h"
int tree_is_bst(const binary_tree_t *tree, int min, int max);

/**
* binary_tree_is_bst - checks if a binary tree is a BST
* @tree: binary tree to be checked
* Return: 1 if tree is BST, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);


	return (tree_is_bst(tree, INT_MIN, INT_MAX));
}
/**
 * tree_is_bst - helper function to check left and right subtree for BST
 * @tree: pointer to the tree to be checked
 * @min: minimum range of the tree node values
 * @max: maximum value of the tree node values
 * Return: returns 1 if it is a binary search tree, 0 otherwise.
*/
int tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (tree_is_bst(tree->left, min, tree->n)
	&& tree_is_bst(tree->right, tree->n, max));
}
