/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:28:39 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 16:53:04 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		final_lst_clear(void)
{
	t_pr_lst *tmp;

	if (g_pr_lst)
	{
		while (g_pr_lst)
		{
			tmp = g_pr_lst;
			if (g_pr_lst->str_before)
				free(g_pr_lst->str_before);
			if (g_pr_lst->type != s)
				free(g_pr_lst->content);
			g_pr_lst = g_pr_lst->next;
			free(tmp);
		}
	}
}

t_pr_lst	*ft_pr_lstlast(void)
{
	t_pr_lst *tmp;

	tmp = g_pr_lst;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void		ft_pr_lstadd_back(t_pr_lst *new)
{
	t_pr_lst *temp;

	temp = g_pr_lst;
	if (g_pr_lst == NULL)
	{
		g_pr_lst = new;
		return ;
	}
	temp = ft_pr_lstlast();
	temp->next = new;
	new->previous = temp;
}

t_pr_lst	*add_lst(void)
{
	t_pr_lst *new_lst;

	if (!(new_lst = (t_pr_lst*)malloc(sizeof(t_pr_lst))))
		return (NULL);
	else
	{
		new_lst->next = NULL;
		new_lst->previous = NULL;
		new_lst->content = NULL;
		new_lst->str_before = NULL;
		new_lst->prev_pos = 0;
		new_lst->type = fault;
		new_lst->mods.accuracy.data = 0;
		new_lst->mods.accuracy.later = 0;
		new_lst->mods.accuracy.found = false;
		new_lst->mods.width.data = 0;
		new_lst->mods.width.found = false;
		new_lst->mods.width.later = 0;
		new_lst->mods.flag = 0;
		ft_pr_lstadd_back(new_lst);
	}
	return (new_lst);
}
