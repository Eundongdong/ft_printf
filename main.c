#include "ft_printf.h"
#include <stdio.h>

#define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)

int main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

    int     result1;
    int     result2;

	ft_printf("%10.c %10.2d %10.2s %10.2i %10.2x %10.2X %10.2u %10.2p\n", 'a', 10, "(null)", f, e, e, e, o);

while(1)
{

}
return (0);

}
