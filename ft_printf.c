/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:53:15 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/02 19:12:28 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MAX UINT_MAX

char 	option_withzero(t_info *info)
{
	char c;

	if (info->flag == -1)
		info ->zero = ' ';
	if ((info->spec > 0 && info->width != 0)||info->zerospec)
		info->zero = ' ';
	c = (info->zero == '0') ? '0' : ' ';
	return (c);
}

int		print_info(t_info *info, int sum)
{
	char	c;
	c = option_withzero(info);
	if (sum > info->spec)
	{
			info->spec = sum;	
	}
	info->width -= info->spec;
	if (!(info->flag == -1 || info->zero == '0'))
		while (info->width-- > 0)
		{
			info->result +=ft_putchar(' ');
		}
	if (info->sign == -1)
	{
		info->result +=ft_putchar('-');
	}
	if (!(info->flag == -1) && info->width >0 )
		while (info->width-- > 0)
		{
			info->result +=ft_putchar(c);
		}
	while (sum < info->spec--)
	{
		info->result +=ft_putchar('0');
	}
	return(info ->width);
}

int		find_num_length(long long num)
{
	long long sum;

	sum = 0;
	if (num == 0)
		return (1);
    while(num)
    {
        sum += 1;
        num = num / 10;
    }
	return(sum);
}

