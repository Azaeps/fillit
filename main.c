/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 12:44:08 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 19:09:24 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*int		check_s(char *s)
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

int		full_check(char *s)
{
	char	*check;
	int		x;
	int		y;

	x = 0;
	y = 0;
	check = malloc(sizeof(char *) * 20);
	while (s[x])
	{
		while (y != 20)
		{
			check[y] = s[x];
			x++;
			y++;
		}
		if (!check_s(check))
			return (0);
		free(check);
		check = malloc(sizeof(char *) * 20);
		y = 0;
		x += 1;
	}
	return (1);
}*/

static char		*read_fd(int fd)
{
	int		x;
	int		y;
	char	*s;
	char	c;

	x = read(fd, &c, 1);
	y = 0;
	s = malloc(sizeof(char *) * 21); /*malloc juste pour les test*/
	if (x == -1)
		return (NULL);
	while (x)
	{
		s[y] = c; /* s a mallocer mais je sais pas a quelle taille */
		y++;
		x = read(fd, &c, 1);
	}
	s[y] = '\0';
	return (s);
}

int				main(int ac, char **av)
{
	char		*s;
	int			fd;
	t_fillit	*list;

	if (ac != 2)
	{
		ft_putstr("usage: fillit imput_file");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	s = read_fd(fd);
	if (!full_check(s))
	{
		printf("ca marche pas");
		return (0);
	}
	list = (t_fillit *)malloc(sizeof(t_fillit));
	stock(s, list);
	return (0);
}
