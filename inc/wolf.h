/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:14:46 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/29 18:47:21 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

# define WDT 1280
# define HGT 720
# define MS 0.05
# define TS 0.05
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ESC 53

typedef struct	s_wolf
{
	int			xmax;
	int			ymax;
	int			**map;
}				t_wolf;

#endif