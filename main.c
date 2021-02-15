#include "get_next_line.h"
#include <fcntl.h>

int main() 
{
    int ret;
	int fd;
    char *line;

    line = 0;
	fd = open("test.txt", O_RDONLY);
    ret = get_next_line(fd, &line);
    while (ret > 0) {
        write(1, line, ft_len(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
        ret = get_next_line(fd, &line);
    }
	return 0;
}
