/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:07:37 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/30 15:34:45 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *fmt, ...);
int				ft_putlowerhexa(unsigned long nb);
int				ft_putupperhexa(unsigned int a);
int				ft_putstr(char *s);
int				ft_putpercent(int count);
int				ft_putchar(char c);
int				ft_putaddress(void *p);
int				ft_putunsignedecimal(unsigned int n);
int				ft_putint(long n);

#endif 
