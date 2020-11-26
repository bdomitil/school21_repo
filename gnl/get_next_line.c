/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:35:18 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/23 02:56:29 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	to_ret(char **left)
{
	free(*left);
	*left = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *left;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			slash;
	int			read_res;

	read_res = -1;
	while ((slash = ft_slash(left)) < 0 && read_res != 0)
	{
		read_res = read(fd, buff, BUFFER_SIZE);
		if (read_res == -1 || BUFFER_SIZE == 0 || !line)
			return (-1);
		buff[read_res] = '\0';
		tmp = left;
		left = ft_strjoin(left, buff);
		free(tmp);
	}
	*line = ft_substr(left, 0, slash);
	tmp = left;
	left = ft_substr(left, slash + 1, ft_strlen(left));
	free(tmp);
	if (slash == -1)
		return (to_ret(&left));
	return (1);
}
