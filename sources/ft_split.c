/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:41:10 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/06 13:42:14 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Will return the length that we have to malloc for the string.
*/

static int		count_length(int index, char const *s)
{
	int		len;

	len = index;
	while (s[len] != ' ' && s[len] != '\t' && s[len])
		len++;
	return (len - index);
}

/*
** Will populate the array only its not a tabs or space then do it again,
** until s[index].
*/

static char		**do_split(int index, char const *s, char **str)
{
	int		len;
	int		index1;
	int		index2;

	index1 = 0;
	index2 = 0;
	while (s[index])
	{
		if (s[index] == ' ' || s[index] == '\t')
			index++;
		else
		{
			len = count_length(index, s);
			str[index1] = (char*)malloc(sizeof(char) * (len + 1));
			while (len-- > 0)
				str[index1][index2++] = s[index++];
			str[index1++][index2] = '\0';
			index2 = 0;
			len = 0;
		}
	}
	str[index1] = NULL;
	return (str);
}

/*
** Will return the number of words separated by tabs and space.
*/

static int		ft_nwords(char const *s)
{
	int		index;
	int		nbwords;

	index = 0;
	nbwords = 0;
	while (s[index])
	{
		while (s[index] == ' ' || s[index] == '\t')
			index++;
		while (s[index] != ' ' && s[index] != '\t' && s[index])
			index++;
		nbwords++;
	}
	return (nbwords);
}

/*
** Make sure that s is= not NULL, then malloc an array.
** Split it aand return it.
*/

char			**ft_split(char *s)
{
	int			index;
	int			nbwords;
	char		**str;

	if (!s)
		return (NULL);
	index = 0;
	nbwords = ft_nwords(s);
	CHK_CC((str = (char**)malloc(sizeof(char*) * (nbwords + 1))));
	str = do_split(index, s, str);
	return (str);
}
