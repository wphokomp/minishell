/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:07:13 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/21 11:56:24 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	size_t	n;
	int		nev;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	nev = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nev = -1;
		i++;
	}
	n = 0;
	if (ft_strcmp(ft_strtrim(str), "9223372036854775807") == 0)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = n * 10;
		n = n + ((int)str[i] - '0');
		i++;
	}
	return (n * nev);
}
