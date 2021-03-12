/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:37:43 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/12 21:36:22 by bdomitil         ###   ########.fr       */
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
# include "mlx.h"
/*part of structures for showing errors*/
typedef enum	e_errors
{
	INVALID_NUMBER_OF_ARGS,
	ERROR_MAP_OPENING,
	INVALID_MAP,
	INVALID_RESOLUTION,
	INVALID_PATH,
	INVALID_COLOR,
	INVALID_PLAYER,
	ERROR_MAP_PROCESSING
}				t_errors;

static char	*g_cust_errors[] = {"INVALID_NUMBER_OF_ARGUMENTS",
	"ERROR IN OPENING MAP", "INVALID MAP", "INVALID RESOLUTION",
	"ERROR IN PATH TO SOMETHING IN CONFIG", "INVALID COLOR", 
	"WRONG NUMBER OF PLAYERS", "ERROR PROCESSING MAP"};
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
	char	**map;
	int		map_height;
	int		map_width;
	char	man;
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

typedef struct s_ray
{
	double			dirx;
	double			diry;
	double			camerax;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			sidex;
	double			sidey;
	double			dx;
	double			dy;
	double			dist;
}				t_ray;

typedef struct	s_mlx_wind
{
	void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}				t_mlx_wind;

typedef struct	s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
}				t_player;

typedef struct	s_plane
{
	double		x;
	double		y;
}				t_plane;

typedef struct	s_mlx
{
	void		*mlx;
	void		*mlx_wind;
	t_mlx_wind	mlx_image;
	t_ray		ray;
	t_player	player;
}				t_mlx;
/*end of part*/

bool	config_parser(char *file_name);
void	print_cust_error(t_errors error);
void	init_glob_vars();
void	parse_resolution(char *str);
void	parse_pathes(char *str, t_read_in_map readinmap);
void	parse_color(char *str, t_read_in_map readinmap);
void	check_map(char *str);
void	configurate_map(char *str);
bool	verify_color_parse(char *str);
void	flood_fill(int i, int j, int width);
int		count_map_heigth(char **map);
void	check_player(bool *player,char q);
void	print_map(); //delete before finish
void	verify_map_contour(void);
void	free_double_mass(char **mass, int mass_heigth);
char	**dublicate_map(char **mass, char filling);
void	create_map(char *str);
void	player_configurate(int posx, int posy);
void	compare_two_maps(char **map1, char **map2);
void	mlx_start();
void	init_aray(t_ray *ray);
/*global variables here*/
int g_ready_to_read_map;
/*shows whether we ready or nor to read map, 8 == ready /
any other means not */

t_config	g_config;
/*global struct of config */
t_mlx		g_mlx;
bool		g_almost_found[8];
/*is used to verify what is almost found*/

static char *g_valid_start[] = {"R ", "NO ", "SO ", "WE ",
	"EA ", "S ", "F ", "C " , "\n"};
/*it is need to compare with what we read in map*/


#endif
