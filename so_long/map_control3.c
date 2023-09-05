/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:42:10 by sbozan            #+#    #+#             */
/*   Updated: 2023/09/05 20:14:00 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void    wallcheck(t_mapinfo *map)
{
    int i;

    i = 0;
    while (i < map->column - 1)
    {
        if (map->map[0][i] != '1' && map->map[map->row - 1][i] != '1')
            ft_exit(map, 1);
        i++;
    }
    i = 0;
    while (i < map->row - 1)
    {
        if (map->map[i][0] != '1' && map->map[i][map->column - 1] != '1')
            ft_exit(map, 1);
        i++;
    }
}

void    checkmap(t_mapinfo *map)
{
    int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < map->row - 1)
	{
		j = 0;
		while (j < map->column - 1)
		{
			if (map->map[i][j] == 'P')
				map->player += 1;
			else if (map->map[i][j] == 'C')
				map->coin += 1;
			else if (map->map[i][j] == 'E')
				map->exit += 1;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				ft_exit(map, 1);
			j++;
		}
		i++;
	}
}

void    sumcheck(t_mapinfo *map)
{
	int	i;

	i = 1;
	if (map->player != 1)
		ft_exit(map, 1);
	if (map->exit != 1)
		ft_exit(map, 1);
	if (map->coin < 1)
		ft_exit(map, 1);
}

void	getplayer(t_mapinfo *map)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < map->row - 1)
	{
		j = 1;
		while (j < map->column - 1)
		{
			if (map->map[i][j] == 'P')
			{
				map->px = j;
				map->py = i;
			}
			j++;
		}
		i++;
	}
}