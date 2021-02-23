/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:37:47 by bdomitil          #+#    #+#             */
/*   Updated: 2021/02/22 19:46:00 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

int main(int argc, char **argv)
{
	if (argc > 3 || argc < 2)
		print_cust_error(INVALID_NUMBER_OF_ARGS);
	else if (argc == 2)
		map_parser(argv[1]);
	else if (argc == 3)
	{
		map_parser(argv[2]);
		//make screenshot (--save )
	}
}