// About file: Min heap binary tree for huffman compression
// Author: Pranava
// Time: June 2019

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minheap.h"

int main(int argc, char *argv[])
{
	struct b_tree_meta_t *tree = create_heap();

	// testing statements and logics and i/o ops
	insert_into_heap(tree, create_node('a', 1));
	insert_into_heap(tree, create_node('b', 2));
	insert_into_heap(tree, create_node('c', 3));
	insert_into_heap(tree, create_node('d', 4));
	insert_into_heap(tree, create_node('e', 5));
	insert_into_heap(tree, create_node('f', 6));
	insert_into_heap(tree, create_node('g', 7));

	printf("\nTraversing tree to display tree in breadth First Order\n");
	unsigned int level = 1;
	struct node_t *temp_node;

	while(level_order_traversing(tree->root, level, &temp_node, 1))
	{
		printf("\n");
		level++;
	}
	///////////////////
	printf("\nDestroying heap\n");
	destroy_heap(tree->root, 1);
	free(tree);
	printf("\n");
	return 0;
}

struct b_tree_meta_t * create_heap()
{
	struct b_tree_meta_t *tree =
							(struct b_tree_meta_t *) malloc(sizeof(struct b_tree_meta_t));
	tree->root = NULL;
	tree->bottom = NULL;
	tree->height = 0;
	return tree;
}

struct node_t * create_node(char s, unsigned int w)
{
	struct node_t *node = (struct node_t *) malloc(sizeof(struct node_t));
	node->w = w;
	node->s = s;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void destroy_heap(struct node_t *root, int display_flag)
{
	if(root == NULL) return;
	destroy_heap(root->left, display_flag);
	destroy_heap(root->right, display_flag);
	if(display_flag)
	{
		printf("%c\t", root->s);
	}
	free(root);
}

void insert_into_heap(struct b_tree_meta_t *tree, struct node_t *node)
{

	if(tree->root == NULL)
	{
		printf("Inserting first node [%c]\n", node->s);
		tree->root = node;
		tree->bottom = node;
		node->parent = NULL;
	}
	else
	{
		if(tree->bottom == tree->root)
		{
			printf("Inserting first left child node [%c]\n\n", node->s);
			tree->bottom = node;
			tree->root->left = node;
			node->parent = tree->root;
			return;
		}
		if(tree->bottom->parent != NULL)
		{
			if(tree->bottom->parent->right == NULL)
			{
				printf("Inserting right node[%c] to parent node[%c]\n\n", node->s, tree->bottom->parent->s);
				tree->bottom->parent->right = node;
				// node->parent = tree->bottom->parent->right; TODO:
				node->parent = tree->bottom->parent;
				tree->bottom = node;
				return;
			}
		}
		// traverse tree and find out correct position
		printf("Traversing tree in breadth first order for seeking last level node\n");
		unsigned int level = 1;
		struct node_t *temp_node;
		unsigned int total = 0;
		while((total = level_order_traversing(tree->root, level, &temp_node, 0)))
		{
			if(total == (unsigned int) pow(2, level - 1))
			{
				level++;
			}
			else
			{
				break;
			}
		}
		printf("Bottom level, simbol, weight is %d, %c, %d\n", level, temp_node->s, temp_node->w);

		// After finding last level node, we will know in which level  new node
		// should be inserted. SO we need to traverse all the parent node level
		// and find the node with no child.
		// WIP
		printf("Traversing tree in breadth first order for seeking last level[%d] childless node\n", level-1);
		level = level - 1;
		if(find_bottom_leaf_node(tree->root, level, &temp_node))
		{
			printf("Did'nt got any childless node !\n");
		}
		else
		{
			printf("Got the Childless Bottom Leaf (level=%d, simbol=%c, weight=%d)\n",
			 					level, temp_node->s, temp_node->w);
			temp_node->left = node;
			node->parent = temp_node;
			tree->bottom = node;
			printf("Inserting as left node[%c] to parent node[%c]\n", node->s, temp_node->s);
		}
	}
	printf("\n");
}

// Level order traversing with stop constraint[child nodes == NULL]
int find_bottom_leaf_node(struct node_t *root, unsigned int level, struct node_t **temp_node)
{
	if(level == 1)
	{
		if(root->left == NULL && root->right == NULL)
		{
			*temp_node = root;
			return 0;
		}
		return 1;
	}
	if(!find_bottom_leaf_node(root->left, level - 1, temp_node))
	{
		return 0;
	}
	if(!find_bottom_leaf_node(root->right, level - 1, temp_node))
	{
		return 0;
	}
	return 1;
}

// temp_node = to find address of last node
// TODO: temp_node is unnessessary here, might have to remove in future
int level_order_traversing(struct node_t *root,
	 					unsigned int level, struct node_t **temp_node, int display_flag)
{
	if(root == NULL)
	{
		return 0;
	}
	if(level == 1)
	{
		*temp_node = root;
		if(display_flag)
		{
			printf("%c\t", root->s);
		}
		return 1;
	}
	int left = level_order_traversing(root->left, level - 1, temp_node, display_flag);
	int right = level_order_traversing(root->right, level - 1, temp_node, display_flag);

	return left + right;
}

void delete_from_heap(struct b_tree_meta_t *tree, struct node_t *node)
{

}

void refresh()
{

}
