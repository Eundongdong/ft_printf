/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:23:54 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/03 01:31:07 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_sub(t_info *info, char word)
{
	if (info->flag == -1)
		info->result += ft_putchar(word);
}

int		char_sub_2(t_info *info, int idx, int spec_num, char word)
{
	idx = 1;
	spec_num *= -1;
	info->result += ft_putchar(word);
	while (idx++ < spec_num)
		info->result += ft_putchar(' ');
	return (spec_num);
}

int		type_char(t_info *info, va_list ap, int i, char *s)
{
	char	word;
	int		idx;
	int		spec_num;
	int		result;

	idx = 1;
	result = 1;
	word = va_arg(ap, int);
	char_sub(info, word);
	if ((spec_num = info->spec) < 0)
		return (char_sub_2(info, idx, spec_num, word));
	if (info->width > 0)
	{
		while (idx++ < info->width)
		{
			if (info->zero == '0' && info->flag == 1)
				info->result += ft_putchar('0');
			else
				info->result += ft_putchar(' ');
		}
		result = info->width;
	}
	if (info->flag == 1)
		info->result += ft_putchar(word);
	return (info->result);
}
