/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:45:42 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/24 16:13:59 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void	texture_to_image(t_texture *textures, char *path, int tex_num)
{
	t_image	image;
	int		y;
	int		x;

	y = 0;
	if (!(image.img = mlx_xpm_file_to_image(g_mlx.mlx, path,
			&image.width, &image.height)))
		print_cust_error(INVALID_TEXTURE);
	image.addr = (int *)mlx_get_data_addr(image.img, &image.bpp,
			&image.line_length, &image.endian);
	if (!(textures[tex_num].buff = ft_calloc(sizeof(int),
				(image.width * image.height))))
		print_cust_error(PROCESSING_ERROR);
	while (y < image.height)
	{
		x = -1;
		while (++x < image.width)
			textures[tex_num].buff[image.width * y + x] =
				image.addr[image.width * y + x];
		y++;
	}
	textures[tex_num].width = image.width;
	textures[tex_num].height = image.height;
}

void	mlx_draw(void)
{
	int				i;
	int				j;
	t_for_loop_list	list;

	i = -1;
	j = 0;
	if (!(list.buff = (int **)ft_calloc(sizeof(int*), g_config.wind_heith)))
		print_cust_error(PROCESSING_ERROR);
	while (++i < g_config.wind_heith)
		if (!(list.buff[i] = (int *)ft_calloc(sizeof(int),
			g_config.wind_width)))
			print_cust_error(PROCESSING_ERROR);
	i = 0;
	if (!(list.textures = (t_texture*)ft_calloc(sizeof(t_texture), 5)))
		print_cust_error(PROCESSING_ERROR);
	if (!(list.zbuff = ft_calloc(sizeof(double), g_config.wind_width)))
		print_cust_error(PROCESSING_ERROR);
	prepare_textures(list.textures);
	screen_save(&list);
	init_to_move(&list.to_move);
	mlx_hook(g_mlx.mlx_wind, 10, 0, &release_after_focus_out, &list.to_move);
	mlx_hook(g_mlx.mlx_wind, 9, 0, &release_after_focus_out, &list.to_move);
	mlx_hook(g_mlx.mlx_wind, 3, 0, &key_release_event, &list.to_move);
	mlx_hook(g_mlx.mlx_wind, 2, 0, &key_press_event, &list.to_move);
	mlx_hook(g_mlx.mlx_wind, 17, 0, &close_window, NULL);
	mlx_loop_hook(g_mlx.mlx, &main_calc, &list);
	mlx_loop(g_mlx.mlx);
}
