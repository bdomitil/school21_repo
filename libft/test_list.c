/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:08:29 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/09 13:58:14 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	int i = 0;
	t_list mass[5];
	t_list *temp = mass;
	t_list ska;
	ska.next = NULL;
	ska.content = "pizds suka";
	while (i < 5)
	{
		if (i == 4)
		{
			mass[4].next = NULL;
			mass[4].content = ft_itoa(i);
			break;
		}
		mass[i].next = &mass[i + 1];
		mass[i].content = ft_itoa(i);
		i++;
	}
	ft_lstprint(&temp);
}
