/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:43:19 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 08:19:22 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dl;
	size_t sl;

	sl = ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	dl = i;
	if (size - i == 0)
		return (sl + i);
	while (src[i - dl] && size - 1 > i)
	{
		dst[i] = src[i - dl];
		i++;
	}
	if (dl < size)
		dst[i] = '\0';
	return (sl + dl);
}
