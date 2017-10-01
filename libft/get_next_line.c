/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:45:39 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/12 16:20:57 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chk_rd(char **st, char *str, char **line, int indx)
{
	char	*tmp;

	str[indx] = '\0';
	if ((tmp = ft_strchr(str, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*st, str);
		tmp = NULL;
		free(str);
		str = 0;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char	*st;
	char	*tmp;
	char	*str;
	int		indx;

	st = ft_strnew(BUFF_SIZE);
	str = ft_strnew(BUFF_SIZE);
	while ((indx = read(fd, str, BUFF_SIZE)) > 0)
	{
		if (chk_rd(&st, str, line, indx))
		{
			free(st);
			st = 0;
			return (1);
		}
			tmp = st;
			st = ft_strjoin(st, str);
			free(tmp);
	}
	return (0);
}
