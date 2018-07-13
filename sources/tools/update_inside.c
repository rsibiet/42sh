/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_inside.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 14:48:34 by mressier          #+#    #+#             */
/*   Updated: 2016/07/25 19:28:00 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int			update_inside(char *begin, char *str, int *i, char *syntax)
{
	static int	pile = 0;

	if (*i == 0)
		pile = 0;
	if ((ft_strchr("{[", *begin)
		|| (*begin == '(' && !is_escaped(str, &str[*i])))
		&& str[*i] == *begin)
	{
		pile++;
		return (1);
	}
	else if (!*begin && is_limit_begin(str, &str[*i], syntax))
	{
		pile++;
		*begin = str[*i];
		return (1);
	}
	else if (*begin && is_limit_end(str, &str[*i], *begin))
	{
		pile--;
		if (pile == 0)
			*begin = 0;
		return (-1);
	}
	return (0);
}
