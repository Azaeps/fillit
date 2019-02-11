/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stock.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 18:42:19 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 19:05:12 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	stock(char *s, t_fillit *list)
{
	int x;
	int y;

	x = 0;
	y = 0;
	list->s = malloc(sizeof(char *) * 20);
	while (s[x])
	{
		while (y != 20)
		{
			list->s[y] = s[x];
			x++;
			y++;
		}
		x += 1;
		y = 0;
		printf("%s", list->s);
		list = list->next;
		list = malloc(sizeof(t_fillit));
		list->s = malloc(sizeof(char *) * 21);
	}
}
