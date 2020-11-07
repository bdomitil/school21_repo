/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:38:52 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/07 14:25:25 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <unistd.h>

char	**ft_split(const char *str, char c);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int q);
char	*ft_strrchr(const char *str, int q);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *where, const char *what, size_t size);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int q);
int		ft_isalpha(int q);
int		ft_isupper(int q);
int		ft_islower(int q);
int		ft_isprint(int q);
int		ft_space(int q);
int		ft_isascii(int q);
int		ft_isalnum(int q);
int		ft_toupper(int q);
int		ft_tolower(int q);
int		ft_atoi(const char *str);
int		ft_char_index(const char *str, char q);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
