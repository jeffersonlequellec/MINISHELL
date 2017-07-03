/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:04:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/29 16:52:59 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Fork the father, Execute the command, Then give back hand on the father
** If exec could not works, tell the user that the command doesnt exist.
*/

static void		ft_execute_command(char **command, char **env)
{
	pid_t	father;

	father = fork();
	if (father == 0)
	{
		if (execve(command[0], command, env) == -1)
		{
			ft_putstr_fd(command[0], 2);
			ft_putendl_fd(": command not found", 2);
			ft_putstr("\x1b[31m❯\x1b[0m ");
			exit(-1);
		}
	}
	else
		wait(&father);
}

/*
** If the path is unset, will test if the command is given with the full path,
** so it can be executable.
*/

static int		ft_test(char **command)
{
	if (access(command[0], X_OK) == 0)
		return (1);
	return (-1);
}

/*
** If Variable PATH is found: Create the path using all of the paths inside PATH
** Test if it's executable then execute and free.
** Else, tell the user that the command has not be found
*/

void			ft_launch(char **command, char **env)
{
	int		start;
	char	**paths;

	if ((start = ft_find_env(env, "PATH=", 5)) >= 0)
	{
		paths = ft_return_paths(start, env);
		command = ft_test_access(command, paths, 0);
		ft_execute_command(command, env);
		ft_arraydel(&paths, ft_arraylen(paths));
	}
	else if (ft_test(command) == 1)
		ft_execute_command(command, env);
	else
	{
		ft_putstr_fd(*command, 2);
		ft_putendl_fd(": path not found", 2);
	}
}

/*
** ENV is being populated.
** Display prompt, Wait for user to write something, Get rid of tabs and space.
** Send the command from user to BUILTINS, if the command is not a BUILTINS,
** send everything to LAUNCH, Then free everything.
*/

int				main(void)
{
	char	*line;
	char	**command;
	char	**env;

	env = ft_populate_env();
	while (42)
	{
		ft_minishell();
		get_next_line(0, &line);
		command = ft_split(line);
		if (ft_arraylen(command) != 0)
		{
			ft_builtins(command, &env, env) == 0 ? ft_launch(command, env) : 0;
			ft_arraydel(&command, ft_arraylen(command));
			ft_strdel(&line);
		}
	}
	ft_arraydel(&env, ft_arraylen(env));
	return (0);
}
