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

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGSMINILIBX = -L minilibx-linux -lmlx -lXext -lX11 -lm
DEBUGGER = -g3
RM = rm -f
NORMINETTE = norminette

# ========================= DIRECTORIOS Y ARCHIVOS =========================== #

DIR_HEADERS = Inc/fdf Inc/libft Inc/get_next_line
DIR_FDF     = Inc/fdf/
DIR_LIBFT   = Inc/libft/
DIR_GNL     = Inc/get_next_line/

HEADERS = $(DIR_FDF)errors.h \
			$(DIR_FDF)fdf.h \
			$(DIR_LIBFT)libft.h \
			$(DIR_GNL)get_next_line.h

DIRSOURCE   = src/

SOURCES_FDF_MANDATORY = $(DIRSOURCE)controls.c \
					$(DIRSOURCE)mlx.c \

SOURCES_FDF_BONUS = $(DIRSOURCE)bonus_utils.c \
					$(DIRSOURCE)bonus_utils_2.c \
					$(DIRSOURCE)controls_bonus.c \
					$(DIRSOURCE)mlx_bonus.c \

SOURCES_FDF = $(DIRSOURCE)bresenham.c \
			$(DIRSOURCE)change_map.c \
			$(DIRSOURCE)color_gradient.c \
			$(DIRSOURCE)color_utils.c \
	  		$(DIRSOURCE)fdf.c \
	  		$(DIRSOURCE)file_utils.c \
	  		$(DIRSOURCE)geometry.c \
	  		$(DIRSOURCE)make_color.c \
	  		$(DIRSOURCE)make_map.c \
	  		$(DIRSOURCE)maths.c \
	  		$(DIRSOURCE)palette.c \
	  		$(DIRSOURCE)points_on_map.c \
	  		$(DIRSOURCE)read_data.c \
	  		$(DIRSOURCE)render.c \
	  		$(DIRSOURCE)scale.c \
	  		$(DIRSOURCE)work_on_file.c \
      		$(DIR_FDF)ft_error.c

ifeq ($(BONUS),1)
	SOURCES = $(SOURCES_FDF) $(SOURCES_FDF_BONUS)
else
	SOURCES = $(SOURCES_FDF) $(SOURCES_FDF_MANDATORY)
endif

# ========================= OBJETOS =========================== #

SRCS        = $(sort $(SOURCES))

OBJSDIR     = ./obj/
OBJS        = $(addprefix $(OBJSDIR), $(notdir $(SRCS:.c=.o)))

# ========================= COLORES PARA EL OUTPUT =========================== #

GREEN			= \033[0;32m
YELLOW			= \033[0;33m
CYAN			= \033[0;36m
MAGENTA			= \033[0;35m
RESET			= \033[0m
RED             = \033[0;31m

# ========================= REGLAS PRINCIPALES =============================== #
.PHONY: all clean fclean re n bonus

all: libft gnl n $(NAME)


bonus:
	@$(MAKE) --no-print-directory BONUS=1 all

$(NAME): $(OBJS)
	@echo "\n${MAGENTA}Compilando el ejecutable $(NAME)...${RESET}\n"
	$(CC) $(OBJS) $(CFLAGS) $(CFLAGSMINILIBX) -L$(DIR_LIBFT) -lft -L$(DIR_GNL) -lgnl $(DEBUGGER) -o $(NAME)
	@echo "${CYAN}=================================================================================================================${RESET}"
	@echo "${GREEN}                                       [✔] $(NAME) successfully compiled.${RESET}                               "
	@echo "${CYAN}=================================================================================================================${RESET}"
	@echo "${MAGENTA}You should use: valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind_output ./$(NAME) maps/0.fdf${RESET}"

# ========================= REGLAS PARA LOS OBJETOS ========================== #
$(OBJSDIR)%.o: $(DIRSOURCE)%.c
	@mkdir -p $(dir $@)
	@echo "${CYAN}Compilando objeto: $<${RESET}"
	$(CC) $(CFLAGS) $(addprefix -I, $(DIR_HEADERS)) -c $< -o $@

$(OBJSDIR)%.o: $(DIR_FDF)/%.c
	@mkdir -p $(dir $@)
	@echo "${CYAN}Compilando objeto: $<${RESET}"
	$(CC) $(CFLAGS) $(addprefix -I, $(DIR_HEADERS)) -c $< -o $@

# ========================= LIMPIEZA DE ARCHIVOS ============================= #

libft: n
	@$(MAKE) -C $(DIR_LIBFT)

gnl: n
	@$(MAKE) -C $(DIR_GNL)

clean:
	@echo "${YELLOW}Limpiando archivos objeto del fdf...${RESET}"
	$(RM) -r $(OBJSDIR)
	@$(MAKE) -C $(DIR_LIBFT) clean
	@$(MAKE) -C $(DIR_GNL) clean

fclean: clean
	@echo "${RED}Eliminando la biblioteca $(NAME)...${RESET}"
	$(RM)	$(NAME)
	@$(MAKE) -C $(DIR_LIBFT) fclean
	@$(MAKE) -C $(DIR_GNL) fclean

re: fclean all
	@$(MAKE) -C $(DIR_LIBFT) re
	@$(MAKE) -C $(DIR_GNL) re
# ========================= OTRAS REGLAS ===================================== #
n:
	@echo "${CYAN}=================================${RESET}"
	@echo "${GREEN}         Norminette.      ${RESET}"
	@echo "${CYAN}=================================${RESET}"
	@echo "\n"
	-$(NORMINETTE) $(HEADERS) $(SRCS)
	@echo "\n"
	@echo "${GREEN}[✔] Norminette completa.${RESET}\n"