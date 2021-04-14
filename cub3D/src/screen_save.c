/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:13:46 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/14 23:27:33 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

static void	fill_header(int fd)
{
	unsigned char	header[14];
	int		count;
	int res;

	ft_memset(header, 0, 14);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	count = g_mlx.mlx_image.height * g_mlx.mlx_image.width
		* g_mlx.mlx_image.bpp / 8 + 54;
	header[2] = (unsigned char)(count);
	header[3] = (unsigned char)(count >> 8);
	header[4] = (unsigned char)(count >> 16);
	header[5] = (unsigned char)(count >> 24);
	header[10] = (unsigned char)(54);
	if ((res = write(fd, header, 14)) == -1)
		print_cust_error(ERROR_SCREENSAVE);
}

static void	fill_header_info(int fd)
{
	unsigned char	header[40];
	int		count;
	int res;

	ft_memset(header, 0, 40);
	header[0] = (unsigned char)(40);
	count= g_mlx.mlx_image.width;
	header[4] = (unsigned char)(count);
	header[5] = (unsigned char)(count >> 8);
	header[6] = (unsigned char)(count >> 16);
	header[7] = (unsigned char)(count >> 24);
	count = g_mlx.mlx_image.height;
	header[8] = (unsigned char)(count);
	header[9] = (unsigned char)(count >> 8);
	header[10] = (unsigned char)(count >> 16);
	header[11] = (unsigned char)(count >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)g_mlx.mlx_image.bpp;
	if ((res = write(fd, header, 40)) == -1)
		print_cust_error(ERROR_SCREENSAVE);
}

static void	fill_pixels(int fd, int **buff)
{
	int i;
	int res;
	int j;
	int k;
	int skip;

	i = g_config.wind_heith;
	skip = 0;
	while (i >= 0)
	{
		j = 0;
		while (j < g_config.wind_width)
		{
				if ( (res = write(fd, &buff[i][j], 4)) == -1)
					print_cust_error(ERROR_SCREENSAVE);
		
			j++;
		
		}
		i--;
	}
}

void	screen_save(t_for_loop_list *list)
{
	int fd;
	char *filename;

	filename = "screenshot.bmp";
	if ((fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0722)) > 0)
	{
		fill_header(fd);
		fill_header_info(fd);
		fill_pixels(fd, list->buff);
		close(fd);
	}
}