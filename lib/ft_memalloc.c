/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:38:53 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 08:02:58 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ret;

	ret = (void*)malloc(sizeof(void) * size);
	if (ret == NULL || size == 0)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
