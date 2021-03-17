/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:32:07 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/17 20:07:24 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void ft_mlx_start()
{
	t_mlx_wind	*mlx_img;
	
	
	mlx_img = &g_mlx.mlx_image;
	g_mlx.mlx = mlx_init();
	g_mlx.mlx_wind= mlx_new_window(g_mlx.mlx, g_config.wind_width, 
									g_config.wind_heith, "test_window");
	mlx_img->img = mlx_new_image(g_mlx.mlx, g_config.wind_width, g_config.wind_heith);
	mlx_img->addr = mlx_get_data_addr(mlx_img->img, &mlx_img->bits_per_pixel, 
					&mlx_img->line_length, &mlx_img->endian);
	mlx_draw();
	// mlx_loop(g_mlx.mlx);
}