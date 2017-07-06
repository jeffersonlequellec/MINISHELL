/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 10:21:04 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/06 11:07:42 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Same as the function below, but will print a newline
** Default function.
*/

static void		ft_print_with_newline(char **command)
{
	size_t	index;

	index = 0;
	while (command[index])
	{
		ft_putstr(command[index]);
		if (command[index + 1])
			ft_putchar(' ');
		index++;
	}
	ft_putchar('\n');
}

/*
** Will echo with the options -n, wich is withouth newline
*/

static void		ft_print_without_newline(char **command)
{
	size_t	index;

	index = 0;
	while (command[index])
	{
		ft_putstr(command[index]);
		if (command[index + 1])
			ft_putchar(' ');
		index++;
	}
}

/*
** Directionnal function, if the options -n is given goes one way.. etc
*/

int				ft_echo(char **command)
{
	if (!command[1])
		ft_putendl("");
	else if (ft_strcmp(command[1], "-n") == 0)
		ft_print_without_newline(command + 2);
	else
		ft_print_with_newline(command + 1);
	return (1);
}
