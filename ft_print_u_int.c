#include "ft_printf.h"

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

	sum += find_num_length(num); // u로 바꿈
	plus_sum = print_info(info, sum);
	//0이 들어왔는데, 정밀도는 0이 아님(혹은 정의 x )
	if (info->zerospec && num == 0)
	{
		return (0);
	}
	if(num>=0)
		ft_putnbr_u(num);
	if (plus_sum >0)
	{
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
    return (info->result + sum);
}