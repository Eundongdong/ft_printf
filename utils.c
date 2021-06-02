#include "ft_printf.h"


void init(t_info *info)//기본값
{
	info->flag = 1; //음수면 -1로 변함
	info->width = 0;
    info->spec = 0;
    info->zero = ' '; //0들어오면 '0'으로 변함
    info->sign = 1;
    info->zerospec = 0; //정밀도에 들어온 값이 정말 0이면 1 변함
    info->result = 0; //읽은 값
}

void	ft_rec(long long nb)
{
	char	nbr;

	if (nb == 0)
		return ;
	ft_rec(nb / 10);
	nbr = nb % 10 + '0';
	write(1,&nbr,1);
}

void	ft_putnbr(long long nb)
{
	char	c;

    if (nb < 0)
	{
		write(1,"-",1);
		ft_rec(-(nb / 10));
		c = '0' - (nb % 10);
	}
	else
	{
		ft_rec(nb / 10);
		c = '0' + (nb % 10);
	}
	write(1,&c,1);
}

void	ft_rec_u(unsigned int nb)
{
	char	nbr;

	if (nb == 0)
		return;
	ft_rec(nb / 10);
	nbr = nb % 10 + '0';
	write(1,&nbr,1);
}

void    ft_putnbr_u(unsigned int nb)
{
    char	c;
	
	ft_rec(nb / 10);
	c = '0' + (nb % 10);
	write(1,&c,1);
}



int     ft_putbase(const char *base, unsigned long long num, int base_count)
{
    int                 sum;
    int                 i;
    int                 count;
    unsigned long long  temp;
    char                *s;

    i = 0;
    sum = 0;
    count = 0;
    if (num == 0)
    {
        write(1,"0",1);
        return(1);
    }
    temp = num;
    while(temp)
    {
        temp = temp / base_count;
        count++;
    }
    if (!(s = (char *)malloc(sizeof(char) * (count + 1))))
        return(-1);
    while(num)
    {
        s[i++] = base[num % base_count];
        num = num / base_count;
    }
    sum = i;
    while(i > 0)
        write(1,&s[--i],1);
    free(s);
    return(sum);
}

int     ft_putchar(char c)
{
    write(1,&c,1);
    return (1);
}