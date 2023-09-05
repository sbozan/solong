/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 04:45:15 by sbozan            #+#    #+#             */
/*   Updated: 2023/09/05 21:54:05 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void	getcolumn(t_mapinfo *map)
{
	char	*line;

	openmap(map);
    line = get_next_line(map->fd);
    if(!line)
        ft_exit(map, 2);
    map->column = ft_strlen(line);
    free(line);
}

void	getrow(t_mapinfo *map)
{
    int tmprow;
    char *line;

    tmprow = 0;
    openmap(map);
    line = get_next_line(map->fd);
    if (!line)
        ft_exit(map, 2);
    while(line)
    {
        tmprow++;
        free(line);
        line = get_next_line(map->fd);
    }
    if(tmprow < 2)
        ft_exit(map, 1);
    close(map->fd);
    map->row = tmprow;
}

void    namecontrol (t_mapinfo *map)
{
    if (map->mapname[0] == '/' && map->mapname[1] == '.')
        ft_exit(map, 1);
    else if (ft_strnstr(map->mapname, ".ber") == 0)
        ft_exit(map, 1);
}

void    structinit(t_mapinfo *map)
{
    map->player = 0;
    map->coin = 0;
    map->exit = 0;
}

void    start(t_mapinfo *map)
{
    structinit(map);
    namecontrol(map);
    getrow(map);
    getcolumn(map);
    columnscontrol(map);
    rectanglecontrol(map);
    allocate(map);
    getmap(map);
    wallcheck(map);
    checkmap(map);
    sumcheck(map);
    getplayer(map);
    path_control(map);
}