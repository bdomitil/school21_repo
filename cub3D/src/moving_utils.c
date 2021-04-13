/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:11:14 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/13 22:03:35 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

int		move_forward(void)
{
	double stepx;
	double stepy;

	stepx = g_mlx.player.posx + g_mlx.player.dirx * 0.1;
	stepy = g_mlx.player.posy + g_mlx.player.diry * 0.1;
	if (g_config.map[(int)stepy][(int)g_mlx.player.posx] == g_config.man ||
		g_config.map[(int)stepy][(int)g_mlx.player.posx] == '0')
		g_mlx.player.posy = stepy;
	if (g_config.map[(int)g_mlx.player.posy][(int)stepx] == g_config.man ||
		g_config.map[(int)g_mlx.player.posy][(int)stepx] == '0')
		g_mlx.player.posx = stepx;
	return (1);
}

int		move_back(void)
{
	double stepx;
	double stepy;

	stepx = g_mlx.player.posx - g_mlx.player.dirx * 0.1;
	stepy = g_mlx.player.posy - g_mlx.player.diry * 0.1;
	if (g_config.map[(int)stepy][(int)g_mlx.player.posx] == g_config.man ||
		g_config.map[(int)stepy][(int)g_mlx.player.posx] == '0')
		g_mlx.player.posy = stepy;
	if (g_config.map[(int)g_mlx.player.posy][(int)stepx] == g_config.man ||
		g_config.map[(int)g_mlx.player.posy][(int)stepx] == '0')
		g_mlx.player.posx = stepx;
	return (1);
}

int		move_left(void)
{
	double stepx;
	double stepy;

	stepx = g_mlx.player.posx - g_mlx.player.planex * 0.1;
	stepy = g_mlx.player.posy - g_mlx.player.planey * 0.1;
	if (g_config.map[(int)stepy][(int)g_mlx.player.posx] == g_config.man ||
		g_config.map[(int)stepy][(int)g_mlx.player.posx] == '0')
		g_mlx.player.posy = stepy;
	if (g_config.map[(int)g_mlx.player.posy][(int)stepx] == g_config.man ||
		g_config.map[(int)g_mlx.player.posy][(int)stepx] == '0')
		g_mlx.player.posx = stepx;
	return (1);
}

int		move_right(void)
{
	double stepx;
	double stepy;

	stepx = g_mlx.player.posx + g_mlx.player.planex * 0.1;
	stepy = g_mlx.player.posy + g_mlx.player.planey * 0.1;
	if (g_config.map[(int)stepy][(int)g_mlx.player.posx] == g_config.man ||
		g_config.map[(int)stepy][(int)g_mlx.player.posx] == '0')
		g_mlx.player.posy = stepy;
	if (g_config.map[(int)g_mlx.player.posy][(int)stepx] == g_config.man ||
		g_config.map[(int)g_mlx.player.posy][(int)stepx] == '0')
		g_mlx.player.posx = stepx;
	return (1);
}

void	init_to_move(t_moving *to_move)
{
	to_move->forward = false;
	to_move->back = false;
	to_move->left = false;
	to_move->right = false;
	to_move->rot_left = false;
	to_move->rot_right = false;
}
