/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:54:57 by nsavry            #+#    #+#             */
/*   Updated: 2014/01/26 13:41:27 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		main(void)
{
	t_filler	fil;
	int			i;

	i = 0;
	fil.test[0] = 0;
	fil.test[1] = 0;
	fil.test[2] = 0;
	while (ft_read_std(&fil) == 1)
	{
		if (ft_solve_filler(&fil) == 1)
		{
			ft_putstr(ft_itoa(fil.ri));
			ft_putchar(' ');
			ft_putstr(ft_itoa(fil.rj));
			ft_putchar('\n');
		}
		else
		{
			ft_putendl("0 0");
			return (0);
		}
	}
	ft_putendl("0 0");
	return (0);
}
