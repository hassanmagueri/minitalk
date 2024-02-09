/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:16:45 by emagueri          #+#    #+#             */
/*   Updated: 2023/11/12 15:45:18 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	lens1;
	int	i;
	int	start;

	if (!s1)
		return (NULL);
	start = 0;
	lens1 = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_strchr(set, s1[i]))
	{
		i--;
		lens1--;
	}
	return (ft_substr(s1, start, lens1 - start));
}
