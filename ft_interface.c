/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:36:54 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 19:37:48 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_form_interface(t_format *form, t_print *tab)
{
	char	target;

	target = form->type;
	if (target == 'c')
		ft_proc_char(tab);
	else if (target == 's')
		ft_proc_string(tab);
	else if (target == 'p')
		ft_proc_voidptr(tab);
	else if (target == 'd')
		ft_proc_signed_digit(tab);
	else if (target == 'i')
		ft_proc_signed_digit(tab);
	else if (target == 'u')
		ft_proc_unsigned_digit(tab);
	else if (target == 'x')
		ft_proc_hex_lower(tab);
	else if (target == 'X')
		ft_proc_hex_upper(tab);
	else if (target == '%')
		ft_proc_percentage(tab);
}
