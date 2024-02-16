/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:48:02 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/16 15:50:51 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	send_byte(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) % 2)
			my_kill(pid, SIGUSR1);
		else
			my_kill(pid, SIGUSR2);
		usleep(100);
		usleep(100);
	}
	return (0);
}

int	is_funct(const char *s, int (*f)(int c))
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (f(s[i]) == 0)
			print_error_exit("invalid PID");
		i++;
	}
	return (1);
}

void	siguser(int sig)
{
	(void)sig;
	ft_putendl_fd("message send with success", 1);
}

int	main(int argc, char const *argv[])
{
	const char	*s;
	int			pid;
	int			i;

	s = argv[2];
	i = 0;
	if (argc != 3)
		print_error_exit("more or less args that we want");
	is_funct(argv[1], ft_isdigit);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > INT_MAX)
		print_error_exit("invalid PID");
	while (s[i])
		send_byte(pid, s[i++]);
	return (0);
}
