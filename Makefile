# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:21:28 by sgendel           #+#    #+#              #
#    Updated: 2022/09/12 19:54:06 by sgendel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	exe/cub3D

PATHSRC		=	bin/

PATHUTILS	=	bin/utils/

LIST		=	./$(PATHSRC)main.c\
				./$(PATHSRC)handler_of_errors.c\
				./$(PATHSRC)parse_map.c\
				./$(PATHUTILS)get_next_line/get_next_line.c\
				./$(PATHUTILS)get_next_line/get_next_line_utils.c\

OBJ			=	$(patsubst %.c, %.o, $(LIST))

HEADER		=	lib/include/cub3D.h

# FLAGS		=	-Wall -Werror -Wextra

LIBXF		=	lib/minilibx/libmlx.a -framework OpenGL -framework AppKit

GREEN = \033[0;32m

RESET = \033[0m

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER) Makefile
	@echo "\ncub3D: $(GREEN)object files were created$(RESET)"
	$(CC) $(OBJ)  $(LIBXF) -o $(NAME)
	@echo "cub3D: $(GREEN)cub3D was created$(RESET)"
# $(FLAGS)
%.o: %.c	$(HEADER)
	$(CC) $(FLAGS) -I mlx -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

