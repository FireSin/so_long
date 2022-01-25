/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:26:52 by rrast             #+#    #+#             */
/*   Updated: 2022/01/19 11:24:59 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	takefill(t_map *map, char s)
{
	if (s == 'P')
		map->player++;
	if (s == 'C')
		map->coll++;
	if (s == 'E')
		map->exit++;
}

void	checklenmap(t_map *map)
{
	if ((int)ft_strlen(map->map[map->y]) != map->x)
		ft_exit(map, 1);
	map->y++;
}

void	readmap(int fd, t_map *map)
{
	char	s;

	while (read(fd, &s, 1) > 0)
	{
		if (s == '\n')
			checklenmap(map);
		else
		{
			map->map[map->y] = ft_strjoin(map->map[map->y], s);
			if (!map->map[map->y])
				ft_exit(map, 5);
			takefill(map, s);
		}
	}
	checklenmap(map);
}

void	checkdir(char *dir, t_map *map)
{
	int		fd;
	char	s;

	fd = open(dir, O_RDONLY);
	if (fd < 0)
		ft_exit(NULL, 0);
	while (read(fd, &s, 1) > 0)
	{
		if (!(s == '\n' || s == '0' || s == '1' \
			|| s == 'E' || s == 'P' || s == 'C') \
			|| (s == '\n' && map->x == 0))
			ft_exit(NULL, 1);
		if (s == '\n' && map->x != 0)
			map->y++;
		if (map->y == 0 && s != '\n')
			map->x++;
	}
	close (fd);
	map->y += 2;
	map->map = (char **)malloc(sizeof(char *) * map->y);
	while (--map->y >= 0)
		map->map[map->y] = 0;
	map->y = 0;
}

t_map	initmap(char *dir)
{
	int		fd;
	t_map	map;

	map.map = NULL;
	map.y = 0;
	map.x = 0;
	map.player = 0;
	map.exit = 0;
	map.coll = 0;
	if (checkfile(dir))
		ft_exit(NULL, 0);
	checkdir(dir, &map);
	fd = open(dir, O_RDONLY);
	if (fd < 0)
		ft_exit(NULL, 0);
	readmap(fd, &map);
	validmap(&map);
	return (map);
}
