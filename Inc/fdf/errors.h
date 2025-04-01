/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:15:22 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/03/31 15:51:12 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

struct						s_core;
typedef struct s_core	t_core;

# define MAP_D "function draw_map : Error: Invalid map data.\n"
# define MAP_P "function points_on_map : Error: Invalid map data.\n"
# define FD_ERROR "function read_data : Error in open file. Use archives in maps/archive.fdf\n"
# define MEMORY_ERROR_R "function read_data : Error: Invalid map data.\n"
# define USAGE "Arguments error: use only two arguments. Usage: ./fdf maps/archive.fdf"
# define CLOSE_ERROR "ERROR"
# define READ_ERROR "ERROR"

int		ft_error(const char *str_1);
void	ft_report_void(const char *str_1);
int		close_and_report(const char *str_1, int fd);
int		free_close_report(const char *s, int fd, t_core *cont, char *file);

#endif
