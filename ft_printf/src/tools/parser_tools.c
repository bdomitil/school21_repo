/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:11:07 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 14:26:08 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_type		is_param(char q)
{
	t_type type;

	type = fault;
	if (q == 'c')
		type = c;
	if (q == 'd')
		type = d;
	if (q == 'i')
		type = i;
	if (q == 's')
		type = s;
	if (q == 'p')
		type = p;
	if (q == 'u')
		type = u;
	if (q == 'x')
		type = x;
	if (q == 'X')
		type = X;
	if (q == '%')
		type = percent;
	return (type);
}

static int	find_flag(char *str)
{
	int		i;

	i = 0;
	while (is_param(str[i]) == fault)
	{
		if (str[i] == '.')
			return (-1);
		if (str[i] == '0' || str[i] == '-')
			return (i);
		if (ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (-1);
}

void		mod_fill(t_pr_lst *new, char *str)
{
	int i;

	i = 0;
	new->mods.flag = find_flag(str) != -1 ? str[i++] : ' ';
	if (ft_isdigit(str[i]) || str[i] == '-')
		new->mods.width.data = ft_atoi(&str[i]);
	else if (str[i] == '*')
	{
		new->mods.width.later = 1;
		new->mods.width.found = true;
	}
	while (is_param(str[i]) == fault)
	{
		if (str[i] == '.')
		{
			new->mods.accuracy.found = true;
			if (str[++i] == '*')
				new->mods.accuracy.later = 1;
			else
				new->mods.accuracy.data = ft_atoi(&str[i]);
		}
		i++;
	}
}

int			find_param(char *str)
{
	int		i;
	char	q;

	i = 0;
	q = str[i];
	while (q != '\0')
	{
		if (is_param(q) != fault)
			return (i);
		if (!ft_isdigit(q) && q != '-' && q != '0' && q != '.' && q != '*')
			return (-1);
		i++;
		q = str[i];
	}
	return (-1);
}
