/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 03:52:01 by smasatak          #+#    #+#             */
/*   Updated: 2026/09/01 06:01:56 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_string	ret;
	int			c;

	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;

	while (1)
	{
		c = ft_getc(fd);

		if (c == EOF)
			break;
		ft_putc(&ret, c);
		if (c == '\n')
			break;
	}
	if (ret.len > 0)
		ft_putc(&ret, '\0');
	return ((char *)ret.str);
}
