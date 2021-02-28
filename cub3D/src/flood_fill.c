#include "../include/cub_header.h"

void flood_fill_util(int i, int j)
{
 char	*curr_sym;
 int	width;

 if (i < 0 || i >= g_config.map_height)
  return ;
  width = ft_strlen(g_config.map[i]);
  if (j < 0 || j >= width)
	return;
//  if (data->map.map_copy[x][y] != empty && data->map.map_copy[x][y] != 0
//    && data->map.map_copy[x][y] != 2 && data->map.map_copy[x][y] != 3)
//   return ;
// if ((i == 0 || j == 0 || i == g_config.map_height - 1
// 	|| j == width - 1) && g_config.map[i][j] == '0')
// 	print_cust_error(INVALID_MAP);
if (g_config.map[i][j] != ' ' && g_config.map[i][j] != '0' &&
	g_config.map[i][j] != '2' && g_config.map[i][j] != g_config.man)
	return ;
//  if (data->map.map_copy[x][y] == new && data->map.map_copy[x][y] != 0
//    && data->map.map_copy[x][y] != 2 && data->map.map_copy[x][y] != 3)
//   return ;
	if (g_config.map[i][j] == '-' && g_config.map[i][j] != '0' &&
		g_config.map[i][j] != '2' && g_config.map[i][j] != g_config.man)
		return ;
 g_config.map[i][j] = '-';
 flood_fill_util(i + 1, j);
 flood_fill_util(i - 1, j);
 flood_fill_util(i, j + 1);
 flood_fill_util(i, j - 1);
}

void flood_fill(int i, int j, int width)
{
if ((i == 0 || j == 0 || i == g_config.map_height - 1
	|| j == width - 1) && (g_config.map[i][j] == '0'
	|| g_config.map[i][j] == g_config.man || g_config.map[i][j] == '2'))
	print_cust_error(INVALID_MAP);

if (g_config.map[i][j] == '0' || g_config.map[i][j] == '2'
	|| g_config.map[i][j] == g_config.man)
	return ;
//  if (!data->map.map_copy[i][j] || data->map.map_copy[i][j] == 2 ||
//    data->map.map_copy[i][j] == 3)
//   return ;
 flood_fill_util(i, j);
}