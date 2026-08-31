/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:22:36 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/25 21:36:01 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read関数
// ファイルディスクリプタから読み込む
// 引数
// fd = ファイルディスクリプタ
// buf = 読み込んだデータを保存する領域のポインタ
// byte = ファイルから読み込むバイト数

// 戻り値
// 成功:読み込んだバイト数(ファイル終端に達した場合は0)
// 失敗:-1

// 解説
// ファイルディスクリプタ(fd)から、byteで指定した領域分のデータを読み込み、
// bufへ格納する。

//below somple program

// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// #define BUF_SIZE 512

// int	main(void)
// {
// 	//declare valiable
// 	int	fd1;
// 	int	fd2;
// 	int	byte_num;
// 	char	buf[BUF_SIZE];

// 	//initialize valiable
// 	fd1 = 0;
// 	fd2 = 0;
// 	byte_num = 0;
// 	memset(buf, '\0', BUF_SIZE);

// 	//open file
// 	fd1 = open("./file1", O_RDONLY); //open for read only
// 	fd2 = open("./file2", O_WRONLY); //open by write only

// 	if (fd1 == -1 || fd2 == -1)
// 	{
// 		fprintf(stdout, "file open error\n");
// 		return (1);
// 	}

// 	//read 5 bytes by file
// 	byte_num = read(fd1, &buf[0], 5);

// 	if (byte_num == -1)
// 	{
// 		fprintf(stdout, "file reading error\n");
// 		return (1);
// 	}

// 	fprintf(stdout, "read %dbytes by file1\n", byte_num);
// 	fprintf(stdout, "read string:%s\n", buf);

// 	//writing 3bytes to file
// 	byte_num = write(fd2, &buf[0], 3);

// 	if (byte_num == -1)//faile road file
// 	{
// 		fprintf(stdout, "roading file erorr\n");
// 		return (1);
// 	}

// 	fprintf(stdout, "writing %dbytes by file2.\n", byte_num);
// 	buf[byte_num] = '\0';
// 	fprintf(stdout, "wrote string:%s\n", buf);

// 	//close files
// 	close (fd1);
// 	close (fd2);

// 	return (0);
// }
// ssize_t	read(int fd, void *bf, size_t byte)
// {

// }

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_getc(fd)
{
	static char	buf[BUFSIZ];
	static char	*bufp;
	static int	n;

	n = 0;
	if (n == 0)
	{
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
int	main(void)
{
	int	fd;
	int	c;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break;
		printf("%c\n", c);
	}
	close (fd);
	return (0);
}
