/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:46:13 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 19:52:04 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr(unsigned long long nbr, t_print *tab)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
		ft_putaddr(nbr / 16, tab);
	tab->total_length += write(1, &hex[nbr % 16], 1);
}

void	ft_proc_voidptr(t_print	*tab)
{
	unsigned long long	nbr;

	nbr = (unsigned long long)va_arg(tab->args, void *);
	tab->total_length += write(1, "0x", 2);
	ft_putaddr(nbr, tab);
}
