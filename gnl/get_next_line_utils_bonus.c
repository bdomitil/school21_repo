/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:38:11 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/24 02:38:16 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != EOF)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char				*to_ret;
	int					size;
	int					i;

	size = 0;
	if (len < 0)
		len = ft_strlen(s);
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[size] != '\0')
		size++;
	to_ret = malloc(len * sizeof(char) + 1);
	if (!to_ret)
		return (NULL);
	while (start < (size_t)size && i < len)
	{
		to_ret[i] = s[start];
		start++;
		i++;
	}
	to_ret[i] = '\0';
	return (to_ret);
}

int		ft_slash(char *str)
{
	unsigned long long i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		pos;
	char	*to_ret;

	i = 0;
	pos = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	to_ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!to_ret)
		return (NULL);
	else
	{
		while (s1 != NULL && s1[i] != '\0' && s1[i] != EOF)
			to_ret[pos++] = s1[i++];
		i = 0;
		while (s2 != NULL && s2[i] != '\0' && s2[i] != EOF)
		{
			to_ret[pos] = s2[i++];
			pos++;
		}
		to_ret[pos] = '\0';
	}
	return (to_ret);
}

t_list	*ft_lstadd_back(t_list **lst, int fd)
{
	t_list *temp;
	t_list *new;

	new = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->left = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		new->previous_lst = NULL;
		return (new);
	}
	temp = lst[0];
	while (temp != NULL)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	new->previous_lst = temp;
	temp->next = new;
	return (new);
}