int     type_int(t_info *info, va_list ap, int i, char *s)
{
    long long num;
    int sum;
	int plus_sum;
		

	// printf("\n @@@ info->flag : %d @@@\n",info->flag);
	// printf("\n @@@ info->width : %d @@@\n",info->width);
	// printf("\n @@@ info->spec : %d @@@\n",info->spec);
	// printf("\n @@@ info->zero : %c @@@\n",info->zero);
	// printf("\n @@@ info->sign : %d @@@\n",info->sign);
	// printf("\n @@@ info->zerospec : %d @@@\n",info->zerospec);
	sum = 0;
	if (info->spec <0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
	num = va_arg(ap,int);
		if (info->width <0)
	{
		info->flag = -1;
		info->width *= -1;
	}
	if (num < 0)
	{
		num = num * (-1);
		info->sign = -1;
		info->width--;
	}

	// printf("~~%d~~\n",info->width);
	// printf("check1\n");

	//나중에 num == 0인 경우만 따로 함수를 빼 놓자
	//0이 들어왔는데, 0속성은 가지고 있지 않고, 정밀도는 0이 아닌 값이고, 넓이가 0이다
	if(num == 0 && info->zero != '0' &&info->zerospec ==0 && !(info->width) && (info->spec) < 0)
    {
		info->result +=ft_putchar('0');
		return (info->result);
	}
	// printf("check2\n");
	//0이 들어왔는데, 정밀도가 0이고, 넓이가 양수
	if(num == 0 && info->zerospec && info->width)
	{
		while(info->width--)
		{
			info->result += ft_putchar(' ');
		}
		return (info->result);
	}

	// printf("check3\n");
	sum += find_num_length(num);
	// printf("**sum : %d \n",sum); // += 에서 =로 바꿈
	// printf("\n sum : %d", sum);
	// printf("sum is : %d\n",sum);
	plus_sum = print_info(info, sum);
	// printf("check4\n");
	//0이 들어왔는데, 정밀도는 0이 아님(혹은 정의 x )
	if (info->zerospec && num == 0)
	{
		// return (plus_sum);
		return (0);
	}
	if(num>=0)
		ft_putnbr(num);
	// printf("\n *** plus_sum : %d\n", plus_sum);
	if (plus_sum >0)
	{
		// sum += plus_sum;
		// printf("\n sum : %d", sum);
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
	// print("\n$$$ info->result : %d \t sum : %d\n",info->result, sum);
    return (info->result + sum);
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
		info->result +=ft_putchar(word);
	if ((spec_num = info->spec) < 0)
	{
		idx = 1;
		spec_num *= -1;
		info->result +=ft_putchar(word);
		while (idx++ <spec_num)
			info->result +=ft_putchar(' ');
		return(spec_num);
	}
	if (info->width > 0)
	{
		while (idx++ < info->width)
		{
			if (info->zero == '0' && info->flag ==1)
				info->result +=ft_putchar('0');
			else
				info->result +=ft_putchar(' ');
		}
		result = info->width;
	}

	if (info->flag == 1)
		info->result +=ft_putchar(word);
    return (info->result);
}
int     type_string(t_info *info, va_list ap, int i, char *s)
{
    char	*string;
    int		sum;
	int		idx;
	int		spec_num;
	int		string_len;
	int		temp;
	

	// printf("\n @@@ info->flag : %d @@@\n",info->flag);
	// printf("\n @@@ info->width : %d @@@\n",info->width);
	// printf("\n @@@ info->spec : %d @@@\n",info->spec);
	// printf("\n @@@ info->zero : %c @@@\n",info->zero);
	// printf("\n @@@ info->sign : %d @@@\n",info->sign);
	// printf("\n @@@ info->zerospec : %d @@@\n",info->zerospec);
	string = va_arg(ap, char*);
	if (!(string)) //NULL이면
		string = ft_strdup("(null)");
	string_len = ft_strlen(string);
	temp = string_len;
	sum = 0;
	idx = 0;
	// printf("#check : sum -> %d\n",sum);
	if (info->flag == -1 && !(info->zerospec))
	{
		if ((info-> spec) )
		{
			idx = 0;
			// printf("???%d???\n",info->spec);
			while(idx < info->spec && idx < string_len)
			{
				sum += ft_putchar(string[idx]);
				// printf("!!!'%c'!!!\n",string[idx]);
				idx++;
			}
		}else
			sum += ft_putstr(string);
	}

	//공백찍기 시작 
	// printf("##check : sum -> %d\n",sum);
	//spec이 음수인 경우,,,
	if ((spec_num = info->spec) < 0)
	{
		idx = 0;
		spec_num *= -1;
		while (idx++ < spec_num)
			info->result +=ft_putchar(' ');
		sum +=idx;
		return(spec_num);
	}
		// printf("###check : sum -> %d\n",sum);
		//정밀도가 0인 경우,(초기값)
	if (info->spec == 0 && info->zerospec)
	{
		idx = 0;
		while (idx++ < info->width)
			info->result +=ft_putchar(' ');
		sum += idx;
		return(info->width);
	}
	// printf("####check : sum -> %d\n",sum);
	// printf("\n sum :[%d] \t [%d]\n",sum,idx);		
	if (info->spec && string_len > info->spec)
			temp = info->spec;
			
	// printf("**** spec : %d \t temp : %d\n",info->spec, temp);
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
		string_len = info->width;
		sum+=idx - 1;
	}
		// printf("#####check : sum -> %d\n",sum);
	if (info->flag == 1)
	{
		if ((info-> spec) && info->flag == 1 )
		{
			idx = 0;
			
			
			// while(idx < info->spec && idx < string_len)
			while (idx < temp)
			{
			// {printf("\n idx : %d\n", idx);printf("???%d??? \t >>>%d<<<\n",info->spec,string_len);
				sum += ft_putchar(string[idx]);
				// printf("!!!'%c'!!!\n",string[idx]);
				idx++;
			}
			
		}
		// printf("######check : sum -> %d\n",sum);
		if (!(info->spec)&&(info->flag))
			sum += ft_putstr(string);
		// if (info->flag == 1 )
		// 	sum += ft_putstr(string);
		// printf("######check : sum -> %d\n",sum);
	}

	return (sum);
}

int		find_num_length_x(unsigned long long num, char check)
{
	int		result;
	int		base_count;

	if (num == 0)
		return(1);
	if (check =='X' || check =='x')
		base_count = 16;
	else
		base_count = 10;
	result = 0;
	while(num)
    {
        num = num / base_count;
        result++;
    }
	return(result);
}


int		type_base(t_info *info, va_list ap, int i, char *s)
{
	unsigned int	num;
	char			check;
	int				sum;
	int				plus_sum;


	// printf("\n @@@ info->flag : %d @@@\n",info->flag);
	// printf("\n @@@ info->width : %d @@@\n",info->width);
	// printf("\n @@@ info->spec : %d @@@\n",info->spec);
	// printf("\n @@@ info->zero : %c @@@\n",info->zero);
	// printf("\n @@@ info->sign : %d @@@\n",info->sign);
	// printf("\n @@@ info->zerospec : %d @@@\n",info->zerospec);
	sum = 0;
	if (info->spec <0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
	num = va_arg(ap, unsigned int);
		if (info->width <0)
	{
		info->flag = -1;
		info->width *= -1;
	}
	check = s[i];
	// if(num == 0 && info->zero != '0' &&info->zerospec ==0)
    // {
	// 	info->result +=ft_putchar('0');
	// 	return(1);
	// }
	//나중에 num == 0인 경우만 따로 함수를 빼 놓자
	//0이 들어왔는데, 0속성은 가지고 있지 않고, 정밀도는 0이 아닌 값이고, 넓이가 0이다
	if(num == 0 && info->zero != '0' &&info->zerospec ==0 && !(info->width) && (info->spec) < 0)
    {
		info->result +=ft_putchar('0');
		return (info->result);
	}
	//0이 들어왔는데, 정밀도가 0이고, 넓이가 양수
	if(num == 0 && info->zerospec && info->width)
	{
		while(info->width--)
		{
			info->result += ft_putchar(' ');
		}
		return (info->result);
	}
	sum += find_num_length_x(num, check);
	// printf("sum is : %d\n",sum);
	plus_sum = print_info(info,sum);
	if (info->zerospec && num == 0)
	{
		// return (plus_sum);
		return (0);
	}	
	// printf("((((info->flag : %d\n",info->flag);
	if (plus_sum > 0 && info->flag == 1)
	{
		// sum += plus_sum;
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
	if (check == 'X')
		sum = ft_putbase("0123456789ABCDEF",num,16);
	else if(check == 'x')
		sum = ft_putbase("0123456789abcdef",num,16);
	else
		sum = ft_putbase("0123456789",num,10);
	if (plus_sum > 0 && info->flag == -1)
	{
		// sum += plus_sum;
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
	// printf("^^3->check\n");
	// printf("***plus_sum : %d\n",plus_sum);

	// printf("^^4->check\n");
	return (sum + info->result);
}

int		find_num_length_u(unsigned int num)
{
	unsigned int sum;

	sum = 0;
    while(num)
    {
        sum += 1;
        num = num / 10;
    }
	return(sum);
}

int		type_unsigned(t_info *info, va_list ap, int i, char *s)
{
	unsigned int	num;
	int				sum;
	int				int_max;
	int				plus_sum;
	
	// printf("\n @@@ info->flag : %d @@@\n",info->flag);
	// printf("\n @@@ info->width : %d @@@\n",info->width);
	// printf("\n @@@ info->spec : %d @@@\n",info->spec);
	// printf("\n @@@ info->zero : %c @@@\n",info->zero);
	// printf("\n @@@ info->sign : %d @@@\n",info->sign);
	sum = 0;
	if (info->spec <0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
	num = va_arg(ap,unsigned int);
	if (info->width <0)
	{
		info->flag = -1;
		info->width *= -1;
	}
	// if(num == 0 && info->zero != '0' &&info->zerospec ==0)
    // {
	// 	info->result +=ft_putchar('0');
	// 	return(1);
	// }
	// sum += find_num_length_u(num);
	// plus_sum = print_info(info,sum);
	// ft_putnbr_u(num);
	// if (plus_sum > 0)
	// {
	// 	sum += plus_sum;
	// 	while (plus_sum-->0)
	// 	info->result +=ft_putchar(' ');
	// }
	// return (sum);
		//나중에 num == 0인 경우만 따로 함수를 빼 놓자
	//0이 들어왔는데, 0속성은 가지고 있지 않고, 정밀도는 0이 아닌 값이고, 넓이가 0이다
	if(num == 0 && info->zero != '0' &&info->zerospec ==0 && !(info->width) && (info->spec) < 0)
    {
		info->result +=ft_putchar('0');
		return (info->result);
	}
	// printf("check2\n");
	//0이 들어왔는데, 정밀도가 0이고, 넓이가 양수
	if(num == 0 && info->zerospec && info->width)
	{
		while(info->width--)
		{
			info->result += ft_putchar(' ');
		}
		return (info->result);
	}

	// printf("check3\n");
	sum += find_num_length(num); // += 에서 =로 바꿈
	// printf("\n sum : %d", sum);
	plus_sum = print_info(info, sum);
	// printf("check4\n");
	//0이 들어왔는데, 정밀도는 0이 아님(혹은 정의 x )
	if (info->zerospec && num == 0)
	{
		// return (plus_sum);
		return (0);
	}
	if(num>=0)
		ft_putnbr_u(num);
	if (plus_sum >0)
	{
		// sum += plus_sum;
		// printf("\n sum : %d", sum);
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
	// printf("\n$$$ info->result : %d \t sum : %d\n",info->result, sum);
    return (info->result + sum);
}

int		type_address(t_info *info, va_list ap, int i, char *s)
{
	int					sum;
	unsigned long long 	num;
	int				plus_sum;


	if (info->spec <0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
	num = va_arg(ap, unsigned long long);
	sum = find_num_length_x(num,'x');
	printf("\n1@#@#%d\n",sum);
	if ( num == '\0')
	{
		if(!(info->zerospec))
		{
			sum = 0;
			num = 0;
		}
	}
	// printf("\n#######num : %llu ######\n",num);
	plus_sum = print_info(info, sum + 2 );
	// printf("!&&&&&&&&plus_sum : %d \n",plus_sum);
	printf("\n2@#@#%d\n",sum);
	if (info->zerospec && num == 0)
	{
		info->result +=ft_putchar('0');
		info->result +=ft_putchar('x');
		return (2);
	}
	printf("\n3@#@#%d\n",sum);
	if (plus_sum > 0 && info->flag == 1)
	{
		// sum += plus_sum;
		// printf("\n sum : %d", sum);
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
	printf("\n4@#@#%d\n",sum);
	if(num>=0)
	{
		info->result +=ft_putchar('0');
		info->result +=ft_putchar('x');
		sum += ft_putbase("0123456789abcdef",num, 16);
	}
	else
	{
		info->result +=ft_putchar('0');
		info->result +=ft_putchar('x');
	}
	printf("\n5@#@#%d\n",sum);
	if (plus_sum >0 && info->flag == -1)
	{
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
	
	printf("@@@@@into->result : %d \t sum : %d\n",info->result,sum);
	return (sum + info->result);
}

int		type_percent(t_info *info, va_list ap, int i, char *s)
{
	char	*content;
	int		sum;
	char	*blank;

	sum = 0;
	content = ft_strdup("");
	if (info->zero == '0' && info->flag == 1)
		blank = ft_strdup("0");
	else
		blank = ft_strdup(" ");
	while(--info->width > 0)
		content = ft_strjoin(content,blank);
	if (info->flag == -1)
		sum += ft_putchar('%');
	sum += ft_putstr(content);
	if (info->flag == 1)
		sum += ft_putchar('%');
	return(sum);


}


int     form_check(t_info *info, va_list ap, int i, char *s)
{
    int sum;
    int idx;

	sum = 0;
	idx = 0;
	// printf("s[i]= %c\n",s[i]);
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
	else if (s[i] == '%')
		sum = type_percent(info, ap, i, s);
	else
	{	
		// printf("else else ");
		return(-1);
		// while (i--)
		// 	sum += ft_putchar(s[idx]);
	}
		
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
	// printf("s[i]= %c\n",s[i]);
	// printf("info -> flag : %d\n",info->flag);
	i = get_width(ap, info, i, s);
	return(i);
}

int     get_width(va_list ap, t_info *info, int i, char *s)
{
    int 	n;
	int		check;
	
	check = 1;
	n = 0;
	while (s[i] == '0' || s[i] == '-')
	{
		while(s[i] == '0')
		{
			info->zero = '0';
			i++;	
		}
		while (s[i] =='-')
		{
			i++;
			check = -1;
		}
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
	info->width = n * check;

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
	// printf("s[i]= %c\n",s[i]);
	// printf("info -> spec %d\n",info->spec);
	return(i);
}


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

int ft_printf(char *s, ...)
{
    va_list ap;
    int     sum;

    va_start(ap,s);
    sum = find_write(ap,s);
    va_end(ap);
    return(sum);
}