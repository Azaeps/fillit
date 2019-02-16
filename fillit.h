/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 19:05:38 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 18:06:04 by thperchi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_fillit
{
	char			*s;
	struct s_fillit	*next;
}					t_fillit;

int					full_check(t_fillit *list);
t_fillit			*stock(int fd, t_fillit *list);
#endif
