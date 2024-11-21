/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:08:38 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/06/20 18:45:19 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Libreria
#ifndef LIBFT_H
# define LIBFT_H

//Librerias incluidas
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//Funciones
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
size_t			count_words(const char *s, char c);
int				ft_atoi(const char *nptr);

#endif
