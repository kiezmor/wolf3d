/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:19:22 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/29 20:48:09 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
	free(e);
	return (0);
}
