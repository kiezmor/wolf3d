/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:45:49 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/01 18:45:49 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_2byte(char *s, wchar_t c)
{
	s[0] = (c >> 6) | 0xC0;
	s[1] = (c & 0x3F) | 0x80;
	return (2);
}

static int	to_3byte(char *s, wchar_t c)
{
	s[0] = ((c >> 12) & 0xF) | 0xE0;
	s[1] = ((c >> 6) & 0x3F) | 0x80;
	s[2] = (c & 0x3F) | 0x80;
	return (3);
}

static int	to_4byte(char *s, wchar_t c)
{
	s[0] = ((c >> 18) & 0x7) | 0xF0;
	s[1] = ((c >> 12) & 0x3F) | 0x80;
	s[2] = ((c >> 6) & 0x3F) | 0x80;
	s[3] = (c & 0x3F) | 0x80;
	return (4);
}

int			ft_wctomb(char *s, wchar_t wc)
{
	if (!s)
		return (0);
	if (wc < 128)
	{
		wc &= 0x7f;
		s[0] = wc;
		return (1);
	}
	else if (wc < 2048)
		return (to_2byte(s, wc));
	else if (wc < 0xFFFF)
		return (to_3byte(s, wc));
	else
		return (to_4byte(s, wc));
	return (0);
}
