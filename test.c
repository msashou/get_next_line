#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

