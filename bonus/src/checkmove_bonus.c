/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:44:48 by rrast             #+#    #+#             */
/*   Updated: 2022/01/19 15:02:55 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_open(t_map map, t_pict img)
{
	int	x;
	int	y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'E')
			{
				mlx_put_image_to_window(map.mlx, map.win, \
				img.opex, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

void	checkmove2(t_map *map, int x, int y, t_pict img)
{
	mlx_put_image_to_window(map->mlx, map->win, \
	img.empty, map->x * 32, map->y * 32);
	mlx_put_image_to_window(map->mlx, map->win, \
	img.empty, (map->x + x) * 32, (map->y + y) * 32);
	mlx_put_image_to_window(map->mlx, map->win, \
	img.pl, (map->x + x) * 32, (map->y + y) * 32);
	map->x += x;
	map->y += y;
	if (map->map[map->y][map->x] == 'C')
	{
		map->map[map->y][map->x] = '0';
		if (--(map->coll) == 0)
			get_open(*map, img);
	}
}

void	checkmove(t_map *map, int x, int y, t_pict img)
{
	char	*step;

	if (map->map[map->y + y][map->x + x] != '1')
	{
		mlx_put_image_to_window(map->mlx, map->win, img.wall, 0, 0);
		step = ft_nbr(++map->player);
		if (!step)
			ft_exit(map, 5);
		mlx_string_put(map->mlx, map->win, 1, 1, 0x0000FF00, step);
		free (step);
		if (map->map[map->y + y][map->x + x] == 'E')
		{
			if (map->coll == 0)
				ft_exit(map, 3);
		}
		else
		{
			if (map->map[map->y + y][map->x + x] == 'F')
				ft_exit(map, 4);
			checkmove2(map, x, y, img);
			map->map[map->y][map->x] = 'P';
			map->map[map->y - y][map->x - x] = '0';
		}
	}
}
