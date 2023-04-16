/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:50:22 by ohassnao          #+#    #+#             */
/*   Updated: 2023/04/16 05:54:59 by ohassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int sigusr, siginfo_t *info, void *oldprsc)
{
	static int	sender_pid;
	static char	character;
	static int	bit;

	(void) oldprsc;
	if (sender_pid != info->si_pid)
	{
		character = (char)255;
		bit = 0;
		sender_pid = info->si_pid;
	}
	if (sigusr == SIGUSR1)
		character = character | 128 >> bit;
	else if (sigusr == SIGUSR2)
		character = character ^ 128 >> bit;
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		bit = 0;
		character = (char)255;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)**argv;
	if (argc == 1)
	{
		sa.sa_sigaction = &receive_bit;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		write(1, "PID : ", 6);
		ft_putnbr_fd(getpid());
		write(1, "\n", 1);
		while (1)
			pause();
	}	
	else
	{
		write(1, "ERROR FOUND :", 13);
		exit(0);
	}
	return (0);
}
