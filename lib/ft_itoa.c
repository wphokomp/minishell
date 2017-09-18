/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:29:41 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 16:14:50 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_getlen(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n /= 10)
		i++;
	return (i);
}

static	char	*ft_checkzero(void)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = '0';
	return (str);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	size_t			str_len;

	str_len = ft_getlen(n);
	i = n;
	if (n == 0)
		return (ft_checkzero());
	if (n < 0)
	{
		i *= -1;
		str_len++;
	}
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	while (i)
	{
		str_len--;
		str[str_len] = i % 10 + '0';
		i /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
