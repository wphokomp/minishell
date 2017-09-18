/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:20:25 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 08:05:37 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*ret;
	char	*sc;

	ret = (char*)dst;
	i = 0;
	sc = (char*)src;
	while (i < (int)n)
	{
		ret[i] = sc[i];
		i++;
	}
	return ((void*)ret);
}
