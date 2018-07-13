/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:08:15 by mdugot            #+#    #+#             */
/*   Updated: 2016/07/26 14:04:40 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include <sys/stat.h>
#include <stdlib.h>

int		quit(t_shell *shell, int n)
{
	clean_exit(shell->edit->term, n, shell);
	return (n);
}

int		commun_char(char *s1, char *s2)
{
	while (*s1)
	{
		if (ft_strchr(s2, *s1))
			return (1);
		s1++;
	}
	return (0);
}

int		has_syntax_in(char *str)
{
	while (*str)
	{
		if (ft_strchr(SYNTAX, *str))
			return (1);
		str++;
	}
	return (0);
}

void	send_key(int key)
{
	char	value[2];

	value[0] = key;
	value[1] = '\0';
	ioctl(0, TIOCSTI, value);
}

void	del_strsplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_strdel(&split[i]);
		i++;
	}
	ft_memdel((void**)&split);
}
