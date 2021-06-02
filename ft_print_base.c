/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 00:00:58 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/03 01:23:42 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_num_length_x(unsigned long long num, char check)
{
	int		result;
	int		base_count;

	if (num == 0)
		return (1);
	if (check == 'X' || check == 'x')
		base_count = 16;
	else
		base_count = 10;
	result = 0;
	while (num)
	{
		num = num / base_count;
		result++;
	}
	return (result);
}

void	base_sub(t_info *info)
{
	if (info->spec < 0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
}

int		base_sub_2(t_info *info, unsigned int num, int sum, char check)
{
	int				plus_sum;

	plus_sum = print_info(info, sum);
	if (info->zerospec && num == 0)
		return (0);
	if (plus_sum > 0 && info->flag == 1)
	{
		while (plus_sum-- > 0)
			info->result += ft_putchar(' ');
	}
	if (check == 'X')
		sum = ft_putbase("0123456789ABCDEF", num, 16);
	else if (check == 'x')
		sum = ft_putbase("0123456789abcdef", num, 16);
	else
		sum = ft_putbase("0123456789", num, 10);
	if (plus_sum > 0 && info->flag == -1)
	{
		while (plus_sum-- > 0)
			info->result += ft_putchar(' ');
	}
	return (sum + info->result);
}

int		type_base(t_info *info, va_list ap, int i, char *s)
{
	unsigned int	num;
	char			check;
	int				sum;

	sum = 0;
	num = va_arg(ap, unsigned int);
	check = s[i];
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
	sum += find_num_length_x(num, check);
	return (base_sub_2(info, num, sum, check));
}
