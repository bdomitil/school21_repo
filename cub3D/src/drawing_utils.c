/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:46:20 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/13 21:51:04 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

int		rgb_color_to_int(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	draw_to_screen(int **buff)
{
	int y;
	int x;

	mlx_clear_window(g_mlx.mlx, g_mlx.mlx_wind);
	y = 0;
	while (y < g_config.wind_heith)
	{
		x = 0;
		while (x < g_config.wind_width)
		{
			g_mlx.mlx_image.addr[y * g_config.wind_width + x] = buff[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_wind,
					g_mlx.mlx_image.img, 0, 0);
}

void	prepare_textures(t_texture *textures)
{
	texture_to_image(textures, g_config.no_path, 0);
	texture_to_image(textures, g_config.so_path, 1);
	texture_to_image(textures, g_config.ea_path, 2);
	texture_to_image(textures, g_config.we_path, 3);
	texture_to_image(textures, g_config.sprite_path, 4);
}

int		fill_celling(int **buff, int drawstart, int x)
{
	int y;
	int color;

	y = 0;
	while (y < drawstart)
	{
		color = rgb_color_to_int(g_config.c_color[0], g_config.c_color[1],
			g_config.c_color[2]);
		buff[y][x] = color;
		y++;
	}
	return (y);
}

void	fill_floor(int **buff, int x, int y)
{
	while (y < g_config.wind_heith)
	{
		buff[y][x] = rgb_color_to_int(g_config.f_color[0],
			g_config.f_color[1], g_config.f_color[2]);
		y++;
	}
}
