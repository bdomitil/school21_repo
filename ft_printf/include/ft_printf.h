/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 18:25:22 by bdomitil          #+#    #+#             */
/*   Updated: 2021/01/14 16:42:15 by bdomitil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "../src/libft/libft.h"
# include <stdbool.h>

typedef enum	e_type
{
	s,
	i,
	c,
	p,
	d,
	u,
	x,
	X,
	percent,
	fault
}				t_type;

typedef struct	s_mod_cont
{
	int		data;
	int		later;
	bool	found;

}				t_mod_cont;

typedef struct	s_mods
{
	t_mod_cont		width;
	t_mod_cont		accuracy;
	char			flag;
}				t_mods;

typedef struct	s_pr_lst
{
	struct s_pr_lst	*next;
	struct s_pr_lst	*previous;
	t_mods			mods;
	t_type			type;
	char			*content;
	char			*str_before;
	int				prev_pos;
}				t_pr_lst;

int				ft_printf(char *str, ...);
void			ft_pr_lstadd_back(t_pr_lst *new_lst);
char			*ft_itoa_base(unsigned long long int x, int base, int up_case);
char			*ft_pointer_to_str(long long int x);
char			*ft_itoa_unsigned(unsigned int n);
t_pr_lst		*ft_pr_lstlast();
void			ft_print_left(char *str);
t_pr_lst		*add_lst();
t_type			is_param(char q);
int				find_param(char *str);
bool			parser(char *str, va_list va);
void			mod_fill(t_pr_lst *lst, char *str);
void			pr_lst_fill(t_pr_lst *new_lst, va_list va, char *str, int i);
char			*ft_char_to_str(char q);
void			ft_print_with_params(char *str, t_pr_lst *lst);
void			ft_print(char *str);
void			final_print();
void			final_lst_clear();
int				count_accuracy(t_pr_lst *lst, char *str);
void			change_mods(t_pr_lst *lst, int acc_len);
void			print_width(t_pr_lst *lst, int print_len, char flag);
t_pr_lst		*g_pr_lst;
size_t			g_print_count;

#endif
