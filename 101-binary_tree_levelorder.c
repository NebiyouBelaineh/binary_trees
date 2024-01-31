#include "binary_trees.h"

/**
* binary_tree_levelorder - traverses through a tree in level order traversal
* @tree: pointer to the root node of the tree to traverse
* @func: pointer to a function to call for each node.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *current;
	queue_t *queue;

	if (!tree || !func)
		return;

	queue = createQueue();

	enqueue(queue, (binary_tree_t *)tree);

	while (queue->front != NULL)
	{
		current = dequeue(queue);

		func(current->n);

		if (current->left != NULL)
			enqueue(queue, current->left);

		if (current->right != NULL)
			enqueue(queue, current->right);
	}

	free(queue);
}
/**
* createQueue - creates an empty queue
* Return: returns the create queue
*/
queue_t *createQueue(void)
{
	queue_t *newQueue;

	newQueue = (queue_t *)malloc(sizeof(queue_t));
	newQueue->front = newQueue->rear = NULL;

	return (newQueue);
}

/**
* enqueue - enqueue a node into the queue
* @queue: pointer to the queue
* @node: pointer to the node to be strored in the queue
*/
void enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *newNode;

	newNode = (queue_node_t *)malloc(sizeof(queue_node_t));
	if (!newNode)
		return;

	newNode->node = node;
	newNode->next = NULL;

	if (queue->rear == NULL)
	{
		queue->front = queue->rear = newNode;
		return;
	}
	queue->rear->next = newNode;
	queue->rear = newNode;
}

/**
* dequeue - dequeue a node from the queue
* @queue: pointer to the queue
* Return: pointer to the front node
*/
binary_tree_t *dequeue(queue_t *queue)
{
	queue_node_t *temp;
	binary_tree_t *node;

	if (queue->front == NULL)
		return (NULL);

	temp = queue->front;
	node = temp->node;

	queue->front = queue->front->next;

	if (queue->front == NULL)
		queue->rear = NULL;

	free(temp);
	return (node);
}
