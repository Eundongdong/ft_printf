#include "ft_printf.h"

int		type_address(t_info *info, va_list ap, int i, char *s)
{
	int					sum;
	unsigned long long 	num;
	int				plus_sum;
	int				null_check; //nullㅇㅣ 들어오면 1
	int				temp;

	null_check = 0;
	if (info->spec <0)
	{
		info->width = info->spec * (-1);
		info->spec = 0;
		info->flag = -1;
	}
	num = va_arg(ap, unsigned long long);
	if (info->width <0)
	{
		info->flag = -1;
		info->width *= -1;
	}
	sum = find_num_length_x(num,'x');
	if ( num == '\0')
	{
		num = 0;
		sum = 0;
		null_check = 1;
		if (!(info->zerospec) && !(info->spec))
			sum = 1;
	}
	//null일 떄 따로 함수로 빼기 (info->width > 2 || info->spec > 2)
	if ((null_check  && (info->spec) ))
	{
		info->result +=ft_putchar('0');
		info->result +=ft_putchar('x');
		if(info->width > info->spec)
		{
			temp = info->width - 2;
			while (temp--)
				info->result +=ft_putchar('0');
		}
		else
		{
			while(info->spec--)
				info->result += ft_putchar('0');
		}
		return(info->result);
	}
	
	if (!(null_check) && sum < info->spec)
	{
		info->result +=ft_putchar('0');
		info->result +=ft_putchar('x');
		if (info->width > info->spec)
		{
			temp = info->width -2 - sum;
			while(temp--)
				info->result += ft_putchar('0');
		}
		else
		{
			temp = info->spec - sum;
			while(temp--)
				info->result += ft_putchar('0');
		}
		ft_putbase("0123456789abcdef",num, 16);
		return(info->result + sum);
	}

	plus_sum = print_info(info, sum + 2 );
	if (plus_sum > 0 && info->flag == 1)
	{
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}

	info->result +=ft_putchar('0');
	info->result +=ft_putchar('x');

	sum = 0;
	if(num>0 || (!(info->zerospec) && null_check))
	{
		sum += ft_putbase("0123456789abcdef",num, 16);
	}
	if (plus_sum >0 && info->flag == -1)
	{
		while (plus_sum-- > 0)
            info->result +=ft_putchar(' ');
	}
	return (sum + info->result);
}