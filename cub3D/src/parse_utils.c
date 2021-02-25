/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:39:50 by bdomitil          #+#    #+#             */
/*   Updated: 2021/02/24 22:28:00 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void	parse_resolution(char *str)
{
	int		i;
	char	**splited_str;

	i = 0;
	splited_str = ft_split(&str[1], ' ');
	while (splited_str[i])
		i++;
	if (i != 2)
		print_cust_error(INVALID_RESOLUTION);
	if (ft_atoi_long(splited_str[0]) > INT32_MAX ||
		ft_atoi(splited_str[0]) < 10)
		print_cust_error(INVALID_RESOLUTION);
	if (ft_atoi_long(splited_str[1]) > INT32_MAX ||
		ft_atoi(splited_str[1]) < 10)
		print_cust_error(INVALID_RESOLUTION);
	g_config.wind_width = ft_atoi_long(splited_str[0]);
	g_config.wind_heith = ft_atoi(splited_str[1]);
	while (--i >= 0)
		free(splited_str[i]);
	free(splited_str);
}

void	parse_pathes(char *str, t_read_in_map readinmap)
{
	int		i;
	char	**splited_str;

	i = 0;
	splited_str = ft_split(&str[ft_strlen(g_valid_start[readinmap])],
		' ');
	while (splited_str[i])
		i++;
	if (i != 1)
		print_cust_error(INVALID_PATH);
	else if (open(splited_str[0], O_RDONLY) < 0)
		print_cust_error(INVALID_PATH);
	if (readinmap == no)
		g_config.no_path = ft_strdup(splited_str[0]);
	else if (readinmap == ea)
		g_config.no_path = ft_strdup(splited_str[0]);
	else if (readinmap == we)
		g_config.no_path = ft_strdup(splited_str[0]);
	else if (readinmap == so)
		g_config.no_path = ft_strdup(splited_str[0]);
	else if (readinmap == sprite)
		g_config.no_path = ft_strdup(splited_str[0]);
	while (--i >= 0)
		free(splited_str[i]);
	free(splited_str);
}

void	parse_color(char *str, t_read_in_map readinmap)
{
	int		i;
	int		j;
	char	**splited_str;
	int		temp;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(g_valid_start[readinmap]);
	splited_str = ft_split(&str[len], ',');
	while (splited_str[i])
		i++;
	if (i != 3)
		print_cust_error(INVALID_COLOR);
	while (j < 3)
		if (!ft_all_numeric(splited_str[j]) ||
		(temp = ft_atoi_long(splited_str[j])) > 255 || temp < 0)
			print_cust_error(INVALID_COLOR);
		else if (readinmap == c)
			g_config.c_color[j++] = temp;
		else if (readinmap == f)
			g_config.c_color[j++] = temp;
	while (--i >= 0)
		free(splited_str[i]);
	free(splited_str);
}
