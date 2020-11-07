/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 04:58:09 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/07 14:59:50 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	g_sym;

static int	is_sym(char q)
{
	if (q == '-' || q == '+')
	{
		g_sym++;
		return (1);
	}
	else
		return (0);
}

static int	enter(char q)
{
	if (ft_isdigit(q) || is_sym(q) || ft_space(q))
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int to_ret;
	int min;
	int i;

	to_ret = 0;
	min = 0;
	g_sym = 0;
	i = 0;
	while (enter(str[i]) && g_sym < 2)
	{
		if (str[i] == '-')
			min++;
		if (ft_isdigit((int)str[i]) == 1)
			to_ret = (to_ret * 10) + ((int)str[i] - 48);
		if ((i > 18 && min > 0))
			return (0);
		else if (i++ > 18)
			return (-1);
	}
	if (min > 0)
		return (to_ret * -1);
	return (to_ret);
}
