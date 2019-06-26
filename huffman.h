struct node_t
{
	unsigned int node_index; // BFS traversal
	unsigned int w;
	char s; // Tree height = 20
	struct node_t *parent;
	struct node_t *left;
	struct node_t *right;
};

struct b_tree_meta_t
{
	struct node_t *root;
	struct node_t *bottom;
	unsigned int height; // Tree height
};

struct map_t
{
	char simbol;
	int weight;
};

struct lookup_table_t
{
	char simbol;
	char code[20];
};
int main(int argc, char *argv[]);
//static void read_input(char *input);
static void insert_into_map(struct map_t *map, int *map_count, char simbol);
char * compress(char *input);
void decompress();
