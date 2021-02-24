/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:37:43 by bdomitil          #+#    #+#             */
/*   Updated: 2021/02/24 21:20:36 by bdomitil         ###   ########.fr       */
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
/*part of structures for showing errors*/
typedef enum	e_errors
{
	INVALID_NUMBER_OF_ARGS,
	ERROR_MAP_OPENING,
	INVALID_MAP,
	INVALID_RESOLUTION,
	INVALID_PATH,
	INVALID_COLOR
}				t_errors;

static char	*g_cust_errors[] = {"INVALID_NUMBER_OF_ARGUMENTS",
	"ERROR IN OPENING MAP", "INVALID MAP", "INVALID RESOLUTION",
	"ERROR IN PATH TO SOMETHING IN CONFIG", "INVALID COLOR"};
/*end of part*/

typedef struct	s_config
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
}				t_config;
/*part of structures for verifying .cub file */

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
	empty
}	t_read_in_map;


/*end of part*/

bool	map_parser(char *file_name);
void	print_cust_error(t_errors error);
void	init_glob_vars();
void	parse_resolution(char *str);
void	parse_pathes(char *str, t_read_in_map readInmap);
void	parse_color(char *str, t_read_in_map readInmap);

/*global variables here*/
int g_ready_to_read_map;
/*shows whether we ready or nor to read map, 8 == ready /
any other means not */

t_config g_config;
/*global struct of config */

static char *g_valid_start[] = {"R ", "NO ", "SO ", "WE ",
	"EA ", "S ", "F ", "C " , "\n"};
/*it is need to compare with what we read in map*/


#endif