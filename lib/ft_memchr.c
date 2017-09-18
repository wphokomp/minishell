/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 12:39:49 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/31 15:33:13 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*ret;

	ret = (char*)s;
	i = 0;
	while ((int)n != 0)
	{
		if (ret[i] == c)
			return ((void*)&ret[i]);
		n--;
		i++;
	}
	return (NULL);
}
