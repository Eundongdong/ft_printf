/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:04:07 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/05 14:55:04 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_num_length_u(unsigned int num)
{
	unsigned int sum;

	sum = 0;
	while (num)
	{
		sum += 1;
		num = num / 10;
	}
	return (sum);
}

int		unsigned_back(t_info *info, int plus_sum, unsigned int num)
{
	int	sum;

	sum = find_num_length(num);
	plus_sum = print_info(info, sum);
	if (info->zerospec && num == 0)
	{
		return (0);
	}
	if (num >= 0)
		ft_putnbr_u(num);
	if (plus_sum > 0)
	{
		while (plus_sum-- > 0)
			info->result += ft_putchar(' ');
	}
	return (info->result + sum);
}

void	unsigned_setting(t_info *info)
{
	if (info->spec < 0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
}

int		type_unsigned(t_info *info, va_list ap)
{
	unsigned int	num;
	int				plus_sum;

	plus_sum = 0;
	num = va_arg(ap, unsigned int);
	if (num == 0)
	{
		if (info->zero != '0' && info->zerospec == 0\
		&& !(info->width) && (info->spec) < 0)
		{
			info->result += ft_putchar('0');
			return (info->result);
		}
		if (info->zerospec && info->width)
		{
			while (info->width--)
				info->result += ft_putchar(' ');
			return (info->result);
		}
	}
	return (unsigned_back(info, plus_sum, num));
}
