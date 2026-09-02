/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 03:53:23 by smasatak          #+#    #+#             */
/*   Updated: 2026/09/02 13:34:53 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	ft_getc(int stream)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n;

	if (n == 0)
	{
		n = read(stream, buf, BUFFER_SIZE);
		bufp = buf;
	}
	if (n == -1)
		return (EOF);
	n--;
	return ((unsigned char)*bufp++);
}

int	ft_putc(t_string *str, unsigned char c)
{
	unsigned char	*new_str;
	int		new_capa;
	size_t		i;

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

// int	main()
// {
// 	int	n;
// 	int	i;

// 	n = 0;
// 	i = 0;
// 	n = open("./file1.txt", O_RDONLY);

// 	if (n == -1)
// 		printf("ERROR\n");
// 	i = ft_getc(n);
// 	if (i == -1)
// 		printf("ERROR getstr\n");

// 	return (0);
// }

// int	main(void)
// {
// 	int	str;

// 	open("./test", O_RDONLY);
// 	str = ft_getstr(0);
// 	printf("%d\n", str);
// 	return (0);
// }

// int	main(void)
// {
// 	int	fd1;
// 	int	fd2;
// 	int	byte_num;
// 	int	read_by_file2;
// 	char	buf[BUFFER_SIZE];
// 	char	buf2[BUFFER_SIZE];

// 	fd1 = 0;
// 	fd2 = 0;
// 	byte_num = 0;
// 	read_by_file2 = 0;
// 	memset(buf, '\0', BUFFER_SIZE);
// 	memset(buf2, '\0', BUFFER_SIZE);

// 	fd1 = open("./file1.txt", O_RDONLY);
// 	if (fd1 == -1)
// 		perror ("open file1");
// 	fd2 = open("./file2.txt", O_RDONLY);
// 	if (fd2 == -1)
// 		perror ("open file2");

// 	if (fd1 == -1 || fd2 == -1)
// 	{
// 		fprintf(stdout, "open file error\n");
// 		return 1;
// 	}

// 	byte_num = read(fd1, &buf[0], BUFFER_SIZE);
// 	read_by_file2 = read (fd2, &buf2[0], BUFFER_SIZE);

// 	if (byte_num == -1)
// 		perror ("read file1");
// 	if (read_by_file2 == -1)
// 		perror ("read file2");

// 	if (byte_num == -1 || read_by_file2 == -1)
// 	{
// 		fprintf(stdout, "reading file error\n");
// 		return 1;
// 	}

// 	fprintf(stdout, "read %dbytes from file1\n", byte_num);
// 	fprintf(stdout, "reading string %s\n", buf);

// 	fprintf(stdout, "read %dbytes frp, file2\n", read_by_file2);
// 	fprintf(stdout, "reading string %s\n", buf2);

// 	close (fd1);
// 	close (fd2);

// 	return 0;
// }
