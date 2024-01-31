/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:11:30 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/17 12:13:45 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_signal(char *binary_code, int target_pid)
{
	int		i;

	while (*binary_code)
	{
		i = 0;
		while (i < 8)
		{
			if (*binary_code & (1 << i))
				kill(target_pid, SIGUSR1);
			else
				kill(target_pid, SIGUSR2);
			i--;
			usleep(90);
		}
		binary_code++;
	}
	i = 0;
	while (i < 8)
	{
		kill(target_pid, SIGUSR2);
		i++;
		usleep(90);
	}
	return (0);
}

void	handle_client(int signal)
{
	if (signal == SIGUSR2)
	{
		write(1, "DONE\n", 5);
	}
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	int					target_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	target_pid = ft_atoi(argv[1]);
	if (target_pid <= 0)
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	sa.sa_handler = handle_client;
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("The pid is %d\n", target_pid);
	send_signal(argv[2], target_pid);
	while (1)
		pause();
}
