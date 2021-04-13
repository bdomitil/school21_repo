/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:49:39 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/13 22:27:07 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void			create_map(char *str)
{
	int		longest;
	char	**temp_str;
	int		i;

	i = 0;
	longest = 0;
	if (!(temp_str = ft_split(str, '\n')))
		print_cust_error(ERROR_MAP_PROCESSING);
	while (temp_str[i])
	{
		if ((int)ft_strlen(temp_str[i]) > longest)
			longest = ft_strlen(temp_str[i]);
		i++;
	}
	while (i <= 0)
		if (!(g_config.map[i--] = ft_calloc(1, longest + 1)))
			print_cust_error(ERROR_MAP_PROCESSING);
	g_config.map_width = longest;
	g_config.map_height = count_map_heigth(temp_str);
	g_config.map = dublicate_map(temp_str, ' ');
	free_double_mass((void **)temp_str, g_config.map_height);
}

static bool		just_numerics(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		if (!ft_isdigit(str[i++]))
			return (false);
	return (true);
}

int				count_map_heigth(char **map)
{
	int i;
	int height;

	i = 0;
	height = 0;
	while (map[i++])
		height++;
	if (height < 3)
		print_cust_error(INVALID_MAP);
	return (height);
}

void			check_player(bool *player, char q)
{
	if (q == 'W' || q == 'E' || q == 'S' || q == 'N')
	{
		if (*player)
			print_cust_error(INVALID_PLAYER);
		else
		{
			*player = true;
			g_config.man = q;
		}
	}
}

bool			verify_color_parse(char *str)
{
	int i;
	int commas;

	i = 0;
	commas = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0' && commas != 2)
	{
		if (str[i] == ',')
		{
			commas++;
			if (!ft_isdigit(str[i + 1]) || !ft_isdigit(str[i - 1]))
				print_cust_error(INVALID_COLOR);
		}
		i++;
	}
	if (commas > 2 || !just_numerics(&str[i]))
		print_cust_error(INVALID_COLOR);
	return (true);
}
