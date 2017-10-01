/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:26:47 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 08:23:51 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	int		x;
	char	*ret;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (i == ft_strlen(s))
		return ("");
	x = ft_strlen(s) - 1;
	while (s[x] == ' ' || s[x] == '\t' || s[x] == '\n')
		x--;
	ret = ft_strsub(s, i, (x - i) + 1);
	return (ret);
}
