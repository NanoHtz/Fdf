# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 14:04:17 by fgalvez-          #+#    #+#              #
#    Updated: 2024/11/12 18:59:05 by fgalvez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#cc fdf.c -L minilibx-linux -lmlx -lXext -lX11 -o fdf

#En la entrega debo juntar ambas flags de compilacion
#Debo quitar la variable exec
#Debo ajustar las flags de all
#Debo quitar el exec de make re

#********** Variables de compilación **********

CC = gcc #Variable para asignar el tipo de compilación
CFLAGS = -Wall -Wextra -Werror -g3 -ggdb3 #Variable para asignar las flags de compilación pedidas siempre en 42
CFLAGS2 = -L minilibx-linux -lmlx -lXext -lX11 #Variable para asignar las flags de compilación para manejar la minilibx

RM = rm -f #variable para el borrado y la limpieza

NAME = fdf #Nombre del programa resultante
INCLUDE = fdf.h \
		Inc/get_next_line/get_next_line.h \
		Inc/libft/libft.h
#Archivos fuente
SOURCES = fdf.c \
		fdf_utils.c \
		events.c \
		menu.c \
		line.c \
		Inc/get_next_line/*.c \
		Inc/libft/*.c

OBJS = $(SOURCES:.c=.o) #EN la variable objs se guarda el resultado de coger los elementos de sources y cambiar el sufijo.c por punto.o
EXEC =  valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./fdf 0.fdf
NORMINETTE = norminette
#********** Palabras resevadas **********

.PHONY: all clean fclean re n
#phony (falsos) indica que las siguientes palabras no son archivos, si existiese un archivo asi, lo ignoraria, ni siquiera lo busca, lo que lo hace mas rapido

#********** Reglas **********

all: $(NAME) #Comando estandar de make, al ejecutar make solo ejecutara lo siguiente:

$(NAME): $(SOURCES) #Name es el nombre del ejecutable final, lo hara a partir de las fuentes(sources). Utiliza las variables para compilar de esa forma concreta.
	@echo "*************************************************ALL*************************************************"
	$(CC) $(SOURCES) $(CFLAGS) $(CFLAGS2) -o $(NAME)

clean: #make clean ejecuta el comando siguiente
	@echo "*************************************************CLEAN*************************************************"
	$(RM)	$(OBJS)

fclean: clean #make fclean ejecuta el comando clean y despues el comando siguiente
	@echo "*************************************************FCLEAN*************************************************"
	$(RM)	$(NAME)

n:
	@echo "*************************************************NORMINETTE*************************************************"
	-$(NORMINETTE) $(SOURCES)

re:  n fclean all #make re ejecuta el comando fclean y despues vuelve a realizar el make.
	@echo "*************************************************RE-VALGRIND*************************************************"
	$(EXEC)
