/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:51:13 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/14 22:14:10 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

static void		ray_config_start(t_ray *ray)
{
	ray->mapx = (int)g_mlx.player.posx;
	ray->mapy = (int)g_mlx.player.posy;
	ray->deltx = fabs(1 / ray->dirx);
	ray->delty = fabs(1 / ray->diry);
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidex = (g_mlx.player.posx - ray->mapx) * ray->deltx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidex = (ray->mapx + 1.0 - g_mlx.player.posx) * ray->deltx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidey = (g_mlx.player.posy - ray->mapy) * ray->delty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidey = (ray->mapy + 1.0 - g_mlx.player.posy) * ray->delty;
	}
	ray->hit = 0;
}

static void		finding_wall(t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidex < ray->sidey)
		{
			ray->sidex += ray->deltx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidey += ray->delty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (g_config.map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->dist = (ray->mapx - g_mlx.player.posx +
			(1 - ray->stepx) / 2) / ray->dirx;
	else
		ray->dist = (ray->mapy - g_mlx.player.posy +
		(1 - ray->stepy) / 2) / ray->diry;
}

static void		text_pos_findig(t_ray *ray, t_texture *text, t_math_vars *vars)
{
	vars->texnum = world_sides(ray);
	if (ray->side == 0)
		vars->wallx = g_mlx.player.posy + ray->dist * ray->diry;
	else
		vars->wallx = g_mlx.player.posx + ray->dist * ray->dirx;
	vars->wallx -= floor(vars->wallx);
	vars->texx = (int)(vars->wallx * (double)text[vars->texnum].width);
	if (ray->side == 0 && ray->dirx > 0)
		vars->texx = text[vars->texnum].width - vars->texx - 1;
	if (ray->side == 1 && ray->diry < 0)
		vars->texx = text[vars->texnum].width - vars->texx - 1;
	vars->step = 1.0 * text[vars->texnum].height / vars->lineheight;
	vars->texpos = (vars->drawstart - g_config.wind_heith / 2
		+ vars->lineheight / 2) * vars->step;
}

static void		buff_filling(t_for_loop_list *list, t_ray *ray, int x,
					t_math_vars *vars)
{
	int y;

	y = 0;
	vars->lineheight = (int)(g_config.wind_heith / ray->dist);
	vars->drawstart = -vars->lineheight / 2 + g_config.wind_heith / 2;
	if (vars->drawstart < 0)
		vars->drawstart = 0;
	vars->drawend = vars->lineheight / 2 + g_config.wind_heith / 2;
	if (vars->drawend >= g_config.wind_heith)
		vars->drawend = g_config.wind_heith - 1;
	y = fill_celling(list->buff, vars->drawstart, x);
	text_pos_findig(ray, list->textures, vars);
	list->zbuff[x] = ray->dist;
	while (y < vars->drawend)
	{
		vars->texy = (int)vars->texpos &
			(list->textures[vars->texnum].height - 1);
		vars->texpos += vars->step;
		list->buff[y][x] = list->textures[vars->texnum].buff
			[list->textures[vars->texnum].height * vars->texy + vars->texx];
		y++;
	}
	fill_floor(list->buff, x, y);
}

int				main_calc(t_for_loop_list *list)
{
	t_ray		ray;
	int			x;
	t_math_vars	vars;

	init_ray(&ray);
	moving_loop(&list->to_move);
	x = 0;
	while (x < g_config.wind_width)
	{
		ray.camerax = 2 * x / (double)g_config.wind_width - 1;
		ray.dirx = g_mlx.player.dirx + g_mlx.player.planex * ray.camerax;
		ray.diry = g_mlx.player.diry + g_mlx.player.planey * ray.camerax;
		ray_config_start(&ray);
		finding_wall(&ray);
		buff_filling(list, &ray, x, &vars);
		x++;
	}
	main_draw_sprite(list);
	if (!g_config.screeshot_need)
		draw_to_screen(list->buff);
	return (0);
}
