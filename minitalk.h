/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:47:00 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/06 14:07:15 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
char	*ft_itoa(int num);
void	sig_handler(int signo, siginfo_t *info, void *context);
void	handle_client(int signal);
int		send_signal(char *binary_code, int target_pid);

#endif