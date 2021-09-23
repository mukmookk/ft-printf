/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:41:15 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 22:15:02 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_proc_string(t_print *tab)
{
	const char		*str;
	int				index;

	index = 0;
	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		tab->total_length += write(1, "(null)", 6);
		return ;
	}
	while (str[index] != '\0')
	{
		tab->total_length += write(1, &str[index], 1);
		index += 1;
	}
}
