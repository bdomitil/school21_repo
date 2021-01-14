/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:53:37 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 16:53:38 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	count_zero(long int x, int base)
{
	int i;

	i = 0;
	while ((x / base) != 0)
	{
		x /= base;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa_base(unsigned long long int x, int base, int upper_case)
{
	int		dev;
	char	*letters;
	int		len;
	char	*word;

	len = count_zero(x, base);
	if ((x < 0) || !(word = (char*)malloc(len + 1)))
		return (NULL);
	word[len--] = '\0';
	letters = (upper_case) ? "ABCDEF" : "abcdef";
	while ((x / base) != 0)
	{
		dev = (x % base);
		if (dev < 10)
			word[len--] = dev + 48;
		if (dev > 9)
			word[len--] = letters[dev - 10];
		x /= base;
	}
	dev = (x % base);
	if (dev > 9)
		word[len] = (dev > 9) ? letters[dev - 10] : dev + 48;
	else
		word[len] = dev + 48;
	return (word);
}
