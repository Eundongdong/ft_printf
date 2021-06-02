/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:55:29 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/03 04:08:33 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rec(long long nb)
{
	char	nbr;

	if (nb == 0)
		return ;
	ft_rec(nb / 10);
	nbr = nb % 10 + '0';
	write(1, &nbr, 1);
}

void	ft_putnbr(long long nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		ft_rec(-(nb / 10));
		c = '0' - (nb % 10);
	}
	else
	{
		ft_rec(nb / 10);
		c = '0' + (nb % 10);
	}
	write(1, &c, 1);
}

void	ft_rec_u(unsigned int nb)
{
	char	nbr;

	if (nb == 0)
		return ;
	ft_rec(nb / 10);
	nbr = nb % 10 + '0';
	write(1, &nbr, 1);
}

void	ft_putnbr_u(unsigned int nb)
{
	char	c;

	ft_rec(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
}

int		ft_pb_2(const char *base, unsigned long long num, int base_count, char *s)
{
	int		i;
	int		temp;
	
	i = 0;
	while (num)
	{
		s[i++] = base[num % base_count];
		num = num / base_count;
	}
	temp = i;
	while (i > 0)
		write(1, &s[--i], 1);
	free(s);
	return (temp);
}

int		ft_putbase(const char *base, unsigned long long num, int base_count)
{
	int					sum;
	int					i;
	int					count;
	unsigned long long	temp;
	char				*s;

	i = 0;
	count = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	temp = num;
	while (temp)
	{
		temp = temp / base_count;
		count++;
	}
	if (!(s = (char *)malloc(sizeof(char) * (count + 1))))
		return (-1);
	sum = ft_pb_2(base, num, base_count, s);
	// free(s);
	return (sum);
}
