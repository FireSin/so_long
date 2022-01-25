/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crwin_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:46:44 by rrast             #+#    #+#             */
/*   Updated: 2022/01/19 13:38:55 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_hook(int keycode, t_map *map)
{
	t_pict	img;

	img = crpict(map->mlx);
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		ft_exit(map, 10);
	}
	if (keycode == 13 || keycode == 126)
		checkmove(map, 0, -1, img);
	if (keycode == 0 || keycode == 123)
		checkmove(map, -1, 0, img);
	if (keycode == 1 || keycode == 125)
		checkmove(map, 0, 1, img);
	if (keycode == 2 || keycode == 124)
		checkmove(map, 1, 0, img);
	moveenemy(map, img);
	return (0);
}

void	crmap(t_map map)
{
	t_pict	img;

	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.x * 32, map.y * 32, "So_Long");
	img = crpict(map.mlx);
	map.x--;
	map.y--;
	map.enemy = NULL;
	takeenemy(&map, &map.enemy);
	takeimgtomap(img, map);
	mlx_string_put(map.mlx, map.win, 1, 1, 0x0000FF00, "0");
	takeplayer(&map);
	map.player = 0;
	mlx_hook(map.win, 2, 1L << 0, ft_hook, &map);
	mlx_hook(map.win, 17, 0L, ft_exitbut, &map);
	mlx_loop(map.mlx);
}
