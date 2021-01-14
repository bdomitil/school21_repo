/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:33:05 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 16:34:21 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_print_left(char *str)
{
	t_pr_lst	*last;
	int			i;

	last = ft_pr_lstlast();
	i = last->prev_pos + 1;
	while (str[i] != '\0')
		g_print_count += write(1, &str[i++], 1);
}

void	ft_print(char *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		g_print_count += write(1, &str[i], 1);
		i++;
	}
}

void	print_width(t_pr_lst *lst, int print_len, char flag)
{
	int	to_include;
	int	width;

	width = lst->mods.width.data;
	if (lst->mods.accuracy.found && lst->mods.accuracy.data >= 0)
		flag = ' ';
	if (lst->type == percent && lst->mods.flag == '0')
		flag = '0';
	to_include = 0;
	if (print_len == 0)
		to_include = width;
	else
		to_include = width - print_len;
	while (to_include > 0)
	{
		g_print_count += write(1, &flag, 1);
		to_include--;
	}
}
