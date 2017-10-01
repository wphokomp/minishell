/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 10:54:49 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/23 17:06:37 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_point(char **str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}
