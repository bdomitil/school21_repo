/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:37:45 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/13 20:26:51 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

t_read_in_map	g_readinmap;
int				g_read_len;

static bool		check_filename(char *str)
{
	int len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len] == '.')
			break ;
		len--;
	}
	return (ft_strcmp(&str[len], ".cub"));
}

static bool		check_line(char *str)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (ft_strncmp(str, g_valid_start[i], ft_strlen(g_valid_start[i]))
			== 0)
		{
			if (g_almost_found[i] == true)
				print_cust_error(INVALID_MAP);
			g_readinmap = i;
			g_almost_found[i] = true;
			g_ready_to_read_map++;
			return (true);
		}
		else if (ft_isempty_str(str))
		{
			g_readinmap = empty;
			return (true);
		}
		i++;
	}
	print_cust_error(INVALID_MAP);
	return (false);
}

static void		parse_line(char *str)
{
	g_read_len += ft_strlen(str);
	if (g_readinmap == resolution)
		parse_resolution(str);
	else if (g_readinmap != f && g_readinmap != c && g_readinmap != empty)
		parse_pathes(str, g_readinmap);
	else if (g_readinmap != empty)
		parse_color(str, g_readinmap);
	else if (g_readinmap == empty)
		g_read_len += 1;
}

static void		parse_map(int fd, char *file_name)
{
	char	*temp_str;
	char	temp_chr;
	int		len;
	char	buff[g_read_len];

	len = 0;
	while (read(fd, &temp_chr, 1) == 1)
		len++;
	if (!(temp_str = (char*)ft_calloc(sizeof(char), len + 1)))
		print_cust_error(INVALID_MAP);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (!read(fd, buff, g_read_len) || !read(fd, temp_str, len))
		print_cust_error(ERROR_MAP_PROCESSING);
	check_map(temp_str);
	create_map(temp_str);
	verify_map_contour();
	free(temp_str);
}

bool			config_parser(char *file_name)
{
	char	*line;
	int		fd;

	line = NULL;
	g_read_len = 8;
	fd = open(file_name, O_RDONLY);
	if (check_filename(file_name) != false || fd < 0)
		print_cust_error(ERROR_MAP_OPENING);
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_line(line))
			print_cust_error(INVALID_MAP);
		else if (g_ready_to_read_map == 8)
		{
			parse_line(line);
			break ;
		}
		else
			parse_line(line);
		free(line);
	}
	free(line);
	parse_map(fd, file_name);
	close(fd);
	return (true);
}
