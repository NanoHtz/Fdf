/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_on_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:06:31 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/02 16:40:25 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

int	process_line(char **line, char **file, t_core *content)
{
	int	columns_count;

	columns_count = columns(*line);
	if (!lines_consistent(columns_count, content))
	{
		free(*line);
		return (0);
	}
	content->render_map->axis_x = columns_count;
	content->render_map->axis_y += 1;
	add_line(line, file);
	return (1);
}

int	read_lines(int fd, char **file, t_core *content)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_line(&line, file, content))
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}

char	*work_on_file(int fd, t_core *content)
{
	char	*file;

	file = malloc(sizeof(char));
	if (file == NULL)
		return (NULL);
	file[0] = '\0';
	content->render_map->axis_y = 0;
	if (!read_lines(fd, &file, content))
	{
		free(file);
		return (NULL);
	}
	return (file);
}
