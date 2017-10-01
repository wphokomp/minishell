/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:28:21 by wphokomp          #+#    #+#             */
/*   Updated: 2017/08/07 14:41:17 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char*)dst;
	s = (const char*)src;
	if (s < d && d < (s + len))
		while (s[len])
		{
			d[len] = s[len];
			len--;
		}
	else
		ft_memcpy(d, s, len);
	return (d);
}
