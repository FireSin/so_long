/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:00:23 by rrast             #+#    #+#             */
/*   Updated: 2022/01/17 15:50:15 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	checkwall(t_map *map)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (map->map[a])
	{
		while (map->map[a][b])
		{
			if ((a == 0 || b == 0 || a == map->y - 1 \
				|| b == map->x - 1) && map->map[a][b] != '1')
				ft_exit(map, 1);
			b++;
		}
		if (b != map->x)
			ft_exit(map, 1);
		b = 0;
		a++;
	}
}

void	validmap(t_map *map)
{
	if (map->map == NULL || map->exit < 1 || map->coll < 1 \
		|| map->player != 1)
	{
		if (map->map == NULL || map->exit < 1 || map->coll < 1)
			ft_exit(map, 1);
		else
			ft_exit(map, 2);
	}
	checkwall(map);
}

int	checkfile(char *dir)
{
	int	i;

	i = 0;
	while (dir[i] && dir[i] != '.')
		i++;
	if (dir[i] == '.' && dir[i + 1] == 'b' && dir[i + 2] == 'e' \
		&& dir[i + 3] == 'r' && dir[i + 4] == '\0')
		return (0);
	return (1);
}

void	takeplayer(t_map *map)
{
	map->y = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			if (map->map[map->y][map->x] == 'P')
				return ;
			map->x++;
		}
		map->y++;
	}
}
