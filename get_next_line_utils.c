/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 03:53:23 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/26 04:30:00 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int stream)
{
	static char	buf[BUFSIZ];
	static char	*bufp;
	static int	n = 0;

	if (n == 0)
	{
		n = read(stream, buf, sizeof buf);
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char) *bufp++);
	else
		return (EOF);
}

int	main(void)
{
	int	fd;
	int	c;

	fd = open("./test.txt", O_RDONLY);
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break;
		printf("%c\n", c);
	}
	close(fd);
	return (0);
}
