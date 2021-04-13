/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:47:03 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/13 22:39:51 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void		sort_sprites(t_sprites *sprites)
{
	t_sprites	temp;
	int			i;
	int			k;

	i = 0;
	while (i < g_config.sprite_num)
	{
		k = 0;
		while (k < g_config.sprite_num - 1)
		{
			if (sprites[k].dist_to_player < sprites[k + 1].dist_to_player)
			{
				temp = sprites[k + 1];
				sprites[k + 1] = sprites[k];
				sprites[k] = temp;
			}
			k++;
		}
		i++;
	}
}

static void	get_sprite_color_in_loop(t_sprite_vars *vars, t_for_loop_list *list)
{
	int k;

	while (vars->stripe < vars->drawendx)
	{
		vars->texx = (int)((256 * (vars->stripe - (-vars->width
		/ 2 + vars->screenx)) * list->textures[4].width / vars->width) / 256);
		if (vars->transy > 0 && vars->stripe > 0 && vars->stripe <
			g_config.wind_width && vars->transy < list->zbuff[vars->stripe])
		{
			k = vars->drawstarty;
			while (k < vars->drawendy)
			{
				vars->d = (k - vars->movescreen) * 256 -
					g_config.wind_heith * 128 + vars->height * 128;
				vars->texy = ((vars->d * list->textures[4].height)
					/ vars->height) / 256;
				vars->color = list->textures[4].buff[list->textures[4].width *
					vars->texy + vars->texx];
				if ((vars->color & 0x00FFFFFF) != 0)
					list->buff[k][vars->stripe] = vars->color;
				k++;
			}
		}
		vars->stripe++;
	}
}

static void	config_sprite_vars(t_sprite_vars *vars)
{
	vars->invdet = 1.0 / (g_mlx.player.planex * g_mlx.player.diry -
		g_mlx.player.dirx * g_mlx.player.planey);
	vars->transx = vars->invdet * (g_mlx.player.diry * vars->x -
		g_mlx.player.dirx * vars->y);
	vars->transy = vars->invdet * (-g_mlx.player.planey * vars->x +
		g_mlx.player.planex * vars->y);
	vars->screenx = (int)((g_config.wind_width / 2) *
		(1 + vars->transx / vars->transy));
	vars->movescreen = (int)(0.0 / vars->transy);
	vars->height = (int)fabs((g_config.wind_heith / vars->transy) / 1);
	vars->drawstarty = -vars->height / 2 +
		g_config.wind_heith / 2 + vars->movescreen;
}

void		draw_sprites(t_sprites *sprites, t_for_loop_list *list)
{
	int				i;
	t_sprite_vars	vars;

	i = -1;
	while (++i < g_config.sprite_num)
	{
		vars.x = sprites[i].x - g_mlx.player.posx;
		vars.y = sprites[i].y - g_mlx.player.posy;
		config_sprite_vars(&vars);
		if (vars.drawstarty < 0)
			vars.drawstarty = 0;
		vars.drawendy = vars.height
			/ 2 + g_config.wind_heith / 2 + vars.movescreen;
		if (vars.drawendy >= g_config.wind_heith)
			vars.drawendy = g_config.wind_heith - 1;
		vars.width = (int)fabs((g_config.wind_heith / vars.transy) / 1);
		vars.drawstartx = -vars.width / 2 + vars.screenx;
		if (vars.drawstartx < 0)
			vars.drawstartx = 0;
		vars.drawendx = vars.width / 2 + vars.screenx;
		if (vars.drawendx >= g_config.wind_width)
			vars.drawendx = g_config.wind_width - 1;
		vars.stripe = vars.drawstartx;
		get_sprite_color_in_loop(&vars, list);
	}
}

void		main_draw_sprite(t_for_loop_list *list)
{
	t_sprites *sprites;

	if (!(sprites = malloc(sizeof(t_sprites) * g_config.sprite_num)))
		print_cust_error(PROCESSING_ERROR);
	get_sprites_pos(sprites);
	sort_sprites(sprites);
	draw_sprites(sprites, list);
	free(sprites);
}
