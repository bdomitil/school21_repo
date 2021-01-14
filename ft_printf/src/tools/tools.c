/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 09:11:02 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 16:51:28 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_char_to_str(char q)
{
	char *str;

	str = NULL;
	if (!(str = (char*)malloc(2)))
		return (NULL);
	str[1] = '\0';
	str[0] = q;
	return (str);
}

char	*ft_pointer_to_str(long long int x)
{
	char *tmp;
	char *tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (x == 0)
	{
		tmp = ft_strdup("0x0");
		if (tmp)
			return (tmp);
		else
			return (NULL);
	}
	tmp = ft_itoa_base(x, 16, 0);
	tmp2 = tmp;
	tmp = ft_strjoin("0x", tmp);
	if (tmp2)
		free(tmp2);
	return (tmp);
}

int		count_accuracy(t_pr_lst *lst, char *str)
{
	int			to_ret;
	int			str_len;
	t_mod_cont	acc;

	to_ret = 0;
	if (lst->mods.width.data < 0)
		lst->mods.flag = '-';
	if (lst->mods.accuracy.data < 0)
		lst->mods.accuracy.found = 0;
	if (lst->mods.width.data < 0)
		lst->mods.width.data *= -1;
	acc = lst->mods.accuracy;
	str_len = ft_strlen(str);
	str_len = lst->type == c ? 1 : str_len;
	if ((int)acc.data >= str_len)
		to_ret = str_len;
	else if (acc.found && acc.data > 0)
		to_ret = acc.data;
	else if (acc.found && lst->type != p)
		to_ret = 0;
	else if (acc.found && lst->type == p && !ft_strcmp(lst->content, "0x0"))
		to_ret = 2;
	else
		to_ret = str_len;
	return (to_ret);
}

void	change_mods(t_pr_lst *lst, int acc_print)
{
	if (lst->mods.width.data < 0)
	{
		lst->mods.width.data *= -1;
		lst->mods.flag = '-';
		return ;
	}
	if (lst->mods.accuracy.data == 0 && lst->mods.flag == '0')
		if (lst->mods.accuracy.found && lst->mods.width.data > 0)
			lst->mods.flag = ' ';
	if (lst->mods.flag == '0' && acc_print > 0)
		lst->mods.flag = ' ';
	if (lst->mods.flag == '0' && lst->mods.width.data > acc_print)
		if (lst->mods.accuracy.data > 0)
			lst->mods.flag = ' ';
}
