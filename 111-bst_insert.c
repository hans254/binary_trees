#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *nw;

	if (tree != NULL)
	{
		current = *tree;

		if (current == NULL)
		{
			nw = binary_tree_node(current, value);
			if (nw == NULL)
				return (NULL);
			return (*tree = nw);
		}

		if (value < current->n) /* insert in left subtree */
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));

			nw = binary_tree_node(current, value);
			if (nw == NULL)
				return (NULL);
			return (current->left = nw);
		}
		if (value > current->n) /* insert in right subtree */
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));

			nw = binary_tree_node(current, value);
			if (nw == NULL)
				return (NULL);
			return (current->right = nw);
		}
	}
	return (NULL);
}

