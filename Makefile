# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 14:04:17 by fgalvez-          #+#    #+#              #
#    Updated: 2024/11/28 12:14:00 by fgalvez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGSMINILIBX = -L minilibx-linux -lmlx -lXext -lX11 -lm
DEBUGGER = -g3
RM = rm -f
NORMINETTE = norminette

INCLUDE = Inc/fdf/fdf.h \
		Inc/get_next_line/get_next_line.h \
		Inc/libft/libft.h \
		Inc/fdf/errors.h \
		Inc/fdf/colors.h

DIRSOURCE = src/
SOURCES = fdf.c \
			read_data.c \
			read_data2.c \
			mlx.c \
			mates.c \
			line.c \
			read_data2.c \
			isometric.c \
			map.c \
			draw.c \
			color_handling.c
FDF = Inc/fdf/*.c
LIBFT = Inc/libft/*.c
GNL = Inc/get_next_line/*.c
SRCS = $(addprefix ${DIRSOURCE}, ${SOURCES})

OBJS = $(SRCS:.c=.o)

#********** Palabras resevadas **********

.PHONY: all clean fclean re n

#********** Reglas **********

all: n $(NAME)

$(NAME): $(OBJS)
	@echo "*************************************************ALL*************************************************"
	$(CC) $(SRCS) $(CFLAGS) $(CFLAGSMINILIBX) $(DEBUGGER) -o $(NAME)

clean:
	@echo "*************************************************CLEAN*************************************************"
	$(RM)	$(OBJS)

fclean: clean
	@echo "*************************************************FCLEAN*************************************************"
	$(RM)	$(NAME)

n:
	@echo "*************************************************NORMINETTE*************************************************"
	-$(NORMINETTE) $(SOURCES)

re: fclean all
	@echo "*************************************************RE-VALGRIND*************************************************"
