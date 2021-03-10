/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:37:47 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/10 17:13:11 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

int main(int argc, char **argv)
{
	void 	*mlx;
	void	*mlx_wind;
	mlx = mlx_init();
	if (argc > 3 || argc < 2)
		print_cust_error(INVALID_NUMBER_OF_ARGS);
	else if (argc == 2)
		config_parser(argv[1]);
	else if (argc == 3)
	{
		config_parser(argv[2]);
		//make screenshot (--save )
	}
	mlx_wind = mlx_new_window(mlx, 720, 480, "test_window");
	mlx_loop(mlx);
}