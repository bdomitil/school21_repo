/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:55:41 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 07:15:17 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	int				i;
	unsigned char	*mdst;
	unsigned char	*msrc;
	unsigned char	q;

	i = 0;
	msrc = src;
	mdst = dst;
	q = (unsigned char)c;
	while (i < (int)n)
	{
		mdst[i] = msrc[i];
		if (msrc[i] == q)
			return (&mdst[i + 1]);
		i++;
	}
	return (NULL);
}
