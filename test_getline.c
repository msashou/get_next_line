/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 03:33:56 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/26 03:45:36 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line = NULL;
	size_t	len = 0;
	ssize_t	read;

	printf("文字を入力してください: ");

	//1行読み込み
	read = getline(&line, &len, stdin);

	if (read != -1)
	{
		printf("入力された内容: %s", line);
		printf("文字数: %zd\n", read);
	}

	//動的確保したメモリの解放
	free (line);
	return (0);
}

//description
//lineptr:格納先ポインタの変数アドレス(初期値NULLでOK)
//n:確保したバッファサイズのポインタ(初期値0でOK)
//stream:読み込み元(標準入力ならstdin,ファイルならFILE*)
