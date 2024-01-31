/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilis2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:31:27 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/31 09:20:07 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	count;

	count = 0;
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putunsignedecimal(unsigned int n)
{
	int		i;
	char	c[11];
	int		count;

	count = 0;
	i = 0;
	if (n == 0)
	{
		if (write (1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	while (n > 0)
	{
		c[i++] = (n % 10) + 48;
		n /= 10;
		count++;
	}
	while (i > 0)
	{
		if (write(1, &c[--i], 1) == -1)
			return (-1);
	}
	return (count);
}

int	ft_putaddress(void *p)
{
	int	count;

	count = 0;
	if (p == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	count += ft_putlowerhexa((unsigned long)p);
	return (count);
}

int	ft_putpercent(int count)
{
	const void	*c;

	c = ((const void *) '%');
	count = 0;
	if (write(1, &c, 1) == -1)
		return ((count) = -1);
	count++;
	return (count);
}
