/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:56:02 by rrast             #+#    #+#             */
/*   Updated: 2022/01/19 14:47:49 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

typedef struct s_pict {
	void	*empty;
	void	*wall;
	void	*pl;
	void	*coll;
	void	*exit;
	void	*opex;
	void	*obst;
}				t_pict;

typedef struct s_map {
	char	**map;
	int		x;
	int		y;
	int		coll;
	int		player;
	int		exit;
	void	*mlx;
	void	*win;
}				t_map;

t_map	initmap(char *dir);
char	*ft_strjoin(char *s1, char s2);
size_t	ft_strlen(const char *str);
void	validmap(t_map *map);
void	ft_exit(t_map *map, int i);
int		checkfile(char *dir);
void	crmap(t_map map);
void	takeplayer(t_map *map);
void	get_open(t_map map, t_pict img);
void	checkmove(t_map *map, int x, int y, t_pict img);
int		ft_exitbut(t_map *map);
t_pict	crpict(void *mlx);

#endif