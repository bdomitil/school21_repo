/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:11:15 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/09 19:34:11 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void(*del)(void*))
{
		t_list	*to_ret;
		int		size;
		int 	i;
		t_list	*temp;

		if (!lst || !f || !del)
			return (NULL);
		to_ret = NULL;
		temp = NULL;
		i = 0;
		size = ft_lstsize(lst);
		while (i++ < size)
		{
			ft_lstadd_back(&temp, ft_lstnew(f(lst->content)));
			if(ft_lstsize
		}
}
