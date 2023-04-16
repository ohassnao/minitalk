/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 04:24:40 by ohassnao          #+#    #+#             */
/*   Updated: 2023/04/16 03:12:49 by ohassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	ft_nondigit(&str[i]);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i + 1] && (str[i + 1] < '0' || str[i + 1] > '9'))
		{
			write(1, "INVALID PID !", 13);
			exit(0);
		}
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}

void	ft_nondigit(const char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		write(1, "INVALID PID !", 13);
		exit(0);
	}
	return ;
}

void	ft_putnbr_fd(int n)
{
	long	nb;

	nb = n;
	if (nb <= 9 && nb >= 0)
		ft_putchar_fd(nb + 48);
	else if (nb < 0)
	{
		ft_putchar_fd('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
}

void	ft_putchar_fd(char c)
{
	write (1, &c, 1);
}
