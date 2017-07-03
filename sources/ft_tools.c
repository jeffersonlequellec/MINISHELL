/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:05:56 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/29 11:20:38 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Directionnal function, that will test if the command from user is bultins,
** if yes send it to the right function.
*/

int				ft_builtins(char **command, char ***address, char **env)
{
	if (ft_strcmp(command[0], "exit") == 0)
		exit(0);
	else if (ft_strcmp(command[0], "cd") == 0 || ft_strcmp(command[0],
			"/usr/bin/cd") == 0)
		return (ft_cd(command, &env, env));
	else if (ft_strcmp(command[0], "setenv") == 0)
		return (ft_setenv(command, address, env));
	else if (ft_strcmp(command[0], "unsetenv") == 0)
		return (ft_unsetenv(command, address, env));
	else if (ft_strcmp(command[0], "echo") == 0 || ft_strcmp(command[0],
			"/bin/echo") == 0)
		return (ft_echo(command));
	else if (ft_strcmp(command[0], "env") == 0 || ft_strcmp(command[0],
			"/usr/bin/env") == 0)
	{
		ft_printarray(env);
		return (1);
	}
	return (0);
}

/*
** Will try all of the path is the variable PATH until it find one that command
** be executed.
*/

static char		**ft_create_command(char **paths, char **command)
{
	size_t	index;
	char	*path;

	index = 0;
	while (paths[index])
	{
		path = ft_threejoin(paths[index], "/", command[0]);
		if (access(path, X_OK) == 0)
		{
			ft_strdel(&command[0]);
			command[0] = ft_strdup(path);
			path ? ft_strdel(&path) : 0;
			return (command);
		}
		path ? ft_strdel(&path) : 0;
		index++;
	}
	return (command);
}

/*
** If the command is already with the full path (/bin/ls) just say yes you
** can executed.
** Else create the path
*/

char			**ft_test_access(char **command, char **paths, int argc)
{
	if (access(command[argc], X_OK) == 0)
		return (command);
	else
		return (ft_create_command(paths, command));
}

/*
** Split all the path given inside the PATH variable, to test it.
*/

char			**ft_return_paths(size_t start, char **env)
{
	char	*str;
	char	**paths;

	str = ft_strsub(env[start], 5, ft_strlen(env[start]));
	paths = ft_strsplit(str, ':');
	ft_strdel(&str);
	return (paths);
}
