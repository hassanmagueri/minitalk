/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:15 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/16 15:59:35 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	print_error_exit(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

void	my_kill(int pid, int sig)
{
	if (kill(pid, sig))
		print_error_exit("PID does not exit");
}
