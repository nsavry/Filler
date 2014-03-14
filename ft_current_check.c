/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 12:59:13 by nsavry            #+#    #+#             */
/*   Updated: 2014/01/26 13:10:39 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "filler.h"

int		ft_check_map(char **map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (map[i][j] != '.' && map[i][j] != 'X' && map[i][j] != 'x'
				&& map[i][j] != 'O' && map[i][j] != 'o')
				return (-1);
			j++;
		}
		if (j != y)
			return (-1);
		i++;
	}
	if (i != x)
		return (-1);
	return (1);
}

int		ft_check_part(char **part, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (part[i] != NULL)
	{
		j = 0;
		while (part[i][j] != 0)
		{
			if (part[i][j] != '.' && part[i][j] != '*')
				return (-1);
			j++;
		}
		if (j != y)
			return (-1);
		i++;
	}
	if (i != x)
		return (-1);
	return (1);
}
