/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:40:13 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 19:41:12 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_proc_char(t_print *tab)
{
	unsigned char	c;

	c = va_arg(tab->args, int);
	tab->total_length += write(1, &c, 1);
}
