/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_info_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:54:45 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/03 00:56:07 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_spec(va_list ap, t_info *info, int i, char *s)
{
	int n;
	int sign;
	int check;

	sign = 1;
	n = 0;
	check = 0;
	if(s[i] == '.')
	{
		i++;
		if(s[i] == '-')
		{
			sign = -1;
			i++;
		}
		while(ft_isdigit(s[i]))
		{
			n = n * 10 + s[i] - 48;
			i++;
		}
		if (s[i] == '*')
		{
			n = va_arg(ap, int);
			if(n < 0)
			{
				check = 1;
				n = 0;
			}
			i++;
		}
		info->spec = n * sign;
		if(n == 0 && !check)
			info->zerospec = 1;
	}
	return(i);
}

// int		find_write(va_list ap, char *s)
// {
// 	int		i;
// 	int		sum;

// 	t_info	info;
// 	i = 0;
// 	sum = 0;
// 	while (s[i] != '\0')
// 	{
// 		init(&info);
// 		if (s[i] == '%')
// 		{
// 			i = get_flag(ap, &info, i, s);
// 			if (form_check(&info, ap, i, s) == -1)
// 				return (-1);
// 			else
// 				sum += form_check(&info, ap, i, s);
// 		}
// 		else
// 		{
// 			sum += 1;
// 			info.result += ft_putchar(s[i]);
// 		}
// 		i++;
// 	}
// 	return (sum);
// }
int     find_write(va_list ap, char *s)
{
    int     i;
    int     sum;
	int		error_check;

	error_check = 0; 
	t_info  info;
	i = 0;
    sum = 0;
    while(s[i] != '\0')
    {
		init(&info);
        if(s[i] =='%')
        {

            i = get_flag(ap, &info, i, s);
            error_check = form_check(&info, ap, i, s);
			if (error_check != -1)
				sum += error_check;
			else
				return(-1);
        }
        else
        {
            sum += 1;
            info.result +=ft_putchar(s[i]);
        }
        i++;
    }
    return (sum);
}