#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leave, subb, btt, level, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leave = size;
	for (level = 0, subb = 1; leave >= subb; subb *= 2, level++)
		leave -= subb;
	/* subtract all nodes except for bottom-most level */

	for (btt = 1 << (level - 1); btt != 1; btt >>= 1)
		tree = leave & btt ? tree->right : tree->left;
	/*
	 * Traverse tree to first empty slot based on the binary
	 * representation of the number of leave.
	 * Example -
	 * If there are 12 nodes in a complete tree, there are 5 leave on
	 * the 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * The first empty node is 101 == RLR, *root->right->left->right
	 */

	new = binary_tree_node(tree, value);
	leave & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		temp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = temp;
		new = new->parent;
	}
	/* Flip values with parent until parent value exceeds new value */

	return (new);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

