/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:49:44 by rrast             #+#    #+#             */
/*   Updated: 2022/01/19 11:41:14 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	clearmap(t_map *map)
{
	int		i;
	t_enemy	*p;

	i = 0;
	if (map->enemy)
	{
		while (map->enemy)
		{
			p = map->enemy;
			map->enemy = map->enemy->next;
			free (p);
			p = NULL;
		}
	}
	while (map->map[i])
		free (map->map[i++]);
	free (map->map);
}

void	ft_exit(t_map *map, int i)
{
	if (i == 0)
		printf("Map can't open\n");
	if (i == 1)
		printf("Map is wrong!\n");
	if (i == 2)
		printf("Please, take only one player.\n");
	if (i == 3)
		printf("You WIN! Score: %d\n", ++map->player);
	if (i == 4)
		printf("You LOSE!\n");
	if (i == 5)
		printf("Malloc error.\n");
	if (map && map->map)
		clearmap(map);
	exit (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (dstsize)
	{
		while (src && src[j] && j < (dstsize - 1))
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	while (src && src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char s2)
{
	size_t	len1;
	char	*dst;
	int		i;

	dst = 0;
	i = 0;
	len1 = ft_strlen(s1);
	dst = malloc(sizeof(char) * (len1 + 2));
	if (!dst)
	{
		free (s1);
		return (NULL);
	}
	ft_strlcpy(dst, s1, len1 + 1);
	dst[len1] = s2;
	dst[len1 + 1] = '\0';
	if (s1)
		free (s1);
	return (dst);
}
