/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:37:43 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/28 21:53:22 by bdomitil         ###   ########.fr       */
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
# include "mlx_static.h"
# define A_KEY 0
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define ESC 53
# define LEFT_KEY 123
# define RIGHT_KEY 125
# define UP_KEY 124
# define DOWN_KEY 126



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
	ERROR_MAP_PROCESSING,
	PROCESSING_ERROR
}				t_errors;

static char	*g_cust_errors[] = {"INVALID_NUMBER_OF_ARGUMENTS",
	"ERROR IN OPENING MAP", "INVALID MAP", "INVALID RESOLUTION",
	"ERROR IN PATH TO SOMETHING IN CONFIG", "INVALID COLOR", 
	"WRONG NUMBER OF PLAYERS", "ERROR PROCESSING MAP", "PROCESSING ERROR"};
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
	no,
	so,
	we,
	ea,
	sprite,
	resolution,
	f,
	c,
	map,
	empty
}	t_read_in_map;

typedef struct	s_image
{
	int		width;
	int		height;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}				t_player;

typedef struct	s_texture
{
	bool	felt;
	int		*buff;
	int		width;
	int		height;
}				t_texture;

typedef struct	s_math_vars
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	double	wallx;
	int		texx;
	double	step;
	int		texy;
	int		color;
	double	texpos;
}				t_math_vars;

typedef struct	s_for_loop_list
{
	t_texture	*textures;
	int			**buff;
}				t_for_loop_list;

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
	double			deltx;
	double			delty;
	double			dist;
}				t_ray;

typedef struct	s_mlx
{
	void		*mlx;
	void		*mlx_wind;
	t_image	mlx_image;
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
void	free_double_mass(void **mass, int mass_heigth);
char	**dublicate_map(char **mass, char filling);
void	create_map(char *str);
void	player_configurate(int posx, int posy);
void	compare_two_maps(char **map1, char **map2);
void	ft_mlx_start();
void	init_ray(t_ray *ray);
void	mlx_draw(void);
int		fill_celling(int **buff, int drawstart, int x);
void	fill_floor(int **buff, int x, int y);
int		rgb_color_to_int(int red, int green, int blue);
void	draw_to_screen(int **buff);
int		world_sides(t_ray *ray);
void	texture_to_image(t_texture *textures, char *path, int tex_num);
void	prepare_textures(t_texture *textures);
int		key_press_event(int key, int **buff);
int		loop_fun(int **buff);
int		main_calc(t_for_loop_list *list);
/*global variables here*/
int g_ready_to_read_map;
/*shows whether we ready or nor to read map, 8 == ready /
any other means not */

t_config	g_config;
/*global struct of config */
t_mlx		g_mlx;
bool		g_almost_found[8];
/*is used to verify what is almost found*/

static char *g_valid_start[] = {"NO ", "SO ", "WE ",
	"EA ", "S ", "R", "F ", "C " , "\n"};
/*it is need to compare with what we read in map*/


#endif
