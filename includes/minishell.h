/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:06:01 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/28 19:13:41 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <signal.h>
# include <fcntl.h>

# define PATH_MAX 4096

/*
** BUILTINS
*/
int		ft_cd(char **command, char ***address, char **env);
int		ft_echo(char **command);
int		ft_setenv(char **command, char ***address, char **env);
int		ft_unsetenv(char **command, char ***address, char **env);

/*
** FT_ENV_TOOLS.C
*/
char	**ft_populate_env(void);
int		ft_find_env(char **env, char *str, int len);
char	**ft_change_env(char **env, char *dst, char *src);

/*
** FT_DISPLAY_TOOLS.C
*/
void	ft_minishell(void);

/*
** FT_TOOLS.C
*/
char	**ft_return_paths(size_t start, char **env);
char	**ft_test_access(char **command, char **paths, int argc);
int		ft_builtins(char **command, char ***address, char **env);

/*
** FT_SPLIT.C
*/
char	**ft_split(char *s);

#endif
