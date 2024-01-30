#include "binary_trees.h"

/**
* binary_tree_nodes - counts the nodes with at least 1 child in binary tree
* @tree: pointer to the root node of the tree to count the number of nodes
* Return: the number of nodes with at least 1 child
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nwchild;

	if (!tree)
		return (0);
    /* Checks for leaf nodes and then returns 0 */
	if ((!tree->left && !tree->right))
		return (0);

    /* Add 1 for every non-leaf node, i.e node with at least 1 child*/
	nwchild = binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1;

	return (nwchild);
}
