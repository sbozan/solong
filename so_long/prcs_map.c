/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prcs_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:22:16 by sbozan            #+#    #+#             */
/*   Updated: 2023/09/05 21:08:11 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void    ft_put_img(t_mapinfo *map, char point, int x, int y)
{
    mlx_put_image_to_window(map->mlx, map->win, map->img_background, x, y);
    if (point == '1')
        mlx_put_image_to_window(map->mlx, map->win, map->img_wall, x, y);
    if (point == 'C')
        mlx_put_image_to_window(map->mlx, map->win, map->img_coin, x, y);
    if (point == 'P' && map->move_count == 0)
        mlx_put_image_to_window(map->mlx, map->win, map->p_img_f, x, y);
    if (point == 'P')
    {
        if (map->current_move == 1)
            mlx_put_image_to_window(map->mlx, map->win, map->p_img_b, x, y);
        if (map->current_move == 0)
            mlx_put_image_to_window(map->mlx, map->win, map->p_img_l, x, y);
        if (map->current_move == 13)
            mlx_put_image_to_window(map->mlx, map->win, map->p_img_f, x, y);
        if (map->current_move == 2)
            mlx_put_image_to_window(map->mlx, map->win, map->p_img_r, x, y);
    }
    if (point == 'E')
        mlx_put_image_to_window(map->mlx, map->win, map->img_exit, x, y);
}

void	replace(t_mapinfo *map, int px, int py, int keycode)
{
	if (keycode == 1 && map->map[px + 1][py] != '1')
	{
		map->map[px + 1][py] = 'P';
		map->px++;
		map->current_move = 1;
	}
	if (keycode == 0 && map->map[px][py - 1] != '1')
	{
		map->map[px][py - 1] = 'P';
		map->py--;
		map->current_move = 0;
	}
	if (keycode == 13 && map->map[px - 1][py] != '1')
	{
		map->map[px - 1][py] = 'P';
		map->px--;
		map->current_move = 13;
	}
	if (keycode == 2 && map->map[px][py + 1] != '1')
	{
		map->map[px][py + 1] = 'P';
		map->py++;
		map->current_move = 2;
	}
	map->map[px][py] = '0';
}

int	check_wall(t_mapinfo *map, int k)
{
	if (k == 13 && map->map[map->px - 1][map->py] == '1')
		return (1);
	if (k == 0 && map->map[map->px][map->py - 1] == '1')
		return (1);
	if (k == 1 && map->map[map->px + 1][map->py] == '1')
		return (1);
	if (k == 2 && map->map[map->px][map->py + 1] == '1')
		return (1);
	return (0);
}

int check_exit(t_mapinfo *map, int k)
{
	if (k == 13 && map->map[map->px - 1][map->py] == 'E')
		return (1);
	if (k == 0 && map->map[map->px][map->py - 1] == 'E')
		return (1);
	if (k == 1 && map->map[map->px + 1][map->py] == 'E')
		return (1);
	if (k == 2 && map->map[map->px][map->py + 1] == 'E')
		return (1);
	return (0);
}

int set_win(int keycode, t_mapinfo *map)
{
    int k;

    k = keycode;
    if (k == 53)
        ft_exit(map, 1);
    if  (check_exit(map, k) && map->coin == 0)
    {
        map->move_count++;
        printf("%d\n", map->move_count);
        exit_game(map);
    }
    if ((k == 13 || k == 0 || k == 1 || k == 2)
        && !check_exit(map, k) && !check_wall(map, k))
    {
        check_coin(map, k);
        replace(map, map->px, map->py, keycode);
        map->move_count++;
        mlx_clear_window(map->mlx, map->win);
        ft_render(map);
        printf("%d\n", map->move_count);
    }
    return (0);
}