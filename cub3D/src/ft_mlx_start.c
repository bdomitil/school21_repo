/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:32:07 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/14 22:15:31 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void	ft_mlx_start(void)
{
	g_mlx.mlx = mlx_init();
	if (!g_config.screeshot_need)
		g_mlx.mlx_wind = mlx_new_window(g_mlx.mlx, g_config.wind_width,
								g_config.wind_heith, "test_window");
	g_mlx.mlx_image.img = mlx_new_image(g_mlx.mlx, g_config.wind_width,
								g_config.wind_heith);
	g_mlx.mlx_image.addr = (int*)mlx_get_data_addr(g_mlx.mlx_image.img,
	&g_mlx.mlx_image.bpp, &g_mlx.mlx_image.line_length,
		&g_mlx.mlx_image.endian);
	mlx_draw();
}
