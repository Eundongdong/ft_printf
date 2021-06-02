/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:31:24 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/03 01:47:44 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_sub(t_info *info)
{
	if (info->spec < 0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
}

int		int_sub_2(t_info *info, long long num)
{
	int		sum;
	int		plus_sum;

	sum = find_num_length(num);
	plus_sum = print_info(info, sum);
	if (info->zerospec && num == 0)
		return (0);
	if (num >= 0)
		ft_putnbr(num);
	if (plus_sum > 0)
	{
		while (plus_sum-- > 0)
			info->result += ft_putchar(' ');
	}
	return (info->result + sum);
}

int		type_int(t_info *info, va_list ap, int i, char *s)
{
	long long	num;

	num = va_arg(ap, int);
	int_sub(info);
	if (num < 0)
	{
		num = num * (-1);
		info->sign = -1;
		info->width--;
	}
	if (num == 0 && info->zero != '0' && info->zerospec == 0 && \
		!(info->width) && (info->spec) < 0)
	{
		info->result += ft_putchar('0');
		return (info->result);
	}
	if (num == 0 && info->zerospec && info->width)
	{
		while (info->width--)
			info->result += ft_putchar(' ');
		return (info->result);
	}
	return (int_sub_2(info, num));
}
