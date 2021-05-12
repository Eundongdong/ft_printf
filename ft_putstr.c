/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:56:09 by marvin            #+#    #+#             */
/*   Updated: 2021/04/26 21:35:01 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *s)
{
	size_t len;
	size_t i;

	if (!(s))
		return (0);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		write(1,&s[i],1);
		i++;
	}
	return (len);
}
