/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 03:48:42 by sbozan            #+#    #+#             */
/*   Updated: 2023/09/05 21:33:09 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct t_mapinfo
{
	char	**map;
	char	**tmpmap;
	char	*mapname;
	int		column;
	int		row;
	int		isvalidkey;
	int		fd;
	int		px;
	int		py;
	int		player;
	int		coin;
	int		exit;
	int		validkey;
	int		move_count;
	int		current_move;
	void	*mlx;
	void	*win;
	void	*p_img_f;
	void	*p_img_b;
	void	*p_img_r;
	void	*p_img_l;
	void	*img_exit;
	void	*img_coin;
	void	*img_wall;
	void	*img_background;
}t_mapinfo;

void	ft_exit(t_mapinfo *map, int errno);
void	openmap(t_mapinfo *map);
void	getrow(t_mapinfo *map);
void	getcolumn(t_mapinfo *map);
void	columnscontrol(t_mapinfo *map);
void	allocate(t_mapinfo *array);
void	getmap(t_mapinfo *map);
void	wallcheck(t_mapinfo *map);
void	checkmap(t_mapinfo *map);
void	rectanglecontrol(t_mapinfo *map);
void	sumcheck(t_mapinfo *map);
void	getplayer(t_mapinfo *map);
char	ft_strnstr(char *name, char *control);
void	structinit(t_mapinfo *map);
void	namecontrol(t_mapinfo *map);
void	start(t_mapinfo *map);
void	allocatetmp(t_mapinfo *map);
void	gettmpmap(t_mapinfo *map);
void	path_control(t_mapinfo *map);
void	valid_map_check(t_mapinfo *arg, int x, int y);
void	ft_set_img(t_mapinfo *map);
void	ft_render(t_mapinfo *map);
void    ft_put_img(t_mapinfo *map, char point, int x, int y);
void	replace(t_mapinfo *map, int px, int py, int keycode);
int 	set_win(int keycode, t_mapinfo *map);
int 	check_exit(t_mapinfo *map, int k);
void	exit_game(t_mapinfo *map);
int 	check_coin(t_mapinfo *map, int k);
int		ft_ext_game(void);
int		check_wall(t_mapinfo *map, int k);

#endif