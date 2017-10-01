/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:46:48 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/28 20:02:11 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_trim(char const *s)
{
	int		i;
	int		x;
	char	*ret;

	i = -1;
	x = ft_strlen(s) - 1;
	while (s[x] == '"')
		x--;
	if (x == 0)
		return ("");
	while (s[++i] == '"')
		;
	ret = ft_strsub(s, i, (x - i) + 1);
	return (ret);
}

void	ft_echo(t_env *e)
{
	int		i;
	char	*str;

	i = 0;
	while (e->args[++i])
	{
		str = ft_strjoin(e->args[i], ft_strjoin(" ", e->args[i + 1]));
		free(e->args[i + 1]);
		e->args[i + 1] = NULL;
		if (e->args[i][0] == '$')
		{
			str = ft_getenv(&e->args[i][1], e);
			if (str)
				ft_putendl(str);
		}
		else
			ft_putendl(ft_trim(str));
	}
}

int		search_paths(t_env *e)
{
	t_search	e_s;

	if (!ft_getenv("PATH", e))
		return (8);
	e_s.path = ft_strsplit(ft_getenv("PATH", e), ':');
	e_s.i = 0;
	while (e_s.i > -1 && e_s.path[e_s.i])
	{
		e_s.dir = opendir(e_s.path[e_s.i]);
		while ((e_s.sd = readdir(e_s.dir)))
			if (!ft_strcmp(e_s.sd->d_name, e->args[0]))
			{
				e_s.str = ft_strjoin(e_s.path[e_s.i], "/");
				run_exec(ft_strjoin(e_s.str, e_s.sd->d_name), e);
				ft_strdel(&e_s.str);
				e_s.i = -2;
			}
		closedir(e_s.dir);
		e_s.i++;
	}
	free_tab(e_s.path);
	return (e_s.i);
}

void	run_cmd(t_env *e)
{
	char	**tab;
	char	*path;
	int		len;

	tab = ft_strsplit(e->args[0], '/');
	len = 0;
	path = ft_strdup(e->args[0]);
	while (tab[len])
		len++;
	ft_strdel(&e->args[0]);
	e->args[0] = ft_strdup(tab[len - 1]);
	run_exec(path, e);
	free_tab(tab);
}

void	ft_changepwd(t_env *e)
{
	int		y;
	int		chk;
	char	buff[1000];

	y = -1;
	chk = 0;
	while (e->env[++y])
		if (!ft_strncmp(e->env[y], "OLDPWD", 6))
			e->env[y] = ft_replace_env(&chk,
					ft_strjoin("OLDPWD=", ft_getenv("PWD", e)), e->env[y]);
	y = -1;
	chk = 0;
	while (e->env[++y])
		if (!ft_strncmp(e->env[y], ft_strjoin("PWD=", getwd(buff))
					, ft_indexof(ft_strjoin("PWD=", getwd(buff)), '=')))
			e->env[y] = ft_replace_env(&chk, ft_strjoin("PWD=", getwd(buff))
					, e->env[y]);
}
