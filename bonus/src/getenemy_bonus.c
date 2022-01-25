/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:48:38 by rrast             #+#    #+#             */
/*   Updated: 2022/01/19 11:34:12 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	countenemy(char **map)
{
	int	x;
	int	y;
	int	k;

	x = 0;
	y = 0;
	k = 0;
	while (map[++y] != 0)
	{
		while (map[y][x])
		{
			if (map[y][x++] == '0')
				k++;
		}
	}
	return (k / 8);
}

int	randint(int min, int max)
{
	int	i;

	i = (rand() % (max - min + 1)) + min;
	return (i);
}

void	takeenemy(t_map *map, t_enemy **enemy)
{
	int	k;
	int	x;
	int	y;

	k = countenemy(map->map);
	while (k)
	{
		srand(time(NULL));
		x = randint(1, map->x);
		srand(time(NULL));
		y = randint(1, map->y);
		if (map->map[y][x] == '0')
		{
			map->map[y][x] = 'F';
			addenemy(enemy, x, y);
			if (!enemy)
				ft_exit(map, 5);
			k--;
		}
	}
}
