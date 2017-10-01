/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:30:38 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/28 22:06:07 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t	g_pid = -1;

void	sig(int signum)
{
	(void)signum;
	if (g_pid > 0)
	{
		ft_putchar('\n');
		kill(g_pid, SIGKILL);
	}
	else
		ft_putendl("\nPlease use the 'exit' command to quit");
}

int		search_cmds(t_env *e)
{
	if (!e->args[0] || !ft_strcmp(e->args[0], ft_itoa(9)))
		return (0);
	if (!ft_strcmp(e->args[0], "cd"))
		ft_cd(e);
	else if (!ft_strcmp(e->args[0], "echo"))
		ft_echo(e);
	else if (!ft_strcmp(e->args[0], "setenv"))
		ft_setenv(e);
	else if (!ft_strcmp(e->args[0], "unsetenv"))
	{
		if (!ft_unsetenv(e))
			ft_putendl("Variable not found");
	}
	else if (!ft_strcmp(e->args[0], "env"))
		ft_env(e);
	else
		return (search_paths(e));
	return (0);
}

void	process_ln(t_env *e)
{
	int		i;
	int		k;

	i = 0;
	k = -1;
	e->cmds = ft_strsplit(e->ln, ';');
	while (e->cmds[i])
	{
		e->args = ft_strsplit(ft_strtrim(e->cmds[i]), ' ');
		while (e->args[++k])
			e->args[k] = ft_strtrim(e->args[k]);
		if (search_cmds(e) > 0)
			run_cmd(e);
		i++;
		if (e->args)
			free_tab(e->args);
	}
	free_tab(e->cmds);
}

void	begin_shell(t_env *e)
{
	ft_putstr("$> ");
	get_next_line(0, &e->ln);
	if (ft_strcmp(e->ln, "exit") != 0)
	{
		if (ft_strcmp(e->ln, "") != 0)
		{
			process_ln(e);
			ft_strdel(&e->ln);
		}
		begin_shell(e);
	}
	else
	{
		ft_strdel(&e->ln);
		free_tab(e->env);
	}
}

int		main(void)
{
	t_env	e;

	signal(SIGINT, sig);
	get_env(&e);
	begin_shell(&e);
	return (0);
}
