/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:14:20 by emagueri          #+#    #+#             */
/*   Updated: 2023/11/11 23:59:04 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	si;
	unsigned int	lendst;

	si = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	lendst = ft_strlen(dst);
	while ((si + lendst) < (dstsize - 1) && src[si])
	{
		dst[lendst + si] = src[si];
		si++;
	}
	dst[lendst + si] = '\0';
	if (dstsize > lendst)
		return (lendst + ft_strlen(src));
	return (dstsize + ft_strlen(src));
}
