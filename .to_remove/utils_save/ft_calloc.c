/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:08:05 by emagueri          #+#    #+#             */
/*   Updated: 2023/11/12 15:52:30 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	int		i;

	i = 0;
	if ((long)count < 0 || (long) size < 0)
		return (NULL);
	res = malloc(count * size);
	if (!res)
		return (0);
	ft_bzero(res, count * size);
	return (res);
}
