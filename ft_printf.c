/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:53:15 by eunjkim           #+#    #+#             */
/*   Updated: 2021/05/24 18:12:31 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	option_withzero(t_info *info)
{
	char c;

	if (info->flag == -1)
		info ->zero = ' ';
	if ((info->spec > 0 && info->width != 0)||info->zero == 0)
		info->zero = ' ';
	c = (info->zero == '0') ? '0' : ' ';
	return (c);
}

int		print_info(t_info *info, int sum)
{
	char c;
		
	c = option_withzero(info);
	if (sum > info->spec)
		info->spec = sum;
	info->width -= info->spec;
	if (!(info->flag == -1 || info->zero == '0'))
		while (info->width-- > 0)
		{
			write(1," ",1);
		}
	if (info->sign == -1)
		write(1,"-",1);
	if (!(info->flag == -1))
		while (info->width-- > 0)
		{
			write(1,&c,1);
		}	
	while (sum < info->spec--)
	{
		write(1,"0",1);
	}
	return(info ->width);
}

int		find_num_length(int num)
{
	int sum;

	sum = 0;
    while(num)
    {
        sum += 1;
        num = num / 10;
    }
	return(sum);
}

int     type_int(t_info *info, va_list ap, int i, char *s)
{
    int num;
    int sum;
	int plus_sum;
	int temp;
		
	if (info->spec <0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
	num = va_arg(ap,int);
	if (num < 0)
	{
		num = num * (-1);
		info->sign = -1;
		info->width--;
	}
	if(num == 0 && info->zero != '0' &&info->zerospec ==0)
    {
		write(1,"0",1);
		return(1);
	}
	sum = find_num_length(num);
	plus_sum = print_info(info, sum);
	if(num>0)
		ft_putnbr(num);
	temp = plus_sum;
	while (temp-- > 0)
            write(1," ",1);		
    return (sum + plus_sum);
}

int     type_char(t_info *info, va_list ap, int i, char *s)
{
    char	word;
	int		idx;
	int		spec_num;
	int		result;
	// printf("\n @@@ info->flag : %d @@@\n",info->flag);
	// printf("\n @@@ info->width : %d @@@\n",info->width);
	// printf("\n @@@ info->spec : %d @@@\n",info->spec);
	// printf("\n @@@ info->zero : %c @@@\n",info->zero);
	// printf("\n @@@ info->sign : %d @@@\n",info->sign);

	idx = 1;
	result = 1;
    word = va_arg(ap, int);	
	
	if (info->flag == -1)
		write(1,&word,1);
	if ((spec_num = info->spec) < 0)
	{
		idx = 1;
		spec_num *= -1;
		write(1,&word,1);
		while (idx++ <spec_num)
			write(1," ",1);
		
		return(spec_num);
	}
	if (info->width > 0)
	{
		while (idx++ < info->width)
		{
			if (info->zero == '0' && info->flag ==1)
				write(1,"0",1);
			else
				write(1," ",1);
		}
		result = info->width;
	}

	if (info->flag == 1)
		write(1,&word,1);
    return (result);
}
int     type_string(t_info *info, va_list ap, int i, char *s)
{
    char	*string;
    int		result;
	int		idx;
	int		spec_num;
	int		string_len;

	string = va_arg(ap, char*);
	string_len = ft_strlen(string);
	result = 0;
	idx = 0;
	if (info->flag == -1 && !(info->zerospec))
		result = ft_putstr(string);
	
	if ((spec_num = info->spec) < 0)
	{
		idx = 0;
		spec_num *= -1;
		while (idx++ < spec_num)
			write(1," ",1);
		result +=idx;
		return(spec_num);
	}
		
	if (info->spec == 0 &&info->zerospec)
	{
		idx = 0;
		while (idx++ < info->width)
			write(1," ",1);
		result += idx;
		return(info->width);
	}
	
	if (info->width > 0)
	{
		while (idx++ < ((info->width) - string_len))
		{
			if (info->zero == '0' && info->flag ==1)
				write(1,"0",1);
			else
				write(1," ",1);
		}
		string_len = info->width;
		result +=idx;
	}
	
	if (info->flag == 1)
		ft_putstr(string);
	return (result);
}

int		type_base(t_info *info, va_list ap, int i, char *s)
{
	unsigned int	num;
	char			check;
	int				sum;

	
	num = va_arg(ap, unsigned int);
	check = s[i];
	if (check == 'X')
		sum = ft_putbase("0123456789ABCDEF",num,16);
	else if(check == 'x')
		sum = ft_putbase("0123456789abcdef",num,16);
	else
		sum = ft_putbase("0123456789",num,10);
	return (sum);
}

int		type_unsigned(t_info *info, va_list ap, int i, char *s)
{
	unsigned int	num;

	num = va_arg(ap,unsigned int);
	
}



int		type_address(t_info *info, va_list ap, int i, char *s)
{
	int				sum;
	unsigned long	num;

	num = va_arg(ap, long long);
	write(1,"0x",2);
	sum = ft_putbase("0123456789abcedf",num,16);
	return (sum + 2);
}

int     form_check(t_info *info, va_list ap, int i, char *s)
{
    int sum;
    sum = 0;
    if(s[i] == 'd'|| s[i]== 'i')
        sum = type_int(info, ap, i, s);
    else if (s[i] == 'c')
        sum = type_char(info, ap, i ,s);
    else if (s[i] == 's')
        sum = type_string(info, ap, i, s);
	else if (s[i] == 'x' || s[i] == 'X')
		sum = type_base(info, ap, i ,s);
	else if (s[i] == 'p')
		sum = type_address(info, ap, i, s);
	else if (s[i] == 'u')
		sum = type_unsigned(info,ap,i,s);
	return(sum);
}

int     get_flag(va_list ap, t_info *info, int i, char *s)
{
    i++;
    if(s[i] == '-')
	{
		info->flag = -1;
		i++;
	}
		
	i = get_width(ap, info, i, s);
	return(i);
}

int     get_width(va_list ap, t_info *info, int i, char *s)
{
    int n;

	n = 0;
	if (s[i] == '0')
	{
		info->zero = '0';
		i++;
	}
	while(ft_isdigit(s[i]))
    {
       n = n * 10 + s[i] - 48;
	   i++;
    }
	if (s[i] == '*')
	{
		n = va_arg(ap,int);
		if (n < 0)
		{
			info->flag = -1;
			n *=-1;
		}	
		i++;
	}
	info->width = n;
	i = get_spec(ap, info, i, s);
	return (i);

}

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


int     find_write(va_list ap, char *s)
{
    int     i;
    int     sum;
	t_info  info;
    
	i = 0;
    sum = 0;
	init(&info);
	i = 0;
    while(s[i] != '\0')
    {
        if(s[i] =='%')
        {

            i = get_flag(ap, &info, i, s);
            sum += form_check(&info, ap, i, s);
        }
        else
        {
            sum += 1;
            write(1, &s[i], 1);
        }
        i++;
    }
    return (sum);
}

int ft_printf(char *s, ...)
{
    va_list ap;
    int     sum;

    va_start(ap,s);
    sum = find_write(ap,s);
    va_end(ap);
    return(sum);
}