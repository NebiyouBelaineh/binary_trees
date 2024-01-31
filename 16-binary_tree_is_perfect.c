#include "binary_trees.h"

int depth(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree, int d, int level);
int is_Perfect(const binary_tree_t *tree);

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: measures the balance factor of a binary tree
* Return: the balance factor of a the binary tree, 0 if tree is NULL
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_Perfect(tree));
}

/**
 * depth-  Calculate the depth
 * @tree: pointer to the binary tree to check depth
 * Return: the depth of the binary tree
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect - Check if the tree is perfect
 * @tree: pointer to the binary tree being checked
 * @d: depth of the tree
 * @level: level
 * Return: 1 if tree is perfect, 0 otherwise
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, d, level + 1) &&
	is_perfect(tree->right, d, level + 1));
}

/**
 * is_Perfect - helper function
 * @tree: tree to be checked
 * Return: 1 if it is perfect, 0
*/
int is_Perfect(const binary_tree_t *tree)
{
	int d = depth(tree);

	return (is_perfect(tree, d, 0));
}
