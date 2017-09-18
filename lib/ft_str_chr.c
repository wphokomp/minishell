/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 10:23:51 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/04 10:35:02 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_chr(char *s, int c)
{
	int		i;
	int		k;
	char	*ret;

	if (!s)
		return (0);
	i = ft_strlen(s);
	while (s[--i] != c)
		;
	if (i == 0)
		return (0);
	ret = (char *)malloc(sizeof(char) * i);
	ft_bzero(ret, i);
	k = -1;
	while (++k < i)
		ret[k] = s[k];
	return (ret);
}
