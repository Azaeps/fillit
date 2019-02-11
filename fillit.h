#ifndef FILLIT
# define FILLIT

#include "./libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct		s_test
{
	char			c;
	int				x;
	int				y;
	struct s_list	*next;
}					t_test;


char				*read_fd(int fd);
int					check_s(char *s);
#endif
