#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*read_fd(int fd)
{
	int	x;
	int	y;
	char	*s;
	char	c;

	x = read(fd, &c, 1);
	y = 0;
	if (x == -1)
		return (NULL);
	while(x)
	{
		s[y] = c; /* s a mallocer mais je sais pas a quelle taille */
		y++;
		x = read(fd, &c, 1);
	}
	s[y] = '\0';
	return (s);
}

int		main(int ac, char **av)
{
	char	*s;
	int	fd;
	t_list	*list;

	if (ac != 2)
	{
		/*usage (jsp ce que c'est xd)*/
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	s = read_fd(fd);
	if (!check_s)
	{
		/*error*/
		return (0);
	}
	return (0);
}
