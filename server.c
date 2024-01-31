/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:49:06 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/06 14:02:28 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	static char	changer;
	static int	counter;

	(void)context;
	if (signo == SIGUSR1)
	{
		changer = changer << 1;
		changer = changer ^ 1;
	}
	else if (signo == SIGUSR2)
		changer = changer << 1;
	counter++;
	if (counter == 8)
	{
		counter = 0;
		if (changer == 0)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		write(1, &changer, 1);
		changer = 0;
	}
}

int	main(void)
{
	struct sigaction    sa;
	int					target_pid;

	target_pid = getpid();
	printf("THE PID IS ... %d\n", target_pid);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(100);
}
