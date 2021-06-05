/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:34:47 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/05 14:35:07 by eunjkim          ###   ########.fr       */
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
