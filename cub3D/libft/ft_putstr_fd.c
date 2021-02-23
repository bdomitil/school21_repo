/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 05:54:32 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/07 12:02:04 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int ft)
{
	int				len;
	unsigned char	q;
	int				i;

	if (!str)
		return ;
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		q = (unsigned char)str[i++];
		write(ft, &q, 1);
	}
}
