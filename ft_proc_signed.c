/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:01:06 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 20:10:57 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putnbr(int n, t_print *tab)
{
	if (n == INT_MIN)
	{
		tab->total_length += write(1, STR_INT_MIN, ft_strlen(STR_INT_MIN));
		return ;
	}
	if (n < 0)
	{
		tab->total_length += write(1, "-", 1);
		n *= -1;
	}
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

void	ft_proc_signed_digit(t_print *tab)
{
	long int		nbr;

	nbr = va_arg(tab->args, int);
	ft_putnbr(nbr, tab);
}
