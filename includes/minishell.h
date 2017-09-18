/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:47:25 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/18 14:17:36 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>

typedef struct	s_env		t_env;
typedef struct	s_search	t_search;

extern pid_t	g_pid;

struct	s_search
{
	int				i;
	char			**path;
	char			*str;
	DIR				*dir;
	struct dirent	*sd;
};

struct	s_env
{
	char	**env;
	char	*ln;
	char	**args;
	char	**cmds;
};

char	*ft_getenv(char *str, t_env *e);
char	**tab_add(char **env, char *str);
char	*ft_replace_env(int *chk, char *str, char *tab);
void	ft_del_env(int *chk, char **env, int indx);
void	ft_env(t_env *e);
void	free_tab(char **tab);
void	ft_echo(t_env *e);
void	run_cmd(t_env *e);
void	get_env(t_env *e);
void	ft_setenv(t_env *e);
void	run_exec(char *path, t_env *e);
int 	ft_unsetenv(t_env *e);
int		search_paths(t_env *e);

#endif
