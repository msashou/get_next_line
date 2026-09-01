/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 03:53:23 by smasatak          #+#    #+#             */
/*   Updated: 2026/09/01 06:04:26 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int stream)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n = 0;

	if (n == 0)
	{
		n = read(stream, buf, BUFFER_SIZE);
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char) *bufp++);
	else
		return (EOF);
}

int	ft_putc(t_string *str, unsigned char c)
{
	unsigned char	*new_str;
	int				new_capa;
	int				i;

	new_capa = str->capa + 1;
	new_str = malloc(sizeof(char) * new_capa);
	if (!new_str)
		return (-1);
	i = 0;
	while (i < str->len)
	{
		new_str[i] = str->str[i];
		i++;
	}
	free(str->str);
	str->str = new_str;
	str->capa = new_capa;
	str->str[str->len] = c;
	str->len++;
	return (0);
}
