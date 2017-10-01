/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:57:01 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/22 21:03:04 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	while (s[len] != c)
	{
		if (s[len] == c)
			break ;
		if (len <= 0)
			return (NULL);
		len--;
	}
	return ((char*)&s[len]);
}
