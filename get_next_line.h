/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 03:54:35 by smasatak          #+#    #+#             */
/*   Updated: 2026/09/02 13:06:24 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_string
{
	unsigned char	*str;
	size_t	len;
	int		capa;
}	t_string;

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

char	*get_next_line(int fd);
int	ft_getc(int stream);
int	ft_putc(t_string *str, unsigned char c);
