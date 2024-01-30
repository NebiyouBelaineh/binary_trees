#include "binary_trees.h"

/**
* binary_tree_node - Creates a binary tree node
* @parent: Pointer to the parent node of the node to create.
* @value: Integer value of the new node
*
* Return: Pointer to the newly created node or NULL if it fails.
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);

	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = parent;

	return (newNode);
}
