/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:53:15 by eunjkim           #+#    #+#             */
/*   Updated: 2021/05/12 15:59:53 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_info(t_info *info, int sum)
{
	int temp;


	printf("\n @@@ sum : %d @@@\n",sum);
	temp = info->width;
	printf("\n @@@ info->spec : %d @@@\n",info->spec);
	if (sum > info->spec)
		info->spec = sum;
	printf("\n @@@ info->spec : %d @@@\n",info->spec);
	info->width -= info->spec;
	printf("\n @@@ info->width : %d @@@\n",info->width);
	if (!(info->flag == -1 && info->zero == '0'))
		while (info->width-- > 0)
			write(1," ",1);
	printf("\n @@@ info->spec : %d @@@\n",info->spec);
	printf("\n @@@ info->width : %d @@@\n",info->width);
	if (info->sign == -1)
		write(1,"-",1);
	if (!(info->flag == -1))
		while (info->width-- > 0)
			write(1,&info->zero,1);
	printf("\n @@@ info->spec : %d @@@\n",info->spec);
	printf("\n @@@ info->width : %d @@@\n",info->width);
	while (sum < info->spec--)
		write(1,"0",1);
	printf("\n @@@ info->spec : %d @@@\n",info->spec);
	printf("\n @@@ info->width : %d @@@\n",info->width);
	return(temp);
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
	
	num = va_arg(ap,int);
	if (num < 0)
	{
		num = num * (-1);
		info->sign = -1;
	}
    if(num == 0)
        return (1);
	sum = find_num_length(num);
	printf("\n## %d ##\n",sum);
	plus_sum = print_info(info, sum);
	printf("\n## %d ##\n",plus_sum);
	ft_putnbr(num);
	temp = plus_sum - sum;
	while (temp-- > 0)
            write(1," ",1);
    return (sum + plus_sum);
}

int     type_char(t_info *info, va_list ap, int i, char *s)
{
    char word;

    word = va_arg(ap, int);
    write(1,&word,1);
    return (1);
}

int     type_string(t_info *info, va_list ap, int i, char *s)
{
    char	*string;
    int		sum;
    
	string = va_arg(ap, char*);
    sum = ft_putstr(string);
	return (sum);
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
	else if (s[i] == 'x' || s[i] == 'X'|| s[i] == 'u')
		sum = type_base(info, ap, i ,s);
	else if (s[i] == 'p')
		sum = type_address(info, ap, i, s);
	return(sum);
}

int     get_flag(va_list ap, t_info *info, int i, char *s)
{
    i++;
    while(1)
    {
        if(s[i] == '-')
			info->flag = -1;
        else
            break;
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
		i++;
	}
	info->width = n;
	i = get_spec(ap, info, i, s);
	return (i);

}

int		get_spec(va_list ap, t_info *info, int i, char *s)
{
	int n;

	n = 0;
	if(s[i] == '.')
	{
		i++;
		while(ft_isdigit(s[i]))
		{
			n = n * 10 + s[i] - 48;
			i++;
		}
		if (s[i] == '*')
		{
			n = va_arg(ap, int);
			i++;
		}
		info->spec = n;
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
	init(info);
    while(s[i] != '\0')
    {
        if(s[i] =='%')
        {
            i = get_flag(ap, &info, i, s);
			//printf("\n***\n %d %d %d\n***\n",info.flag, info.width, info.spec);
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

// int main(void)
// {
//     int a;
//     int b;
//     int c;

// 	printf("%-2.5d#\n",123);
// 	printf("%3.5d#\n",123);
// 	printf("%7.5d#\n",123);
//     a = printf("%d#\n", 123);
//     b = ft_printf("%d#\n", 123);
//     printf("========\n%d %d",a, b);
    
//     return(0);
// }



	// if (info->width > info->spec)
	// {
	// 	//너비만 있으면 숫자는 그냥 호출
	// 	if (info->spec == 0 && info-> width > 0)
	// 	{
	// 		ft_putnbr(num);
    // 		return (sum);
	// 	}
	// 	//정밀도만 있으면 공백에 0 붙이기
	// 	//둘 다 있으면 너비 < 정밀도라면 정밀도만 있다고 생각
	// 	//너비 > 정밀도라면 __00123#(

	// 	if (info->width > sum)
	// 	{

	// 		idx = info->spec - sum;
	// 		while(idx--)
	// 			write(1,"0",1);
	// 	}
	// 	if (info->flag == -1)

	// }