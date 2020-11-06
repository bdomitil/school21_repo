/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:06:12 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/04 03:56:12 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*g_to_ret;
static size_t	g_size;
static int		g_minus;

static size_t	count_len(int n)
{
	size_t size1;

	size1 = 0;
	while (n != 0)
	{
		size1++;
		n /= 10;
	}
	return (size1);
}

char			*ft_itoa(int n)
{
	g_size = count_len(n);
	g_to_ret = NULL;
	if (n == -2147483648)
		return ((g_to_ret = ft_strdup("-2147483648")));
	g_minus = 0;
	if (n < 0)
		g_minus = 1;
	if (n == 0)
		g_size = 1;
	g_to_ret = malloc(g_size * sizeof(char) + 1 + g_minus);
	if (!g_to_ret)
		return (NULL);
	if (g_minus)
	{
		n *= -1;
		g_to_ret[0] = '-';
	}
	g_to_ret[g_size + g_minus] = '\0';
	while (g_size > (size_t)0)
	{
		g_to_ret[g_size - !g_minus] = n % 10 + 48;
		n = n / 10;
		g_size--;
	}
	return (g_to_ret);
}
