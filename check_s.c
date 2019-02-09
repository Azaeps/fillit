#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	check_s(char *s)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (s[x])
	{
		if (s[x] == '#')
		{
			if (s[x + 1] == '#')
				y++;
			if (s[x - 1] == '#')
				y++;
			if (s[x + 5] == '#')
				y++;
			if (s[x - 5] == '#')
				y++;
		}
		x++;
	}
	if (y == 6 || y = 8)
		return (1);
	return (0);
}
