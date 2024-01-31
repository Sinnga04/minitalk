/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:28:47 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/30 15:31:46 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static int	ft_puthelper(int *i, long *n)
{
	int		count;
	int		temp;

	count = 0;
	*i = 0;
	if (*n == 0)
	{
		temp = write(1, "0", 1);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (*n < 0)
	{
		*n *= -1;
		temp = write(1, "-", 1);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

int	ft_putint(long n)
{
	int		i;
	char	c[11];
	int		count;
	int		temp;

	count = ft_puthelper(&i, &n);
	if (count == -1)
		return (-1);
	while (n > 0)
	{
		c[i++] = (n % 10) + 48;
		n /= 10;
	}
	while (i > 0)
	{
		temp = write(1, &c[--i], 1);
		if (temp == -1)
		{
			count = -1;
			break ;
		}
		count += temp;
	}
	return (count);
}

int	ft_putlowerhexa(unsigned long nb)
{
	int		i;
	long	num[100];
	char	*base;
	int		count;

	i = 0;
	count = 0;
	base = "0123456789abcdef";
	if (nb == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	while (nb > 0)
	{
		num[i] = base[nb % 16];
		nb /= 16;
		i++;
		count++;
	}
	while (i > 0)
		if (write(1, &num[--i], 1) == -1)
			return (-1);
	return (count);
}

int	ft_putupperhexa(unsigned int a)
{
	int		i;
	long	num[100];
	char	*base;
	int		count;

	i = 0;
	count = 0;
	base = "0123456789ABCDEF";
	if (a == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	while (a > 0)
	{
		num[i] = base[a % 16];
		a /= 16;
		i++;
		count++;
	}
	while (i > 0)
		if (write(1, &num[--i], 1) == -1)
			return (-1);
	return (count);
}

int	ft_putstr(char *s)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (s == 0)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		count += 6;
		return (count);
	}
	while (s[a] != 0)
	{
		if (write(1, &s[a], 1) == -1)
			return (-1);
		a++;
		count++;
	}
	return (count);
}
