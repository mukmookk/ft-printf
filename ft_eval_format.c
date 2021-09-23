/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:38:44 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 19:39:20 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_eval_format(const char	*format, t_print *tab, char c)
{
	const char		*ptr_format;
	t_format		*form;

	form = malloc(sizeof(t_format));
	if (tab == NULL)
	{
		return (NULL);
	}
	form->total_length = 0;
	form->type = c;
	ptr_format = format;
	ft_form_interface(form, tab);
	tab->total_length += form->total_length;
	return (form);
}
