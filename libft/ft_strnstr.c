/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:01:57 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 08:22:10 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t x;

	if (ft_strlen((char*)little) == 0)
		return ((char*)big);
	if (ft_strlen((char*)big) == 0)
		return (NULL);
	i = 0;
	while ((big[i] && len > i) || len < i)
	{
		x = 0;
		while (big[i] == little[x] && big[i] && little[x] && len > i)
		{
			x++;
			i++;
			if (x == ft_strlen((char*)little))
				return ((char*)&big[i - ft_strlen((char*)little)]);
		}
		if (x == 0)
		{
			i++;
		}
	}
	return (NULL);
}
