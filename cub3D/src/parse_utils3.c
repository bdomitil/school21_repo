/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:36:55 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/13 22:41:11 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void	get_sprites_pos(t_sprites *sprites)
{
	int i;
	int j;
	int sp_num;

	i = 0;
	sp_num = 0;
	while (i < g_config.map_height)
	{
		j = -1;
		while (++j < g_config.map_width && sp_num < g_config.sprite_num)
			if (g_config.map[i][j] == '2')
			{
				sprites[sp_num].x = j + 0.5;
				sprites[sp_num].y = i + 0.5;
				sp_num++;
			}
		i++;
	}
	i = -1;
	while (++i < g_config.sprite_num)
		sprites[i].dist_to_player = ((g_mlx.player.posx - sprites[i].x) *
		(g_mlx.player.posx - sprites[i].x) + (g_mlx.player.posy - sprites[i].y)
			* (g_mlx.player.posy - sprites[i].y));
}

void	compare_two_maps(char **map1, char **map2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_config.map_height)
	{
		while (j < g_config.map_width)
		{
			if (map1[i][j] == '0' &&
				map2[i][j] != '0')
				print_cust_error(INVALID_MAP);
			else if (map1[i][j] == '2' &&
				map2[i][j] != '2')
				print_cust_error(INVALID_MAP);
			else if (map1[i][j] == g_config.man &&
				map2[i][j] != g_config.man)
				print_cust_error(INVALID_MAP);
			j++;
		}
		j = 0;
		i++;
	}
}

void	free_double_mass(void **mass, int mass_heigth)
{
	int i;

	i = 0;
	if (!mass)
		return ;
	while (i < mass_heigth)
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}

char	**dublicate_map(char **mass, char filling)
{
	char	**to_ret;
	int		i;

	i = 0;
	if (!(to_ret = malloc(sizeof(char *) * g_config.map_height)))
		print_cust_error(ERROR_MAP_PROCESSING);
	while (i < g_config.map_height)
	{
		if (!(to_ret[i] = ft_calloc(1, g_config.map_width + 1)))
			print_cust_error(ERROR_MAP_PROCESSING);
		ft_memset(to_ret[i], filling, g_config.map_width);
		ft_strcpy(to_ret[i], mass[i]);
		i++;
	}
	return (to_ret);
}
