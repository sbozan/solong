/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:07:52 by sbozan            #+#    #+#             */
/*   Updated: 2023/09/05 20:23:46 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	valid_map_check(t_mapinfo *map, int x, int y)
{
	char	*p;

	p = &map->tmpmap[x][y];
	if (*p == 'E')
		map->validkey = 1;
	if (*p != 'E' && *p != '1')
	{
		if (*p == 'C')
			map->coin--;
		*p = '.';
		if (map->tmpmap[x][y + 1] != '1' &&
			map->tmpmap[x][y + 1] != '.')
			valid_map_check(map, x, y + 1);
		if (map->tmpmap[x][y - 1] != '1' &&
			map->tmpmap[x][y - 1] != '.')
			valid_map_check(map, x, y - 1);
		if (map->tmpmap[x - 1][y] != '1' &&
			map->tmpmap[x - 1][y] != '.')
			valid_map_check(map, x - 1, y);
		if (map->tmpmap[x + 1][y] != '1' &&
			map->tmpmap[x + 1][y] != '.')
			valid_map_check(map, x + 1, y);
	}
}

void	path_control(t_mapinfo *map)
{
	int	i;

	i = 0;
	map->validkey = 0;
	valid_map_check(map, map->px, map->py);
	while (map->row > i)
	{
		free(map->tmpmap[i]);
		i++;
	}
	if (map->coin != 0 || map->validkey != 1)
		ft_exit(map, 1);
}
