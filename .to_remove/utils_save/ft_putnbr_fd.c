/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:36:49 by emagueri          #+#    #+#             */
/*   Updated: 2023/11/11 23:25:45 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long nb, int fd)
{
	if (nb < 10)
		ft_putchar_fd(nb + 48, fd);
	else
	{
		ft_putnbr(nb / 10, fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	if (fd < 0)
		return ;
	ln = (long) n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln = -ln;
	}
	ft_putnbr(ln, fd);
}
