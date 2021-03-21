/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:21:00 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/21 22:18:23 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void	print_cust_error(t_errors error)
{
	write(2, g_cust_errors[error], ft_strlen(g_cust_errors[error]));
	exit(error + 1);
}

void	init_glob_vars(void)
{
	int i;

	i = 0;
	g_ready_to_read_map = 0;
	while (i < 3)
	{
		g_config.c_color[i] = 0;
		g_config.f_color[i++] = 0;
	}
}

void	player_configurate(int posx, int posy)
{
	g_mlx.player.posx = posy;
	g_mlx.player.posy = posx;
	g_mlx.player.planex = 0;
	g_mlx.player.planey = -0.66;
	if(g_config.man == 'W')
	{
		g_mlx.player.dirx = -1;
		g_mlx.player.diry = 0;
		// g_mlx.player.planex = 0;
		// g_mlx.player.planey = -0.66;
	}
	else if (g_config.man == 'E')
	{
		g_mlx.player.dirx = 1;
		g_mlx.player.diry = 0;
		// g_mlx.player.planex = 0;
		// g_mlx.player.planey = 0.66;
	}
	else if (g_config.man == 'S')
	{
		g_mlx.player.dirx = 0;
		g_mlx.player.diry = 1;
		// g_mlx.player.planex = -0.66;
		// g_mlx.player.planey = 0;
	}
	else 
	{
		g_mlx.player.dirx = 0;
		g_mlx.player.diry = -1;
		// g_mlx.player.planex = 0.66;
		// g_mlx.player.planey = 0;
	}
}