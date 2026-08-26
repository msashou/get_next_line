/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 03:52:01 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/26 04:00:53 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_string	ret;
	int			c;

	//初期化
	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;

	while (1)
	{
		c = ft_getc(fd);//1文字読み込む

		if (c == EOF)
			break;//ファイルの最後なだループから抜ける
		ft_putc(&ret, c)//1文字詰める
		if (c == '\n')
			break;//改行だったらループから抜ける
	}
	if (ret.len > 0)
		ft_putc(&ret, '\0');//最後にNULL文字を詰める
	return ret.str;
}
