/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:42:59 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/28 18:53:24 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char *repl)
{
	char	*temp;

	temp = ft_strdup(str);
	free(str);
	str = ft_strdup(ft_strjoin(repl, temp + 1));
	free(temp);
	temp = 0;
	return (str);
}
