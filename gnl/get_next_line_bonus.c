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

#include "get_next_line_bonus.h"

t_list	*find_fd(t_list *lst, int fd)
{
	t_list *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		clear_and_ret(t_list **lst, t_list *curr)
{
	if (curr->previous_lst == NULL)
	{
		*lst = curr->next;
		if (*lst)
			(*lst)->previous_lst = NULL;
	}
	else
		curr->previous_lst->next = curr->next;
	free(curr->left);
	curr->left = NULL;
	free(curr);
	curr = NULL;
	return (0);
}

int		get_line(t_list *curr)
{
	int		read_res;
	char	buff[BUFFER_SIZE + 1];
	int		slash;
	char	*tmp;

	read_res = -1;
	while ((slash = ft_slash(curr->left)) < 0 && read_res != 0)
	{
		read_res = read(curr->fd, buff, BUFFER_SIZE);
		if (read_res == -1 || BUFFER_SIZE <= 0)
			return (-2);
		buff[read_res] = '\0';
		tmp = curr->left;
		curr->left = ft_strjoin(curr->left, buff);
		free(tmp);
	}
	return (slash);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*lst;
	char			*tmp;
	int				slash;
	t_list			*curr;

	if (!line)
		return (-1);
	if (!(curr = find_fd(lst, fd)))
		if (!(curr = ft_lstadd_back(&lst, fd)))
			return (-1);
	slash = get_line(curr);
	if (slash == -2)
		return (-1);
	*line = ft_substr(curr->left, 0, slash);
	tmp = curr->left;
	curr->left = ft_substr(curr->left, slash + 1, ft_strlen(curr->left));
	free(tmp);
	if (slash == -1)
		return (clear_and_ret(&lst, curr));
	return (1);
}
