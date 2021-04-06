/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:47:03 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/06 19:56:47 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_header.h"

void	sort_sprites(t_sprites *sprites)
{
	t_sprites	temp;
	int			i;
	int			k;

	i = 0;
	while (i < g_config.sprite_num)
	{
		k = 0;
		while (k < g_config.sprite_num - 1)
		{
			if (sprites[k].dist_to_player < sprites[k + 1].dist_to_player)
			{
				temp = sprites[k + 1];
				sprites[k + 1] = sprites[k];
				sprites[k] = temp;
			}
			k++;
		}
		i++;
	}
}

int		main_draw_sprite()
{
	int i;

	i = 0;
	t_sprites **sprites;
	
	if (!(sprites = malloc(sizeof(t_sprites*) * g_config.sprite_num)))
		print_cust_error(PROCESSING_ERROR);
	get_sprites_pos(sprites);
	return (1);
}