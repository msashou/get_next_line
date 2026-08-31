#include "get_next_line.h"

// int	main(void)
// {
// 	int	fd;
// 	char	*line;

// 	fd = open("./test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	if (fd != 0)
		close(fd);
	return (0);
}
