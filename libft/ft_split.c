/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:59:54 by bdomitil          #+#    #+#             */
/*   Updated: 2020/11/06 18:02:53 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int      count_word(const char *str, char q)
{
    int i;
    int num;
    int stop;

    i = 0;
    stop = ft_strlen(str);
    num = 0;
    while (str[i] == q && str[i] != '\0')
	    i++;
    while (str[stop] == q)
	    stop++;
    while (i < stop + 1)
    {
            if (str[i] == q && str[i + 1] != q)
                    num++;
                i++;
    }
    if (i < 1)
	    return (0);
    return (num + 1);
}

static int     get_len(const char *str, char q)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] != q)
        i++;
    return (i);
}

static char    *get_next_word(const char *str, char q)
{
    int     len;
    char    *word;

    while (*str != '\0' && *str == q)
        str++;
    len = get_len(str, q);
    word = ft_substr(str, 0, len);
    if (!word)
        return (NULL);
    return (word);
}

static void ft_free(char **mass, int pos)
{
    while (pos >= 0)
        free(mass[pos--]);
    free(mass);
}
char    **ft_split(const char *str, char q)
{
    int     word_num;
    int     i;
    char    **to_ret;

    i = 0;
    to_ret = NULL;
    if (!str)
        return (NULL);
    word_num = count_word(str, q);
    to_ret = malloc (word_num * sizeof(char*) + 1);
    	if (!to_ret)
		return (NULL);
    while (i < word_num)
    {
        to_ret[i] = get_next_word(str, q);
	if (!to_ret[i])
        {
            ft_free(to_ret, i);
            return (NULL);
        }
        str += ft_strlen(to_ret[i]) + 1;
        i++;
    }
    to_ret[i] = NULL;
    return (to_ret);
}
