#include "binary_trees.h"
int tree_balance(const binary_tree_t *tree);
int tree_is_full(const binary_tree_t *tree);
size_t tree_height(const binary_tree_t *tree);


/**
 * tree_is_full - checks if a binary tree is full
 * @tree: measures the balance factor of a binary tree
 * Return: the balance factor of a the binary tree, 0 if tree is NULL
 */

int tree_is_full(const binary_tree_t *tree)
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
	return (tree_is_full(tree->left) && tree_is_full(tree->right));
}

/**
 * tree_balance - measures the balance factor of a binary tree
 * @tree: measures the balance factor of a binary tree
 * Return: the balance factor of a the binary tree, 0 if tree is NULL
 */

int tree_balance(const binary_tree_t *tree)
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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: measures the balance factor of a binary tree
 * Return: the balance factor of a the binary tree, 0 if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_balance(tree) == 0 && tree_is_full(tree));
}
