# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/01 10:22:57 by jominodi     #+#   ##    ##    #+#        #
#    Updated: 2019/04/11 17:49:40 by thperchi    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean lib

NAME = fillit

SRC_DIR = ./srcs/
OBJ_DIR = $(SRC_DIR)object/
INC_DIR = $(SRC_DIR)
LIB_DIR = ./libft/

SRC_NAME = fillit.c\
		   ft_solver.c\
		   ft_check.c\
		   ft_map.c
INC_NAME = $(NAME).h
LIB_NAME = libft.a

OBJ_NAME = $(SRC_NAME:.c=.o)
	INC = $(addprefix $(INC_DIR), $(INC_NAME))
	SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
	OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
	LIB = $(addprefix $(LIB_DIR), $(LIB_NAME))

FLAG = -Wall -Werror -Wextra

all	: $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ) $(LIB)
		gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)

$(LIB) :
		$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR) :
		mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		gcc $(FLAG) -I $(INC) -o $@ -c $<

lib :
		$(MAKE) -C $(LIB_DIR)

clean : lib_clean
		rm -rf $(OBJ_DIR)

lib_clean :
		$(MAKE) -C $(LIB_DIR) clean

fclean : lib_fclean
		rm -rf $(OBJ_DIR)
			rm -rf $(NAME)

lib_fclean :
		$(MAKE) -C $(LIB_DIR) fclean

re : fclean lib all
