/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:45:42 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/28 21:55:14 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"
# define texheight 32
# define texwidth 32
//and counting texture height and width in texture to image 
//fix 
t_texture *text;

void	texture_to_image(t_texture *textures, char *path, int tex_num)
{
	t_image *image;
	int y;
	int x;

	y = 0;
	image = (t_image*)malloc(sizeof(t_image));
	if (!(image->img = mlx_xpm_file_to_image(g_mlx.mlx, path,
			&textures[tex_num].width, &textures[tex_num].height)))
		print_cust_error(ERROR_MAP_OPENING);
	image->addr = (int *) mlx_get_data_addr(image->img, &image->bpp,
			&image->line_length, &image->endian);
	if(!(textures[tex_num].buff = ft_calloc(sizeof(int),
				(image->height * image->width))))
		print_cust_error(PROCESSING_ERROR);
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			textures[tex_num].buff[image->width * y + x] = image->addr[image->width * y + x];
			x++;
		}
		y++;
	}
	// mlx_destroy_image(g_mlx.mlx, image->img);
}

int		calc(int **buff)
{
	int	x;
	int y;
	int lineheight;
	int drawstart;
	int drawend;
	int texnum;
	double wallx;
	int texx;
	double step;
	int texy;
	int color;
	double texpos;
	int cell_collor;
	int floor_collor;
	t_ray temp_ray;
	t_ray *ray;
	
	x = 0;
	y = 0;
	ray = &temp_ray;
	cell_collor = rgb_color_to_int(g_config.c_color[0],g_config.c_color[1], g_config.c_color[2]);
	floor_collor = rgb_color_to_int(g_config.f_color[0],g_config.f_color[1], g_config.f_color[2]);
	init_ray(ray);
	x = 0;
	y = 0;
	while (x < g_config.wind_width)
	{
		ray->camerax = 2 * x / (double)g_config.wind_width - 1;
		ray->dirx = g_mlx.player.dirx + g_mlx.player.planex * ray->camerax;
		ray->diry = g_mlx.player.diry + g_mlx.player.planey * ray->camerax;
		

		
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
			ray->dist = (ray->mapx - g_mlx.player.posx + (1 - ray->stepx) / 2) / ray->dirx;
		else
			ray->dist = (ray->mapy - g_mlx.player.posy + (1 - ray->stepy) / 2) / ray->diry;
			
		lineheight = (int)(g_config.wind_heith / ray->dist);
		drawstart = -lineheight / 2 + g_config.wind_heith / 2;
		if(drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + g_config.wind_heith / 2;
		if(drawend >= g_config.wind_heith)
			drawend = g_config.wind_heith - 1;

		//texture printing is here
		// texnum = g_config.map[ray->mapx][ray->mapy];  //case which wall is facing the player
		texnum = world_sides(ray);
		if (ray->side == 0)
			wallx = g_mlx.player.posy + ray->dist * ray->diry;
		else
			wallx = g_mlx.player.posx + ray->dist * ray->dirx;
		
		wallx -= floor(wallx);
		texx = (int)(wallx * (double)texwidth);
		
		if (ray->side == 0 && ray->dirx > 0)
			texx = texwidth - texx - 1;
			
		if (ray->side == 1 && ray->diry < 0)
			texx = texwidth - texx - 1;
			
		step = 1.0 * texheight / lineheight;
		texpos = (drawstart - g_config.wind_heith / 2 + lineheight / 2) * step;
		y = 0;
		// printf("start = %d\n end = %d\n", drawstart, drawend);
		while (y < drawstart)
		{
			color = rgb_color_to_int(233, 212, 23);
			buff[y][x] = color;
			y++;
		}
		while (y < drawend)
		{
			texy = (int)texpos & (texheight - 1);
			texpos += step;
			color = text[texnum].buff[texheight * texy + texx];
			// color = rgb_color_to_int(255, 146, 79);
			if (ray->side == 1)
				color = (color >> 1) & 8355711;
			buff[y][x] = color;
			y++;
		}
		while (y < g_config.wind_heith)
		{
			color = rgb_color_to_int(255, 255, 255);
			buff[y][x] = color;
			y++;
		}
		x++;
	}
	return (0);
}

int		loop_fun(int **buff)
{
	calc(buff);
	draw_to_screen(buff);
	return 0;
}

void mlx_draw(void)
{
	int				i;
	int				j;
	int				**buff;
	t_texture		*text;
	t_for_loop_list	list;
	
	i = 0;
	j = 0;
	if (!(buff = (int **)ft_calloc(sizeof(int*), g_config.wind_heith)))
		print_cust_error(PROCESSING_ERROR);
	while (i < g_config.wind_heith)
	{
		if(!(buff[i] = (int *)ft_calloc(sizeof(int), g_config.wind_width)))
			print_cust_error(PROCESSING_ERROR);
		i++;
	}
	i = 0;
	text = (t_texture*)malloc(sizeof(t_texture) * 5);
	prepare_textures(text);
	list.buff = buff;
	list.textures = text;
	// mlx_loop_hook(g_mlx.mlx, loop_fun, buff);
	mlx_loop_hook(g_mlx.mlx, &main_calc, &list);
	mlx_hook(g_mlx.mlx_wind, 2, 0, &key_press_event, buff);
	mlx_loop(g_mlx.mlx);
}