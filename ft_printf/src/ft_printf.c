/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:56:15 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 16:56:50 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(char *str, ...)
{
	va_list va;

	g_pr_lst = NULL;
	g_print_count = 0;
	va_start(va, str);
	g_print_count = 0;
	if (!parser(str, va))
		return (0);
	va_end(va);
	if (g_pr_lst)
	{
		final_print();
		ft_print_left(str);
		final_lst_clear();
	}
	else
		ft_print(str);
	return (g_print_count);
}
