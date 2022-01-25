/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:44:48 by rrast             #+#    #+#             */
/*   Updated: 2022/01/18 15:29:27 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	checkmove(t_map *map, int x, int y, t_pict img)
{
	if (map->map[map->y + y][map->x + x] != '1')
	{
		if (map->map[map->y + y][map->x + x] == 'E')
		{
			if (map->coll == 0)
				ft_exit(map, 3);
		}
		else
		{
			printf("Steps: %d\n", ++map->player);
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
				map->coll -= 1;
				map->map[map->y][map->x] = '0';
			}
		}
	}
}
