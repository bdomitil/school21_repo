/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:21:00 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/28 19:33:41 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

int		world_sides(t_ray *ray)
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
		if (ray->mapx > g_mlx.player.diry)
			return (1);
		else 
			return (0);
	}
}

void	print_cust_error(t_errors error)
{
	write(2, g_cust_errors[error], ft_strlen(g_cust_errors[error]));
	exit(error + 1);
}

int		key_press_event(int key, int **buff)
{
	double stepx;
	double stepy;
	double olddirx;
	double oldplanex;

	if (key == W_KEY)
	{
		stepx = g_mlx.player.posx + g_mlx.player.dirx * 0.1;
		stepy = g_mlx.player.posy + g_mlx.player.diry * 0.1;
		if (g_config.map[(int)stepy][(int)g_mlx.player.posx] != '1')
			g_mlx.player.posy = stepy;
		if (g_config.map[(int)g_mlx.player.posy][(int)stepx] != '1')
			g_mlx.player.posx = stepx;
	}
	if (key == S_KEY)
	{
		stepx = g_mlx.player.posx - g_mlx.player.dirx * 0.1;
		stepy = g_mlx.player.posy - g_mlx.player.diry * 0.1;
		if (g_config.map[(int)stepy][(int)g_mlx.player.posx] != '1')
			g_mlx.player.posy = stepy;
		if (g_config.map[(int)g_mlx.player.posy][(int)stepx] != '1')
			g_mlx.player.posx = stepx;
	}
	if (key == A_KEY)
	{
		olddirx = g_mlx.player.dirx;
		g_mlx.player.dirx = g_mlx.player.dirx * cos(-0.1) - g_mlx.player.diry * sin(-0.1);
		g_mlx.player.diry = olddirx * sin(-0.1) + g_mlx.player.diry * cos(-0.1);
		oldplanex = g_mlx.player.planex;
		g_mlx.player.planex = g_mlx.player.planex * cos(-0.1) - g_mlx.player.planey * sin(-0.1);
		g_mlx.player.planey = g_mlx.player.planex * sin(-0.1) + g_mlx.player.planey * cos(-0.1); 
	}
	if (key == D_KEY)
	{
		olddirx = g_mlx.player.dirx;
		g_mlx.player.dirx = g_mlx.player.dirx * cos(0.1) - g_mlx.player.diry * sin(0.1);
		g_mlx.player.diry = olddirx * sin(0.1) + g_mlx.player.diry * cos(0.1);
		oldplanex = g_mlx.player.planex;
		g_mlx.player.planex = g_mlx.player.planex * cos(0.1) - g_mlx.player.planey * sin(0.1);
		g_mlx.player.planey = g_mlx.player.planex * sin(0.1) + g_mlx.player.planey * cos(0.1); 
	}
	if (key == ESC)
		exit(0);
	// loop_fun(buff);
	// printf("x pos = %d\n,y pos = %d\n unit = %c\n",(int) g_mlx.player.posx ,(int) g_mlx.player.posy, g_config.map[(int) g_mlx.player.posx ][(int) g_mlx.player.posy]);
	return (0);
}

void	player_configurate(int posx, int posy)
{
	g_mlx.player.posx = posx;
	g_mlx.player.posy = posy;
	if(g_config.man == 'W')
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