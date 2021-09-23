/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:31:16 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 20:17:32 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef STR_INT_MIN
#  define STR_INT_MIN "-2147483648"
# endif

typedef struct s_print
{
	va_list		args;
	int			total_length;
	int			cur_pos;
}				t_print;

typedef struct s_format
{
	int		total_length;
	char	type;
}				t_format;

t_print		*ft_init_tab(t_print *tab);
int			ft_strlen(const char *s);

void		ft_form_interface(t_format *form, t_print *tab);
t_format	*ft_eval_format(const char	*format, t_print *tab, char c);

void		ft_proc_char(t_print *tab);
void		ft_proc_string(t_print *tab);
void		ft_proc_signed_digit(t_print *tab);
void		ft_proc_unsigned_digit(t_print *tab);
void		ft_proc_percentage(t_print *tab);
void		ft_proc_hex_lower(t_print *tab);
void		ft_proc_hex_upper(t_print *tab);
void		ft_putaddr(unsigned long long nbr, t_print *tab);
void		ft_proc_voidptr(t_print	*tab);

void		form_ctl(const char *format, t_print *tab, char cur_char, int *ret);
int			ft_printf(const char *format, ...);
#endif