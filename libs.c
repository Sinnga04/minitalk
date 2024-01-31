/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:46:13 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/06 14:03:15 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	get_num_digits(int n)
{
	int	numdigits;

	numdigits = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		numdigits++;
	}
	return (numdigits);
}

char	*ft_itoa(int num)
{
	long	n;
	int		sign;
	int		numdigits;
	char	*str;

	n = num;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	numdigits = get_num_digits(n) + (sign == -1);
	str = (char *)malloc((numdigits + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[numdigits] = '\0';
	while (numdigits > 0)
	{
		str[--numdigits] = '0' + (n % 10);
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	z;
	int	neg_counter;

	i = 0;
	z = 0;
	neg_counter = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			neg_counter++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		z = z * 10 + (str[i] - '0');
		i++;
	}
	if (neg_counter == 1)
	{
		z *= -1;
	}
	return (z);
}