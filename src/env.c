/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:01:56 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/18 14:02:40 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_env(t_env *e)
{
	extern char		**environ;
	int				y;

	y = 0;
	while (environ[y])
		y++;
	e->env = ft_strnew_point(y);
	y = -1;
	while (environ[++y])
		e->env[y] = ft_strdup(environ[y]);
	e->env[y] = 0;
}

int		ft_unsetenv(t_env *e)
{
	int		chk;
	int		i;
	int		y;

	i = 0;
	chk = 0;
	while (e->args[i])
	{
		y = 0;
		while (e->env[y])
		{
			if (!ft_strncmp(e->env[y], e->args[i], ft_indexof(e->env[y], '=')))
				ft_del_env(&chk, e->env, y);
			y++;
		}
		i++;
	}
	return (chk);
}

void	ft_env(t_env *e)
{
	int		y;

	y = -1;
	while (e->env[++y])
		ft_putendl(e->env[y]);
}

void	ft_setenv(t_env *e)
{
	int		i;
	int		y;
	int		chk;

	i = 0;
	y = -1;
	while (e->args[++i])
	{
		chk = 0;
		if (ft_strchr(e->args[i], '='))
		{
			while (e->env[++y])
				if (!ft_strncmp(e->env[y], e->args[i]
							, ft_indexof(e->args[i], '=')))
					e->env[y] = ft_replace_env(&chk, e->args[i], e->env[y]);
			if (!chk)
				e->env = tab_add(e->env, e->args[i]);
		}
	}
}

char	*ft_getenv(char *str, t_env *e)
{
	int		y;

	y = -1;
	while (e->env[++y])
		if (ft_strstr(e->env[y], str))
			return (&e->env[y][ft_strlen(str) + 1]);
	return (0);
}
