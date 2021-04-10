/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:47:03 by bdomitil          #+#    #+#             */
/*   Updated: 2021/04/10 18:05:55 by bdomitil         ###   ########.fr       */
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

void	draw_sprites(t_sprites *sprites, t_for_loop_list *list)
{
	for(int i = 0; i < g_config.sprite_num; i++)
	{
		double spriteX = sprites[i].x - g_mlx.player.posx;
		
		double spriteY = sprites[i].y - g_mlx.player.posy;



		double invDet = 1.0 / (g_mlx.player.planex * g_mlx.player.diry - g_mlx.player.dirx * g_mlx.player.planey);

		double transformX = invDet * (g_mlx.player.diry * spriteX - g_mlx.player.dirx * spriteY);
		double transformY = invDet * (-g_mlx.player.planey * spriteX + g_mlx.player.planex * spriteY); 

		int spriteScreenX = (int)((g_config.wind_width / 2) * (1 + transformX / transformY));


		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0
		int vMoveScreen = (int)(vMove / transformY);


		int spriteHeight = (int)fabs((g_config.wind_heith  / transformY) / vDiv); 
		int drawStartY = -spriteHeight / 2 + g_config.wind_heith / 2 + vMoveScreen;
		if(drawStartY < 0) 
			drawStartY = 0;
		int drawEndY = spriteHeight / 2 + g_config.wind_heith / 2 + vMoveScreen;
		if(drawEndY >= g_config.wind_heith) drawEndY = g_config.wind_heith - 1;

		//calculate width of the sprite
		int spriteWidth = (int)fabs((g_config.wind_heith / transformY) / uDiv);
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= g_config.wind_width) drawEndX = g_config.wind_width - 1;

		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * list->textures[4].width / spriteWidth) / 256);
			if(transformY > 0 && stripe > 0 && stripe < g_config.wind_width && transformY < list->zbuff[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int d = (y-vMoveScreen) * 256 - g_config.wind_heith * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * list->textures[4].height) / spriteHeight) / 256;
				int color = list->textures[4].buff[list->textures[4].width * texY + texX]; //get current color from the texture
				if((color & 0x00FFFFFF) != 0) 
					list->buff[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
			}
		}
	}
}

int		main_draw_sprite(t_for_loop_list *list)
{
	t_sprites *sprites;

	if (!(sprites = malloc(sizeof(t_sprites) * g_config.sprite_num)))
	print_cust_error(PROCESSING_ERROR);
	get_sprites_pos(sprites);
	sort_sprites(sprites);
	draw_sprites(sprites, list);
	free(sprites);
	return (1);
	
}