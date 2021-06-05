/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:55:29 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/05 14:35:08 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pb_2(unsigned long long temp, int base_count, int count)
{
	while (temp)
	{
		temp = temp / base_count;
		count++;
	}
	return (count);
}

int		ft_putbase(const char *base, unsigned long long num, int base_count)
{
	int					sum;
	int					i;
	int					count;
	char				*s;

	i = 0;
	sum = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = ft_pb_2(num, base_count, 0);
	if (!(s = (char *)malloc(sizeof(char) * (count + 1))))
		return (-1);
	while (num)
	{
		s[i++] = base[num % base_count];
		num = num / base_count;
	}
	sum = i;
	while (i > 0)
		write(1, &s[--i], 1);
	free(s);
	return (sum);
}
