#include "ft_printf.h"

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
	plus_sum = print_info(info,sum);
	if (info->zerospec && num == 0)
	{
		return (0);
	}	
	if (plus_sum > 0 && info->flag == 1)
	{
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
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
	return (sum + info->result);
}
