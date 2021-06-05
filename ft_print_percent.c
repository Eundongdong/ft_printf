/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:48:40 by eunjkim           #+#    #+#             */
/*   Updated: 2021/06/05 15:10:34 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*percent_sub(t_info *info, char *content, char *blank)
{
	char	*temp;

	while (--info->width > 0)
	{
		temp = ft_strjoin(content, blank);
		free(content);
		content = temp;
	}
	return (content);
}

int		type_percent(t_info *info)
{
	char	*content;
	int		sum;
	char	*blank;

	sum = 0;
	content = ft_strdup("");
	if (info->zero == '0' && info->flag == 1)
		blank = ft_strdup("0");
	else
		blank = ft_strdup(" ");
	content = percent_sub(info, content, blank);
	if (info->flag == -1)
		sum += ft_putchar('%');
	sum += ft_putstr(content);
	if (info->flag == 1)
		sum += ft_putchar('%');
	free(content);
	free(blank);
	return (sum);
}
