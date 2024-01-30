#include "binary_trees.h"

/**
* binary_tree_is_leaf - checks if a node is a leaf node
* @node: pointer to the node being checked
*
* Return: 1 if it is a leaf, 0 otherwise
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	/**
	* leaf: is a node that has no child nodes
	* This means pointers to the left and the right nodes are NULL
	* Therefore we need to check every node if it
	* has both left and right nodes to be pointing to NULL
	*/
	if (!node->left && !node->right)
		return (1);
	return (0);
}
