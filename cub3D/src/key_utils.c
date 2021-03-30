/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:35:53 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/30 21:58:19 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

int		rotate_left(void)
{
	double	olddirx;
	double	oldplanex;
	
	olddirx = g_mlx.player.dirx;
	g_mlx.player.dirx = g_mlx.player.dirx * cos(-0.06) - g_mlx.player.diry * sin(-0.06);
	g_mlx.player.diry = olddirx * sin(-0.06) + g_mlx.player.diry * cos(-0.06);
	oldplanex = g_mlx.player.planex;
	g_mlx.player.planex = g_mlx.player.planex * cos(-0.06) - g_mlx.player.planey * sin(-0.06);
	g_mlx.player.planey = oldplanex * sin(-0.06) + g_mlx.player.planey * cos(-0.06);
	return (1);
}

int		rotate_right(void)
{
	double	olddirx;
	double	oldplanex;
	
	olddirx = g_mlx.player.dirx;
	g_mlx.player.dirx = g_mlx.player.dirx * cos(0.06) - g_mlx.player.diry * sin(0.06);
	g_mlx.player.diry = olddirx * sin(0.06) + g_mlx.player.diry * cos(0.06);
	oldplanex = g_mlx.player.planex;
	g_mlx.player.planex = g_mlx.player.planex * cos(0.06) - g_mlx.player.planey * sin(0.06);
	g_mlx.player.planey = oldplanex * sin(0.06) + g_mlx.player.planey * cos(0.06);
	return (1);
}

int	key_release_event(int key, t_moving *to_move)
{
	if (key == W_KEY)
		to_move->forward.pressed = false;		
	else if (key == S_KEY)
		to_move->back.pressed = false;
	else if (key == A_KEY)
		to_move->left.pressed = false;	
	else if (key == D_KEY)
		to_move->right.pressed = false;
	else if (key == LEFT_KEY)
		to_move->rot_left.pressed = false;
	else if (key == RIGHT_KEY)
		to_move->rot_right.pressed = false;
	return (0);
	
}

int key_press_event(int key, t_moving *to_move)
{

	if (key == W_KEY)
		to_move->forward.pressed = true;
	if (key == S_KEY)
		to_move->back.pressed = true;
	if (key == A_KEY)
		to_move->left.pressed = true;
	if (key == D_KEY)
		to_move->right.pressed = true;
	if (key == LEFT_KEY)
		to_move->rot_left.pressed = true;
	if (key == RIGHT_KEY)
		to_move->rot_right.pressed = true;
	if (key == ESC)
		exit(0);
	return (0);
}

int	moving_loop(t_moving *to_move)
{
	if (to_move->forward.pressed)
		move_forward();
	if (to_move->back.pressed)
		move_back();
	if (to_move->left.pressed)
		move_left();
	if (to_move->right.pressed)
		move_right();
	if (to_move->rot_right.pressed)
		rotate_right();
	if (to_move->rot_left.pressed)
		rotate_left();
	return (0);
}