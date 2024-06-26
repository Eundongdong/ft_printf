/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:54:03 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/05 14:56:09 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include "libft/libft.h"

typedef struct	s_info
{
	int		width;
	int		flag;
	int		spec;
	char	zero;
	int		sign;
	int		zerospec;
	int		result;
}				t_info;

void			init(t_info *info);
int				ft_putchar(char c);
int				get_width(va_list ap, t_info *info, int i, char *s);
int				get_spec(va_list ap, t_info *info, int i, char *s);
char			option_withzero(t_info *info);
int				print_info(t_info *info, int sum);
int				type_unsigned(t_info *info, va_list ap);
int				type_address(t_info *info, va_list ap);
int				type_base(t_info *info, va_list ap, int i, char *s);
int				type_char(t_info *info, va_list ap);
int				type_int(t_info *info, va_list ap);
int				type_percent(t_info *info);
int				type_string(t_info *info, va_list ap);
int				find_num_length_x(unsigned long long num, char check);
int				find_num_length(long long num);
int				get_flag(va_list ap, t_info *info, int i, char *s);
void			ft_rec(long long nb);
void			ft_rec_u(unsigned int nb);
void			ft_putnbr(long long nb);
void			ft_putnbr_u(unsigned int nb);
int				puttype_d(va_list ap, int i, char *s);
int				form_check(t_info *info, va_list ap, int i, char *s);
int				find_write(va_list ap, char *s);
int				ft_printf(char *s, ...);
int				ft_putstr(char *s);
int				ft_putbase(const char *base, unsigned long long num,
							int base_count);

#endif
