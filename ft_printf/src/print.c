/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:35:35 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 17:29:50 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	print_str(t_pr_lst *lst, char *str)
{
	int	print_len;
	int	i;

	i = 0;
	print_len = count_accuracy(lst, str);
	if (lst->mods.accuracy.data < 0 && lst->mods.flag != '-')
		lst->mods.flag = ' ';
	if (lst->mods.flag == '0' || lst->mods.flag == ' ')
		print_width(lst, print_len, lst->mods.flag);
	if (lst->type != c)
		while (print_len - i > 0 && str[i] != '\0')
			g_print_count += write(1, &str[i++], 1);
	else
		g_print_count += write(1, str, 1);
	if (lst->mods.flag == '-')
		print_width(lst, print_len, ' ');
}

static void	helper(t_pr_lst *lst, int *to_width, int *print_len, int *str_len)
{
	t_mod_cont acc;

	acc = lst->mods.accuracy;
	*str_len = ft_strlen(lst->content);
	if (acc.found && acc.data == 0 && lst->content[0] == '0')
		*str_len -= 1;
	if (acc.data > *str_len)
		*to_width = acc.data;
	else
		*to_width = *str_len;
	if (lst->content[0] == '-' && (acc.data >= *str_len))
	{
		*str_len -= 1;
		*to_width += 1;
	}
	*print_len = acc.data - *str_len;
}

static void	print_num(t_pr_lst *lst, char *str)
{
	int			print_len;
	int			i;
	int			str_len;
	int			to_width;
	t_mod_cont	acc;

	i = 0;
	acc = lst->mods.accuracy;
	str_len = 0;
	to_width = 0;
	helper(lst, &to_width, &print_len, &str_len);
	change_mods(lst, print_len);
	if (str[i] == '-' && lst->mods.flag == '0')
		g_print_count += write(1, &str[i++], 1);
	if (lst->mods.flag == '0' || lst->mods.flag == ' ')
		print_width(lst, to_width, lst->mods.flag);
	if (str[i] == '-' && (acc.data > 0 || lst->mods.width.data - to_width > 0))
		g_print_count += write(1, &str[i++], 1);
	while (print_len-- > 0)
		g_print_count += write(1, "0", 1);
	while (str[i] != 0 && str_len != 0)
		g_print_count += write(1, &str[i++], 1);
	if (lst->mods.flag == '-')
		print_width(lst, to_width, ' ');
}

void		final_print(void)
{
	t_pr_lst	*tmp;
	t_type		type;

	tmp = g_pr_lst;
	while (tmp)
	{
		ft_print(tmp->str_before);
		type = tmp->type;
		if (type != s && type != c && type != p)
			print_num(tmp, tmp->content);
		else
			print_str(tmp, tmp->content);
		tmp = tmp->next;
	}
}
