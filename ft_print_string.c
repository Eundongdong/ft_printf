/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 02:42:06 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/03 03:30:10 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_sub(t_info *info,int check, char *str, int sum)
{
	int		idx;
	int		mark;

	idx = 0;
	mark = (info->spec < 0) ? (info->spec) *(-1) : info->width ;
	while (idx++ < mark)
		info->result += ft_putchar(' ');
	sum += idx;
	if (check)
		free(str);
	return (info->width);
}

int		string_sub2(t_info *info, int sum, char *str)
{
	int	idx;

	idx = 0;
	if (info->spec)
	{
		while (idx < info->spec && idx < ft_strlen(str))
		{
			sum += ft_putchar(str[idx]);
			idx++;
		}
	}else
		sum += ft_putstr(str);
	return(sum);

}

int		string_sub3(t_info *info, int temp)
{
	int		idx;

	idx = 0;
	while (idx++ < ((info->width) - temp))
	{
		if (info->zero == '0' && info->flag ==1)
			info->result +=ft_putchar('0');
		else
			info->result +=ft_putchar(' ');
	}
	return (idx - 1);
}

// int		string_sub4(t_info *info, int check, char *str, int sum)
// {
// 	int		temp;
// 	int		idx;

// 	if (info->spec && ft_strlen(str) > info->spec)
// 			temp = info->spec;
// 	if (info->width > 0 && temp< info->width)
// 		sum += string_sub3(info, temp);
// 	if (info->flag == 1)
// 	{
// 		if ((info-> spec) && info->flag == 1 )
// 		{
// 			idx = 0;
// 			while (idx++ < temp)
// 				sum += ft_putchar(str[idx]);
// 		}
// 		if (!(info->spec)&&(info->flag))
// 			sum += ft_putstr(str);
// 	}
// 	return (sum);
// }
int     type_string(t_info *info, va_list ap, int i, char *s)
{
    char	*str;
    int		sum;
	int		idx;
	int		temp;
	int		check;

	check = 0;
	if (!(str = va_arg(ap, char*) ))
	{
		str = ft_strdup("(null)");
		check = 1;
	}
	temp = ft_strlen(str);;
	sum = 0;
	if (info->flag == -1 && !(info->zerospec))
		sum += string_sub2(info, sum, str);
	if (info->spec <0 || (info->spec == 0 && info->zerospec))
		return (string_sub(info,check, str, sum));
	// sum = (string_sub4(info,check, str, sum));
	// if(check)
	// 	free(str);
	// return (sum);
	if (info->spec && ft_strlen(str) > info->spec)
			temp = info->spec;
			
	if (info->width > 0 && temp< info->width)
	{
		idx = 0; // ㅂㅏ뀐 점
		while (idx++ < ((info->width) - temp))
		{
			if (info->zero == '0' && info->flag ==1)
			{
				info->result +=ft_putchar('0');
			}
			else
			{
				info->result +=ft_putchar(' ');
			}
		}
		ft_strlen(str) = info->width;
		sum+=idx - 1;
	}
	if (info->flag == 1)
	{
		if ((info-> spec) && info->flag == 1 )
		{
			idx = 0;
			
			while (idx < temp)
			{
				sum += ft_putchar(str[idx]);
				idx++;
			}
			
		}
		if (!(info->spec)&&(info->flag))
			sum += ft_putstr(str);

	}
	if(check)
		free(str);
	return (sum);
}