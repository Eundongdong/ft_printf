#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a1;
    int b1;
    int c1;

    
    a1 = ft_printf("%-10d#\n", 123);
	b1 = printf("%-10d#\n", 123);
    printf("========\n%d %d\n",a1, b1);
    printf("========\n");


	// ft_printf("[%1.d]\n", 3);
	// printf("[%1.d]\n", 3);
    // printf("========\n");
	// ft_printf("[%1d]\n", 0);
	// printf("[%1d]\n", 0);
    // printf("========\n");
	// ft_printf("[%0.d]\n", 0);
	// printf("[%0.d]\n", 0);
    // printf("========\n");
	// ft_printf("[%.0d]\n", 0);
	// printf("[%.0d]\n", 0);
    // 	printf("\n");
	// ft_printf("[%07.5d]\n", -12);
	// printf("[%07.5d]\n", -12);
	// ft_printf("[%7.5d]\n", -12);
	// printf("[%7.5d]\n", -12);
	// ft_printf("[%7.-5d]\n", -12);
	// printf("[%7.-5d]\n", -12);
	// ft_printf("[%07.-5d]\n", 12);
	// printf("[%07.-5d]\n", 12);
	// ft_printf("[%03.5d]\n", -12);
	// printf("[%03.5d]\n", -12);
	// ft_printf("[%3.5d]\n", -12);
	// printf("[%3.5d]\n", -12);
	// ft_printf("[%03.-5d]\n", 12);
	// printf("[%03.-5d]\n", 12);

	// ft_printf("[%-6.4s]\n", "70000");
	// printf("[%-6.4s]\n", "70000");
	// ft_printf("[%-2.3s]\n", "12345");
	// printf("[%-2.3s]\n", "12345");
	// ft_printf("[%-3.6s]\n", "12345");
	// printf("[%-3.6s]\n", "12345");
	// ft_printf("[%-8.4s]\n", "1234567");
	// printf("[%-8.4s]\n", "1234567");
	// ft_printf("[%-010.5s]\n", "12345");
	// printf("[%-010.5s]\n", "12345");


	// printf("\n\n-----------1 option-------------\n\n");
	// ft_printf("\n\n-----------1 option-------------\n\n");
	// printf("test2[10d]:%10d!\n",123);
	// ft_printf("test2[10d]:%10d!\n",123);
	// printf("test3[.20]:%.20d!\n",123);
	// ft_printf("test3[.20]:%.20d!\n",123);
	// printf("test4[-10]:%-10d!\n",123);
	// ft_printf("test4[-10]:%-10d!\n",123);
	// printf("test5[.-20]:%.-20d!\n",123); //negative precisionthe pase 'p'
	// ft_printf("test5[.-20]:%.-20d!\n",123); //negative precisionthe pase 'p'
	// printf("\n\n------------2 option------------\n\n");
	// ft_printf("\n\n------------2 option------------\n\n");
	// printf("test6[10.20]:%10.20d!\n",123);
	// ft_printf("test6[10.20]:%10.20d!\n",123);
	// printf("test7[20.10]:%10.10d!\n",123);
	// ft_printf("test7[20.10]:%10.10d!\n",123);
	// printf("test8[-10.20]:%-10.20d!\n",123);
	// ft_printf("test8[-10.20]:%-10.20d!\n",123);
	// printf("test9[10.-20]:%10.-20d!\n",123); //as above
	// ft_printf("test9[10.-20]:%10.-20d!\n",123); //as above
	// printf("test10[20.-10]:%20.-10d!\n",123);//as above
	// ft_printf("test10[20.-10]:%20.-10d!\n",123);//as above
	// printf("test11[-20.10]:%-20.10d!\n",123);
	// ft_printf("test11[-20.10]:%-20.10d!\n",123);
	// printf("\n\n-----------wilddard-------------\n\n");
	// ft_printf("\n\n-----------wilddard-------------\n\n");
	// printf("test12[10.*(20)]:%10.*d!\n",20,123);
	// ft_printf("test12[10.*(20)]:%10.*d!\n",20,123);
	// printf("test13[10.*(-20)%10.*d!\n",-20,123);
	// ft_printf("test13[10.*(-20)%10.*d!\n",-20,123);
	// printf("test14[20.*(10)]:%-10.*d!\n",10,123);
	// ft_printf("test14[20.*(10)]:%-10.*d!\n",10,123);
	// printf("test15[20.*(-10)]:%-10.*d!\n",-10,123);
	// ft_printf("test15[20.*(-10)]:%-10.*d!\n",-10,123);
	// printf("test16[*(10).20]:%*.20d!\n",10,123);
	// ft_printf("test16[*(10).20]:%*.20d!\n",10,123);
	// printf("test17[*(-10).20]:%*.20d!\n",-10,123);
	// ft_printf("test17[*(-10).20]:%*.20d!\n",-10,123);
	// printf("test18[*(20).10]:%*.10d!\n",20,123);
	// ft_printf("test18[*(20).10]:%*.10d!\n",20,123);
	// printf("test19[*(-20).10]:%*.10d!\n",-20,123);
	// ft_printf("test19[*(-20).10]:%*.10d!\n",-20,123);
	// printf("\n\n-------------apply to flag-----------\n\n");
	// ft_printf("\n\n-------------apply to flag-----------\n\n");
	// printf("test20[-010.20]:%-010.20d!\n",123);//double flag
	// ft_printf("test20[-010.20]:%-010.20d!\n",123);//double flag
	// printf("test21[-020.10]:%-020.10d!\n",123);//double flag
	// ft_printf("test21[-020.10]:%-020.10d!\n",123);//double flag
	// printf("test22[010.20]:%010.20d!\n",123);
	// ft_printf("test22[010.20]:%010.20d!\n",123);
	// printf("test23[010.20]:%020.10d!\n",123);
	// ft_printf("test23[010.20]:%020.10d!\n",123);
	// printf("\n\n-------------zero-----------\n\n");
	// ft_printf("\n\n-------------zero-----------\n\n");
	// printf("testz1[0]:%0d!\n",123);
	// ft_printf("testz1[0]:%0d!\n",123);
	// printf("testz2[0]:%.0d!\n", 123);
	// ft_printf("testz2[0]:%.0d!\n", 123);
	// printf("test24[0.0]:%0.0d!\n",123);
	// ft_printf("test24[0.0]:%0.0d!\n",123);
	// printf("test25[10.0]:%10.0d!\n",123);
	// ft_printf("test25[10.0]:%10.0d!\n",123);
	// printf("test26[0.10]:%0.10d!\n",123);
	// ft_printf("test26[0.10]:%0.10d!\n",123);
	// printf("\n\n-------------zero in wilddard-----------\n\n");
	// ft_printf("\n\n-------------zero in wilddard-----------\n\n");
	// printf("test27[*.10]:%*.10d!\n",0, 123);
	// ft_printf("test27[*.10]:%*.10d!\n",0, 123);
	// printf("test28[*.]:%*.d!\n",0, 123);
	// ft_printf("test28[*.]:%*.d!\n",0, 123);
	// printf("test29[10.*]:%10.*d!\n",0, 123);
	// ft_printf("test29[10.*]:%10.*d!\n",0, 123);
	// printf("test30[-10.*]:%-10.*d!\n",0, 123);
	// ft_printf("test30[-10.*]:%-10.*d!\n",0, 123);
	// printf("test31[*.*]:%*.*d!\n",0,0, 123);
	// ft_printf("test31[*.*]:%*.*d!\n",0,0, 123);

return(0);
}
