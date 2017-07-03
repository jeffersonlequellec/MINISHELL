/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:16:53 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/29 11:21:19 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Will display in color the directory we are.
*/

static void		ft_display(char *buf, size_t len)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strsub(buf, len, ft_strlen(buf));
	ret = ft_memalloc(16 + ft_strlen(tmp) + 18);
	ft_strcpy(ret, "\x1b[35m");
	ft_strcat(ret, tmp);
	ft_strcat(ret, "\x1b[0m ");
	ft_strcat(ret, "\x1b[32m");
	ft_strcat(ret, "❯");
	ft_strcat(ret, "\x1b[0m ");
	ft_putstr(ret);
	ft_strdel(&tmp);
	ft_strdel(&ret);
}

/*
** Search where the user is (PWD) then send it to print.
** If getcwd couldn't find, will print just minishell.
*/

void			ft_minishell(void)
{
	size_t	len;
	char	buf[PATH_MAX];

	len = 0;
	if (getcwd(buf, PATH_MAX))
	{
		if (ft_strcmp(buf, "/") != 0)
		{
			len = ft_strlen(buf) - 1;
			while (buf[len] != '/' && buf[len])
				len--;
			len++;
		}
		ft_display(buf, len);
	}
	else
		ft_putstr("\x1b[35mMINISHELL\x1b[0m \x1b[32m❯\x1b[0m ");
}
