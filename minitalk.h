/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 04:25:14 by ohassnao          #+#    #+#             */
/*   Updated: 2023/04/16 05:30:43 by ohassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h> 
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_nondigit(const char *str);
void	ft_putnbr_fd(int n);
void	ft_putchar_fd(char c);
void	receive_bit(int sigusr, siginfo_t *info, void *oldprsc);
void	send_bit(int pid, char*str);

#endif   