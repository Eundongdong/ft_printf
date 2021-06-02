#include "ft_printf.h"

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



int     type_int(t_info *info, va_list ap, int i, char *s)
{
    long long num;
    int sum;
	int plus_sum;
		
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
	sum += find_num_length(num);
	plus_sum = print_info(info, sum);
	//0이 들어왔는데, 정밀도는 0이 아님(혹은 정의 x )
	if (info->zerospec && num == 0)
	{
		return (0);
	}
	if(num>=0)
		ft_putnbr(num);
	if (plus_sum >0)
	{
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
    return (info->result + sum);
}