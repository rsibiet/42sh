/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 20:07:56 by rorousse          #+#    #+#             */
/*   Updated: 2016/07/25 17:40:56 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <globbing.h>

static int		get_size_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

static int		search_indice(char **tab)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (tab[i] != NULL)
	{
		if (tab[i][0] && (ft_strcmp(tab[i], tab[min]) < 0 || !(tab[min][0])))
			min = i;
		i++;
	}
	return (min);
}

char			**ft_tri_insert(char **tab)
{
	char	**tab_triay;
	int		taille;
	int		i;
	int		min;

	i = 0;
	taille = get_size_tab(tab);
	tab_triay = (char**)malloc((taille + 1) * sizeof(char*));
	while (i < taille)
	{
		min = search_indice(tab);
		tab_triay[i] = ft_strdup(tab[min]);
		tab[min][0] = '\0';
		i++;
	}
	tab_triay[i] = NULL;
	free_double_char(tab);
	return (tab_triay);
}
