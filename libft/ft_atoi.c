/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 04:58:09 by bdomitil          #+#    #+#             */
/*   Updated: 2020/10/30 19:39:43 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	enter(char q)
{
	if (ft_isdigit(q) || q == '-' || q == '+' || ft_space(q))
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int to_ret;
	int sym;
	int min;
	int i;

	to_ret = 0;
	min = 0;
	sym = 0;
	i = 0;
	while (enter(str[i]))
	{
		if (str[i] == '-')
			min++;
		if (str[i] == '+' || str[i] == '-')
			sym++;
		if (ft_isdigit((int)str[i]) == 1)
			to_ret = (to_ret * 10) + ((int)str[i] - 48);
		if ((i > 18 && min > 0) || sym > 1)
			return (0);
		else if (i++ > 18)
			return (-1);
	}
	if (sym > 0)
		return (to_ret * -1);
	return (to_ret);
}
