/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:54:06 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 16:54:28 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	count_len(unsigned int n)
{
	size_t size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa_unsigned(unsigned int n)
{
	char	*to_ret;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	size = count_len(n);
	to_ret = malloc(size * sizeof(char) + 1);
	if (!to_ret)
		return (NULL);
	to_ret[size] = '\0';
	size--;
	while (size >= 0)
	{
		to_ret[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (to_ret);
}
