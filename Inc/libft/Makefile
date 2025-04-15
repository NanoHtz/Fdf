# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 14:04:17 by fgalvez-          #+#    #+#              #
#    Updated: 2025/04/03 11:33:04 by fgalvez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========================= VARIABLES GLOBALES =============================== #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# ========================= DIRECTORIOS Y ARCHIVOS =========================== #

OBJ_DIR = obj

SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_substr.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ========================= COLORES PARA EL OUTPUT =========================== #

GREEN			= \033[0;32m
YELLOW			= \033[0;33m
CYAN			= \033[0;36m
MAGENTA			= \033[0;35m
RESET			= \033[0m
RED             = \033[0;31m

# ========================= REGLAS ============================= #

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creando la biblioteca estática $@..."
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)  # Crea el directorio de objetos si no existe
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${YELLOW}Limpiando los archivos objeto de la libft...${RESET}"
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "${RED}Eliminando la biblioteca $(NAME)...${RESET}"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
