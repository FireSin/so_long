/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:13:17 by rrast             #+#    #+#             */
/*   Updated: 2022/01/17 16:04:40 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	return (img);
}

int	ft_exitbut(t_map *map)
{
	ft_exit(map, 5);
	return (0);
}
