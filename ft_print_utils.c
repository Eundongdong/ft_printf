/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:46:47 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/03 01:48:28 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_num_length(long long num)
{
	long long	sum;

	sum = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		sum += 1;
		num = num / 10;
	}
	return (sum);
}

char	option_withzero(t_info *info)
{
	char		c;

	if (info->flag == -1)
		info->zero = ' ';
	if ((info->spec > 0 && info->width != 0) || info->zerospec)
		info->zero = ' ';
	c = (info->zero == '0') ? '0' : ' ';
	return (c);
}

int		print_info(t_info *info, int sum)
{
	char	c;

	c = option_withzero(info);
	if (sum > info->spec)
		info->spec = sum;
	info->width -= info->spec;
	if (!(info->flag == -1 || info->zero == '0'))
		while (info->width-- > 0)
			info->result += ft_putchar(' ');
	if (info->sign == -1)
		info->result += ft_putchar('-');
	if (!(info->flag == -1) && info->width > 0)
		while (info->width-- > 0)
			info->result += ft_putchar(c);
	while (sum < info->spec--)
		info->result += ft_putchar('0');
	return (info->width);
}
