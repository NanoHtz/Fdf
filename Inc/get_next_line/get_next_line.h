/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:08:38 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/08/21 18:53:46 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Libreria
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Guarda del macro del Buffer
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//Librerias utilizadas
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>//Libreria para el main

//Nodo de mi lista enlazada.
typedef struct list
{
	char			*buffer_str;
	struct list		*next_bs;
}	t_list;

char	*get_next_line(int fd);
void	make_new_list(t_list **list, int fd);
int		look_for_newline(t_list *list);
void	add_string_to_list(t_list	**list, char *buffer);
t_list	*look_for_end(t_list *list);
int		len_for_endline(t_list *list);
void	str_cpy(t_list *list, char *str);
void	cancel_mem(t_list **list, t_list *clean, char *buf);
void	prepare_the_recall(t_list	**list);
char	*get_the_line(t_list *list);

#endif
