#include "binary_trees.h"

/**
* bst_remove - removes a node from a BST
* @root: pointer to the root node of the tree to remove the node
* @value: value of the node to remove from the tree
* Return: pointer to the new root node of the tree after removing the node
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *current;

	if (!root)
		return (NULL);

	if (root->n > value)
	{
		root->left = bst_remove(root->left, value);
		return (root);
	}
	else if (root->n < value)
	{
		root->right = bst_remove(root->right, value);
		return (root);
	}
	if (root->left == NULL)/* Checks if there are left and right children */
	{
		temp = root->right;
		free(root);
		return (temp);
	}
	else if (root->right == NULL)
	{
		temp = root->left;
		free(root);
		return (temp);
	}
	else /* if both child are present */
	{
		current = root;
		temp = root->right;
		while (temp->left)/* moves to the right subtree to look for successor */
			current = temp, temp = temp->left;
		if (current != root)
			current->left = temp->right;
		else
			current->right = temp->right;
		root->n = temp->n, free(temp);
		return (root);
	}
}
