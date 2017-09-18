/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 07:39:50 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 08:18:53 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	ret = (char *)malloc(sizeof(ret) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ft_bzero((void*)ret, len);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}
