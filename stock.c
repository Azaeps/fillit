/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stock.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 18:42:19 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 04:35:50 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*stock(int fd, t_fillit *list)
{
	int x;
	int y;
	int z;
	char c;

	x = 0;
	y = 0;
	z = read(fd, &c, 1);
	list->s = malloc(sizeof(char *) * 20);
	while (z)
	{
		while (y != 20)
		{
			list->s[y] = c;
			x++;
			y++;
			z = read(fd, &c, 1);
		}
		list->s[y] = '\0';
		if (c == '\n')
			z = read(fd, &c, 1);
		y = 0;
		printf("%s\n", list->s);
		if (c == '\0')
			break;
		list->next = malloc(sizeof(t_fillit));
		list = list->next;
		list->s = malloc(sizeof(char *) * 20);
	}
	list = NULL;
	return (list);
}
