/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:52:30 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/24 02:52:32 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_list
{
	struct s_list	*next;
	char			*left;
	int				fd;
	struct s_list	*previous_lst;
}				t_list;

int				ft_slash(char *str);
char			*ft_substr(char const *s, unsigned int start, int len);
char			*ft_strjoin(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);
void			*ft_memset(void *s, int q, size_t size);
size_t			ft_strlen(const char *str);
t_list			*ft_lstadd_back(t_list **lst, int fd);

#endif
