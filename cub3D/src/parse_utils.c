#include "../include/cub_header.h"

void parse_resolution(char *str)
{
	int i;
	char **splited_str;

	i = 0;
	splited_str = ft_split(&str[1], ' ');
	while (splited_str[i])
		i++;
	if (i > 2 || i < 1)
		print_cust_error(INVALID_RESOLUTION);
	g_config.wind_width = ft_atoi(splited_str[0]);
	g_config.wind_heith = ft_atoi(splited_str[1]);
INT32
}