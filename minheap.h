#include "huffman.h"

int main(int argc, char *argv[]);
struct b_tree_meta_t * create_heap();
struct node_t * create_node(char s, unsigned int w);
void destroy_heap(struct node_t *root, int display_flag);
void insert_into_heap(struct b_tree_meta_t *tree, struct node_t *node);
void delete_from_heap(struct b_tree_meta_t *tree, struct node_t *node);
int find_bottom_leaf_node(struct node_t *root, unsigned int level, struct node_t **temp_node);
int level_order_traversing(struct node_t *root, unsigned int level, int display_flag);
void refresh();
