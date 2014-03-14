/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_solve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 12:41:38 by nsavry            #+#    #+#             */
/*   Updated: 2014/01/26 13:20:06 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "filler.h"

int		ft_solve_filler(t_filler *fil)
{
	int		test;

	fil->ri = 0;
	test = 0;
	while (fil->ri <= (fil->mimap - fil->mipart))
	{
		fil->rj = 0;
		while (fil->rj <= (fil->mjmap - fil->mjpart))
		{
			if (ft_check_one_part(fil) == 1)
				return (1);
			(fil->rj)++;
		}
		(fil->ri)++;
	}
	return (0);
}

int		ft_check_one_part(t_filler *fil)
{
	int		found;

	found = 0;
	fil->i = 0;
	while (fil->part[fil->i] != NULL)
	{
		fil->j = 0;
		while (fil->part[fil->i][fil->j] != 0)
		{
			if ((PART == '*') && (MAP == PLAYER || MAP == PLAYER + 32))
				found++;
			if ((PART == '*') && (MAP == ENEMY || MAP == ENEMY + 32))
				found = 2;
			(fil->j)++;
		}
		(fil->i)++;
	}
	return (found);
}
