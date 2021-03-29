/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:11:14 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/29 22:23:00 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"


int		key_press_event(int key)
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
		stepx = g_mlx.player.posx - g_mlx.player.planex * 0.1;
		stepy = g_mlx.player.posy - g_mlx.player.planey * 0.1;
		if (g_config.map[(int)stepy][(int)g_mlx.player.posx] != '1')
			g_mlx.player.posy = stepy;
		if (g_config.map[(int)g_mlx.player.posy][(int)stepx] != '1')
			g_mlx.player.posx = stepx;
	}

	if (key == D_KEY)
	{
		stepx = g_mlx.player.posx + g_mlx.player.planex * 0.1;
		stepy = g_mlx.player.posy + g_mlx.player.planey * 0.1;
		if (g_config.map[(int)stepy][(int)g_mlx.player.posx] != '1')
			g_mlx.player.posy = stepy;
		if (g_config.map[(int)g_mlx.player.posy][(int)stepx] != '1')
			g_mlx.player.posx = stepx;
	}

	if (key == LEFT_KEY)
	{
		olddirx = g_mlx.player.dirx;
		g_mlx.player.dirx = g_mlx.player.dirx * cos(-0.1) - g_mlx.player.diry * sin(-0.1);
		g_mlx.player.diry = olddirx * sin(-0.1) + g_mlx.player.diry * cos(-0.1);
		oldplanex = g_mlx.player.planex;
		g_mlx.player.planex = g_mlx.player.planex * cos(-0.1) - g_mlx.player.planey * sin(-0.1);
		g_mlx.player.planey = oldplanex * sin(-0.1) + g_mlx.player.planey * cos(-0.1); 
	}
	if (key == RIGHT_KEY)
	{
		olddirx = g_mlx.player.dirx;
		g_mlx.player.dirx = g_mlx.player.dirx * cos(0.1) - g_mlx.player.diry * sin(0.1);
		g_mlx.player.diry = olddirx * sin(0.1) + g_mlx.player.diry * cos(0.1);
		oldplanex = g_mlx.player.planex;
		g_mlx.player.planex = g_mlx.player.planex * cos(0.1) - g_mlx.player.planey * sin(0.1);
		g_mlx.player.planey = oldplanex * sin(0.1) + g_mlx.player.planey * cos(0.1); 
	}
	if (key == ESC)
		exit(0);
	// loop_fun(buff);
	// printf("x pos = %d\n,y pos = %d\n unit = %c\n",(int) g_mlx.player.posx ,(int) g_mlx.player.posy, g_config.map[(int) g_mlx.player.posx ][(int) g_mlx.player.posy]);
	return (0);
}