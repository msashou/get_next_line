#include "get_next_line.h"

// int	main(void)
// {
// 	int	fd;
// 	char	*line;

// 	fd = open("./test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

void	def_i(void)
{
	static int	i;

	i++;
	printf("%d\n", i);
	return ;
}

int	main()
{
	def_i();
	def_i();

	return 0;
}
