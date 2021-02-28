/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:21:00 by bdomitil          #+#    #+#             */
/*   Updated: 2021/02/26 16:04:36 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void	print_cust_error(t_errors error)
{
	write(2, g_cust_errors[error], ft_strlen(g_cust_errors[error]));
	exit(error + 1);
}

void	init_glob_vars(void)
{
	int i;

	i = 0;
	g_ready_to_read_map = 0;
	while (i < 3)
	{
		g_config.c_color[i] = 0;
		g_config.f_color[i++] = 0;
	}
}
