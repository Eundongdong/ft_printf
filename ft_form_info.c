/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:31:38 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/03 00:12:44 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flag(va_list ap, t_info *info, int i, char *s)
{
	i++;
	if (s[i] == '-')
	{
		info->flag = -1;
		i++;
	}
	i = get_width(ap, info, i, s);
	return (i);
}

int		get_width(va_list ap, t_info *info, int i, char *s)
{
	int		n;
	int		check;

	check = 1;
	n = 0;
	while (s[i] == '0' || s[i] == '-')
	{
		while (s[i] == '0')
		{
			info->zero = '0';
			i++;
		}
		while (s[i] == '-')
		{
			i++;
			check = -1;
		}
	}
	while (ft_isdigit(s[i]))
	{
		n = n * 10 + s[i] - 48;
		i++;
	}
	if (s[i] == '*')
	{
		n = va_arg(ap, int);
		if (n < 0)
		{
			info->flag = -1;
			n *= -1;
		}
		i++;
	}
	info->width = n * check;
	if (info->width < 0)
	{
		info->flag = -1;
		info->width *= -1;
	}
	i = get_spec(ap, info, i, s);
	return (i);
}
