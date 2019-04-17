/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solver.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <thperchi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 10:26:26 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 18:10:28 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**copy_map(char **map, int size)
{
	char	**c_map;
	int		i;

	i = 0;
	c_map = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		c_map[i] = ft_strdup(map[i]);
		i++;
	}
	c_map[i] = NULL;
	return (c_map);
}

int		display_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
	ft_putchar('\n');
	return (0);
}

void	ft_place_piece(int *tab, char **map, t_val *val, char c)
{
	int three;

	val->x = 1;
	val->y = 0;
	three = 0;
	map[val->i][val->j] = c;
	while (three++ < 3)
	{
		map[val->i + tab[val->y]][val->j + tab[val->x]] = c;
		val->y += 2;
		val->x += 2;
	}
}

int		ft_check_position(int *tab, char **map, t_val *val, int size)
{
	int three;
	int	tmp_i;
	int	tmp_j;

	val->x = 0;
	val->y = 1;
	three = 0;
	while (three++ < 3)
	{
		tmp_i = val->i + tab[val->x];
		tmp_j = val->j + tab[val->y];
		if (tmp_i < 0 || tmp_i >= size || tmp_j < 0 || tmp_j >= size)
			return (0);
		if (map[tmp_i][tmp_j] != '.')
			return (0);
		val->y += 2;
		val->x += 2;
	}
	return (1);
}

int		ft_solver(t_fillit *list, char **map, char c, int size)
{
	t_val	*val;
	char	**c_map;

	val = (t_val *)malloc(sizeof(t_val));
	val->i = -1;
	if (!list && display_map(map) == 0)
		return (1);
	while (map[++val->i])
	{
		val->j = 0;
		while (map[val->i][val->j] && list)
		{
			if (map[val->i][val->j] == '.')
				if (ft_check_position(list->index, map, val, size))
				{
					c_map = copy_map(map, size);
					ft_place_piece(list->index, c_map, val, c);
					if (ft_solver(list->next, c_map, c + 1, size))
						return (1);
				}
			val->j++;
		}
	}
	return (0);
}
