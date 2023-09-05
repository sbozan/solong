/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:08:08 by sbozan            #+#    #+#             */
/*   Updated: 2023/09/05 21:10:34 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_set_img(t_mapinfo *map)
{
	int x;
	int y;
	
	x = 64;
	y = x;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->px * 64,map->py * 64, "Don't think, feel it.");
	map->p_img_f = mlx_xpm_file_to_image(map->mlx, "/textures/pf.xpm",
			&x, &y);
	map->p_img_b = mlx_xpm_file_to_image(map->mlx, "/textures/pb.xpm",
			&x, &y);
	map->p_img_r = mlx_xpm_file_to_image(map->mlx, "/textures/pr.xpm",
			&x, &y);
	map->p_img_l = mlx_xpm_file_to_image(map->mlx, "/textures/pl.xpm",
			&x, &y);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, "/textures/exit.xpm",
			&x, &y);
	map->img_coin = mlx_xpm_file_to_image(map->mlx, "/textures/coin.xpm",
			&x, &y);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "/textures/wall.xpm",
			&x, &y);
	map->img_background = mlx_xpm_file_to_image(map->mlx, "/textures/bg.xpm",
			&x, &y);
}

void	ft_render(t_mapinfo *map)
{
	int	x;
	int	y;
	int	j;
	int	i;

	i = 0;
	y = 0;
	while (i < map->column)
	{
		j = 0;
		x = 0;
		while (j < map->row)
		{
			ft_put_img(map, map->map[i][j], x, y);
			j++;
			x += 64;
		}
		i++;
		y += 64;
	}
}

int	ft_ext_game(void)
{
	exit(1);
}

int	main(int ac, char *av[])
{
	t_mapinfo map;
	map.mapname = av[1];
	if(ac == 2)
	{
		start(&map);
		map.move_count = 0;
		ft_set_img(&map);
		ft_render(&map);
		mlx_hook(map.win, 2, 0, set_win, &map);
		mlx_hook(map.win, 17, 0, ft_ext_game, 0);
		mlx_loop(map.mlx);
		return(1);
	}
	else
		perror("\n\x1B[31mERROR: Please Check Arguments\n");
	return(0);
}
	
	//printf("%d\n", map.row);
	//int i = 0;
	//while (map.row--)
	//{
	//	printf("satır %d. %s\n", i+1, map.map[i]);
	//	i++;
	//}
	//printf("%s \n%d \n%d\n%d\n%d\n%d\n%d\n%d", map.mapname, map.column, map.fd,
	//	map.px, map.py, map.player, map.coin, map.exit);
