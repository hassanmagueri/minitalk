/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:48:05 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/16 15:52:49 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	siguser(int n, siginfo_t *sig_info, void *unused)
{
	static unsigned char	byte;
	static int				bits_index;
	static int				current_pid;

	if (current_pid == 0)
		current_pid = sig_info->si_pid;
	else if (current_pid != sig_info->si_pid)
	{
		byte = 0;
		bits_index = 0;
		current_pid = sig_info->si_pid;
	}
	byte = byte * 2 + (SIGUSR1 == n);
	bits_index++;
	if (bits_index == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		bits_index = 0;
	}
	(void)unused;
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		return (1);
	ft_putstr_fd("pid ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = siguser;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
