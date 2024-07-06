# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lteng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 15:46:17 by lteng             #+#    #+#              #
#    Updated: 2024/05/18 15:39:39 by lteng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = events.c	init.c main.c render.c utils.c

OBJS = $(SRCS:.c=.o)
CC = cc -g
CFLAGS = -Wall -Werror -Wextra
NAME = fractol
RM = rm -rf
all: $(NAME)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./mlx
MLX = $(MLX_PATH)/libmlx.a

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lXext -lX11 -lm 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
