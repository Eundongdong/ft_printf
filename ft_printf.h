/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:54:03 by eunjkim           #+#    #+#             */
/*   Updated: 2021/05/18 16:25:14 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_info
{
    int width;
    int flag;
    int spec;
    char zero;
    int sign;
    int zerospec;
}				t_info;


# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include "libft/libft.h"

void 	init(t_info *info);
int     get_width(va_list ap, t_info *info, int i, char *s);
int		get_spec(va_list ap, t_info *info, int i, char *s);
int     get_flag(va_list ap, t_info *info, int i, char *s);
void	ft_rec(int nb);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int     puttype_d(va_list ap, int i, char *s);
int     form_check(t_info *info, va_list ap, int i, char *s);
int     find_write(va_list ap, char *s);
int     ft_printf(char *s, ...);
int		ft_putstr(char *s);
int     ft_putbase(const char *base, unsigned long num, int base_count);
#endif