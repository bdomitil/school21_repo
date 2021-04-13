/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:35:53 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/13 22:01:42 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

int	rotate_left(void)
{
	double	olddirx;
	double	oldplanex;

	olddirx = g_mlx.player.dirx;
	g_mlx.player.dirx = g_mlx.player.dirx * cos(-0.06) -
		g_mlx.player.diry * sin(-0.06);
	g_mlx.player.diry = olddirx * sin(-0.06) + g_mlx.player.diry
		* cos(-0.06);
	oldplanex = g_mlx.player.planex;
	g_mlx.player.planex = g_mlx.player.planex * cos(-0.06) -
		g_mlx.player.planey * sin(-0.06);
	g_mlx.player.planey = oldplanex * sin(-0.06) +
		g_mlx.player.planey * cos(-0.06);
	return (1);
}

int	rotate_right(void)
{
	double	olddirx;
	double	oldplanex;

	olddirx = g_mlx.player.dirx;
	g_mlx.player.dirx = g_mlx.player.dirx * cos(0.06) -
		g_mlx.player.diry * sin(0.06);
	g_mlx.player.diry = olddirx * sin(0.06) +
		g_mlx.player.diry * cos(0.06);
	oldplanex = g_mlx.player.planex;
	g_mlx.player.planex = g_mlx.player.planex *
		cos(0.06) - g_mlx.player.planey * sin(0.06);
	g_mlx.player.planey = oldplanex * sin(0.06) +
		g_mlx.player.planey * cos(0.06);
	return (1);
}

int	key_release_event(int key, t_moving *to_move)
{
	if (key == W_KEY)
		to_move->forward = false;
	else if (key == S_KEY)
		to_move->back = false;
	else if (key == A_KEY)
		to_move->left = false;
	else if (key == D_KEY)
		to_move->right = false;
	else if (key == LEFT_KEY)
		to_move->rot_left = false;
	else if (key == RIGHT_KEY)
		to_move->rot_right = false;
	return (0);
}

int	key_press_event(int key, t_moving *to_move)
{
	if (key == W_KEY)
		to_move->forward = true;
	if (key == S_KEY)
		to_move->back = true;
	if (key == A_KEY)
		to_move->left = true;
	if (key == D_KEY)
		to_move->right = true;
	if (key == LEFT_KEY)
		to_move->rot_left = true;
	if (key == RIGHT_KEY)
		to_move->rot_right = true;
	if (key == ESC)
		exit(0);
	return (0);
}

int	moving_loop(t_moving *to_move)
{
	if (to_move->forward)
		move_forward();
	if (to_move->back)
		move_back();
	if (to_move->left)
		move_left();
	if (to_move->right)
		move_right();
	if (to_move->rot_right)
		rotate_right();
	if (to_move->rot_left)
		rotate_left();
	return (0);
}
