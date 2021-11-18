# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alla <alla@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 11:10:49 by user42            #+#    #+#              #
#    Updated: 2021/11/18 18:54:37 by alla             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -I./include

NAME = cub3d.a

LIBFTD = Libft/libft.a

MINILIBX = -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRC_PATH =	get_next_line.c			\
			get_next_line_utils.c	\
			calcul.c				\
			hit_1.c					\
			hit_2.c					\
			init.c					\
			main.c					\
			move.c					\
			pixel.c					\
			raycasting.c			\
			rotate.c				\
			sprite.c				\
			sprite_2.c				\
			check_map_2.c			\
			check_map.c				\
			check_params.c			\
			check_params_2.c		\
			get_color_params.c		\
			get_texture.c			\
			save_bmp.c				\
			new.c					\

SRC = $(addprefix src/,$(SRC_PATH))

OBJ	= $(SRC:.c=.o)

all : minilibx libft $(NAME)

clean :
	$(RM) $(OBJ)
	make clean -C Libft
	make clean -C minilibx-linux

fclean : clean
	$(RM) $(NAME) cub3D
	make fclean -C Libft
	make clean -C minilibx-linux

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) -o cub3D src/main.c $(NAME) $(LIBFTD) $(MINILIBX)

libft :
	make -C Libft

minilibx :
	make -C minilibx-linux

re : fclean all

.PHONY : all clean re