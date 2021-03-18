/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:45:42 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/18 18:33:00 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"
# define texheight 64
# define texwidth 64
void	texture_to_image(int *texture, char *path)
{
	t_image image;
	int y;
	int x;

	y = 0;
	
	if (!(image.img = mlx_xpm_file_to_image(g_mlx.mlx, path, &image.width, &image.height)))
		print_cust_error(ERROR_MAP_OPENING);
	image.addr = (int *) mlx_get_data_addr(image.img, &image.bpp, &image.line_length, &image.endian);
	while (y < image.height)
	{
		x= 0;
		while (x < image.width)
		{
			texture[image.width * y + x] = image.addr[image.width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(g_mlx.mlx, image.img);
}
void	draw_to_screen(int **buff)
{
	int y;
	int x;
	y = 0;
	while (y < g_config.wind_heith)
	{
		x = 0;
		while (x < g_config.wind_width)
		{
			g_mlx.mlx_image.addr[y * g_config.wind_width + x] = buff[y][x];
			x++;
		}
		y++;
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_wind, g_mlx.mlx_image.img, 0, 0);
	}
}
void	prepare_textures(int **textures)
{
	texture_to_image(textures[0], g_config.no_path);
	texture_to_image(textures[1], g_config.so_path);
	texture_to_image(textures[2], g_config.we_path);
	texture_to_image(textures[3], g_config.ea_path);
	texture_to_image(textures[4], g_config.sprite_path);
}
int		calc(t_ray *ray, int **textures, int **buff)
{
	int	x;
	int y;
	int lineheight;
	int drawstart;
	int drawend;
	int texnum;
	double wallx;
	int texx;
	int step;
	int texy;
	int color;
	double texpos;
	
	x = 0;
	while (x < g_config.wind_width)
	{
		ray->camerax = 2 * x / (double)g_config.wind_width - 1;
		ray->dirx = ray->diry + g_mlx.player.planex * ray->camerax;
		ray->diry = ray->diry + g_mlx.player.planey * ray->camerax;
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
			ray->sidex= (ray->sidex + 1.0 - g_mlx.player.posx) * ray->deltx;
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

		while (ray->hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
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
			//Check if ray has hit a wall
			if (g_config.map[ray->mapx][ray->mapy] > 0) ray->hit = 1;
		}
		if (ray->side == 0)
			ray->dist = (ray->mapx - g_mlx.player.posx + (1 - ray->stepx) / 2) / ray->dirx;
		else
			ray->dist = (ray->mapy - g_mlx.player.posy + (1 - ray->stepy) / 2) / ray->diry;
		//Calculate height of line to draw on screen
		lineheight = (int)(g_config.map_height / ray->dist);
		//calculate lowest and highest pixel to fill in current stripe
		drawstart = -lineheight / 2 + g_config.map_height / 2;
		if(drawstart < 0)
			drawstart = 0;
		 drawend = lineheight / 2 + g_config.map_height / 2;
		if(drawend >= g_config.map_height)
			drawend = g_config.map_height - 1;

		// texturing calculations
		 texnum = g_config.map[ray->mapx][ray->mapy];

		// calculate value of wallX
		if (ray->side == 0)
			wallx = g_mlx.player.posy + ray->dist * ray->diry;
		else
			wallx = g_mlx.player.posx + ray->dist * ray->dirx;
		wallx -= floor(wallx);

		// x coordinate on the texture
		texx = (int)(wallx * (double)texwidth);
		if (ray->side == 0 && ray->dirx > 0)
			texx = texwidth - texx - 1;
		if (ray->side == 1 && ray->diry < 0)
			texx = texwidth - texx - 1;

		// How much to increase the texture coordinate perscreen pixel
		step = 1.0 * texheight / lineheight;
		// Starting texture coordinate
		texpos = (drawstart - g_config.wind_heith / 2 + lineheight / 2) * step;
		y = drawstart;
		while (y < drawend)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			texy = (int)texpos & (texheight - 1);
			texpos += step;
			color = textures[texnum][texheight * texy + texy];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (ray->side == 1)
				color = (color >> 1) & 8355711;
			buff[y][x] = color;
			y++;
		}
		x++;
	}
	draw_to_screen(buff);
	return (0);
}
void mlx_draw(void)
{
	t_ray ray;
	int i;
	int j;
	int **textures;
	int **buff;
	
	g_mlx.mlx = mlx_init();
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
	if (!(textures = (int **)ft_calloc(sizeof(int*), 5)))
			print_cust_error(PROCESSING_ERROR);
	while(i < 5)
	{
		if (!(textures[i] = (int *)ft_calloc(sizeof(int), (texheight * texwidth))))
			print_cust_error(PROCESSING_ERROR);
		i++;
	}	
	prepare_textures(textures);
	init_ray(&ray);
	g_mlx.mlx = mlx_init();
	g_mlx.mlx_wind= mlx_new_window(g_mlx.mlx, g_config.wind_width, 
									g_config.wind_heith, "test_window");
	g_mlx.mlx_image.img = mlx_new_image(g_mlx.mlx, g_config.wind_width, g_config.wind_heith);
	g_mlx.mlx_image.addr = (int*)mlx_get_data_addr(g_mlx.mlx_image.img, &g_mlx.mlx_image.bpp, 
					&g_mlx.mlx_image.line_length, &g_mlx.mlx_image.endian);
	mlx_loop_hook(g_mlx.mlx, calc, buff);
	mlx_loop(g_mlx.mlx);
}