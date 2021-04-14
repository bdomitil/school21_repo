/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:39:50 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/14 22:08:04 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void			parse_resolution(char *str)
{
	int		i;
	char	**sp_str;
	int		sc_wd;
	int		sc_hg;

	i = 0;
	mlx_get_screen_size(&sc_wd, &sc_hg);
	sp_str = ft_split(&str[1], ',');
	while (sp_str[i])
		i++;
	if (i != 2 || !verify_color_parse(str))
		print_cust_error(INVALID_RESOLUTION);
	if (ft_atoi_long(sp_str[0]) <= 0 || ft_atoi_long(sp_str[1]) <= 0)
		print_cust_error(INVALID_RESOLUTION);
	if ((ft_atoi_long(sp_str[0]) > sc_wd || ft_atoi_long(sp_str[0]) < 50)
		& !g_config.screeshot_need)
		g_config.wind_width = sc_wd;
	else
		g_config.wind_width = ft_atoi_long(sp_str[0]);
	if ((ft_atoi_long(sp_str[1]) > sc_wd || ft_atoi(sp_str[1]) < 50)
		& !g_config.screeshot_need)
		g_config.wind_heith = sc_hg;
	else
		g_config.wind_heith = ft_atoi(sp_str[1]);
	free_double_mass((void **)sp_str, i);
}

void			parse_pathes(char *str, t_read_in_map readinmap)
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
		g_config.ea_path = ft_strdup(splited_str[0]);
	else if (readinmap == we)
		g_config.we_path = ft_strdup(splited_str[0]);
	else if (readinmap == so)
		g_config.so_path = ft_strdup(splited_str[0]);
	else if (readinmap == sprite)
		g_config.sprite_path = ft_strdup(splited_str[0]);
	free_double_mass((void **)splited_str, i);
}

void			parse_color(char *str, t_read_in_map readinmap)
{
	int				i;
	int				j;
	char			**splited_str;
	int				temp;
	long long int	len;

	i = 0;
	j = 0;
	len = ft_strlen(g_valid_start[readinmap]);
	verify_color_parse(&str[len]);
	splited_str = ft_split(&str[len], ',');
	while (splited_str[i])
		i++;
	while (j < 3)
		if (!ft_all_numeric(splited_str[j]) || i < 3 ||
		(temp = ft_atoi_long(splited_str[j])) > 255 || temp < 0)
			print_cust_error(INVALID_COLOR);
		else if (readinmap == c)
			g_config.c_color[j++] = temp;
		else if (readinmap == f)
			g_config.f_color[j++] = temp;
	free_double_mass((void **)splited_str, i);
}

void			verify_map_contour(void)
{
	int		i;
	int		j;
	int		width;
	char	**temp_map;

	i = 0;
	j = 0;
	temp_map = dublicate_map(g_config.map, '-');
	while (i < g_config.map_height)
	{
		width = ft_strlen(g_config.map[i]);
		while (j < width)
		{
			if (g_config.map[i][j] == g_config.man)
				player_configurate(j, i);
			flood_fill(i, j, width);
			j++;
		}
		j = 0;
		i++;
	}
	compare_two_maps(temp_map, g_config.map);
	free_double_mass((void **)temp_map, g_config.map_height);
}

void			check_map(char *str)
{
	int		i;
	char	q;
	bool	player;

	i = 0;
	player = false;
	while (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		q = str[i];
		if (q == 'W' || q == 'E' || q == 'S' || q == 'N')
			check_player(&player, q);
		else if (q != '1' && q != '2' && q != '0' &&
		q != ' ' && q != '\n')
			print_cust_error(INVALID_MAP);
		else if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
			print_cust_error(INVALID_MAP);
		else if (str[i] == '2')
			g_config.sprite_num++;
		i++;
	}
	if (!player)
		print_cust_error(INVALID_PLAYER);
}
