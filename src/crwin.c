/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crwin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:46:44 by rrast             #+#    #+#             */
/*   Updated: 2022/01/19 14:55:31 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	takeimgtomap2(t_pict img, t_map map, int x, int y)
{
	if (map.map[y][x] == '1')
	{
		if (x == 0 || x == map.x || y == 0 || y == map.y)
			mlx_put_image_to_window(map.mlx, map.win, \
			img.wall, x * 32, y * 32);
		else
			mlx_put_image_to_window(map.mlx, map.win, \
			img.obst, x * 32, y * 32);
	}
	if (map.map[y][x] == 'P')
	{
		mlx_put_image_to_window(map.mlx, map.win, \
		img.empty, x * 32, y * 32);
		mlx_put_image_to_window(map.mlx, map.win, \
		img.pl, x * 32, y * 32);
	}
	if (map.map[y][x] == 'C')
	{
		mlx_put_image_to_window(map.mlx, map.win, \
		img.empty, x * 32, y * 32);
		mlx_put_image_to_window(map.mlx, map.win, \
		img.coll, x * 32, y * 32);
	}
}

void	takeimgtomap(t_pict img, t_map map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map.map[y])
	{
		while (map.map[y][x])
		{
			if (map.map[y][x] == '0')
				mlx_put_image_to_window(map.mlx, map.win, img.empty, \
				x * 32, y * 32);
			if (map.map[y][x] == 'E')
				mlx_put_image_to_window(map.mlx, map.win, \
				img.exit, x * 32, y * 32);
			takeimgtomap2(img, map, x, y);
			x++;
		}
		y++;
		x = 0;
	}
}

int	ft_hook(int keycode, t_map *map)
{
	t_pict	img;

	img = crpict(map->mlx);
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		ft_exit(map, 5);
	}
	if (keycode == 13 || keycode == 126)
		checkmove(map, 0, -1, img);
	if (keycode == 0 || keycode == 123)
		checkmove(map, -1, 0, img);
	if (keycode == 1 || keycode == 125)
		checkmove(map, 0, 1, img);
	if (keycode == 2 || keycode == 124)
		checkmove(map, 1, 0, img);
	return (0);
}

int	ft_mouse(int button, int x, int y, t_map *map)
{
	t_map	*pld;

	pld = map;
	printf("%d\n", button);
	printf("%d\n", x);
	printf("%d\n", y);
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
	takeimgtomap(img, map);
	takeplayer(&map);
	map.player = 0;
	mlx_hook(map.win, 2, 1L << 0, ft_hook, &map);
	mlx_hook(map.win, 17, 0L, ft_exitbut, &map);
	mlx_loop(map.mlx);
}
