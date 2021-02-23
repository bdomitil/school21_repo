/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:37:45 by bdomitil          #+#    #+#             */
/*   Updated: 2021/02/23 04:17:35 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

t_red_in_map g_redInMap;
t_found_inmap g_found_inmap;

static bool check_filename(char *str)
{
	int len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len] == '.')
			break;
		len--;
	}
	return (ft_strcmp(&str[len], ".cub"));
}

static bool check_line (char *str)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (ft_strnstr(str, g_valid_start[i], ft_strlen(g_valid_start[i]))
			!= NULL || ft_isempty_str(str))
		{
			g_redInMap = i;
			if (g_found_inmap.isfound[i])
				break;
			else 
				g_found_inmap.isfound[i] = true;
			return (true);
		}
		i++;
	}
	print_cust_error(INVALID_MAP);
	return false;
}

static void parse_line (char *str)
{
	
}

bool map_parser(char *file_name)
{
    char *line;
	int fd;

	line = NULL;
	if (check_filename(file_name) != false|| (fd = open(file_name, O_RDONLY)) < 0)
		print_cust_error(ERROR_MAP_OPENING);
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_line(line))
			print_cust_error(INVALID_MAP);
		else 
			parse_line(line);
	}
	close (fd);
	return true;
}