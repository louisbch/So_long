# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:24:53 by lbouchon          #+#    #+#              #
#    Updated: 2023/01/12 11:31:21 by lbouchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NORMINETTE = norminette

SRCS = \
			get_next_line.c			\
			get_next_line_utils.c	\
			ft_strlen.c				\
			ft_strnstr.c			\
			ft_strncmp.c			\
			ft_strjoin.c			\
			ft_split.c				\
			ft_putstr_fd.c			\
			ft_strdup.c				\
			ft_print_hex.c			\
			ft_print_unsigned.c		\
			ft_printf.c				\
			ft_printptr.c			\
			ft_printstr.c			\
			ft_utils.c				\

OBJS = ${SRCS:.c=.o}

%.o : %.c
		@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $@ $^
	
clean:
		$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
		$(NORMINETTE)

.PHONY: all clean fclean re
