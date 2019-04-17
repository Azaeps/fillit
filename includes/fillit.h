/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 19:05:38 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 16:35:33 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct		s_fillit
{
	char			*s;
	struct s_fillit	*next;
	int				index[6];
}					t_fillit;

typedef struct		s_value
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				ref_x;
	int				ref_y;
	int				check;
}					t_val;

int					full_check(t_fillit *list);
t_fillit			*stock(int fd, t_fillit *list);
int					num_char(char *str);
void				error(void);
char				**ft_map(int x, char **map, int *size);
int					ft_solver(t_fillit *list, char **map, char c, int size);
char				**ft_map_upsize(int size);

#endif
