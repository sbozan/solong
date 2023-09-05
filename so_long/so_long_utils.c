/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:13:34 by sbozan            #+#    #+#             */
/*   Updated: 2023/09/05 21:33:05 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void	ft_exit(t_mapinfo *map, int errno)
{
	if (errno == 1)
	{
		printf("%s ファイルは無効なファイルです", map->mapname);//....ber dosyası geçersiz bir dosya
		exit(1);
	}
	else if (errno == 2)
	{
        
		printf("%s ファイルが見つかりません", map->mapname);//....ber dosyası bulunamadı
		exit(1);
	}
}

void	openmap(t_mapinfo *map)
{
	int	fd;
	int i;
	map->fd = open(map->mapname, O_RDONLY);
	if (map->fd < 0)
	{
		close(map->fd);
		ft_exit(map, 2);
	}
}
int check_coin(t_mapinfo *map, int k)
{
	if (k == 13 && map->map[map->px - 1][map->py] == 'C')
		map->coin--;
	if (k == 0 && map->map[map->px][map->py - 1] == 'C')
		map->coin--;
	if (k == 1 && map->map[map->px + 1][map->py] == 'C')
		map->coin--;
	if (k == 2 && map->map[map->px][map->py + 1] == 'C')
		map->coin--;
	return(map->coin);
}

void	exit_game(t_mapinfo *map)
{
	write(1, "YOU WIN .d\n", 11);
	mlx_destroy_window(map->mlx, map->win);
	exit(1);
}

char	ft_strnstr(char *haystack, char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (!needle[j+1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
