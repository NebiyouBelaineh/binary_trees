#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a node as the right-child of another node
* @parent: Pointer to the parent node of the node to create.
* @value: Integer value of the new node
*
* Return: Pointer to the newly created node or NULL if it fails.
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *rightNode, *temp;

	if (!parent)
		return (NULL);

	rightNode = malloc(sizeof(binary_tree_t));
	if (!rightNode)
		return (NULL);

	rightNode->n = value;
	rightNode->left = NULL;
	rightNode->parent = parent;

	if (!parent->right)
	{
		rightNode->right = NULL;
		parent->right = rightNode;
	}
	else
	{
		temp = parent->right;
		parent->right = rightNode;
		rightNode->right = temp;
		rightNode->right->parent = rightNode;
	}
	return (rightNode);
}
