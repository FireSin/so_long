/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveenemy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:28:43 by rrast             #+#    #+#             */
/*   Updated: 2022/01/19 14:39:29 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	moveenem(t_map *map, t_pict img, t_enemy *p, int x)
{
	if (map->map[p->y][p->x] == 'P')
		ft_exit(map, 4);
	mlx_put_image_to_window(map->mlx, map->win, \
		img.empty, p->x * 32, p->y * 32);
	mlx_put_image_to_window(map->mlx, map->win, img.enemy, x * 32, p->y * 32);
	map->map[p->y][p->x] = '0';
	map->map[p->y][x] = 'F';
	p->x = x;
}

void	moveright(t_map *map, t_pict img, t_enemy *p)
{
	if (map->map[p->y][p->x + 1] == '0')
		moveenem(map, img, p, p->x + 1);
	else
	{
		if (p && p->r == '+' && (map->map[p->y][p->x + 1] == '1' \
			|| map->map[p->y][p->x + 1] == 'C' \
			|| map->map[p->y][p->x + 1] == 'E' \
			|| map->map[p->y][p->x + 1] == 'P' \
			|| map->map[p->y][p->x + 1] == 'F'))
		{
			if (map->map[p->y][p->x + 1] == 'P' \
			|| map->map[p->y][p->x - 1] == 'P')
				ft_exit(map, 4);
			if (map->map[p->y][p->x - 1] == '0')
			{
				p->r = '-';
				moveenem(map, img, p, p->x - 1);
			}
		}
	}
}

void	moveleft(t_map *map, t_pict img, t_enemy *p)
{
	if (p && p->r == '-' && map->map[p->y][p->x - 1] == '0')
		moveenem(map, img, p, p->x - 1);
	else
	{
		if (p && p->r == '-' && (map->map[p->y][p->x - 1] == '1' \
			|| map->map[p->y][p->x - 1] == 'C' \
			|| map->map[p->y][p->x - 1] == 'E' \
			|| map->map[p->y][p->x - 1] == 'P' \
			|| map->map[p->y][p->x - 1] == 'F'))
		{
			if (map->map[p->y][p->x - 1] == 'P' \
				|| map->map[p->y][p->x + 1] == 'P')
				ft_exit(map, 4);
			if (map->map[p->y][p->x + 1] == '0')
			{
				p->r = '+';
				moveenem(map, img, p, p->x + 1);
			}
		}
	}
}

void	moveenemy(t_map *map, t_pict img)
{
	t_enemy	*p;

	p = map->enemy;
	while (p)
	{
		if (p && p->r == '+')
			moveright(map, img, p);
		else
		{
			if (p && p->r == '-')
				moveleft(map, img, p);
		}
		p = p->next;
	}
}
