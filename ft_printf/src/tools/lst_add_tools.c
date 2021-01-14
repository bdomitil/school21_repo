/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:27:13 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 14:56:36 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	fill_str_before(t_pr_lst *new, char *str, int i)
{
	int			end;
	int			prev_pos;

	end = 0;
	while ((new->type = is_param(str[end + i])) == fault)
		end++;
	if (new->previous)
	{
		prev_pos = new->previous->prev_pos + 1;
		new->str_before = ft_substr(str, prev_pos, (i - 1) - prev_pos);
	}
	else
		new->str_before = ft_substr(str, 0, i - 1);
	new->prev_pos = end + i;
}

static void	fill_params(t_pr_lst *new, va_list va)
{
	if (new->mods.width.later)
		new->mods.width.data = va_arg(va, int);
	if (new->mods.accuracy.later)
		new->mods.accuracy.data = va_arg(va, int);
	if (new->type == d || new->type == i)
		new->content = ft_itoa(va_arg(va, int));
	if (new->type == s)
		new->content = (char*)va_arg(va, char*);
	if (new->type == c)
		new->content = ft_char_to_str(va_arg(va, int));
	if (new->type == p)
		new->content = ft_pointer_to_str((long long int)va_arg(va, void *));
	if (new->type == u)
		new->content = ft_itoa_unsigned(va_arg(va, int));
	if (new->type == x)
		new->content = ft_itoa_base(va_arg(va, unsigned int), 16, 0);
	if (new->type == X)
		new->content = ft_itoa_base(va_arg(va, unsigned int), 16, 1);
	if (new->type == percent)
		new->content = ft_char_to_str('%');
	if (new->type == s && !new->content)
		new->content = "(null)";
}

void		pr_lst_fill(t_pr_lst *new, va_list va, char *str, int i)
{
	mod_fill(new, &str[i]);
	fill_str_before(new, str, i);
	fill_params(new, va);
}
