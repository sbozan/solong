/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:44:03 by sbozan            #+#    #+#             */
/*   Updated: 2023/09/05 21:28:33 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

//char	*ft_strnstr(char *name, char *control)
//{
//	int	i;
//	int	j;
//	i = 0;
//	while (name[i] && name[0] != '.')
//	{
//		j = 0;
//		//printf("%s", "1");
//		while ((name[i+j]) == control[j])
//		{
//			//printf("%s", "1");
//			if (!control[j+1])
//			{
//				if (i == 0)
//				{
//					//printf("%s", "1");
//					return (NULL);
//				}
//				else if (!name[i+j+1])
//				{
//					//printf("%s", "1");
//					if(name[i-1] == '/')
//						return (NULL);
//					printf("%s", "1");
//					return (name);
//				}
//			}
//			j++;
//		}
//		i++;
//	}
//	printf("%s\n", name);
//	return (NULL);
//}

void	allocate(t_mapinfo *array)
{
	int	i;

	i = 0;
	array->map = malloc((array->row + 1) * sizeof(char *));
	array->map[array->row] = NULL;
	while (i < array->row)
	{
		array->map[i] = malloc(array->column * sizeof(char));
		i++;
	}
}

void	getmap(t_mapinfo *map)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	openmap(map);
	while (i < map->row)
	{
		line = get_next_line(map->fd);
		while (j < map->column)
		{
			map->map[i][j] = line[j];
			j++;
		}
		free(line);
		map->map[i][map->column - 1] = '\0';
		j = 0;
		i++;
	}
	close(map->fd);
}

void	allocatetmp(t_mapinfo *map)
{
	int	i;

	i = 0;
	map->tmpmap = malloc((map->row + 1) * sizeof(char *));
	map->tmpmap[map->row] = NULL;
	while (i < map->row)
	{
		map->tmpmap[i] = malloc(map->column * sizeof(char));
		i++;
	}
}

void	gettmpmap(t_mapinfo *map)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	openmap(map);
	while (i < map->row)
	{
		line = get_next_line(map->fd);
		while (j < map->column)
		{
			map->tmpmap[i][j] = map->map[i][j];
			j++;
		}
		free(line);
		map->tmpmap[i][map->column - 1] = '\0';
		j = 0;
		i++;
	}
	close(map->fd);
}
