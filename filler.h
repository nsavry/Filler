/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:55:50 by nsavry            #+#    #+#             */
/*   Updated: 2014/01/26 12:58:56 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define PART fil->part[fil->i][fil->j]
# define MAP fil->map[fil->ri + fil->i][fil->rj + fil->j]
# define PLAYER fil->player
# define ENEMY fil->enemy

typedef struct	s_filler
{
	char	**map;
	char	**part;
	int		mimap;
	int		mjmap;
	int		mipart;
	int		mjpart;
	int		i;
	int		j;
	int		ri;
	int		rj;
	char	player;
	char	enemy;
	int		test[3];
}				t_filler;

int		ft_solve_filler(t_filler *fil);
int		ft_check_one_part(t_filler *fil);
int		ft_read_std(t_filler *fil);
int		ft_read_player(t_filler *fil, char * line);
int		ft_read_map(t_filler *fil, char * line);
int		ft_read_part(t_filler *fil, char * line);
int		ft_check_map(char **map, int x, int y);
int		ft_check_part(char **part, int x, int y);

# endif /* !FILLER_H */
