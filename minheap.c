// About file: Min heap binary tree for huffman compression
// Author: Pranava
// Time: June 2019

#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"
#include "minheap.h"

int main(int argc, char *argv[])
{
	struct b_tree_meta_t *tree = create_heap();
	
	// testing statements and logics and i/o ops
	insert_into_heap(tree, create_node('a', 1));
	insert_into_heap(tree, create_node('b', 2));
	insert_into_heap(tree, create_node('c', 3));
	struct node_t *orphan = create_node('d', 4);
	insert_into_heap(tree, orphan);
	free(orphan);
	
	printf("\nTraversing tree to display tree in breadth First Order\n");
	unsigned int level = 1;
	struct node_t *temp_node;
	
	while(level_order_traversing(tree->root, level, &temp_node, 1))
	{
		level++;
	}
	///////////////////
	printf("\nDestroying heap\n");
	destroy_heap(tree->root);
	free(tree);
	return 0;
}

struct b_tree_meta_t * create_heap()
{
	struct b_tree_meta_t *tree = (struct b_tree_meta_t *) malloc(sizeof(struct b_tree_meta_t));
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

void destroy_heap(struct node_t *root)
{
	if(root == NULL) return;
	destroy_heap(root->left);
	destroy_heap(root->right);
	printf("\t%c", root->s);
	free(root);
}

void insert_into_heap(struct b_tree_meta_t *tree, struct node_t *node)
{
	
	if(tree->root == NULL)
	{
		printf("Inserting first node \n");
		tree->root = node;
		tree->bottom = node;
		node->parent = NULL;
	}
	else
	{
		if(tree->bottom == tree->root)
		{
			printf("Inserting first left child node [%c]\n", node->s);
			tree->bottom = node;
			tree->root->left = node;
			node->parent = tree->root;
			return;
		}
		if(tree->bottom->parent != NULL)
		{
			if(tree->bottom->parent->right == NULL)
			{
				printf("Inserting right node of parent node [%c]\n", node->s);
				tree->bottom->parent->right = node;
				node->parent = tree->bottom->parent->right;
				return;
			}
		}
		// traverse tree and find out correct position
		// TODO:
		printf("Traversing tree in breadth first order for seeking last level node\n");
		unsigned int level = 1;
		struct node_t *temp_node;
		
		while(level_order_traversing(tree->root, level, &temp_node, 0))
		{
			level++;
		}
		printf("Bottom level, simbol, weight is %d, %c, %d\n", level, temp_node->s, temp_node->w);
		
		// After finding last level node, we will know in which level  new node should be inserted. SO we need to traverse all the parent node level and find the node with no child.
		// WIP
		printf("Traversing tree in breadth first order for seeking last level node\n");
		level--;
		find_bottom_leaf_node(tree->root, level, &temp_node);
	}
}

// Level order traversing with stop constraint[child nodes == NULL]
int find_bottom_leaf_node(struct b_tree_meta_t *tree, unsigned int level, struct node_t **temp_node)
{
	//TODO:
}

// temp_node = to find address of last node
int level_order_traversing(struct node_t *root, unsigned int level, struct node_t **temp_node, int display_flag)
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
	
	return left || right;
}

void delete_from_heap(struct b_tree_meta_t *tree, struct node_t *node)
{
	
}

void refresh()
{
	
}