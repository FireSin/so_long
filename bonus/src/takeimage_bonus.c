/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeimage_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:10:16 by rrast             #+#    #+#             */
/*   Updated: 2022/01/18 15:22:22 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	takeimgtomap3(t_pict img, t_map map, int x, int y)
{
	if (map.map[y][x] == 'F')
	{
		mlx_put_image_to_window(map.mlx, map.win, \
		img.empty, x * 32, y * 32);
		mlx_put_image_to_window(map.mlx, map.win, \
		img.enemy, x * 32, y * 32);
	}
}

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
	takeimgtomap3(img, map, x, y);
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
