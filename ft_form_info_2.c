/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_info_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:54:45 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/05 14:58:13 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_sub(t_info *info, int n, int sign, int check)
{
	info->spec = n * sign;
	if (n == 0 && !check)
		info->zerospec = 1;
}

int		spec_sub_2(va_list ap, int *check, int i, int *n)
{
	*n = va_arg(ap, int);
	if (*n < 0)
	{
		*check = 1;
		*n = 0;
	}
	i++;
	return (i);
}

int		get_spec(va_list ap, t_info *info, int i, char *s)
{
	int n;
	int sign;
	int check;

	sign = 1;
	n = 0;
	check = 0;
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '-')
		{
			sign = -1;
			i++;
		}
		while (ft_isdigit(s[i]))
			n = n * 10 + s[i++] - 48;
		if (s[i] == '*')
			i = spec_sub_2(ap, &check, i, &n);
		spec_sub(info, n, sign, check);
	}
	return (i);
}

int		write_sub(t_info *info, char c)
{
	info->result += ft_putchar(c);
	return (1);
}

int		find_write(va_list ap, char *s)
{
	int		i;
	int		sum;
	int		error_check;
	t_info	info;

	error_check = 0;
	i = 0;
	sum = 0;
	while (s[i] != '\0')
	{
		init(&info);
		if (s[i] == '%')
		{
			i = get_flag(ap, &info, i, s);
			error_check = form_check(&info, ap, i, s);
			if (error_check != -1)
				sum += error_check;
			else
				return (-1);
		}
		else
			sum += write_sub(&info, s[i]);
		i++;
	}
	return (sum);
}
