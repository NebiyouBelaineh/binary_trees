#include "binary_trees.h"

/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 *
 * Return: Ancestor node, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *temp = NULL;
	binary_tree_t *parser = NULL;

	if (!first || !second)
		return (NULL);

	while (first)
	{
		parser = (binary_tree_t *)second;
		while (parser)
		{
			if (parser == first)
			{
				temp = (binary_tree_t *)first;
				return (temp);
			}
			parser = parser->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
