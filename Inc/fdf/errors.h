/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:24:38 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/26 21:49:30 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define ERROR -1
# define ARGS "Error in arguments"
# define USAGE "You should use: ./fdf maps/test_map_file.fdf"
# define FD_ERROR "Error opening file"
# define MAP_DIM "The map does not have a stable dimension.\n" \
					"Some line has more elements than another"
# define READ_ERROR "Error in read_data() function"

# define MEMORY_ERROR "Memory error in read_data(malloc)" //Errores de memoria
# define CLOSE_ERROR "Error closing file" //Errores de memoria



# define MAP_ERROR 1 //Error al leer el mapa
# define ERROR_READING 1 //Error de lectura


int	ft_error(int x, const char *str_1, ...);

#endif
