/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:53:31 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/31 09:30:54 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_format(char fmt, va_list *arg)
{
	int	i;
	int	count;

	count = -1;
	i = 0;
	if (fmt == 's')
		count = ft_putstr(va_arg(*arg, char *));
	else if (fmt == 'x')
		count = ft_putlowerhexa(va_arg(*arg, unsigned int));
	else if (fmt == 'c')
		count = ft_putchar(va_arg(*arg, int));
	else if (fmt == 'X')
		count = ft_putupperhexa(va_arg(*arg, unsigned int));
	else if (fmt == 'd' || fmt == 'i')
		count = ft_putint(va_arg(*arg, int));
	else if (fmt == 'u')
		count = ft_putunsignedecimal(va_arg(*arg, unsigned int));
	else if (fmt == '%')
		count = ft_putpercent('%');
	else if (fmt == 'p')
		count = ft_putaddress(va_arg(*arg, void *));
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		i;
	int		count;
	int		temp;

	count = 0;
	i = 0;
	va_start(arg, input);
	while (input[i] != 0)
	{
		if (input[i] == '%' && input[i + 1])
			temp = ft_format(input[i++ + 1], &arg);
		else
			temp = ft_putchar(input[i]);
		if (temp == -1)
		{
			count = -1;
			break ;
		}
		count += temp;
		i++;
	}
	va_end(arg);
	return (count);
}
