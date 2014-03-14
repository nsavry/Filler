/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 12:46:13 by nsavry            #+#    #+#             */
/*   Updated: 2014/01/26 13:19:28 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "filler.h"
#include "libft.h"

int		ft_read_std(t_filler *fil)
{
	char	*line;
	char	error;

	while (ft_strstr_bool(line, "Piece") != 1)
	{
		ft_get_next_line(0, &line);
		if (ft_strstr_bool(line, "$$$"))
			error = ft_read_player(fil, line);
		else if (ft_strstr_bool(line, "Plateau") == 1)
			error = ft_read_map(fil, line);
		else if (ft_strstr_bool(line, "Piece"))
			error = ft_read_part(fil, line);
		if (error == -1)
			return (-1);
	}
	if (fil->test[0] == 0 || fil->test[1] == 0 || fil->test[2] == 0)
		return (-1);
	return (1);
}

int		ft_read_player(t_filler *fil, char *line)
{
	int		i;

	i = 0;
	if (line[10] == '1')
	{
		fil->player = 'O';
		fil->enemy = 'X';
	}
	else if (line[10] == '2')
	{
		fil->player = 'X';
		fil->enemy = 'O';
	}
	else
		return (-1);
	fil->test[0] = 1;
	return (1);
}

int		ft_read_map(t_filler *fil, char *line)
{
	char	**tab;
	int		i;

	i = ft_strlen(line);
	line[i - 1] = 0;
	tab = ft_strsplit(line + 8, ' ');
	i = 0;
	while (tab[i] != NULL)
		i++;
	if (i != 2)
		return (0);
	fil->mimap = ft_atoi(tab[0]);
	fil->mjmap = ft_atoi(tab[1]);
	ft_get_next_line(0, &line);
	i = 0;
	fil->map = (char **)malloc(sizeof(char *) * (fil->mimap + 1));
	while (i < fil->mimap)
	{
		ft_get_next_line(0, &line);
		fil->map[i++] = ft_strdup(line + 4);
	}
	fil->map[i] = NULL;
	fil->test[1] = 1;
	return (ft_check_map(fil->map, fil->mimap, fil->mjmap));
}

int		ft_read_part(t_filler *fil, char *line)
{
	char	**tab;
	int		i;

	i = ft_strlen(line);
	line[i - 1] = 0;
	tab = ft_strsplit(line + 6, ' ');
	i = 0;
	while (tab[i] != NULL)
		i++;
	if (i != 2)
		return (0);
	fil->mipart = ft_atoi(tab[0]);
	fil->mjpart = ft_atoi(tab[1]);
	i = 0;
	fil->part = (char **)malloc(sizeof(char *) * (fil->mipart + 1));
	while (i < fil->mipart)
	{
		ft_get_next_line(0, &line);
		fil->part[i] = ft_strdup(line);
		i++;
	}
	fil->part[i] = NULL;
	fil->test[2] = 1;
	return (ft_check_part(fil->part, fil->mipart, fil->mjpart));
}
