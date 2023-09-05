/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:16:43 by sbozan            #+#    #+#             */
/*   Updated: 2023/09/05 21:49:11 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void    columnscontrol(t_mapinfo *map)
{
    char *line;
    int i;
    
    i = 1;
    openmap(map);
    get_next_line(map->fd);
    while (i < map->row)
    {
        line = get_next_line(map->fd);
        if (map->column != ft_strlen(line) && i != map->row - 1)
        {
            printf("%d\n%d\n%d\n%d", map->column, ft_strlen(line), i, map->row);
            ft_exit(map, 1);
        }
        else if (map->column != ft_strlen(line) + 1 && i == map->row -1)
            ft_exit(map, 1);
        i++;
        free(line);
    }
    close (map->fd);
}


void    rectanglecontrol(t_mapinfo *map)
{
	if (map->row == map->column || map->row > 22 || map->column > 40)
	{
		ft_exit(map, 1);
	}
}