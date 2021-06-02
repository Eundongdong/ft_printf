#include "ft_printf.h"

int     type_string(t_info *info, va_list ap, int i, char *s)
{
    char	*str;
    int		sum;
	int		idx;
	int		spec_num;
	int		string_len;
	int		temp;
	int		check;

	check = 0;
	str = va_arg(ap, char*);
	if (!(str)) //NULL이면
	{
		str = ft_strdup("(null)");
		check = 1;
	}
	string_len = ft_strlen(str);
	if (info->width <0)
	{
		info->flag = -1;
		info->width *= -1;
	}
	temp = string_len;
	sum = 0;
	idx = 0;
	if (info->flag == -1 && !(info->zerospec))
	{
		if ((info-> spec) )
		{
			idx = 0;
			while(idx < info->spec && idx < string_len)
			{
				sum += ft_putchar(str[idx]);
				idx++;
			}
		}else
			sum += ft_putstr(str);
	}

	//공백찍기 시작 
	//spec이 음수인 경우,,,
	if ((spec_num = info->spec) < 0)
	{
		idx = 0;
		spec_num *= -1;
		while (idx++ < spec_num)
			info->result +=ft_putchar(' ');
		sum +=idx;
		if (check)
			free(str);
		return(spec_num);
	}
		//정밀도가 0인 경우,(초기값)
	if (info->spec == 0 && info->zerospec)
	{
		idx = 0;
		while (idx++ < info->width)
			info->result +=ft_putchar(' ');
		sum += idx;
		if (check)
			free(str);
		return(info->width);
	}
		
	if (info->spec && string_len > info->spec)
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
		string_len = info->width;
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