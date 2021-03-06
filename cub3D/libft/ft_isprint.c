/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 04:36:44 by bdomitil          #+#    #+#             */
/*   Updated: 2020/10/30 06:42:29 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int q)
{
	if (q > 31 && q < 127)
		return (1);
	else
		return (0);
}
