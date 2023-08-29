#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t a = 0, v = 0;

		a = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		v = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((a > v) ? a : v);
	}
	return (0);
}

