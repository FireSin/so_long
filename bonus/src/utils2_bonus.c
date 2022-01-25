/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:13:17 by rrast             #+#    #+#             */
/*   Updated: 2022/01/19 12:38:41 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_pict	crpict(void *mlx)
{
	t_pict	img;
	int		width;
	int		height;

	img.pl = mlx_xpm_file_to_image(mlx, "./capt/cleric.xpm", &width, &height);
	img.coll = mlx_xpm_file_to_image(mlx, "./capt/ghost.xpm", &width, &height);
	img.empty = mlx_xpm_file_to_image(mlx, "./capt/lava.xpm", &width, &height);
	img.exit = mlx_xpm_file_to_image(mlx, "./capt/enter.xpm", &width, &height);
	img.wall = mlx_xpm_file_to_image(mlx, "./capt/catac.xpm", &width, &height);
	img.obst = mlx_xpm_file_to_image(mlx, "./capt/drag.xpm", &width, &height);
	img.opex = mlx_xpm_file_to_image(mlx, "./capt/opex.xpm", &width, &height);
	img.enemy = mlx_xpm_file_to_image(mlx, "./capt/knig.xpm", &width, &height);
	return (img);
}

int	ft_exitbut(t_map *map)
{
	ft_exit(map, 10);
	return (0);
}

void	addenemy(t_enemy **enemy, int x, int y)
{
	t_enemy	*tmp;

	tmp = (t_enemy *)malloc(sizeof(t_enemy));
	if (!tmp)
		return ;
	tmp->x = x;
	tmp->y = y;
	if (!*enemy)
	{
		tmp->r = '+';
		tmp->next = NULL;
	}
	else
	{
		if ((*enemy)->r == '+')
			tmp->r = '-';
		else
			tmp->r = '+';
		tmp->next = *enemy;
	}
	*enemy = tmp;
}

char	*ft_nbr(int i)
{
	char	*step;
	int		k;
	int		n;

	k = 0;
	n = 1;
	step = NULL;
	while (i)
	{
		k = (k * 10) + (i % 10);
		i = i / 10;
		n++;
	}
	step = (char *)malloc(sizeof(char) * n);
	if (!step)
		return (NULL);
	step[--n] = '\0';
	while (i != n)
	{
		step[i] = (k % 10) + 48;
		k = k / 10;
		i++;
	}	
	return (step);
}
