/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:25:09 by rorousse          #+#    #+#             */
/*   Updated: 2016/07/25 17:50:39 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globbing.h"

static char	**init_ret(char ***temp)
{
	char	**ret;

	ret = (char**)malloc(2 * sizeof(char*));
	ret[0] = ft_strdup("");
	ret[1] = NULL;
	*temp = NULL;
	return (ret);
}

char		**ft_glob(char *str)
{
	char	**ret;
	char	**split;
	char	**temp;
	int		i;

	split = split_accolades(str);
	i = 0;
	ret = init_ret(&temp);
	while (split[i] != NULL)
	{
		if (detect_double(split[i]) > 0)
		{
			if (ft_strcmp(split[i], "**/") == 0)
				temp = glob_recursion("**/*/");
			else
				temp = glob_recursion(split[i]);
		}
		else
			temp = launch(split[i]);
		ret = add_double_char(ret, temp);
		i++;
	}
	free_double_char(split);
	ret = ft_tri_insert(ret);
	return (ret);
}
