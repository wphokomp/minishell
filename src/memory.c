/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:04:37 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/18 14:03:03 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_exec(char *path, t_env *e)
{
	int		status;

	g_pid = fork();
	if (!g_pid)
	{
		if (execve(path, e->args, e->env) == -1)
		{
			ft_putendl("Command not found");
			exit(1);
		}
	}
	else
	{
		waitpid(g_pid, &status, WUNTRACED);
		g_pid = 0;
	}
	ft_strdel(&path);
}

char	**tab_add(char **env, char *str)
{
	char	**tmp;
	int		y;
	int		len;

	y = -1;
	len = ft_strlen_point(env);
	tmp = ft_strnew_point(len + 1);
	tmp[len + 1] = 0;
	while (++y < len)
		tmp[y] = ft_strdup(env[y]);
	tmp[len] = ft_strdup(str);
	free_tab(env);
	return (tmp);
}

void	free_tab(char **tab)
{
	int		y;

	y = -1;
	while (tab[++y])
		ft_strdel(&tab[y]);
	ft_strdel(tab);
}

char	*ft_replace_env(int *chk, char *str, char *tab)
{
	char	*tmp;

	*chk = 1;
	ft_strdel(&tab);
	//free(tab);
	//tab = NULL;
	tmp = ft_strdup(str);
	return (tmp);
}

void	ft_del_env(int *chk, char **env, int indx)
{
	*chk = 1;
	while (env[indx])
	{
		ft_strdel(&env[indx]);
		if (env[indx + 1])
			env[indx] = ft_strdup(env[indx + 1]);
		indx++;
	}
}
