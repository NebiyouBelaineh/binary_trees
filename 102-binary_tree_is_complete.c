#include "binary_trees.h"
int countNumNodes(const binary_tree_t *tree);
int checkComplete(const binary_tree_t *tree, int index, int numNodes);
/**
 * countNumNodes -  count nodes number
 * @tree: the tree to check
 *
 * Return: nodes number or 0
 */
int countNumNodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + countNumNodes(tree->left) + countNumNodes(tree->right));
}
/**
 * checkComplete -  checks if a binary tree is complete
 * @tree: the tree to check
 * @index: index of element
 * @numNodes: number of nodes
 *
 * Return: 1 is complete, 0 if not
 */
int checkComplete(const binary_tree_t *tree, int index, int numNodes)
{
	if (!tree)
		return (1);
	/*printf("index: [%d] value [%d], */
	/*NumNodes[%d]\n", index, tree->n, numNodes);*/
	if (index >= numNodes)
		return (0);
	return (checkComplete(tree->left, 2 * index + 1, numNodes)
	 && checkComplete(tree->right, 2 * index + 2, numNodes));
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: the tree to check
 *
 * Return: 1 is complete, 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int numNodes = 0;

	if (!tree)
		return (0);
	numNodes = countNumNodes(tree);
	return (checkComplete(tree, 0, numNodes));
}
