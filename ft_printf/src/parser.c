/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:57:22 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 17:10:58 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

bool	parser(char *str, va_list va)
{
	int			i;
	int			param_pos;
	t_pr_lst	*new;

	param_pos = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if ((param_pos = find_param(&(str[++i])) != -1))
			{
				if (!(new = add_lst()))
				{
					final_lst_clear();
					return (false);
				}
				pr_lst_fill(new, va, str, i);
			}
			else
				i--;
		}
		i++;
	}
	return (true);
}
