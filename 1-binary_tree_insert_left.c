#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: the parent node
 * @value: the value to add
 *
 * Return: binary tree or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *leftNode, *temp;

	if (!parent)
		return (NULL);

	leftNode = malloc(sizeof(binary_tree_t));

	if (!leftNode)
		return (NULL);

	leftNode->n = value;
	leftNode->left = NULL;
	leftNode->right = NULL;

	if (!parent->left)
	{
		leftNode->parent = parent;
		parent->left = leftNode;
	}
	else
	{
		temp = parent->left;
		parent->left = leftNode;
		parent->left->left = temp;
		parent->left->parent = parent;
		parent->left->left->parent = parent->left;
	}
	return (leftNode);
}
