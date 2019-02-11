/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 12:44:08 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 15:51:55 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		check_s(char *s)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	while (s[x])
	{
		if (s[x] == '#')
		{
			if (s[x + 1] == '#')
				y++;
			if (s[x - 1] == '#')
				y++;
			if (s[x - 5] == '#')
				y++;
			if (s[x + 5] == '#')
				y++;
			z++;
		}
		if (s[x] != '.' && s[x] != '#' && s[x] != '\n' && s[x] != '\0')
			return (0);
		if ((x == 4 || x == 9 || x == 14) && s[x] != '\n')
			return (0);
		x++;
	}
	if ((y == 6 || y == 8) && z == 4 && x == 20)
		return (1);
	return (0);
}

char	*read_fd(int fd)
{
	int	x;
	int	y;
	char	*s;
	char	c;

	x = read(fd, &c, 1);
	y = 0;
	s = malloc(sizeof (char *) * 21); /*malloc juste pour les test*/
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
	t_test	*list;

	if (ac != 2)
	{
		ft_putstr("usage: fillit imput_file");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	s = read_fd(fd);
	printf("%s", s);
	if (!check_s(s))
	{
		printf("ca marche pas");
		return (0);
	}
	return (0);
}
