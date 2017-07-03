/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 15:23:36 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/29 16:56:09 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Find where the value of the var start.
*/

static size_t	ft_find_index(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '=')
		index++;
	return (index + 1);
}

/*
** Find the occurence of OLDPWD, and where the value of the var start.
** Return it
*/

static char		*ft_oldpwd(char **env)
{
	int		start;
	size_t	index;

	if ((start = ft_find_env(env, "OLDPWD=", 7)) >= 0)
	{
		index = ft_find_index(env[start]);
		return (ft_strsub(env[start], index, ft_strlen(env[start])));
	}
	return (NULL);
}

/*
** if (cd -) find the OLDPWD then change direction.
** if (cd || cd ~) change to the user root.
** if chdir didn't worked, print the error to the user.
*/

static int		ft_change_direction(char *direction, char **env, int ret)
{
	char	*temp;

	if (direction && ft_strcmp(direction, "-") == 0)
	{
		if ((temp = ft_oldpwd(env)))
		{
			ret = chdir(temp);
			ft_strdel(&temp);
		}
	}
	else if (direction == NULL || ft_strcmp(direction, "~") == 0)
		ret = chdir("/Users/jle-quel/");
	else
	{
		if ((ret = chdir(direction) == -1))
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putendl_fd(direction, 2);
		}
	}
	return (ret);
}

/*
** Create a temporary oldpwd.
** change direction, then if chdir works change the OLDPWD
** always change the PWD
*/

int				ft_cd(char **command, char ***address, char **env)
{
	char	buf[PATH_MAX];
	char	*oldpwd;
	int		ret;

	ret = 0;
	oldpwd = getcwd(buf, PATH_MAX);
	ret = ft_change_direction(command[1], env, ret);
	if (ret == 0)
		*address = ft_change_env(env, "OLDPWD", oldpwd);
	*address = ft_change_env(env, "PWD", getcwd(buf, PATH_MAX));
	return (1);
}
