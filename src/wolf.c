/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:19:22 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/31 23:32:20 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_exit(t_wolf *e)
{
	mlx_destroy_image(e->mlx, e->img);
	free(e);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_initmlx(t_wolf *e)
{
	e->x = 5;
	e->y = 5;
	e->dx = -1;
	e->dy = 0;
	e->px = 0;
	e->py = 0.66;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WID, HEI, "Wolf3d");
	mlx_hook(e->win, 17, 1L << 17, &ft_exit, e);
	mlx_hook(e->win, 2, 1L << 0, &ft_move, e);
	mlx_loop_hook(e->mlx, &ft_raycast, e);
	mlx_loop(e->mlx);
}

int    ft_move(int key, t_wolf *e)
{
	if (key == ESC)
		ft_exit(e);
	if (key == UP || key == DOWN)
	{
		e->ms = (key == UP) ? (MS) : (-MS);
			if (!(e->map[(int)(e->x + e->dx * e->ms)][(int)e->y]))
				e->x += e->dx * e->ms;
		if (!(e->map[(int)e->x][(int)(e->y + e->dy * e->ms)]))
			e->y += e->dy * e->ms;
	}
	if (key == LEFT || key == RIGHT)
	{
		e->ts = (key == LEFT) ? (TS) : (-TS);
		e->tmp = e->dx;
		e->dx = e->dx * cos(e->ts) - e->dy * sin(e->ts);
		e->dy = e->tmp * sin(e->ts) + e->dy * cos(e->ts);
		e->tmp = e->px;
		e->px = e->px * cos(e->ts) - e->py * sin(e->ts);
		e->py = e->tmp * sin(e->ts) + e->py * cos(e->ts);
	}
	return (0);
}

static void	error(int i)
{
	if (i == 1)
		ft_putendl("Error, wrong number of argument.");
	if (i == 2)
		ft_putendl("Error, invalid file.");
	if (i == 3)
		ft_putendl("Error, alloc struct");
	if (i == 4)
		ft_putendl("Error, invalid map.");
	if (i == 5)
		ft_putendl("Error while creating map.");
	ft_putendl("Usage: ./wolf3d <map>");
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	t_wolf	*e;
	int		i;

	if (ac != 2)
		error(1);
	if (!(e = (t_wolf *)malloc(sizeof(t_wolf))))
		error(3);
	if ((i = open_map(av[1], e)) != 0)
		error(i);
	ft_initmlx(e);
	return (0);
}
