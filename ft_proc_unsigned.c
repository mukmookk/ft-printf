/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:03:08 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 20:06:44 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned n, t_print *tab)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, tab);
		ft_putnbr(n % 10, tab);
	}
	else
	{
		n += '0';
		tab->total_length += write(1, &n, 1);
	}	
}

void	ft_proc_unsigned_digit(t_print *tab)
{
	unsigned int		nbr;

	nbr = va_arg(tab->args, int);
	ft_putnbr(nbr, tab);
}
