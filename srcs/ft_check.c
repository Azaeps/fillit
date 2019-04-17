/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 10:26:06 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 18:49:37 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			ft_index2(t_fillit *list, t_val *val)
{
	while (list->s[val->i])
	{
		if (list->s[val->i] == '#')
		{
			if (val->check == 1)
			{
				val->ref_y = val->y;
				val->ref_x = val->x;
				val->check = 0;
			}
			else
			{
				list->index[val->j++] = val->y - val->ref_y;
				list->index[val->j++] = val->x - val->ref_x;
			}
		}
		val->i++;
		val->x++;
		if (list->s[val->i] == '\n' && val->i++)
		{
			val->x = 0;
			val->y++;
		}
	}
}

t_fillit		*ft_index(t_fillit *list, t_val *val)
{
	t_fillit	*tmp;

	tmp = list;
	while (list)
	{
		val->check = 1;
		val->j = 0;
		val->x = 0;
		val->y = 0;
		val->i = 0;
		if (list->s[val->i])
			ft_index2(list, val);
		list = list->next;
	}
	list = tmp;
	return (list);
}

static int		valid_tetri(int y, char *s, int x)
{
	if (s[x + 1] == '#')
		y++;
	if (s[x - 1] == '#')
		y++;
	if (s[x - 5] == '#')
		y++;
	if (s[x + 5] == '#')
		y++;
	return (y);
}

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
		if (s[x] == '#')
		{
			y = valid_tetri(y, s, x);
			z++;
		}
		if (s[x] != '.' && s[x] != '#' && s[x] != '\n' && s[x] != '\0')
			error();
		if ((x == 4 || x == 9 || x == 14) && s[x] != '\n')
			error();
		x++;
	}
	if ((y == 6 || y == 8) && z == 4 && x == 20)
		return (1);
	return (0);
}

int				full_check(t_fillit *list)
{
	t_val		*val;
	char		**map;
	t_fillit	*tmp;
	char		c;
	int			size;

	val = (t_val *)malloc(sizeof(t_val));
	val->x = 0;
	tmp = list;
	map = NULL;
	c = 'A';
	while (list)
	{
		if (!check_s(list->s))
			return (0);
		val->x++;
		list = list->next;
	}
	map = ft_map(val->x, map, &size);
	list = tmp;
	list = ft_index(list, val);
	while (ft_solver(list, map, c, size) == 0 && size++)
	{
		free(map);
		map = ft_map_upsize(size);
	}
	return (1);
}
