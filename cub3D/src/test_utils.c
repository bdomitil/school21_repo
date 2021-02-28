#include "../include/cub_header.h"

void print_map()
{
	int i;
	i = 0;
	while (i < g_config.map_height)
	{
			printf("%s\n",g_config.map[i]);
		i++;
	}
}