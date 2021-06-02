/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:53:15 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/03 00:55:13 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MAX UINT_MAX

int		form_check(t_info *info, va_list ap, int i, char *s)
{
	int		sum;
	int		idx;

	sum = 0;
	idx = 0;
	if (s[i] == 'd' || s[i] == 'i')
		sum = type_int(info, ap, i, s);
	else if (s[i] == 'c')
		sum = type_char(info, ap, i, s);
	else if (s[i] == 's')
		sum = type_string(info, ap, i, s);
	else if (s[i] == 'x' || s[i] == 'X')
		sum = type_base(info, ap, i, s);
	else if (s[i] == 'p')
		sum = type_address(info, ap, i, s);
	else if (s[i] == 'u')
		sum = type_unsigned(info, ap, i, s);
	else if (s[i] == '%')
		sum = type_percent(info, ap, i, s);
	else
		return (-1);
	return (sum);
}



int		ft_printf(char *s, ...)
{
	va_list	ap;
	int		sum;

	va_start(ap, s);
	sum = find_write(ap, s);
	va_end(ap);
	return (sum);
}
