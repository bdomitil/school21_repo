/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:55:41 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/03 07:12:27 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t n)
{
	size_t			i;
	unsigned char	*mdst;
	unsigned char	*msrc;

	i = 0;
	msrc = (unsigned char*)src;
	mdst = (unsigned char*)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src > dst)
		ft_memcpy(mdst, msrc, n);
	else
	{
		while (n > i)
		{
			n--;
			mdst[n] = msrc[n];
		}
	}
	return (dst);
}
