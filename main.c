#include "get_next_line.h"


int main(int ac, char **av)
{
	char *line = "Inicializanddo..";
	int fd = open(av[1], 0b100);

	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\0')
			break;
		printf("%s", line);
        free(line);
    }
	close(fd);
	return 0;
}