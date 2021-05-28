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

    result1 = 0;
    result2 = 0;


	result1 = printf("%1.d!\n", l); //T23
	result2 = ft_printf("%1.d!\n", l); //T23


	// result1 = printf("%2d",j);
	// result2 = ft_printf("%2d",j);
    printf("result1 = %d \n",result1);
    printf("result2 = %d \n",result2);

    return (0);

}
