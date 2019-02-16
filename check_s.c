/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_s.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 12:47:47 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 05:50:28 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		check_s(char *s)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	while (s[x])
	{
		if (s[x] == '#'/* && (s[x - 1] != '#' && s[x + 1] != '#'
					&& s[x - 5] != '#' && s[x + 5] != '#')*/)
		{
			//return (0);
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
	printf("%d\n", y);
	printf("%d\n", z);
	if ((y == 6 || y == 8) && z == 4 && x == 20)
		return (1);
	return (0);
}

int				full_check(t_fillit *list)
{
//	char	*check;
	int		x;
//	int		y;

	x = 0;
//	y = 0;
//	check = malloc(sizeof(char *) * 21);
	while (list)
	{
/*		while (y != 20)
		{
			check[y] = list->s[x];
			x++;
			y++;
		}
	//	printf("%s", check);*/
		if (list->next->next == NULL)
			return (1);
		if (!check_s(list->s))
			return (0);
	//	free(check);
	//	check = malloc(sizeof(char *) * 21);
	//	y = 0;
		x++;
		printf("%d\n", x);
		list = list->next;
	}
	return (1);
}
