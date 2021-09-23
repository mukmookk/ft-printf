/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:26:17 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 22:04:56 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	form_ctl(const char *format, t_print *tab, char cur_char, int *ret)
{
	t_format	*form;

	form = NULL;
	if (cur_char == '%')
	{
		tab->cur_pos += 1;
		form = ft_eval_format(format, tab, format[tab->cur_pos]);
	}
	else
		*ret += write(1, &format[tab->cur_pos], 1);
	free(form);
	tab->cur_pos += 1;
}

t_print	*ft_init_tab(t_print *tab)
{
	tab->total_length = 0;
	tab->cur_pos = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print		*tab;
	int			ret;
	int			cur_char;

	ret = 0;
	tab = malloc(sizeof(t_print));
	if (tab == NULL)
		return (0);
	va_start(tab->args, format);
	ft_init_tab(tab);
	while (format[tab->cur_pos] != '\0')
	{
		cur_char = format[tab->cur_pos];
		form_ctl(format, tab, cur_char, &ret);
	}
	ret += tab->total_length;
	va_end(tab->args);
	free(tab);
	return (ret);
}
