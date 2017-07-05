/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 11:01:10 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/05 17:25:02 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Make sure that you can have "*=*=*"
*/

static int		ft_check(char **command)
{
	size_t	index;
	size_t	i;

	index = 0;
	while (command[index])
	{
		i = 0;
		while (command[index][i])
		{
			if (command[index][i] == '=')
				return (0);
			i++;
		}
		index++;
	}
	return (1);
}

/*
** As explicit as it is, just print the error for the user.
*/

static int		ft_parsing_setenv(char **command)
{
	if (!command[1] || !command[2])
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	else if (command[3])
		ft_putendl_fd("setenv: Too many arguments.", 2);
	else if (ft_isalpha(command[0][0]) == 0)
		ft_putendl_fd("setenv: Variable name must begin with a letter.", 2);
	else if (ft_check(command) == 0)
		ft_putendl_fd("setenv: usage: Variable Value", 2);
	else
		return (1);
	return (0);
}

/*
** Will malloc a var, copy the current env, then add one at the end.
*/

static char		**ft_addvar(char **old, char **new)
{
	size_t	index1;
	size_t	index2;
	size_t	len;
	char	**array;

	index1 = 0;
	index2 = 0;
	len = ft_arraylen(old) + ft_arraylen(new);
	CHK_CC((array = (char**)malloc(sizeof(char*) * len + 1)));
	while (old[index1])
	{
		array[index1] = ft_strdup(old[index1]);
		index1++;
	}
	array[index1] = ft_threejoin(new[index2], "=", new[index2 + 1] ?
	new[index2 + 1] : "");
	array[index1 + 1] = NULL;
	return (array);
}

/*
** Directionnal function, if the command from the user is valid, either Change
** or create var.
*/

int				ft_setenv(char **command, char ***address, char **env)
{
	int		start;
	char	**memory;

	memory = *address;
	if (ft_parsing_setenv(command) == 1)
	{
		if ((start = ft_find_env(env, command[1],
			ft_strlen(command[1]) - 1)) >= 0)
			*address = ft_change_env(env, command[1], command[2]);
		else
		{
			*address = ft_addvar(env, command + 1);
			ft_arraydel(&memory, ft_arraylen(memory));
		}
	}
	return (1);
}
