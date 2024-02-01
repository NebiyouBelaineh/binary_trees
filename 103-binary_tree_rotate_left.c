#include "binary_trees.h"
/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree
 * @tree: the tree to check
 *
 * Return: new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->right == NULL)
		return (tree);
	new_root = tree->right;
	temp = new_root->left;

	new_root->left = tree;
	tree->right = temp;

	if (temp)
		temp->parent = tree;

	new_root->parent = tree->parent;
	tree->parent = new_root;
	return (new_root);
}
