/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 03:54:35 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/31 07:20:35 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_string
{
	unsigned char	*str;//文字列
	size_t	len;//文字列の長さ
	int		capa;//確保した領域の長さ
}	t_string;

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

char	*get_next_line(int fd);
int	ft_getc(int stream);
int	ft_putc(t_string *str, unsigned char c);
