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
    t_list  *temp;
   
    if (!lst)
        return ;
    temp = lst[0];
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}
