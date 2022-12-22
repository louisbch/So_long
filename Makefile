# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:47:11 by lbouchon          #+#    #+#              #
#    Updated: 2022/12/22 13:17:49 by lbouchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

RM = rm -rf

DIR = srcs/

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

NORMINETTE = norminette
			
SRCS = $(DIR)main.c			\
		$(DIR)ft_map.c		\
		$(DIR)ft_utils.c	\
		
OBJS = ${SRCS:.c=.o}

MLX_INC = -I minilibx

MLX_LIB = minilibx/libmlx.a

MLX_LINK = -L minilibx -l mlx -framework OpenGL -framework Appkit

LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

all : subsystems $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(MLX_LINK) $(LIBFT) -o $(NAME) $(OBJS)
		@echo "\033[0;42mSo_long is now compile !\033[0m"

subsystems:
	make -C minilibx all
	make -C libft all
		
clean:
	@make -C minilibx clean
	@make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean 
	$(RM) $(NAME)

re: fclean all

%.o: %.c
		@echo "\033[1;33mCompiling So_long...\033[0m"
		$(CC) $(MLX_INC) $(CFLAGS) -o $@ -c $<

norm:
		$(NORMINETTE)
.PHONY: all clean fclean re norm