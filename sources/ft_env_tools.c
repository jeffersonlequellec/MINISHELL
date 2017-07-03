/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:23:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/29 11:21:06 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Will change in the env, the variable dst, will value src.
*/

char	**ft_change_env(char **env, char *dst, char *src)
{
	int		start;
	char	*memory;

	if ((start = ft_find_env(env, dst, ft_strlen(dst) - 1)) >= 0)
	{
		memory = env[start];
		env[start] = ft_threejoin(dst, "=", src);
		ft_strdel(&memory);
	}
	return (env);
}

/*
** Used to find the occurence of a given var inside env.
*/

int		ft_find_env(char **env, char *str, int len)
{
	size_t	index;

	index = 0;
	while (env[index])
	{
		if (ft_strncmp(str, env[index], len) == 0)
			return (index);
		index++;
	}
	return (-1);
}

/*
** Will populate the char* with the extern environ.
*/

char	**ft_populate_env(void)
{
	size_t			index;
	size_t			len;
	extern char		**environ;
	char			**env;

	index = 0;
	len = ft_arraylen(environ);
	CHK_CC((env = (char**)malloc(sizeof(char*) * len + 1)));
	while (index < len)
	{
		env[index] = ft_strdup(environ[index]);
		index++;
	}
	env[index] = NULL;
	return (env);
}
