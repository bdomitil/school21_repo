/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:32:20 by bdomitil          #+#    #+#             */
/*   Updated: 2021/03/12 21:40:03 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void	init_aray(t_ray *ray)
{
	ray->dirx = 0;
	ray->diry = 0;
	ray->camerax = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->sidex = 0;
	ray->sidey = 0;
	ray->dx = 0;
	ray->dy = 0;
	ray->dist = 0;
}