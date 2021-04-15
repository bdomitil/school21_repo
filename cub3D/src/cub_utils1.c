/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:21:00 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/15 17:21:29 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

int			world_sides(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->mapx > g_mlx.player.posx)
			return (2);
		else
			return (3);
	}
	else
	{
		if (ray->mapy > g_mlx.player.posy)
			return (1);
		else
			return (0);
	}
}

void		print_cust_error(t_errors error)
{
	write(2, g_cust_errors[error], ft_strlen(g_cust_errors[error]));
	exit(error + 1);
}

static void	west_east(void)
{
	if (g_config.man == 'W')
	{
		g_mlx.player.dirx = -1;
		g_mlx.player.diry = 0;
		g_mlx.player.planex = 0;
		g_mlx.player.planey = -0.66;
	}
	else if (g_config.man == 'E')
	{
		g_mlx.player.dirx = 1;
		g_mlx.player.diry = 0;
		g_mlx.player.planex = 0;
		g_mlx.player.planey = 0.66;
	}
}

void		player_configurate(int posx, int posy)
{
	g_mlx.player.posx = posx + 0.5;
	g_mlx.player.posy = posy + 0.5;
	if (g_config.man == 'W' || g_config.man == 'E')
		west_east();
	else if (g_config.man == 'S')
	{
		g_mlx.player.dirx = 0;
		g_mlx.player.diry = 1;
		g_mlx.player.planex = -0.66;
		g_mlx.player.planey = 0;
	}
	else
	{
		g_mlx.player.dirx = 0;
		g_mlx.player.diry = -1;
		g_mlx.player.planex = 0.66;
		g_mlx.player.planey = 0;
	}
}

int			close_window(void)
{
	exit(0);
}
