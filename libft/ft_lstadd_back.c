/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:53:01 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/09 13:57:20 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = lst[0];
	if (temp)
		while (temp)
		{
			if (temp->next == NULL)
			{
				temp->next = new;
				break ;
			}
			temp = temp->next;
		}
	else
		lst[0] = new;
}
