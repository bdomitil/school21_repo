/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:37:43 by bdomitil          #+#    #+#             */
/*   Updated: 2021/02/23 04:16:12 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_HEADER_H
# define CUB_HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libft.h"

typedef enum	e_errors
{
	INVALID_NUMBER_OF_ARGS,
	ERROR_MAP_OPENING,
	INVALID_MAP
}				t_errors;

static char	*g_cust_errors[] = {"INVALID_NUMBER_OF_ARGUMENTS",
	"ERROR IN OPENING MAP", "INVALID_MAP"};

static char *g_valid_start[] = {"R", "NO", "SO", "WE",
	"EA", "S", "F", "C" , "\n"};

typedef struct	s_map
{
	int		wind_width;
	int		wind_heith;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*sprite_path;
	int		f_color[3];
	int		c_color[3];
}				t_map;

typedef enum e_red_in_map
{
	resolution,
	no,
	so,
	we,
	ea,
	sprite,
	f,
	c,
	map,
	error
}	t_red_in_map;

typedef struct s_found_inmap
{
	bool isfound[8];
}			t_found_inmap;

bool	map_parser(char *file_name);
void	print_cust_error(t_errors error);


#endif
