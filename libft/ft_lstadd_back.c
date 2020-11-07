/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:53:01 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/08 00:02:35 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (lst[0])
	{
		if (lst[0]->next == NULL)
		{
			lst[0]->next = new;
			return ;
		}
		lst[0] = lst[0]->next;
	}
}
