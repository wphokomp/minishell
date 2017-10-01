/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:41:43 by wphokomp          #+#    #+#             */
/*   Updated: 2017/09/28 18:50:56 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_env *e)
{
	if (!e->args[1])
		e->args = tab_add(e->args, ft_getenv("HOME", e));
	if ((ft_strlen_point(e->args) > 1) && (!ft_strcmp(e->args[1], "~/")
				|| !ft_strcmp(e->args[1], "~")))
	{
		free(e->args[1]);
		e->args[1] = 0;
		e->args[1] = ft_strdup(ft_getenv("HOME", e));
	}
	if (ft_strstr(e->args[1], "~") != NULL)
		e->args[1] = ft_strreplace(e->args[1], ft_getenv("HOME", e));
	if (!ft_strcmp(e->args[1], "-") && ft_strlen_point(e->args) > 1)
	{
		free(e->args[1]);
		e->args[1] = 0;
		e->args[1] = ft_strdup(ft_getenv("OLDPWD", e));
		ft_putendl(e->args[1]);
	}
	if (!chdir(e->args[1]))
		ft_changepwd(e);
	else
		ft_putendl("cd: directory not found");
}
