/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:17:23 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 08:23:11 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t x;

	if (ft_strlen((char*)little) == 0)
		return ((char*)big);
	if (ft_strlen((char*)big) == 0)
		return (NULL);
	i = 0;
	while (i < ft_strlen(big) + 1)
	{
		x = 0;
		while (little[x] == big[x + i])
		{
			if (x == ft_strlen(little) - 1)
			{
				return ((char*)&big[i]);
			}
			x++;
		}
		i++;
	}
	return (NULL);
}
