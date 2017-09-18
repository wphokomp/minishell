/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:30:38 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/18 15:28:28 by wphokomp         ###   ########.fr       */
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
	if (!ft_strcmp(e->args[0], "cd"))
	{
		if (!e->args[1] || chdir(e->args[1]) != 0)
			ft_putendl("cd: directory not found");
	}
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
	else if (!ft_strcmp(e->args[0], "ls") || !ft_strcmp(e->args[0], "clear"))
		return (search_paths(e));
	else
		ft_putendl("Command not found");
	return (0);
}

void	process_ln(t_env *e)
{
	int		i;

	i = 0;
	e->cmds = ft_strsplit(e->ln, ';');
	while (e->cmds[i])
	{
		e->args = ft_strsplit(e->cmds[i], ' ');
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

int		main()
{
	t_env	e;

	signal(SIGINT, sig);
	get_env(&e);
	begin_shell(&e);
	return (0);
}
