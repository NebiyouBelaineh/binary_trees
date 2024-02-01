#include "binary_trees.h"
/**
 * binary_tree_rotate_right -  performs a left-rotation on a binary tree
 * @tree: the tree to check
 *
 * Return: new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	new_root = tree->left;
	temp = new_root->right;

	new_root->right = tree;
	tree->left = temp;

	if (temp)
		temp->parent = tree;

	new_root->parent = tree->parent;
	tree->parent = new_root;
	return (new_root);
}
