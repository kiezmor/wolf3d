/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:49:44 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/01 18:49:44 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcstombs(char *s, const wchar_t *ws, size_t n)
{
	size_t	src;
	size_t	dest;

	src = 0;
	dest = 0;
	while (dest < n - 1)
		dest += (ft_wctomb(&s[dest], ws[src++]));
	s[dest] = '\0';
	return (dest);
}
