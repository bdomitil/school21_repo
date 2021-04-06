/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:52:31 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/04 15:53:06 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void	flood_fill_util(int i, int j)
{
	int	width;

	if (i < 0 || i >= g_config.map_height)
		return ;
	width = ft_strlen(g_config.map[i]);
	if (j < 0 || j >= width)
		return ;
	if (g_config.map[i][j] != ' ' && g_config.map[i][j] != '0' &&
		g_config.map[i][j] != '2' && g_config.map[i][j] != g_config.man)
		return ;
	if (g_config.map[i][j] == '-' && g_config.map[i][j] != '0' &&
		g_config.map[i][j] != '2' && g_config.map[i][j] != g_config.man)
		return ;
	g_config.map[i][j] = '-';
	flood_fill_util(i + 1, j);
	flood_fill_util(i - 1, j);
	flood_fill_util(i, j + 1);
	flood_fill_util(i, j - 1);
}

void	flood_fill(int i, int j, int width)
{
	if ((i == 0 || j == 0 || i == g_config.map_height - 1
		|| j == width - 1) && (g_config.map[i][j] == '0'
		|| g_config.map[i][j] == g_config.man || g_config.map[i][j] == '2'))
		print_cust_error(INVALID_MAP);
	if (g_config.map[i][j] == '0' || g_config.map[i][j] == '2'
		|| g_config.map[i][j] == g_config.man)
		return ;
	flood_fill_util(i, j);
}
