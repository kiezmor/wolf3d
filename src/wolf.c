/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:19:22 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/29 17:40:07 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	error(int i)
{
	if (i == 1)
		ft_putendl("Error, wrong number of argument.");
	if (i == 2)
		ft_putendl("Error, file not found.");
	ft_putendl("Usage: ./wolf3d <map>");
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	int	fd;
	
	if (ac > 2 || ac < 2)
		error(1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error(2);
	close(fd);
}
