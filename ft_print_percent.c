#include "ft_printf.h"

int		type_percent(t_info *info, va_list ap, int i, char *s)
{
	char	*content;
	int		sum;
	char	*blank;
	char 	*temp;

	sum = 0;
	if (info->width <0)
	{
		info->flag = -1;
		info->width *= -1;
	}
	content = ft_strdup("");
	if (info->zero == '0' && info->flag == 1)
		blank = ft_strdup("0");
	else
		blank = ft_strdup(" ");
	while(--info->width > 0)
	{
		temp = ft_strjoin(content,blank);
		content = temp;
		free(temp);
	}
	if (info->flag == -1)
		sum += ft_putchar('%');
	sum += ft_putstr(content);
	if (info->flag == 1)
		sum += ft_putchar('%');
	free(content);
	free(blank);
	return(sum);


}
