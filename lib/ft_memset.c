/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:40:54 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 08:06:47 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*ret;

	if ((int)len < 0)
		return (NULL);
	ret = (char*)b;
	i = 0;
	while ((int)len > 0)
	{
		ret[i] = c;
		i++;
		len--;
	}
	return (ret);
}
