#include "binary_trees.h"
int tree_is_avl(const binary_tree_t *tree);
size_t tree_height(const binary_tree_t *tree);

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

	return (tree_is_bst(tree->left, min, tree->n) &&
	tree_is_bst(tree->right, tree->n, max));
}

/**
* binary_tree_is_avl - checks if a binary tree is a valid AVL tree
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is a valid AVL tree, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	/* checks if tree is a valid BST first */
	if (!tree_is_bst(tree, INT_MIN, INT_MAX))
		return (0);
	return (tree_is_avl(tree));
}

/**
* tree_is_avl - helper function recursively checks if a tree is an AVL tree
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is a valid AVL tree, 0 otherwise
*/
int tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	/* Check the balance factor of both the left and righ subtree recursively */
	/* check if tree is balanced */
	if (binary_tree_balance(tree) > 1 || binary_tree_balance(tree) < -1)
		return (0);
	return (tree_is_avl(tree->left) && tree_is_avl(tree->right));
}

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
