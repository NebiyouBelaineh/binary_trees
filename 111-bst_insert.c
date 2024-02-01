#include "binary_trees.h"

/**
* bst_insert - inserts a value in a BST
* @tree: pointer to the address of the BST
* @value: value to be stored in a node of the BST
* Return: pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);/*creates the root node*/
		if (*tree == NULL)
			return (NULL);
		return (*tree);
	}
	if (value < (*tree)->n)/* check left subtree*/
	{
		if ((*tree)->left == NULL)/*check if left subtree is empty*/
		{
			(*tree)->left = binary_tree_node(*tree, value);
			if ((*tree)->left == NULL)
				return (NULL);
			return ((*tree)->left);
		}
		else
		{
			return (bst_insert(&(*tree)->left, value));
		}
	}
	else if (value > (*tree)->n)/* check right subtree*/
	{
		if ((*tree)->right == NULL)/* check if right subtree is empty*/
		{
			(*tree)->right = binary_tree_node(*tree, value);
			if ((*tree)->right == NULL)
				return (NULL);
			return ((*tree)->right);
		}
		else
		{
			return (bst_insert(&(*tree)->right, value));
		}
	}
	return (NULL);
}
