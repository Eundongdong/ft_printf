/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:04:25 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/05 14:55:58 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		address_sub(t_info *info)
{
	int		temp;

	info->result += ft_putchar('0');
	info->result += ft_putchar('x');
	if (info->width > info->spec)
	{
		temp = info->width - 2;
		while (temp--)
			info->result += ft_putchar('0');
	}
	else
	{
		while (info->spec--)
			info->result += ft_putchar('0');
	}
	return (info->result);
}

int		address_sub_2(t_info *info, int sum, unsigned long long num)
{
	int	temp;

	info->result += ft_putchar('0');
	info->result += ft_putchar('x');
	if (info->width > info->spec)
	{
		temp = info->width - 2 - sum;
		while (temp--)
			info->result += ft_putchar('0');
	}
	else
	{
		temp = info->spec - sum;
		while (temp--)
			info->result += ft_putchar('0');
	}
	ft_putbase("0123456789abcdef", num, 16);
	return (info->result + sum);
}

int		add_sub_3(t_info *info, int sum, unsigned long long num, int n_c)
{
	int	plus_sum;

	plus_sum = print_info(info, sum + 2);
	if (plus_sum > 0 && info->flag == 1)
	{
		while (plus_sum-- > 0)
			info->result += ft_putchar(' ');
	}
	info->result += ft_putchar('0');
	info->result += ft_putchar('x');
	sum = 0;
	if (num > 0 || (!(info->zerospec) && n_c))
		sum += ft_putbase("0123456789abcdef", num, 16);
	if (plus_sum > 0 && info->flag == -1)
	{
		while (plus_sum-- > 0)
			info->result += ft_putchar(' ');
	}
	return (sum + info->result);
}

void	add_sub_4(t_info *info)
{
	if (info->spec < 0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
}

int		type_address(t_info *info, va_list ap)
{
	int					sum;
	unsigned long long	num;
	int					n_c;

	n_c = 0;
	num = va_arg(ap, unsigned long long);
	sum = find_num_length_x(num, 'x');
	if (num == '\0')
	{
		num = 0;
		sum = 0;
		n_c = 1;
		if (!(info->zerospec) && !(info->spec))
			sum = 1;
	}
	if ((n_c && (info->spec)))
		return (address_sub(info));
	if (!(n_c) && sum < info->spec)
		return (address_sub_2(info, sum, num));
	return (add_sub_3(info, sum, num, n_c));
}
