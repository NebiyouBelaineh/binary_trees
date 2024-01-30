#ifndef BINARY_TREES_H
#define BINARY_TREES_H
/**
* struct binary_tree_s - Binary tree node
*
* @n: Integer stored in the node
* @parent: Pointer to the parent node
* @left: Pointer to the left child node
* @right: Pointer to the right child node
*/

struct binary_tree_s
{
	int n;

	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct binary_tree_s binary_tree_t;
/* Binary Search Tree */
typedef struct binary_tree_s bst_t;
/* AVL Tree */
typedef struct binary_tree_s avl_t;
/* Max Binary Heap */
typedef struct binary_tree_s heap_t;
/* Tree Print Function */
void binary_tree_print(const binary_tree_t *);
/* creates binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/* inserts a node as the left-child of another node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/* inserts a node as the right child of another node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/* deltes an entire binary tree */
void binary_tree_delete(binary_tree_t *tree);
/* checks if a node is a leaf */
int binary_tree_is_leaf(const binary_tree_t *node);
/* checks if a given node is a root */
int binary_tree_is_root(const binary_tree_t *node);
/* Traveres through a tree in pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/* Traveres through a tree in post-order traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/* Traveres through a tree in post-order traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/* Measures the height of a binary tree */
size_t binary_tree_height(const binary_tree_t *tree);
/* measures the depth of a node in a binary tree */
size_t binary_tree_depth(const binary_tree_t *tree);
/* measuers the size of a binary tree */
size_t binary_tree_size(const binary_tree_t *tree);
/* counts the leaves in a binary tree */
size_t binary_tree_leaves(const binary_tree_t *tree);
#endif /*BINARY_TREES_H*/
