#include "binary_trees.h"

/**
* tree_sibling - finds the sibling of a node
* @node: pointer to the node to find the sibling
* Return: Sibiling of the node, NULL if it fails or if node has no sibiling
*/
binary_tree_t *tree_sibling(binary_tree_t *node)
{
	/**
	* For a node to have a sibiling, it needs to have a parent node
	* Therefore, we will check if it has a parent node,
	* Next we will check if the parent node has a left and right child
	* The parent node should return true if it
	*/
	if (!node)
		return (NULL);
	if (!node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);
	else
		return (NULL);
}

/**
* binary_tree_uncle - finds the uncle of a node
* @node: pointer to the node to find the uncle
* Return: pointer to the uncle of the node, NULL otherwise
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;
	/**
	* An uncle node is a sibiling to the parent node.
	* We need to return a pointer to the given node's parent sibiling
	*/
	if (!node)
		return (NULL);
	if (!node->parent)
		return (NULL);
	uncle = tree_sibling(node->parent);

	return (uncle);
}
