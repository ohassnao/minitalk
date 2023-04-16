/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:50:42 by ohassnao          #+#    #+#             */
/*   Updated: 2023/04/16 05:58:25 by ohassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char*str)
{
	int	bit;
	int	i;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (str[i] & (128 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(0);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					exit(0);
			usleep(800);
			bit++;
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		send_bit(ft_atoi(argv[1]), argv[2]);
		exit(0);
	}
	else
	{
		write(1, "SYNTAXE ERROR : <./client> <PID> <message_to_send>", 50);
		exit(0);
	}
}
