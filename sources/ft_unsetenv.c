/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 08:56:32 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/29 11:20:24 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Will copy the full env, without the var that you want to delete.
** the variable is given as the occurence inside env.
*/

static char		**ft_deletevar(char **env, int start)
{
	size_t	index1;
	size_t	index2;
	size_t	len;
	char	**array;

	index1 = 0;
	index2 = 0;
	len = ft_arraylen(env);
	CHK_CC((array = (char**)malloc(sizeof(char*) * len)));
	while (index1 < len - 1)
	{
		if (index1 == (size_t)start)
			break ;
		array[index1++] = ft_strdup(env[index2++]);
	}
	index2++;
	while (index1 < len - 1)
		array[index1++] = ft_strdup(env[index2++]);
	array[index1] = NULL;
	return (array);
}

/*
** while you want to delete var it will send everything to the ERASOR.
*/

int				ft_unsetenv(char **command, char ***address, char **env)
{
	size_t	index;
	int		start;
	char	**memory;

	index = 1;
	if (command[1])
	{
		while (command[index])
		{
			if ((start = ft_find_env(env, command[index],
				ft_strlen(command[index]) - 1)) >= 0)
			{
				memory = *address;
				*address = ft_deletevar(env, start);
				ft_arraydel(&memory, ft_arraylen(memory));
				env = *address;
			}
			index++;
		}
	}
	else
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	return (1);
}
