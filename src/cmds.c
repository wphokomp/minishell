/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:46:48 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/18 15:52:40 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_write(char *str)
{
	int		ret;

	ret = 0;
	if (!ft_strcmp(str, ">"))
		ret = 1;
	else if (!ft_strcmp(str, ">>"))
		ret = 2;
	return (ret);
}

char	*ft_trim(char const *s, int *u)
{
	int		i;
	int		x;
	char 	*ret;

	i = -1;
	x = ft_strlen(s) - 1;
	while (s[x] == '"')
		x--;
	if (x == 0)
		return ("");
	while (s[++i] == '"');
	while (s[x] == '"');
	if (i > -1 || x == (int)ft_strlen(s) - 1)
		*u = 0;
	ret = ft_strsub(s, i, (x - i) + 1);
	return (ret);
}

void	ft_echo(t_env *e)
{
	int		i;
	int		u;
	int		fd;
	char	*str;

	i = 0;
	u = -1;
	while (e->args[++i])
		if (e->args[i][0] == '$')
		{
			str = ft_getenv(&e->args[i][1], e);
			if (str)
				ft_putendl(str);
		}
		else if (ft_write(e->args[i]) == 1)
		{
			fd = open(e->args[i + 1], O_RDWR | O_CREAT, 770);
			ft_putstr_fd(ft_trim(e->args[1], &u), fd);
		}
		else if (ft_write(e->args[i]) == 2)
		{
			fd = open (e->args[i + 1], O_RDWR | O_CREAT | O_APPEND, 770);
			ft_putstr_fd(ft_trim(e->args[1], &u), fd);
		}
	if (u == 0)
		ft_putendl(ft_trim(e->args[1], &u));
}

int		search_paths(t_env *e)
{
	t_search	e_s;

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
