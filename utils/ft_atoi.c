/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:48:01 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/16 00:31:15 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char	*str)
{
	unsigned long long	num;
	int					sign;
	int					i;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - 48;
		if (num > LONG_MAX)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
	}
	return (num * sign);
}
