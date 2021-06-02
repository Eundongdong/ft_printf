#include "ft_printf.h"

int     type_char(t_info *info, va_list ap, int i, char *s)
{
    char	word;
	int		idx;
	int		spec_num;
	int		result;

	idx = 1;
	result = 1;
    word = va_arg(ap, int);	
		
	if (info->width <0)
	{
		info->flag = -1;
		info->width *= -1;
	}
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