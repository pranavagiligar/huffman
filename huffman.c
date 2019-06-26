#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "huffman.h"

int main(int argc, char *argv[])
{
	struct map_t *map;
	int map_count = 0;
	map = (struct map_t *) malloc(26 * sizeof(struct map_t));
	char input[] = "strstrstrstrstrstrstrstrstrstrstrstr";
	int input_len = strlen(input);
	
	for(int i=0; i<input_len; i++)
	{
		insert_into_map(map, &map_count, input[i]);
	}
	
	
	printf("Simbol count table\n");
	for(int i = 0; i < map_count; i++)
	{
		printf("%c\t%d\n", map[i].simbol, map[i].weight);
	}
	printf("\n");
	
	
	
	
	free(map);
	return 0;
}

static void insert_into_map(struct map_t *map, int *count, char simbol)
{
	int i = 0;
	while(i < *count)
	{
		if(map[i].simbol == simbol)
		{
			map[i].weight++;
			break;
		}
		i++;
	}
	if(i == *count)
	{
		map[*count].simbol = simbol;
		map[*count].weight = 1;
		*count += 1;
	}
}
